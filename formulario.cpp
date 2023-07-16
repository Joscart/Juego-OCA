#include "formulario.h"
#include "ui_formulario.h"

Formulario::Formulario(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Formulario)
{
    ui->setupUi(this);
    ui->lblGanso->setMovie(new QMovie(":/Recursos/Videos/XOsX.gif"));
    ui->lblGanso->movie()->setScaledSize(QSize(60,50));
    ui->lblGanso->movie()->start();
}

Formulario::~Formulario()
{
    delete ui;
}
