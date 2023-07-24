#ifndef INICIO_H
#define INICIO_H

#include <QWidget>

namespace Ui {
class Inicio;
}

class Inicio : public QWidget
{
    Q_OBJECT

public:
    explicit Inicio(QWidget *parent = nullptr);
    ~Inicio();

private:
    Ui::Inicio *ui;
};

#endif // INICIO_H
