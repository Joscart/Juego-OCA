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

