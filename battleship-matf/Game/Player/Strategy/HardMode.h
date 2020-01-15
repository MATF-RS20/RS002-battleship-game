#ifndef HARDMODE_H
#define HARDMODE_H

#include <QObject>

class HardMode : public QObject
{
    Q_OBJECT
public:
    explicit HardMode(QObject *parent = nullptr);

signals:

public slots:
};

#endif // HARDMODE_H