#ifndef TABLERO_H
#define TABLERO_H

#include <QWidget>
#include <QLabel>
#include <QGraphicsDropShadowEffect>
#include <QSoundEffect>
#include <dado.h>
#include <formulario.h>
#include <casilla.h>
#include <ficha.h>
#include <pregunta.h>

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

    QList<Pregunta *> preguntas();
    void setPreguntas(QList<Pregunta *> newPreguntas);

public slots:
    void moverFicha(int pasos);
    void moverFicha(QString pasosText);
    void moverFichaA(int casillaDestino);

signals:
    void actualChanged(Ficha *actual);

private:
    Ui::Tablero *ui;
    QList <Casilla*> m_casillas;
    QList <QLabel*> m_numeradores;
    QList <Ficha*> m_jugadores;
    QList <Pregunta*> m_preguntas;
    QList <Pregunta*> m_preguntasBase;
    Ficha *actual = nullptr;
    void cargarWidgets();
    void cambiarTurno();
    void restaurarPreguntas();
    int m_turno = -1;
    int m_speed = 300;
    Dado *m_dado;
    Formulario *m_formulario;
    QSoundEffect m_soundTap;
    void delay(int mSecs);
    QList <int> m_casillasOca = {
        1,5,9,14,18,23,27,32,36,41,45,51,54,59,63
    };
    QList <int> m_casillasPuente = {
        15,30
    };
    QList <int> m_casillasCalabera = {
        58
    };
    int m_casillaFinal = 64;

};

#endif // TABLERO_H
