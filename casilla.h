#ifndef CASILLA_H
#define CASILLA_H

class Casilla
{
private:
    int valor;
    int x;
    int y;
public:
    Casilla();
    Casilla(const int &valor, int x, int y);

    int getValor() const;
    void setValor(const int &newValor);
    int getX() const;
    void setX(int newX);
    int getY() const;
    void setY(int newY);
};

#endif // CASILLA_H
