#ifndef ACERCADE_H
#define ACERCADE_H

#include <QDialog>

namespace Ui {
class AcercaDe;
}

class AcercaDe : public QDialog
{
    Q_OBJECT

public:
    explicit AcercaDe(QWidget *parent = nullptr);
    ~AcercaDe();

private:
    Ui::AcercaDe *ui;
};

#endif // ACERCADE_H
