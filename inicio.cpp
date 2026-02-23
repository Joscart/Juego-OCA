#include "inicio.h"
#include "ui_inicio.h"

Inicio::Inicio(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Inicio)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

Inicio::~Inicio()
{
    delete ui;
}
