#include "tablero.h"
#include "ui_tablero.h"

Tablero::Tablero(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tablero)
{
    ui->setupUi(this);
}

Tablero::~Tablero()
{
    delete ui;
}
