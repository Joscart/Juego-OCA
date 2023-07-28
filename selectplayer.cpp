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
    m_lblImagenesFicha.append(ui->rbtnJugador_1);
    m_lblImagenesFicha.append(ui->rbtnJugador_2);
    m_lblImagenesFicha.append(ui->rbtnJugador_3);
    m_lblImagenesFicha.append(ui->rbtnJugador_4);
    //set imagenes
    for(int i=0;i<4;i++){
        QIcon ButtonIcon(m_imagenesFicha[i]);
           m_lblImagenesFicha[i]->setIcon(ButtonIcon);
           m_lblImagenesFicha[i]->setIconSize(QSize(250, 250)); // Ajusta el tamaño según sea necesario
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
    if(ui->lineEditJugador_1->text().isEmpty() &&
        ui->lineEditJugador_2->text().isEmpty() &&
        ui->lineEditJugador_3->text().isEmpty() &&
        ui->lineEditJugador_4->text().isEmpty()){

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




void SelectPlayer::on_rbtnJugador_1_clicked()
{
    ui->lineEditJugador_1->setFocus();
}


void SelectPlayer::on_rbtnJugador_2_clicked()
{
    ui->lineEditJugador_2->setFocus();
}


void SelectPlayer::on_rbtnJugador_3_clicked()
{
    ui->lineEditJugador_3->setFocus();
}


void SelectPlayer::on_rbtnJugador_4_clicked()
{
    ui->lineEditJugador_4->setFocus();
}


void SelectPlayer::on_lineEditJugador_1_textChanged(const QString &arg1)
{
    if(!arg1.isEmpty()){
        foreach(Jugador *actual,m_jugadores){
            if(actual->numJugador()==1){
                delJugadores(actual);

            }
        }
        Jugador *aux = new Jugador();
        aux->setNombre(arg1);
        aux->setFichaImagen(m_imagenesFicha[0]);
        aux->setNumJugador(1);
        setJugadores(aux);
        QSound::play(":/Recursos/Audio/SoundPregunta2.wav");
    }else{
        foreach(Jugador *actual,m_jugadores){
            if(actual->numJugador()==1){
                delJugadores(actual);
                QSound::play(":/Recursos/Audio/SoundAlerta.wav");
            }
        }
    }
}


void SelectPlayer::on_lineEditJugador_2_textChanged(const QString &arg1)
{
    if(!arg1.isEmpty()){
        foreach(Jugador *actual,m_jugadores){
            if(actual->numJugador()==2){
                delJugadores(actual);

            }
        }
        Jugador *aux = new Jugador();
        aux->setNombre(arg1);
        aux->setFichaImagen(m_imagenesFicha[1]);
        aux->setNumJugador(2);
        setJugadores(aux);
        QSound::play(":/Recursos/Audio/SoundPregunta2.wav");
    }else{
        foreach(Jugador *actual,m_jugadores){
            if(actual->numJugador()==2){
                delJugadores(actual);
                QSound::play(":/Recursos/Audio/SoundAlerta.wav");
            }
        }
    }
}


void SelectPlayer::on_lineEditJugador_3_textChanged(const QString &arg1)
{
    if(!arg1.isEmpty()){
        foreach(Jugador *actual,m_jugadores){
            if(actual->numJugador()==3){
                delJugadores(actual);

            }
        }
        Jugador *aux = new Jugador();
        aux->setNombre(arg1);
        aux->setFichaImagen(m_imagenesFicha[2]);
        aux->setNumJugador(3);
        setJugadores(aux);
        QSound::play(":/Recursos/Audio/SoundPregunta2.wav");
    }else{
        foreach(Jugador *actual,m_jugadores){
            if(actual->numJugador()==3){
                delJugadores(actual);
                QSound::play(":/Recursos/Audio/SoundAlerta.wav");
            }
        }
    }
}


void SelectPlayer::on_lineEditJugador_4_textChanged(const QString &arg1)
{
    if(!arg1.isEmpty()){
        foreach(Jugador *actual,m_jugadores){
            if(actual->numJugador()==4){
                delJugadores(actual);

            }
        }
        Jugador *aux = new Jugador();
        aux->setNombre(arg1);
        aux->setFichaImagen(m_imagenesFicha[3]);
        aux->setNumJugador(4);
        setJugadores(aux);
        QSound::play(":/Recursos/Audio/SoundPregunta2.wav");
    }else{
        foreach(Jugador *actual,m_jugadores){
            if(actual->numJugador()==4){
                delJugadores(actual);
                QSound::play(":/Recursos/Audio/SoundAlerta.wav");
            }
        }
    }
}

