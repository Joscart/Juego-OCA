#include "pregunta.h"

Pregunta::Pregunta(QObject *parent): QObject{parent}
{

}

Pregunta::Pregunta(const QString indice,const QString pregunta, const QString respuesta):
    m_indice(indice),
    m_pregunta(pregunta),
    m_respuesta(respuesta)

{

}
const QString &Pregunta::indice() const{
    return m_indice;
}
const QString &Pregunta::pregunta() const
{
    return m_pregunta;
}

const QString &Pregunta::respuesta() const
{
    return m_respuesta;
}
