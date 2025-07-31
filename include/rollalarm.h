#ifndef ROLLALARM_H
#define ROLLALARM_H

#include "abstractcard.h"

#include <QPainter>

class CRollWidget: public QWidget
{
    Q_OBJECT
    Q_PROPERTY(int value READ getValue WRITE setValue)
public:
    CRollWidget(QWidget *parent = nullptr): QWidget(parent)
    {
        setAttribute(Qt::WA_TranslucentBackground);
    }

    struct Item
    {
        QString addr1;
        QString addr2;
        QString code;
        QString time;
    };

    void append(QString addr1, QString addr2, QString code, QString time);

    int getValue() const;
    void setValue(int value);

protected:
    void paintEvent(QPaintEvent *event);

private:
    QList<Item> m_value;
    int value;
};

class CRollAlarm : public CAbstractCard
{
    Q_OBJECT
public:
    explicit CRollAlarm(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // ROLLALARM_H
