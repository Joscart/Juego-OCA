#include "temario.h"
#include "qlineedit.h"
#include "ui_temario.h"
#include "QDebug"
#include <QStack>
#include <QTableWidget>
#include <QMessageBox>
#include <QDialog>
#include <QFile>
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
    Preguntas *p = pd.preguntas();
    int fila=ui->tbl_temario->rowCount();
    ui->tbl_temario->insertRow(fila);
    ui->tbl_temario->setItem(fila, PREGUNTA, new QTableWidgetItem(p->pregunta()));
    ui->tbl_temario->setItem(fila, RESPUESTA, new QTableWidgetItem(p->respuesta()));
    m_listaPreguntas.append(new Preguntas(QString::number(m_listaPreguntas.size()+1),p->pregunta(),p->respuesta()));
}


void Temario::on_btnguardar_clicked()
{
    int filas = ui->tbl_temario->rowCount();
    if(filas== 0 ){
        QMessageBox::warning(this, "Guardar temario", "el temario no tiene suficientes preguntas");
        return;
    }
    QString carpetaarchivo= ui->lnltematica->text();

    if(carpetaarchivo.isEmpty()){
        QMessageBox::warning(this,"Guardar temario","Debe ingresar un nombre al temario");
        return;
    }
    QString archivobin=carpetaarchivo+".bin";
    QString folderpath = QCoreApplication::applicationDirPath();
    QString seleccionardireccion = folderpath + "/" + archivobin;
    QFile archivo(seleccionardireccion);
    if (archivo.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream salida(&archivo);
        for (int i=0; i<filas; i++) {
            QTableWidgetItem *pregunta = ui->tbl_temario->item(i, PREGUNTA);
            QTableWidgetItem *respuesta = ui->tbl_temario->item(i, RESPUESTA);

            salida << pregunta->text() << respuesta->text() << "\n";
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
            //Agregar a la tabla
            fila = ui->tbl_temario->rowCount();
            ui->tbl_temario->insertRow(fila);
            ui->tbl_temario->setItem(fila, PREGUNTA, new QTableWidgetItem(datos[PREGUNTA]));
            ui->tbl_temario->setItem(fila, RESPUESTA, new QTableWidgetItem(datos[RESPUESTA]));
            m_listaPreguntas.append(new Preguntas(QString::number(m_listaPreguntas.size()+1),datos[PREGUNTA],datos[RESPUESTA]));
        }
        archivo.close();
    }
}

QStack<Preguntas *> Temario::randomizarPreguntas()
{
    QList <Preguntas*> temp = m_listaPreguntas;
    QStack <Preguntas*> sacarPreguntas;
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

