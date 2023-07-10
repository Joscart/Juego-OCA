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
    void añadirFicha(Ficha *newFicha);
    void eliminarFicha(Ficha *ficha);

private:
    Ui::Casilla *ui;
    QVector<Ficha*> Fichas;
    void mostrarFicha();
};

#endif // CASILLA_H
