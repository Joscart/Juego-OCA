#ifndef TABLERO_H
#define TABLERO_H

#include <QWidget>
#include <QLabel>
#include <QGraphicsDropShadowEffect>
#include <dado.h>
#include <formulario.h>
#include <casilla.h>
#include <ficha.h>

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

    void addFicha(Ficha *newFicha);

    void moverFicha(int pasos);

private slots:
    void iniciarAnimacion();

private:
    Ui::Tablero *ui;
    QList <Casilla*> m_casillas;
    QList <QLabel*> m_numeradores;
    QList <Ficha*> m_jugadores;
    Ficha *actual = nullptr;
    void cargarWidgets();

    void cambiarTurno();
    int m_turno;
    int m_contadorAnimacion=-1;
    Dado *m_dado;
    Formulario *m_formulario;
    QTimer *m_timer = new QTimer(this);
};

#endif // TABLERO_H
