#ifndef JUGADOR_H
#define JUGADOR_H

#include <QObject>
#include <ficha.h>

class Jugador : public QObject
{
    Q_OBJECT
public:
    explicit Jugador(QObject *parent = nullptr);

signals:

private:
    Ficha m_ficha;
};

#endif // JUGADOR_H
