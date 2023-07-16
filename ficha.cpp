#include "ficha.h"

Ficha::Ficha(QObject *parent)
    : QObject{parent}
{

}

const QString &Ficha::NombreJugador() const
{
    return m_NombreJugador;
}

void Ficha::setNombreJugador(const QString &newNombreJugador)
{
    m_NombreJugador = newNombreJugador;
}

const QPixmap &Ficha::imagen() const
{
    return m_imagen;
}

void Ficha::setImagen(const QPixmap &newImagen)
{
    m_imagen = newImagen;
}
