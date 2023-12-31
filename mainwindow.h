#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <tablero.h>
#include <jugador.h>
#include <temario.h>
#include <selectplayer.h>
#include <configuracion.h>
#include <acercade.h>
#include <QDesktopServices>
#include <QSound>
#include <QUrl>
#include <QTemporaryDir>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Configuracion &config();

private slots:
    void on_actionSalir_triggered();

    void on_actionNuevo_Juego_triggered();

    void on_btnEasterEgg_clicked();

    void on_actionConfiguracion_triggered();

    void on_actionPantalla_Completa_toggled(bool arg1);

    void on_actionInstrucciones_triggered();

    void on_actionAcerca_de_triggered();

private:
    Ui::MainWindow *ui;
    Tablero *m_tablero = nullptr;
    QList <Jugador*> m_jugadores;
    Configuracion m_config;
    Temario *m_preguntas;
    SelectPlayer *m_fichas = nullptr;
    void datatest();
};
#endif // MAINWINDOW_H
