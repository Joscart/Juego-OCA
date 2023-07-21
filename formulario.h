#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QWidget>
#include <QMovie>
#include <QLabel>
#include <pregunta.h>
#include <ficha.h>

namespace Ui {
class Formulario;
}

class Formulario : public QWidget
{
    Q_OBJECT

public:
    explicit Formulario(QWidget *parent = nullptr);
    ~Formulario();

    void setPreguntas(QList<Pregunta *> *newPreguntas);

    void usarPregunta();

    void mostrarPregunta();

    Pregunta *actual() const;

    void setJugadores(QList<Ficha *> *newJugadores);

    void actualizarJugadores();

signals:

    void respuesta(bool);

public slots:
    void setFichaActual(Ficha *newFichaActual);

private slots:
    void on_btnVerdadero_clicked();

    void on_btnFalso_clicked();

private:
    Ui::Formulario *ui;
    QList<Pregunta*> *m_preguntas;
    Pregunta *m_actual = nullptr;
    QList <Ficha*> *m_jugadores;
    QList <QLabel*> m_lbljugadores;
    Ficha *m_fichaActual;
};

#endif // FORMULARIO_H
