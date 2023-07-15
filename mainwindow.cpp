#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    m_tablero = new Tablero();
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
    ui->horizontalLayout->replaceWidget(ui->Tablero,m_tablero);
    ui->verticalLayout->replaceWidget(ui->Dado,m_tablero->dado());
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
}

