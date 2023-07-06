#ifndef PREGUNTA_H
#define PREGUNTA_H

#include <QObject>

class Pregunta : public QObject
{
    Q_OBJECT
public:
    explicit Pregunta(QObject *parent = nullptr);

signals:

};

#endif // PREGUNTA_H
