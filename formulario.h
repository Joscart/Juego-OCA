#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QWidget>
#include <QMovie>
#include <pregunta.h>

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

private:
    Ui::Formulario *ui;
    QList<Pregunta*> *m_preguntas;
    Pregunta *m_actual = nullptr;
};

#endif // FORMULARIO_H
