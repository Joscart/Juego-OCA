#ifndef DICE_H
#define DICE_H

#include <QLabel>
#include <QVector>
#include <QPixmap>

class Dice : public QLabel {
    Q_OBJECT

public:
    explicit Dice(QWidget* parent = nullptr);

    int roll();

protected:
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    QVector<QPixmap> m_dicePixmaps;
signals:
    void closingWithData(int myData);  // Reemplaza "int" con el tipo de datos que quieras transmitir

protected:
    void closeEvent(QCloseEvent *event) override {
        emit closingWithData(myData);  // Reemplaza "myData" con los datos que quieras transmitir
        QLabel::closeEvent(event);
    }

private:
    int myData;
};

#endif // DICE_H
