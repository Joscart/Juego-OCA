#include "jugador.h"

Jugador::Jugador(QObject *parent)
    : QObject(parent)
{
    m_ficha = new Ficha(this);
}

void Jugador::setFichaImagen(const QPixmap &imagen)
{
    m_ficha->setImagen(imagen);
}

const QString &Jugador::nombre() const
{
    return m_nombre;
}

void Jugador::setNombre(const QString &nuevoNombre)
{
    m_nombre = nuevoNombre;
    m_ficha->setNombreJugador(nuevoNombre);
}

Ficha *Jugador::ficha() const
{
    return m_ficha;
}

int Jugador::puntaje() const
{
    return m_puntaje;
}

void Jugador::setPuntaje(int nuevoPuntaje)
{
    m_puntaje = nuevoPuntaje;
}

int Jugador::numJugador() const
{
    return m_numJugador;
}

void Jugador::setNumJugador(int nuevoNum)
{
    m_numJugador = nuevoNum;
}
