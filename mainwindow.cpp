#include "mainwindow.h"
#include "acercade.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //fondo azul areado
    setWindowState(Qt::WindowMaximized);
    //Por defult que inicie en una windows vacia
    ui->stackedWidget->setCurrentIndex(0);//widget vacio
    m_preguntas = m_config.temario();
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
    m_jugadores.clear();
    if (m_fichas != nullptr) {
        if(m_tablero != nullptr){
            ui->horizontalLayout->removeWidget(m_tablero);
            m_tablero->hide();
            ui->horizontalLayout->insertWidget(0, ui->wTablero);
            ui->verticalLayout->removeWidget(m_tablero->dado());
            m_tablero->dado()->hide();
            ui->verticalLayout->insertWidget(2, ui->wDado);
            ui->verticalLayout->removeWidget(m_tablero->formulario());
            m_tablero->formulario()->hide();
            ui->verticalLayout->insertWidget(0, ui->wPregunta);
            delete m_tablero;
            m_tablero = nullptr;
        }
        SelectPlayer *aux1 = new SelectPlayer();
        ui->verticalLayout_5->removeWidget(m_fichas);
        m_fichas->hide();
        ui->verticalLayout_5->insertWidget(0, aux1);
        delete m_fichas;
        m_fichas = aux1;
    } else {
        m_fichas = new SelectPlayer();
        ui->verticalLayout_5->replaceWidget(ui->wSelecion, m_fichas);
    }

    connect(m_fichas,&SelectPlayer::cancelarPressed,this,[this](){
        ui->stackedWidget->setCurrentIndex(0);
        ui->verticalLayout_5->removeWidget(m_fichas);
        m_fichas->hide();
        ui->verticalLayout_5->insertWidget(0, ui->wSelecion);
        delete m_fichas;
        m_fichas = nullptr;
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

            qDeleteAll(m_jugadores);
            m_jugadores.clear();

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
            m_tablero->setObjectName("Tablero");
            m_tablero->formulario()->setObjectName("Formulario");
            m_tablero->dado()->setObjectName("Dado");
        }

        //datatest
        //datatest();
        m_jugadores = m_fichas->jugadores();

        //ui->horizontalLayout->replaceWidget(ui->wTablero,m_tablero);
        foreach (Jugador *actual, m_jugadores) {
            m_tablero->addFicha(actual->ficha());
        }
        m_tablero->setPreguntas(m_preguntas->randomizarPreguntas());
    });
}


void MainWindow::on_btnEasterEgg_clicked()
{
    ui->lblEasterEgg->setText(tr("Disfruta el show :D"));
    QDesktopServices::openUrl(QUrl("https://www.youtube.com/watch?v=7YZCUpnaTfg&ab_channel=DontSubscribeToMe"));
}


void MainWindow::on_actionConfiguracion_triggered()
{
    m_config.temario()->cargarPreguntas();
    m_config.exec();
    ui->retranslateUi(this);
    this->update();

}

Configuracion &MainWindow::config()
{
    return m_config;
}

void MainWindow::datatest()
{
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
}

void MainWindow::on_actionPantalla_Completa_toggled(bool arg1)
{
    if(arg1){
        //maximizar ventana
        setWindowState(Qt::WindowFullScreen);
    }else{
        //maximizar ventana
        setWindowState(Qt::WindowNoState);
    }
}


void MainWindow::on_actionInstrucciones_triggered()
{

    QString filePath = QApplication::applicationDirPath() + "/Reglas_Juego_Oca.pdf";
    if(QFile::exists(filePath)) {
        // El archivo existe, trata de abrirlo
        QDesktopServices::openUrl(QUrl::fromLocalFile(filePath));
    } else {
        // El archivo no existe, haz algo aquí
    }
}


void MainWindow::on_actionAcerca_de_triggered()
{
    AcercaDe a;
    a.exec();
}

