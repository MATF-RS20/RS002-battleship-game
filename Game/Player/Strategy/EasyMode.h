#ifndef EASYMODE_H
#define EASYMODE_H

#include <QObject>

class EasyMode : public QObject
{
    Q_OBJECT
public:
    explicit EasyMode(QObject *parent = nullptr);

signals:

public slots:
};

#endif // EASYMODE_H