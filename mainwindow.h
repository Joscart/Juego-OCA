#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <tablero.h>
#include <jugador.h>
#include <configuracion.h>
#include <QDesktopServices>
#include <QUrl>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionSalir_triggered();

    void on_actionNuevo_Juego_triggered();

    void on_btnEasterEgg_clicked();

    void on_actionConfiguracion_triggered();

private:
    Ui::MainWindow *ui;
    Tablero *m_tablero;
    QList <Jugador*> m_jugadores;
    Configuracion m_config;
};
#endif // MAINWINDOW_H
