#ifndef CASILLA_H
#define CASILLA_H
#include "ficha.h"
#include <QWidget>

namespace Ui {
class Casilla;
}

class Casilla : public QWidget
{
    Q_OBJECT

public:
    explicit Casilla(QWidget *parent = nullptr);
    ~Casilla();
    void aniadirFicha(Ficha *newFicha);
    void eliminarFicha(Ficha *ficha);
    int casillaEncontrada();

    enum class Tipo {
        Normal,
        Calavera,
        Oca,
        Puente
    };

    Casilla(Tipo tipo);//Constructor de casilla
    // Esta es una función miembro constante llamada 'getTipo' que no toma argumentos.
    // Devuelve el valor del miembro de datos 'tipo'. Como es constante, no puede modificar ningún miembro de datos de la clase.
    Tipo getTipo() const;

private:
    Ui::Casilla *ui;
    QVector<Ficha*> Fichas;
    void mostrarFicha();
    Tipo tipo; //Almacena tipo de casilla

};

#endif // CASILLA_H
