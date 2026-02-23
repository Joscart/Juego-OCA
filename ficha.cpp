#include "ficha.h"

Ficha::Ficha(QObject *parent)
    : QObject(parent)
{
}

const QString &Ficha::nombreJugador() const
{
    return m_nombreJugador;
}

void Ficha::setNombreJugador(const QString &nombre)
{
    m_nombreJugador = nombre;
}

const QPixmap &Ficha::imagen() const
{
    return m_imagen;
}

void Ficha::setImagen(const QPixmap &nuevaImagen)
{
    m_imagen = nuevaImagen;
}

int Ficha::numCasillas() const
{
    return m_numCasillas;
}

void Ficha::setNumCasillas(int cantidad)
{
    m_numCasillas = cantidad;
}

