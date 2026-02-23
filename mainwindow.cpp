#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDesktopServices>
#include <QFile>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowState(Qt::WindowMaximized);
    ui->stackedWidget->setCurrentIndex(0);
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
    ui->stackedWidget->setCurrentIndex(1);
    m_jugadores.clear();

    if (m_fichas != nullptr) {
        if (m_tablero != nullptr) {
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

        auto *nuevoSelector = new SelectPlayer();
        ui->verticalLayout_5->removeWidget(m_fichas);
        m_fichas->hide();
        ui->verticalLayout_5->insertWidget(0, nuevoSelector);
        delete m_fichas;
        m_fichas = nuevoSelector;
    } else {
        m_fichas = new SelectPlayer();
        ui->verticalLayout_5->replaceWidget(ui->wSelecion, m_fichas);
    }

    connect(m_fichas, &SelectPlayer::cancelarPressed, this, [this]() {
        ui->stackedWidget->setCurrentIndex(0);
        ui->verticalLayout_5->removeWidget(m_fichas);
        m_fichas->hide();
        ui->verticalLayout_5->insertWidget(0, ui->wSelecion);
        delete m_fichas;
        m_fichas = nullptr;
    });

    connect(m_fichas, &SelectPlayer::siguientePressed, this, [this]() {
        ui->stackedWidget->setCurrentIndex(2);

        if (m_tablero != nullptr) {
            auto *nuevoTablero = new Tablero();
            ui->horizontalLayout->removeWidget(m_tablero);
            m_tablero->hide();
            ui->horizontalLayout->insertWidget(0, nuevoTablero);
            ui->verticalLayout->removeWidget(m_tablero->dado());
            m_tablero->dado()->hide();
            ui->verticalLayout->insertWidget(2, nuevoTablero->dado());
            ui->verticalLayout->removeWidget(m_tablero->formulario());
            m_tablero->formulario()->hide();
            ui->verticalLayout->insertWidget(0, nuevoTablero->formulario());
            delete m_tablero;
            m_tablero = nuevoTablero;
            m_tablero->setObjectName(QStringLiteral("Tablero"));
            m_tablero->formulario()->setObjectName(QStringLiteral("Formulario"));
            m_tablero->dado()->setObjectName(QStringLiteral("Dado"));

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
            m_tablero->setObjectName(QStringLiteral("Tablero"));
            m_tablero->formulario()->setObjectName(QStringLiteral("Formulario"));
            m_tablero->dado()->setObjectName(QStringLiteral("Dado"));
        }

        m_jugadores = m_fichas->jugadores();

        for (Jugador *jugador : m_jugadores) {
            m_tablero->addFicha(jugador->ficha());
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

void MainWindow::crearDatosDePrueba()
{
    const QStringList nombres = {
        QStringLiteral("Jugador_1"), QStringLiteral("Jugador_2"),
        QStringLiteral("Jugador_3"), QStringLiteral("Jugador_4")
    };
    for (int i = 0; i < nombres.size(); ++i) {
        auto *jugador = new Jugador(this);
        jugador->setNombre(nombres[i]);
        jugador->setFichaImagen(
            QPixmap(QStringLiteral(":/Recursos/Imagenes/Ficha%1.png").arg(i + 1)));
        m_jugadores.append(jugador);
    }
}

void MainWindow::on_actionPantalla_Completa_toggled(bool checked)
{
    setWindowState(checked ? Qt::WindowFullScreen : Qt::WindowNoState);
}

void MainWindow::on_actionInstrucciones_triggered()
{
    const QString filePath = QApplication::applicationDirPath() + "/Reglas_Juego_Oca.pdf";
    if (QFile::exists(filePath)) {
        QDesktopServices::openUrl(QUrl::fromLocalFile(filePath));
    }
}

void MainWindow::on_actionAcerca_de_triggered()
{
    AcercaDe dialog;
    dialog.exec();
}

