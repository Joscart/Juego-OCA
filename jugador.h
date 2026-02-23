#pragma once

#include <QObject>
#include "ficha.h"

class Jugador : public QObject
{
    Q_OBJECT

public:
    explicit Jugador(QObject *parent = nullptr);

    void setFichaImagen(const QPixmap &imagen);

    const QString &nombre() const;
    void setNombre(const QString &nuevoNombre);

    Ficha *ficha() const;

    int puntaje() const;
    void setPuntaje(int nuevoPuntaje);

    int numJugador() const;
    void setNumJugador(int nuevoNum);

private:
    QString m_nombre;
    Ficha *m_ficha = nullptr;
    int m_puntaje = 0;
    int m_numJugador = 0;
};
