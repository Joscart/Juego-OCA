#pragma once

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class AcercaDe; }
QT_END_NAMESPACE

class AcercaDe : public QDialog
{
    Q_OBJECT

public:
    explicit AcercaDe(QWidget *parent = nullptr);
    ~AcercaDe() override;

private:
    Ui::AcercaDe *ui;
};
