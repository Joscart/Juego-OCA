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
    m_Fichas.append(newFicha);
}

void Casilla::eliminarFicha(Ficha *ficha)
{
    m_Fichas.removeOne(ficha);
}


void Casilla::mostrarFicha()
{
    if(m_Fichas.size()>4)
        return;


}

Casilla::Tipo Casilla::getTipo() const
{
    return tipo;
}

void Casilla::casillaAccion(int casilla)
{
if(casilla==0){
    //pregunta
}else if (casilla==1){

}else if(casilla==2){

}else if(casilla==3){

}else if(casilla==4){

}
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

