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
    if(!ui->rbtnJugador_1->isChecked() and
        !ui->rbtnJugador_2->isChecked() and
        !ui->rbtnJugador_3->isChecked() and
        !ui->rbtnJugador_4->isChecked()){
        QMessageBox::warning(this, tr("Nuevo Juego"), tr("Necesita seleccionar almenos 1 ficha"));
        return;
    }
    emit siguientePressed();
}


void SelectPlayer::on_btnCancelar_clicked()
{
    emit cancelarPressed();
}

QList<Jugador *> &SelectPlayer::jugadores()
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
        Jugador *aux = new Jugador();
        aux->setNombre(tr("Jugador_4"));
        aux->setFichaImagen(m_imagenesFicha[3]);
        setJugadores(aux);
        QSound::play(":/Recursos/Audio/SoundPregunta2.wav");
    }else{
        foreach(Jugador *actual,m_jugadores){
            if(actual->nombre()==tr("Jugador_4")){
                delJugadores(actual);
                QSound::play(":/Recursos/Audio/SoundAlerta.wav");
            }
        }
    }
}


void SelectPlayer::on_rbtnJugador_3_toggled(bool checked)
{
    if(checked){
        Jugador *aux = new Jugador();
        aux->setNombre(tr("Jugador_3"));
        aux->setFichaImagen(m_imagenesFicha[2]);
        setJugadores(aux);
        QSound::play(":/Recursos/Audio/SoundPregunta2.wav");
    }else{
        foreach(Jugador *actual,m_jugadores){
            if(actual->nombre()==tr("Jugador_3")){
                delJugadores(actual);
                QSound::play(":/Recursos/Audio/SoundAlerta.wav");
            }
        }
    }
}


void SelectPlayer::on_rbtnJugador_2_toggled(bool checked)
{
    if(checked){
        Jugador *aux = new Jugador();
        aux->setNombre(tr("Jugador_2"));
        aux->setFichaImagen(m_imagenesFicha[1]);
        setJugadores(aux);
        QSound::play(":/Recursos/Audio/SoundPregunta2.wav");
    }else{
        foreach(Jugador *actual,m_jugadores){
            if(actual->nombre()==tr("Jugador_2")){
                delJugadores(actual);
                QSound::play(":/Recursos/Audio/SoundAlerta.wav");
            }
        }
    }
}


void SelectPlayer::on_rbtnJugador_1_toggled(bool checked)
{
    if(checked){
        Jugador *aux = new Jugador();
        aux->setNombre(tr("Jugador_1"));
        aux->setFichaImagen(m_imagenesFicha[0]);
        setJugadores(aux);
        QSound::play(":/Recursos/Audio/SoundPregunta2.wav");
    }else{
        foreach(Jugador *actual,m_jugadores){
            if(actual->nombre()==tr("Jugador_1")){
                delJugadores(actual);
                QSound::play(":/Recursos/Audio/SoundAlerta.wav");
            }
        }
    }
}

