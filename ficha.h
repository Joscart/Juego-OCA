#ifndef FICHA_H
#define FICHA_H

#include <QObject>

class Ficha : public QObject
{
    Q_OBJECT
public:
    explicit Ficha(QObject *parent = nullptr);

signals:

};

#endif // FICHA_H
