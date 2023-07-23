#include "selectplayer.h"
#include "ui_selectplayer.h"

SelectPlayer::SelectPlayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SelectPlayer)
{
    ui->setupUi(this);
    //set imagenes
    m_imagenesFicha.append(QPixmap(":/Recursos/Imagenes/Ficha1.png"));
    m_imagenesFicha.append(QPixmap(":/Recursos/Imagenes/Ficha2.png"));
    m_imagenesFicha.append(QPixmap(":/Recursos/Imagenes/Ficha3.png"));
    m_imagenesFicha.append(QPixmap(":/Recursos/Imagenes/Ficha4.png"));
    //set lbl
    m_lblImagenesFicha.append(ui->lblImagenFicha_1);
    m_lblImagenesFicha.append(ui->lblImagenFicha_2);
    m_lblImagenesFicha.append(ui->lblImagenFicha_3);
    m_lblImagenesFicha.append(ui->lblImagenFicha_4);
    //set imagenes
    for(int i=0;i<4;i++){
        m_lblImagenesFicha[i]->setPixmap(m_imagenesFicha[i]);
    }
    connect(ui->btnCancelar,&QPushButton::clicked,this,&SelectPlayer::on_btnCancelar_clicked);
    connect(ui->btnSiguiente,&QPushButton::clicked,this,&SelectPlayer::on_btnSiguiente_clicked);
}

SelectPlayer::~SelectPlayer()
{
    delete ui;
}

void SelectPlayer::on_btnSiguiente_clicked()
{
    emit siguientePressed();
}


void SelectPlayer::on_btnCancelar_clicked()
{
    emit cancelarPressed();
}

QList<Jugador *> SelectPlayer::jugadores()
{
    return m_jugadores;
}

void SelectPlayer::setJugadores(Jugador *newJugadores)
{
    if(m_jugadores.size()>=4)
        m_jugadores.removeFirst();
    m_jugadores.append(newJugadores);
}

void SelectPlayer::delJugadores(Jugador *jugador)
{
    for(int i=0;i<m_jugadores.size();i++){
        if(m_jugadores[i]==jugador){
            m_jugadores.removeOne(jugador);
        }
    }
}


void SelectPlayer::on_rbtnJugador_4_toggled(bool checked)
{
    if(checked){
        setJugadores(new Jugador);
        m_jugadores.last()->setNombre(tr("Jugador_")+QString::number(m_jugadores.size()));
        m_jugadores.last()->setFichaImagen(m_imagenesFicha[3]);
    }else{

    }
}

