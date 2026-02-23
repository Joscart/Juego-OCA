#include "formulario.h"
#include "ui_formulario.h"

#include <QElapsedTimer>

Formulario::Formulario(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Formulario)
{
    ui->setupUi(this);
    ui->lblGanso->setMovie(new QMovie(QStringLiteral(":/Recursos/Videos/XOsX.gif")));
    ui->lblGanso->movie()->setScaledSize(QSize(100, 100));
    ui->lblGanso->movie()->start();
    actualizarJugadores();
}

Formulario::~Formulario()
{
    delete ui;
}

void Formulario::setPreguntas(QList<Pregunta *> *nuevasPreguntas)
{
    m_preguntas = nuevasPreguntas;
    m_actual = m_preguntas->back();
}

void Formulario::usarPregunta()
{
    if (m_preguntas == nullptr || m_preguntas->isEmpty()) {
        m_actual = nullptr;
        return;
    }
    if (m_preguntas->size() == 1) {
        m_actual = nullptr;
        m_preguntas->pop_back();
        return;
    }
    m_preguntas->pop_back();
    m_actual = m_preguntas->back();
}

void Formulario::mostrarPregunta()
{
    if (m_actual == nullptr) {
        return;
    }
    ui->stkPreguntar->setCurrentIndex(0);
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

void Formulario::correcto()
{
    ui->stkPreguntar->setCurrentIndex(2);
    ui->lblPreguntar->setPixmap(QPixmap(QStringLiteral(":/Recursos/Imagenes/OcaCorrecto.png")));
    delay(1000);
    ui->stkPreguntar->setCurrentIndex(1);
}

void Formulario::incorrecto()
{
    ui->stkPreguntar->setCurrentIndex(2);
    ui->lblPreguntar->setPixmap(QPixmap(QStringLiteral(":/Recursos/Imagenes/OcaIncorrecto2.png")));
    delay(1000);
    ui->stkPreguntar->setCurrentIndex(1);
}

void Formulario::delay(int mSecs)
{
    QElapsedTimer timer;
    timer.start();
    while (timer.elapsed() < mSecs) {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}

void Formulario::setFichaActual(Ficha *ficha)
{
    m_fichaActual = ficha;
    ui->lblTurnoFicha->setText(tr("Turno:\n") + m_fichaActual->nombreJugador());
    ui->lblImagenFicha->setPixmap(m_fichaActual->imagen());
    ui->stkPreguntar->setCurrentIndex(1);
}

void Formulario::setJugadores(QList<Ficha *> *jugadores)
{
    m_jugadores = jugadores;
}

void Formulario::actualizarJugadores()
{
    if (m_jugadores == nullptr || m_actual == nullptr) {
        return;
    }
    ui->stkPreguntar->setCurrentIndex(1);
}
