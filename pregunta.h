#pragma once

#include <QObject>

class Pregunta : public QObject
{
    Q_OBJECT

public:
    explicit Pregunta(QObject *parent = nullptr);
    Pregunta(const QString &indice, const QString &pregunta, const QString &respuesta);

    const QString &indice() const;
    const QString &pregunta() const;
    const QString &respuesta() const;

private:
    QString m_indice;
    QString m_pregunta;
    QString m_respuesta;
};
