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

    int numCasillas() const;
    void setNumCasillas(int newNumCasillas);

signals:

private:
    QString m_NombreJugador;
    QPixmap m_imagen;
    int m_numCasillas = 0;
};

#endif // FICHA_H
