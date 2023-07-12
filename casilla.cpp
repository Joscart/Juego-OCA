#include "casilla.h"
#include "ui_casilla.h"

Casilla::Casilla(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Casilla)
{
    ui->setupUi(this);
}

Casilla::Casilla(Tipo tipo) //Constructor añadido
    : tipo(tipo) {
}

Casilla::~Casilla()
{
    delete ui;
}

void Casilla::aniadirFicha(Ficha *newFicha)
{
    Fichas.append(newFicha);
}

void Casilla::eliminarFicha(Ficha *ficha)
{
    Fichas.removeOne(ficha);
}


void Casilla::mostrarFicha()
{
    if(Fichas.size()>4)
        return;

    QString style = "QWidget#Casilla{border-image: url(:/Recursos/Imagenes/Casilla.jpeg);}\n";
    for (int i=0;i<Fichas.size();i++) {
        style += "QLabel#lbl"+QString::number(i+1)+"{border-image: url("+Fichas[i]->urlFicha()+");}\n";
    }
    setStyleSheet(style);
}

Casilla::Tipo Casilla::getTipo() const
{
    return tipo;
}

int Casilla::casillaEncontrada()
{
    switch (tipo) {
    case Tipo::Normal:
        return 0;
    case Tipo::Calavera:
        return 1;
    case Tipo::Oca:
        return 2;
    case Tipo::Puente:
        return 3;
    default:
        return -1;  // Podría ser útil tener un valor por defecto en caso de error.
    }
}
