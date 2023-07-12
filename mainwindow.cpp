#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "temario.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actiontemario_triggered()
{
    Temario t;
    t.exec();
}

