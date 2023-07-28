#include "temario.h"
#include "ui_temario.h"
Temario::Temario(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Temario),
    ARCHIVO(QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation) + "/temario.bin")
{
    ui->setupUi(this);
    setWindowTitle(tr("TEMARIO"));
    ui->tbl_temario->setColumnCount(2);
    QStringList titulo;
    titulo <<tr("pregunta") <<tr("respuesta");
    ui->tbl_temario->setHorizontalHeaderLabels(titulo);
    ui->tbl_temario->setColumnWidth(PREGUNTA,641);
    ui->tbl_temario->setColumnWidth(RESPUESTA,90);
    // Crear el directorio si no existe
       QString ruta = QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation);
       QDir dir;
       if (!dir.exists(ruta)) {
           dir.mkpath(ruta);
       }
    cargarPreguntas();
}

Temario::~Temario()
{
    delete ui;
}



void Temario::on_btnagregar_clicked()
{
    preguntasdialog pd(this);
    pd.setWindowTitle(tr("agregar pregunta"));
    int res=pd.exec();
    if(res==QDialog::Rejected){
        return;
    }
    Pregunta *p = pd.preguntas();
    int fila=ui->tbl_temario->rowCount();
    ui->tbl_temario->insertRow(fila);
    ui->tbl_temario->setItem(fila, PREGUNTA, new QTableWidgetItem(p->pregunta()));
    ui->tbl_temario->setItem(fila, RESPUESTA, new QTableWidgetItem(p->respuesta()));
    m_listaPreguntas.append(new Pregunta(QString::number(m_listaPreguntas.size()+1),p->pregunta(),p->respuesta()));
}


void Temario::on_btnguardar_clicked()
{
    int filas = ui->tbl_temario->rowCount();
    if(filas== 0 ){
        QMessageBox::warning(this, tr("Guardar temario"), tr("el temario no tiene suficientes preguntas"));
        return;
    }

    QFile archivo(ARCHIVO);
    if (archivo.open(QFile::WriteOnly | QFile::Truncate)) {
        QDataStream salida(&archivo);
        salida.setVersion(QDataStream::Qt_5_15); // o la versión de Qt que estás utilizando

        for (int i=0; i<filas; i++) {
            QTableWidgetItem *pregunta = ui->tbl_temario->item(i,PREGUNTA);
            QTableWidgetItem *respuesta = ui->tbl_temario->item(i, RESPUESTA);

            if (!pregunta || !respuesta) {
                // Manejar o informar el error aquí
                continue;
            }

            salida << pregunta->text() << respuesta->text();
        }
        archivo.close();
        if (salida.status() != QDataStream::Ok) {
            QMessageBox::critical(this, tr("Guardar temario"), tr("Error al escribir en ") + ARCHIVO);
        } else {
            QMessageBox::information(this,tr("Guardar temario"),tr("Temario guardado"));
        }
    } else {
        QMessageBox::critical(this,tr("Guardar temario"), tr("No se puede abrir para escritura ") + ARCHIVO);
    }
}


void Temario::cargarPreguntas()
{
    QFile archivo(ARCHIVO);

    if (!(archivo.exists())){
        archivo.setFileName(":/Recursos/Preguntas/temario.bin");
    }

    m_listaPreguntas.clear();

    ui->tbl_temario->clearContents();
    ui->tbl_temario->setRowCount(0);
    if (archivo.open(QFile::ReadOnly)) {
        QDataStream entrada(&archivo);
        int fila;
        while(!entrada.atEnd()){
            QStringList datos;
            datos.append("");
            datos.append("");
            entrada >> datos[PREGUNTA] >> datos[RESPUESTA];
            fila = ui->tbl_temario->rowCount();
            ui->tbl_temario->insertRow(fila);
            ui->tbl_temario->setItem(fila, PREGUNTA, new QTableWidgetItem(datos[PREGUNTA]));
            ui->tbl_temario->setItem(fila, RESPUESTA, new QTableWidgetItem(datos[RESPUESTA]));
            m_listaPreguntas.append(new Pregunta(QString::number(m_listaPreguntas.size()+1),datos[PREGUNTA],datos[RESPUESTA]));
        }
        archivo.close();
    }
}

void Temario::mostrarPreguntas(const QString &rArchivo){
    QFile archivo(rArchivo);
    if(!archivo.exists()){
        QMessageBox::critical(this,tr("cargar temario"),tr("el temario no existe"));
        return;
    }

    m_listaPreguntas.clear();

    ui->tbl_temario->clearContents();
    ui->tbl_temario->setRowCount(0);
    if(archivo.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream direccion(&archivo);
        int fila=0;
        while (!direccion.atEnd()) {
            QString linea= direccion.readLine();
            QStringList datos= linea.split(";");
            if(datos.size()==2){
                ui->tbl_temario->insertRow(fila);
                ui->tbl_temario->setItem(fila, PREGUNTA, new QTableWidgetItem(datos[PREGUNTA]));
                ui->tbl_temario->setItem(fila, RESPUESTA, new QTableWidgetItem(datos[RESPUESTA]));
                m_listaPreguntas.append(new Pregunta(QString::number(m_listaPreguntas.size()+1),datos[PREGUNTA],datos[RESPUESTA]));
                fila++;
            }
        }
        archivo.close();
    }else{
        QMessageBox::critical(this,tr("cargar temario"),tr("No se pudo abrir el temario"));
    }
}

