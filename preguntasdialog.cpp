#include "preguntasdialog.h"
#include "ui_preguntasdialog.h"
#include <QDialog>
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
    QString pregunta = ui->lnlpregunta->text();
    QString respuesta = ui->lnlrespuesta->text();
    this->m_preguntas = new Preguntas(pregunta,respuesta);
    accept();
}


void preguntasdialog::on_buttonBox_rejected()
{
    reject();
}
Preguntas *preguntasdialog::preguntas() const
{
    return m_preguntas;
}

