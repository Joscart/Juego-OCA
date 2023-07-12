#ifndef TEMARIO_H
#define TEMARIO_H

#include <QDialog>
#include <QFile>
#include <QMessageBox>

#include "preguntas.h"
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

private:
    Ui::Temario *ui;
    const QString ARCHIVO = "temario.cvs";
    enum columna{
        PREGUNTA, RESPUESTA
    };
    void cargarPreguntas();
};

#endif // TEMARIO_H