QList<Pregunta *> Temario::randomizarPreguntas()
{
    QList <Pregunta*> temp = m_listaPreguntas;
    QList <Pregunta*> sacarPreguntas;
    srand(time(0));

    while(!temp.isEmpty()){
        int aux = rand()%(temp.size());
        sacarPreguntas.append(temp[aux]);
        temp.removeAt(aux);
    }
    return sacarPreguntas;
}
void Temario::on_btneditar_clicked()
{
    int fila=ui->tbl_temario->currentRow();
    if (fila < 0) {
        return;
    }
    QTableWidgetItem *preguntaN = ui->tbl_temario->item(fila,PREGUNTA);
    QTableWidgetItem *respuestaN = ui->tbl_temario->item(fila,RESPUESTA);
    if(preguntaN && respuestaN){
        QString preguntanueva = preguntaN->text();
        QString respuestanueva = respuestaN->text();

        preguntasdialog pd(this);
        pd.setWindowTitle(tr("Editar Pregunta"));
        pd.setPregunta(preguntanueva);
        pd.setRespuesta(respuestanueva);

        int res = pd.exec();
        if(res == QDialog::Rejected){
            return;
        }
        QString preguntaF= pd.getPregunta();
        QString respuestaF= pd.getRespuesta();

        preguntaN->setText(preguntaF);
        respuestaN->setText(respuestaF);

        QMessageBox::information(this,tr("editor de preguntas"),tr("pregunta actualizada"));

    }


}

void Temario::on_btneliminar_clicked()
{
    int fila=ui->tbl_temario->currentRow();
    if (fila < 0) {
        return;
    }
    ui->tbl_temario->setCurrentCell(fila,PREGUNTA);
    for(int i=0;i<m_listaPreguntas.size();i++){
        if(m_listaPreguntas[i]->pregunta()==ui->tbl_temario->currentItem()->text()){
            m_listaPreguntas.removeAt(i);
        }
    }
    ui->tbl_temario->removeRow(fila);
}


void Temario::on_btnexportar_clicked()
{
    int filas = ui->tbl_temario->rowCount();
    if (filas == 0) {
        QMessageBox::warning(this, tr("Guardar temario"), tr("No hay datos para guardar"));
        return;
    }
    QString selectedFilePath = QFileDialog::getSaveFileName(this, tr("Guardar temario"), QDir::homePath() + "/temario.csv", tr("Archivos csv") + " (*.csv)");
    if (selectedFilePath.isEmpty()) {
        QMessageBox::information(this, tr("Guardar temario"), tr("Operación de exportar cancelada"));
        return;
    }
    QFile archivo(selectedFilePath);
    QTextStream salida(&archivo);
    if (archivo.open(QIODevice::WriteOnly)) {
        for (int i = 0; i < filas; i++) {
            QTableWidgetItem *pregunta = ui->tbl_temario->item(i, PREGUNTA);
            QTableWidgetItem *respuesta = ui->tbl_temario->item(i, RESPUESTA);
            salida << pregunta->text() <<";"<< respuesta->text() << "\n";
        }
        archivo.close();
        QMessageBox::information(this, tr("Guardar temario"), tr("Preguntas guardadas exitosamente en el archivo csv"));
    } else {
        QMessageBox::critical(this, tr("Guardar temario"), tr("No se puede escribir en el archivo csv"));
    }
    cargarPreguntas();
}


void Temario::on_btnimportar_clicked()
{
    QString direccionA = QFileDialog::getOpenFileName(this, tr("Seleccionar temario"), QString(), tr("Archivos de texto") + "( *.csv )");
    if (!direccionA.isEmpty()) {
        mostrarPreguntas(direccionA);
        QMessageBox::information(this, tr("Cargar archivo"), tr("Temario cargado exitosamente."));
    }
}
void Temario::retranslateUi() {
    ui->tbl_temario->setHorizontalHeaderLabels({QApplication::translate("Temario", "Pregunta", nullptr), QApplication::translate("Temario", "Respuesta", nullptr)});

    ui->btnexportar->setText(QApplication::translate("Temario", "Exportar", nullptr));
    ui->btnimportar->setText(QApplication::translate("Temario", "Importar", nullptr));
    ui->btnagregar->setText(QApplication::translate("Temario", "Agregar", nullptr));
    ui->btneditar->setText(QApplication::translate("Temario", "Editar", nullptr));
    ui->btneliminar->setText(QApplication::translate("Temario", "Eliminar", nullptr));
    ui->btnguardar->setText(QApplication::translate("Temario", "Guardar", nullptr));


}

