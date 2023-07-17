#ifndef CONFIGURACION_H
#define CONFIGURACION_H

#include <QDialog>

namespace Ui {
class Configuracion;
}

class Configuracion : public QDialog
{
    Q_OBJECT

public:
    explicit Configuracion(QWidget *parent = nullptr);
    ~Configuracion();

private slots:

    void on_btnOpcion_1_clicked();

    void on_btnOpcion_2_clicked();

private:
    Ui::Configuracion *ui;
};

#endif // CONFIGURACION_H
