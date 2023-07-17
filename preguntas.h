#ifndef PREGUNTAS_H
#define PREGUNTAS_H

#include <QObject>
class Preguntas: public QObject
{
public:
    explicit Preguntas(QObject *parent=nullptr);
    Preguntas(const QString indice, const QString pregunta, const QString respuesta);
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
