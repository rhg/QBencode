#pragma once

#include <QObject>

#include "heapless-bencode/bencode.h"

class QBencode : public QObject
{
    Q_OBJECT
    bencode_t mBencode;
    Q_PROPERTY(QString from READ from WRITE setFrom NOTIFY fromChanged)
    Q_PROPERTY(Type type READ type)
public:
    enum Type {
        Int,
        String,
        List,
        Dict,
        Unknown
    };
    Q_ENUMS(Type)
    explicit QBencode(QObject *parent = nullptr);
    QString from();
    void setFrom(QString from);
    enum Type type();
signals:
    void fromChanged();
public slots:
};
