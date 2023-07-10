#ifndef FICHA_H
#define FICHA_H

#include <QObject>

class Ficha : public QObject
{
    Q_OBJECT
public:
    explicit Ficha(QObject *parent = nullptr);

    const QString &urlFicha() const;
    void setUrlFicha(const QString &newUrlFicha);

signals:

private:
    QString m_urlFicha;
};

#endif // FICHA_H
