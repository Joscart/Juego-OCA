#include "jugador.h"

Jugador::Jugador(QObject *parent)
    : QObject{parent}
{
    m_ficha = new Ficha();
}

void Jugador::setFichaImagen(QPixmap imagen)
{
    m_ficha->setImagen(imagen);
}

const QString &Jugador::nombre() const
{
    return m_nombre;
}

void Jugador::setNombre(const QString &newNombre)
{
    m_nombre = newNombre;
    m_ficha->setNombreJugador(newNombre);
}

Ficha *Jugador::ficha() const
{
    return m_ficha;
}

void Jugador::setFicha(Ficha *newFicha)
{
    m_ficha = newFicha;
}

int Jugador::puntaje() const
{
    return m_puntaje;
}

void Jugador::setPuntaje(int newPuntaje)
{
    m_puntaje = newPuntaje;
}
