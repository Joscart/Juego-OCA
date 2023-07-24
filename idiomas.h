#ifndef IDIOMAS_H
#define IDIOMAS_H

#include <QDialog>

namespace Ui {
class Idiomas;
}

class Idiomas : public QDialog
{
    Q_OBJECT

public:
    explicit Idiomas(QDialog *parent = nullptr);
    ~Idiomas();
    Idiomas& idiomas();
    void retranslateUi();
signals:
    void idiomaCambiado(QString idioma);
     void cerrarConfiguracion();

private slots:
    void on_bttnAceptar_clicked();

private:
    Ui::Idiomas *ui;

};

#endif // IDIOMAS_H
