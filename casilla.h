#ifndef CASILLA_H
#define CASILLA_H
#include "ficha.h"
//#include "preguntas.h"
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
    void casillaAccion(int casilla);

private:
    Ui::Casilla *ui;
    QVector<Ficha*> m_Fichas;
    void mostrarFicha();
    Tipo tipo; //Almacena tipo de casilla
    QList <QWidget*> LugarFichas;
};

#endif // CASILLA_H
