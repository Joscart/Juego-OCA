#include "ficha.h"

Ficha::Ficha(QObject *parent)
    : QObject{parent}
{

}

const QString &Ficha::urlFicha() const
{
    return m_urlFicha;
}

void Ficha::setUrlFicha(const QString &newUrlFicha)
{
    m_urlFicha = newUrlFicha;
}
