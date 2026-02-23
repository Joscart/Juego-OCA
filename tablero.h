#pragma once

#include <QWidget>
#include <QLabel>
#include <QGraphicsDropShadowEffect>
#include <QSoundEffect>
#include <QMessageBox>

#include "dado.h"
#include "formulario.h"
#include "casilla.h"
#include "ficha.h"
#include "pregunta.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Tablero; }
QT_END_NAMESPACE

class Tablero : public QWidget
{
    Q_OBJECT

public:
    explicit Tablero(QWidget *parent = nullptr);
    ~Tablero() override;

    Dado *dado() const;
    Formulario *formulario() const;

    void addFicha(Ficha *ficha);

    QList<Pregunta *> preguntas() const;
    void setPreguntas(const QList<Pregunta *> &nuevasPreguntas);

public slots:
    void moverFicha(int pasos);
    void procesarTirada(int resultado);
    void moverFichaA(int casillaDestino);

signals:
    void actualChanged(Ficha *actual);

private:
    Ui::Tablero *ui;

    QList<Casilla *> m_casillas;
    QList<QLabel *> m_numeradores;
    QList<Ficha *> m_jugadores;
    QList<Pregunta *> m_preguntas;
    QList<Pregunta *> m_preguntasBase;

    QSoundEffect m_music;
    Ficha *m_actual = nullptr;
    Dado *m_dado = nullptr;
    Formulario *m_formulario = nullptr;

    int m_turno = -1;

    static constexpr int kVelocidadAnimacion = 300;
    static constexpr int kCasillaFinal = 64;

    const QList<int> kCasillasOca = {
        1, 5, 9, 14, 18, 23, 27, 32, 36, 41, 45, 51, 54, 59, 63
    };
    const QList<int> kCasillasPuente = { 15, 30 };
    const QList<int> kCasillasCalavera = { 58 };

    void cargarWidgets();
    void cambiarTurno();
    void restaurarPreguntas();
    void delay(int mSecs);
};
