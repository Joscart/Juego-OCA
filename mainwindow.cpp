#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //fondo azul areado
    //Por defult que inicie en una windows vacia
    ui->stackedWidget->setCurrentIndex(0);//widget vacio
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionSalir_triggered()
{
    close();
}


void MainWindow::on_actionNuevo_Juego_triggered()
{
    //Iniciar el widget del juego
    m_tablero = new Tablero();
    ui->stackedWidget->setCurrentIndex(2);
    ui->horizontalLayout->replaceWidget(ui->Tablero,m_tablero);
    ui->verticalLayout->replaceWidget(ui->Dado,m_tablero->dado());
    ui->verticalLayout->replaceWidget(ui->Pregunta,m_tablero->formulario());
    setStyleSheet("QWidget#Tablero{"
                  "min-width: 880px;"
                  "min-height: 680px;"
                  "border-image: url(:/Recursos/Imagenes/Tablero2.png);"
                  "}"
                  "QWidget#Pregunta{"
                  "min-width: 300px;"
                  "min-height: 340px;"
                  "}"
                  "QWidget#Dado{"
                  "min-width: 300px;"
                  "min-height: 340px;"
                  "}");
    //Datos Prueba
    m_jugadores.append(new Jugador());
    m_jugadores.append(new Jugador());
    m_jugadores.append(new Jugador());
    m_jugadores[0]->setFichaImagen(QPixmap(":/Recursos/Imagenes/Ficha1.png"));
    m_jugadores[1]->setFichaImagen(QPixmap(":/Recursos/Imagenes/Ficha2.png"));
    m_jugadores[2]->setFichaImagen(QPixmap(":/Recursos/Imagenes/Ficha3.png"));
    m_tablero->addFicha(m_jugadores[0]->ficha());
    m_tablero->addFicha(m_jugadores[1]->ficha());
    m_tablero->addFicha(m_jugadores[2]->ficha());
    m_tablero->moverFicha(5);
    m_tablero->moverFicha(-1);
    m_tablero->moverFicha(6);
}


void MainWindow::on_btnEasterEgg_clicked()
{
    ui->lblEasterEgg->setText("Disfruta el show :D");
    QDesktopServices::openUrl(QUrl("https://www.youtube.com/watch?v=7YZCUpnaTfg&ab_channel=DontSubscribeToMe"));
}


void MainWindow::on_actionConfiguracion_triggered()
{
    m_config.exec();
}

