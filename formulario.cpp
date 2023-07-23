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
    if(m_preguntas->size()<0 and m_preguntas->isEmpty()){
        m_actual = nullptr;
        return;
    }
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
    ui->stkPreguntar->setCurrentIndex(0);
    if(m_actual->pregunta().length()<30){
        ui->lblPregunta->setText(m_actual->pregunta());
    }else{
        QString aux = m_actual->pregunta();
        aux = aux.trimmed();
        QStringList palabras_pregunta = aux.split(" ");
        aux = "";
        for(int i=0;i<palabras_pregunta.size();i++){
            aux += palabras_pregunta[i] + " ";
            if((i+1)%2==0)
                aux += "\n";
        }
        ui->lblPregunta->setText(aux);
    }

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

void Formulario::correcto()
{
    ui->stkPreguntar->setCurrentIndex(2);
    ui->lblPreguntar->setPixmap(QPixmap(":/Recursos/Imagenes/OcaCorrecto.png"));
    delay(1000);
    ui->stkPreguntar->setCurrentIndex(1);
}

void Formulario::incorrecto()
{
    ui->stkPreguntar->setCurrentIndex(2);
    ui->lblPreguntar->setPixmap(QPixmap(":/Recursos/Imagenes/OcaIncorrecto2.png"));
    delay(1000);
    ui->stkPreguntar->setCurrentIndex(1);
}

void Formulario::delay(int mSecs)
{
    QTime dieTime= QTime::currentTime().addMSecs(mSecs);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void Formulario::setFichaActual(Ficha *newFichaActual)
{
    m_fichaActual = newFichaActual;
    ui->lblTurnoFicha->setText("Turno:\n" + m_fichaActual->NombreJugador());
    ui->lblImagenFicha->setPixmap(m_fichaActual->imagen());
    ui->stkPreguntar->setCurrentIndex(1);
}

void Formulario::setJugadores(QList<Ficha *> *newJugadores)
{
    m_jugadores = newJugadores;
}

void Formulario::actualizarJugadores()
{
    if(m_jugadores==nullptr)
        return;
    if(m_actual==nullptr)
        return;

    ui->stkPreguntar->setCurrentIndex(1);
}

