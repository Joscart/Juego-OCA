#ifndef TEMARIO_H
#define TEMARIO_H

#include <QDialog>
#include <QFile>
#include <QMessageBox>
#include <ctime>
#include "QDebug"
#include <QStack>
#include <QTableWidget>
#include "QFileDialog"
#include <QStandardPaths>
#include "pregunta.h"
#include "preguntasdialog.h"

namespace Ui {class Temario;}

class Temario : public QDialog
{
    Q_OBJECT

public:
    explicit Temario(QWidget *parent = nullptr);
    ~Temario();

    QList<Pregunta *> randomizarPreguntas();

    void cargarPreguntas();
    void retranslateUi();
private slots:

    void on_btnagregar_clicked();

    void on_btnguardar_clicked();

    void on_btneditar_clicked();

    void on_btneliminar_clicked();

    void on_btnexportar_clicked();

    void on_btnimportar_clicked();

private:
    Ui::Temario *ui;
    QString ruta = QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation);
    const QString ARCHIVO = ruta + "/temario.bin";
    enum columna{
        PREGUNTA, RESPUESTA
    };
    QList <Pregunta*> m_listaPreguntas;
    void mostrarPreguntas(const QString &rArchivo);
    int mseleccion = -1;
};

#endif // TEMARIO_H
