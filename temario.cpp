#include "temario.h"
#include "qlineedit.h"
#include "ui_temario.h"
Temario::Temario(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Temario)
{
    ui->setupUi(this);
    setWindowTitle("TEMARIO");
    ui->tbl_temario->setColumnCount(2);
    QStringList titulo;
    titulo <<"pregunta" <<"respuesta";
    ui->tbl_temario->setHorizontalHeaderLabels(titulo);
    ui->tbl_temario->setColumnWidth(PREGUNTA,641);
    ui->tbl_temario->setColumnWidth(RESPUESTA,90);

    cargarPreguntas();
}

Temario::~Temario()
{
    delete ui;
}



void Temario::on_btnagregar_clicked()
{
    preguntasdialog pd(this);
    pd.setWindowTitle("agregar pregunta");
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
        QMessageBox::warning(this, "Guardar temario", "el temario no tiene suficientes preguntas");
        return;
    }

    QString archivobin=ARCHIVO;
    QString folderpath = QCoreApplication::applicationDirPath();
    QString seleccionardireccion = folderpath + "/" + archivobin;
    QFile archivo(seleccionardireccion);
    if (archivo.open(QFile::WriteOnly | QFile::Truncate)) {
        QDataStream salida(&archivo);
        for (int i=0; i<filas; i++) {
            QTableWidgetItem *pregunta = ui->tbl_temario->item(i,PREGUNTA);
            QTableWidgetItem *respuesta = ui->tbl_temario->item(i, RESPUESTA);

            salida << pregunta->text() <<";"<< respuesta->text()<<" " ;
        }
        archivo.close();
        QMessageBox::information(this,"Guardar temario","temario guardado");
    }else{
        QMessageBox::critical(this,"Guardar temario", "No se puede escribir sobre " + ARCHIVO);
    }
}

void Temario::cargarPreguntas()
{
    QFile archivo(ARCHIVO);
    if (!archivo.exists())
        return;

    if (archivo.open(QFile::ReadOnly)) {
        QTextStream entrada(&archivo);
        int fila;
        while(!entrada.atEnd()){
            QString linea = entrada.readLine();
            QStringList datos = linea.split(";");
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
        QMessageBox::critical(this,"cargar temario","el temario no existe");
        return;
    }
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
                ui->tbl_temario->setItem(fila, PREGUNTA, new QTableWidgetItem(datos[0]));
                ui->tbl_temario->setItem(fila, RESPUESTA, new QTableWidgetItem(datos[1]));
                fila++;
            }
        }
        archivo.close();
    }else{
        QMessageBox::critical(this,"cargar temario","No se pudo abrir el temario");
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
        pd.setWindowTitle("Editar Pregunta");
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

        QMessageBox::information(this,"editor de preguntas","pregunta actualizada");

    }


}

void Temario::on_btneliminar_clicked()
{
    int fila=ui->tbl_temario->currentRow();
    if (fila < 0) {
        return;
    }
    ui->tbl_temario->removeRow(fila);
}


void Temario::on_btnexportar_clicked()
{
    int filas = ui->tbl_temario->rowCount();
    if (filas == 0) {
        QMessageBox::warning(this, "Guardar temario", "No hay datos para guardar");
        return;
    }
    QString selectedFilePath = QFileDialog::getSaveFileName(this, "Guardar temario", QDir::homePath(), "Archivos csv (*.csv)");
    if (selectedFilePath.isEmpty()) {
        QMessageBox::information(this, "Guardar temario", "Operación de exportar cancelada");
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
        QMessageBox::information(this, "Guardar temario", "Preguntas guardadas exitosamente en el archivo csv");
    } else {
        QMessageBox::critical(this, "Guardar temario", "No se puede escribir en el archivo csv");
    }
}


void Temario::on_btnimportar_clicked()
{
    QString direccionA = QFileDialog::getOpenFileName(this, "Seleccionar temario", QString(), "Archivos de texto (*.txt *.csv *.bin )");
    if (!direccionA.isEmpty()) {
        mostrarPreguntas(direccionA);
        QMessageBox::information(this, "Cargar archivo", "Temario cargado exitosamente.");
    }
}

