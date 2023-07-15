#ifndef TABLERO_H
#define TABLERO_H

#include <QWidget>
#include <QLabel>
#include <QGraphicsDropShadowEffect>
#include <dado.h>
#include <formulario.h>
#include <casilla.h>

namespace Ui {
class Tablero;
}

class Tablero : public QWidget
{
    Q_OBJECT

public:
    explicit Tablero(QWidget *parent = nullptr);
    ~Tablero();

    Dado *dado() const;

    Formulario *formulario() const;

private:
    Ui::Tablero *ui;
    QList <QWidget*> m_casillas;
    QList <QLabel*> m_numeradores;
    void cargarWidgets();
    Dado *m_dado;
    Formulario *m_formulario;
};

#endif // TABLERO_H
