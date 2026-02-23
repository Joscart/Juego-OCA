#pragma once

#include <QObject>
#include <QPixmap>

class Ficha : public QObject
{
    Q_OBJECT

public:
    explicit Ficha(QObject *parent = nullptr);

    const QString &nombreJugador() const;
    void setNombreJugador(const QString &nombre);

    const QPixmap &imagen() const;
    void setImagen(const QPixmap &nuevaImagen);

    int numCasillas() const;
    void setNumCasillas(int cantidad);

private:
    QString m_nombreJugador;
    QPixmap m_imagen;
    int m_numCasillas = 0;
};
