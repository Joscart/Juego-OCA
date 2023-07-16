#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <tablero.h>
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

private:
    Ui::MainWindow *ui;
    Tablero *m_tablero;
};
#endif // MAINWINDOW_H
