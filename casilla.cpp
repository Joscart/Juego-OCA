#include "casilla.h"
#include "ui_casilla.h"

Casilla::Casilla(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Casilla)
{
    ui->setupUi(this);
    LugarFichas.append(ui->lbl1);
    LugarFichas.append(ui->lbl2);
    LugarFichas.append(ui->lbl3);
    LugarFichas.append(ui->lbl4);
    mostrarFicha();
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
    mostrarFicha();
}

void Casilla::eliminarFicha(Ficha *ficha)
{
    for(int i=0;i<m_Fichas.size();i++){
        if(m_Fichas[i]==ficha){
            m_Fichas.removeOne(ficha);
        }
    }
    mostrarFicha();
}


void Casilla::mostrarFicha()
{
    for(int i=0;i<4;i++){
        if(i<m_Fichas.size()){
            LugarFichas[i]->setPixmap(m_Fichas[i]->imagen());
        }else{
            LugarFichas[i]->setPixmap(QPixmap());
        }
    }

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

