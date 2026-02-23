#pragma once

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Inicio; }
QT_END_NAMESPACE

class Inicio : public QWidget
{
    Q_OBJECT

public:
    explicit Inicio(QWidget *parent = nullptr);
    ~Inicio() override;

private:
    Ui::Inicio *ui;
};
