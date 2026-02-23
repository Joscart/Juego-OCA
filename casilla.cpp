#include "casilla.h"
#include "ui_casilla.h"

Casilla::Casilla(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Casilla)
{
    ui->setupUi(this);
    m_lugarFichas = { ui->lbl1, ui->lbl2, ui->lbl3, ui->lbl4 };
    actualizarVistaFichas();
}

Casilla::~Casilla()
{
    delete ui;
}

void Casilla::aniadirFicha(Ficha *ficha)
{
    m_fichas.append(ficha);
    actualizarVistaFichas();
}

void Casilla::eliminarFicha(Ficha *ficha)
{
    m_fichas.removeOne(ficha);
    actualizarVistaFichas();
}

void Casilla::actualizarVistaFichas()
{
    for (int i = 0; i < m_lugarFichas.size(); ++i) {
        if (i < m_fichas.size()) {
            m_lugarFichas[i]->setPixmap(m_fichas[i]->imagen());
        } else {
            m_lugarFichas[i]->setPixmap(QPixmap());
        }
    }
}

void Casilla::setTipo(Tipo nuevoTipo)
{
    m_tipo = nuevoTipo;
}

Casilla::Tipo Casilla::getTipo() const
{
    return m_tipo;
}
