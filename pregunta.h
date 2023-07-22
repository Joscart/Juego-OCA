#ifndef PREGUNTAS_H
#define PREGUNTAS_H

#include <QObject>
class Pregunta: public QObject
{
public:
    explicit Pregunta(QObject *parent=nullptr);
    Pregunta(const QString indice, const QString pregunta, const QString respuesta);
    const QString &indice() const;
    const QString &pregunta() const;
    const QString &respuesta() const;
signals:

private:
    QString m_indice;
    QString m_pregunta;
    QString m_respuesta;
};

#endif // PREGUNTAS_H
