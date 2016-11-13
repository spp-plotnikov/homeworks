#pragma once

#include <QObject>


class NetworkEntity : public QObject
{
    Q_OBJECT
public:
    explicit NetworkEntity(QObject *parent = 0);

signals:

public slots:
};
