#include "preguntasdialog.h"
#include "ui_preguntasdialog.h"

preguntasdialog::preguntasdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::preguntasdialog)
{
    ui->setupUi(this);
}

preguntasdialog::~preguntasdialog()
{
    delete ui;
}

void preguntasdialog::on_buttonBox_accepted()
{
    QString respuesta;
    QString indice;
    /*for(int i=0;i<20;i++){

    }*/

    QString pregunta = ui->lnlpregunta->text();
    if(pregunta.isEmpty()){
        QMessageBox::warning(this,tr("ingresar pregunta"), tr("campo de pregunta vacio"));
            return;
    }

    if(ui->verdaderoButton->isChecked()){
        respuesta="verdadero";
    }else if(ui->falsobutton->isChecked()){
        respuesta="falso";
    }
    this->m_preguntas = new Pregunta(indice,pregunta,respuesta);
    accept();
}


void preguntasdialog::on_buttonBox_rejected()
{
    reject();
}
Pregunta *preguntasdialog::preguntas() const
{
    return m_preguntas;
}

QString preguntasdialog::getRespuesta() const
{
    QString respuesta;
    if(ui->verdaderoButton->isChecked()){
        respuesta= "verdadero";
    }else if(ui->falsobutton->isChecked()){
        respuesta= "falso";
    }
    return respuesta;
}

void preguntasdialog::setRespuesta(const QString &newRespuesta)
{
    if(newRespuesta.isEmpty())
        return;
    int index= ui->falsobutton->isChecked();
    if(index != -1){
        ui->falsobutton->setChecked(index);
    }
}

QString preguntasdialog::getPregunta() const
{
    return ui->lnlpregunta->text();
}

void preguntasdialog::setPregunta(const QString &newPregunta)
{
    ui->lnlpregunta->setText(newPregunta);
}

