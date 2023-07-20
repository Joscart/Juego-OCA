#include "formulario.h"
#include "ui_formulario.h"

Formulario::Formulario(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Formulario)
{
    ui->setupUi(this);
    ui->lblGanso->setMovie(new QMovie(":/Recursos/Videos/XOsX.gif"));
    ui->lblGanso->movie()->setScaledSize(QSize(60,50));
    ui->lblGanso->movie()->start();
}

Formulario::~Formulario()
{
    delete ui;
}

void Formulario::setPreguntas(QList<Pregunta *> *newPreguntas)
{
    m_preguntas = newPreguntas;
    m_actual = m_preguntas->back();
}

void Formulario::usarPregunta()
{
    if(m_preguntas->size()<0)
        return;
    if(m_preguntas->size()==1){
        m_actual = nullptr;
        m_preguntas->pop_back();
        return;
    }
    m_preguntas->pop_back();
    m_actual = m_preguntas->back();
}

void Formulario::mostrarPregunta()
{
    if(m_actual==nullptr)
        return;
    ui->lblPregunta->setText(m_actual->pregunta());
}
