#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->horizontalLayout->replaceWidget(ui->Tablero,new Tablero());
}

MainWindow::~MainWindow()
{
    delete ui;
}
