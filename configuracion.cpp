#include "configuracion.h"
#include "ui_configuracion.h"

Configuracion::Configuracion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Configuracion)
{
    ui->setupUi(this);
}

Configuracion::~Configuracion()
{
    delete ui;
}

void Configuracion::on_btnOpcion_1_clicked()
{
    ui->stkConfig->setCurrentIndex(0);
}


void Configuracion::on_btnOpcion_2_clicked()
{
    ui->stkConfig->setCurrentIndex(1);
}

