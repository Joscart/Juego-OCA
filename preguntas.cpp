#include "preguntas.h"

Preguntas::Preguntas(QObject *parent): QObject{parent}
{

}

Preguntas::Preguntas(const QString indice,const QString pregunta, const QString respuesta):
    m_indice(indice),
    m_pregunta(pregunta),
    m_respuesta(respuesta)

{

}
const QString &Preguntas::indice() const{
    return m_indice;
}
const QString &Preguntas::pregunta() const
{
    return m_pregunta;
}

const QString &Preguntas::respuesta() const
{
    return m_respuesta;
}
