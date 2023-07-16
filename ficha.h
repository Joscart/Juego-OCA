#ifndef FICHA_H
#define FICHA_H

#include <QObject>
#include <QPixmap>

class Ficha : public QObject
{
    Q_OBJECT
public:
    explicit Ficha(QObject *parent = nullptr);

    const QString &NombreJugador() const;
    void setNombreJugador(const QString &newNombreJugador);

    const QPixmap &imagen() const;
    void setImagen(const QPixmap &newImagen);

signals:

private:
    QString m_NombreJugador;
    QPixmap m_imagen;
};

#endif // FICHA_H
