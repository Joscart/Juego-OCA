#include "dado.h"
#include "ui_dado.h"

Dado::Dado(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Dado)
{
    ui->setupUi(this);
    //set imagenes
    for(int i=0;i<6;i++){
        imagenes[i] = QPixmap(":/Recursos/Imagenes/Dice"+QString::number(i+1)+".png");
    }
    //set timer
    QTimer *timer = new QTimer(this);
    connect(ui->btnDado,&QPushButton::clicked,[timer, this](){
        contadorAnimacion = -1;
        timer->start(200);
    });
    ui->btnDado->setIcon(QPixmap(":/Recursos/Imagenes/Dice1.png"));
    ui->btnDado->setIconSize(QSize(250,250));
    //conect timer
    connect(timer,&QTimer::timeout,[timer,this](){
        if(++contadorAnimacion<6){
            ui->btnDado->setIcon(imagenes[contadorAnimacion]);
        }else{
            timer->stop();
            contadorAnimacion = QRandomGenerator::global()->bounded(1,7)-1;
            ui->btnDado->setIcon(imagenes[contadorAnimacion]);
        }
    });
}

Dado::~Dado()
{
    delete ui;
}

int Dado::resultado() const
{
    return contadorAnimacion+1;
}

