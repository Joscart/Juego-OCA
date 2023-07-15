#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QWidget>

namespace Ui {
class Formulario;
}

class Formulario : public QWidget
{
    Q_OBJECT

public:
    explicit Formulario(QWidget *parent = nullptr);
    ~Formulario();

private:
    Ui::Formulario *ui;
};

#endif // FORMULARIO_H
