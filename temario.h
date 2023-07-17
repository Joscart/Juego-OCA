#ifndef TEMARIO_H
#define TEMARIO_H

#include <QDialog>
#include <QFile>
#include <QMessageBox>
#include <ctime>
#include <QFile>

#include "pregunta.h"
#include "preguntasdialog.h"

namespace Ui {class Temario;}

class Temario : public QDialog
{
    Q_OBJECT

public:
    explicit Temario(QWidget *parent = nullptr);
    ~Temario();

private slots:

    void on_btnagregar_clicked();

    void on_btnguardar_clicked();

    void on_btneditar_clicked();

    void on_btneliminar_clicked();

private:
    Ui::Temario *ui;
    const QString ARCHIVO = "temario.cvs";
    enum columna{
        PREGUNTA, RESPUESTA
    };
    QList <Pregunta*> m_listaPreguntas;
    void cargarPreguntas();
    QStack<Pregunta*> randomizarPreguntas();
    int mseleccion = -1;
};

#endif // TEMARIO_H