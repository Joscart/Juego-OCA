#include "temario.h"
#include "ui_temario.h"
#include "QDebug"
Temario::Temario(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Temario)
{
    ui->setupUi(this);
    setWindowTitle("TEMARIO");
    ui->tbl_temario->setColumnCount(2);
    QStringList titulo;
    titulo <<"preguntas" <<"respuestas";
    ui->tbl_temario->setHorizontalHeaderLabels(titulo);
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
}


void Temario::on_btnguardar_clicked()
{
    int filas = ui->tbl_temario->rowCount();
    if(filas== 0){
        QMessageBox::warning(this, "Guardar temario", "el temario no tiene suficientes preguntas");
        return;
    }
    QFile archivo(ARCHIVO);
    if (archivo.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream salida(&archivo);
        for (int i=0; i<filas; i++) {
            QTableWidgetItem *pregunta = ui->tbl_temario->item(i, PREGUNTA);
            QTableWidgetItem *respuesta = ui->tbl_temario->item(i, RESPUESTA);
            salida << pregunta->text() << ";" << respuesta->text() << "\n";
        }
        archivo.close();
        QMessageBox::information(this,"Guardar temario","temario guardado");
    }else{
        QMessageBox::critical(this,"Guardar temario", "No se puede escribir sobre " + ARCHIVO);
    }
}
void Temario::cargarPreguntas()
{
    // Verificar si el archivo existe
    QFile archivo(ARCHIVO);
    if (!archivo.exists())
        return;

    // cargar datos
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
        }
        archivo.close();
    }
}

