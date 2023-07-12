#include "preguntas.h"

Preguntas::Preguntas(QObject *parent): QObject{parent}
{

}

Preguntas::Preguntas(const QString &pregunta, const QString &respuesta):
    m_pregunta(pregunta),
    m_respuesta(respuesta)

{

}

const QString &Preguntas::pregunta() const
{
    return m_pregunta;
}

const QString &Preguntas::respuesta() const
{
    return m_respuesta;
}
