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
    m_lbljugadores.append(ui->lblJugador_1);
    m_lbljugadores.append(ui->lblJugador_2);
    m_lbljugadores.append(ui->lblJugador_3);
    m_lbljugadores.append(ui->lblJugador_4);
    actualizarJugadores();
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

Pregunta *Formulario::actual() const
{
    return m_actual;
}

void Formulario::on_btnVerdadero_clicked()
{
    emit respuesta(true);
}


void Formulario::on_btnFalso_clicked()
{
    emit respuesta(false);
}

void Formulario::setFichaActual(Ficha *newFichaActual)
{
    m_fichaActual = newFichaActual;
}

void Formulario::setJugadores(QList<Ficha *> *newJugadores)
{
    m_jugadores = newJugadores;
}

void Formulario::actualizarJugadores()
{
//    for(int i=0;i<4;i++){
//        if(i<m_jugadores->size()){
//            m_lbljugadores[i]->setText(m_jugadores->at(i)->NombreJugador());
//        }else{
//            m_lbljugadores[i]->setText("");
//        }
//    }
}

