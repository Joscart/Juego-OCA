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
    m_preguntas = m_config.temario();
    m_fichas = new SelectPlayer();

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
    //seleccionar jugadores
    ui->stackedWidget->setCurrentIndex(1);
    if (m_fichas != nullptr) {
        SelectPlayer *aux1 = new SelectPlayer();
        ui->verticalLayout_6->removeWidget(m_fichas);
        m_fichas->hide();
        ui->verticalLayout_6->insertWidget(0, aux1);
        delete m_fichas;
        m_fichas = aux1;
    } else {
        m_fichas = new SelectPlayer();
        ui->verticalLayout_6->replaceWidget(ui->wSelecion, m_fichas);
    }

    //Datos de prueba
    m_jugadores.append(new Jugador);
    m_jugadores.last()->setNombre("Jugador_1");
    m_jugadores.last()->setFichaImagen(QPixmap(":/Recursos/Imagenes/Ficha1.png"));
    m_jugadores.append(new Jugador);
    m_jugadores.last()->setNombre("Jugador_2");
    m_jugadores.last()->setFichaImagen(QPixmap(":/Recursos/Imagenes/Ficha2.png"));
    m_jugadores.append(new Jugador);
    m_jugadores.last()->setNombre("Jugador_3");
    m_jugadores.last()->setFichaImagen(QPixmap(":/Recursos/Imagenes/Ficha3.png"));
    m_jugadores.append(new Jugador);
    m_jugadores.last()->setNombre("Jugador_4");
    m_jugadores.last()->setFichaImagen(QPixmap(":/Recursos/Imagenes/Ficha4.png"));

    connect(m_fichas,&SelectPlayer::cancelarPressed,this,[this](){
        ui->stackedWidget->setCurrentIndex(0);
    });
    connect(m_fichas,&SelectPlayer::siguientePressed,this,[this](){
        ui->stackedWidget->setCurrentIndex(2);
        //Iniciar el widget del juego
        if (m_tablero != nullptr) {
            Tablero *aux = new Tablero();
            ui->horizontalLayout->removeWidget(m_tablero);
            m_tablero->hide();
            ui->horizontalLayout->insertWidget(0, aux);
            ui->verticalLayout->removeWidget(m_tablero->dado());
            m_tablero->dado()->hide();
            ui->verticalLayout->insertWidget(2, aux->dado());
            ui->verticalLayout->removeWidget(m_tablero->formulario());
            m_tablero->formulario()->hide();
            ui->verticalLayout->insertWidget(0, aux->formulario());
            delete m_tablero;
            m_tablero = aux;
            m_tablero->setObjectName("Tablero");
            m_tablero->formulario()->setObjectName("Formulario");
            m_tablero->dado()->setObjectName("Dado");
        } else {
            m_tablero = new Tablero();
            ui->horizontalLayout->removeWidget(ui->wTablero);
            ui->wTablero->hide();
            ui->horizontalLayout->insertWidget(0, m_tablero);
            ui->verticalLayout->removeWidget(ui->wDado);
            ui->wDado->hide();
            ui->verticalLayout->insertWidget(2, m_tablero->dado());
            ui->verticalLayout->removeWidget(ui->wPregunta);
            ui->wPregunta->hide();
            ui->verticalLayout->insertWidget(0, m_tablero->formulario());
            delete ui->wTablero;
            delete ui->wDado;
            delete ui->wPregunta;
            m_tablero->setObjectName("Tablero");
            m_tablero->formulario()->setObjectName("Formulario");
            m_tablero->dado()->setObjectName("Dado");
        }

        //ui->horizontalLayout->replaceWidget(ui->wTablero,m_tablero);
        setStyleSheet("QWidget#Tablero{"
                      "min-width: 880px;"
                      "min-height: 680px;"
                      "border-image: url(:/Recursos/Imagenes/Tablero2.png);"
                      "}"
                      "QWidget#Formulario{"
                      "min-width: 300px;"
                      "min-height: 340px;"
                      "}"
                      "QWidget#Dado{"
                      "min-width: 300px;"
                      "min-height: 340px;"
                      "}");
        foreach (Jugador *actual, m_jugadores) {
            m_tablero->addFicha(actual->ficha());
        }
        m_tablero->setPreguntas(m_preguntas->randomizarPreguntas());
    });
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


