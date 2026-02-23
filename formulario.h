#pragma once

#include <QWidget>
#include <QMovie>
#include <QLabel>

#include "pregunta.h"
#include "ficha.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Formulario; }
QT_END_NAMESPACE

class Formulario : public QWidget
{
    Q_OBJECT

public:
    explicit Formulario(QWidget *parent = nullptr);
    ~Formulario() override;

    void setPreguntas(QList<Pregunta *> *nuevasPreguntas);
    void usarPregunta();
    void mostrarPregunta();

    Pregunta *actual() const;

    void setJugadores(QList<Ficha *> *jugadores);
    void actualizarJugadores();

signals:
    void respuesta(bool esVerdadero);

public slots:
    void setFichaActual(Ficha *ficha);
    void correcto();
    void incorrecto();

private slots:
    void on_btnVerdadero_clicked();
    void on_btnFalso_clicked();

private:
    Ui::Formulario *ui;
    QList<Pregunta *> *m_preguntas = nullptr;
    Pregunta *m_actual = nullptr;
    QList<Ficha *> *m_jugadores = nullptr;
    Ficha *m_fichaActual = nullptr;

    void delay(int mSecs);
};
