#ifndef JUGADOR_H
#define JUGADOR_H

#include <QObject>
#include <ficha.h>

class Jugador : public QObject
{
    Q_OBJECT
public:
    explicit Jugador(QObject *parent = nullptr);

    void setFichaImagen(QPixmap imagen);

    const QString &nombre() const;
    void setNombre(const QString &newNombre);

    Ficha *ficha() const;
    void setFicha(Ficha *newFicha);

    int puntaje() const;
    void setPuntaje(int newPuntaje);

    int numJugador() const;
    void setNumJugador(int newNumJugador);

signals:

private:
    QString m_nombre;
    Ficha *m_ficha;
    int m_puntaje;
    int m_numJugador;
};

#endif // JUGADOR_H
