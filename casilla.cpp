#include "casilla.h"

int Casilla::getValor() const
{
    return valor;
}

void Casilla::setValor(const int &newValor)
{
    valor = newValor;
}

int Casilla::getX() const
{
    return x;
}

void Casilla::setX(int newX)
{
    x = newX;
}

int Casilla::getY() const
{
    return y;
}

void Casilla::setY(int newY)
{
    y = newY;
}

Casilla::Casilla() {



}

Casilla::Casilla(const int &valor, int x, int y) : valor(valor),
    x(x),
    y(y)
{}
