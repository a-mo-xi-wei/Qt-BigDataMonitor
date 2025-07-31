#ifndef DYNAMICALARM_H
#define DYNAMICALARM_H

#include "abstractcard.h"
#include <QPainter>
#include <QPainterPath>

class CLineSlider: public QWidget
{
    Q_OBJECT
    Q_PROPERTY(int value READ getValue WRITE setValue)
public:
    CLineSlider(QWidget *parent = nullptr): QWidget(parent)
    {
        m_value = 0;
        setAttribute(Qt::WA_TranslucentBackground);
    }

    // QWidget interface
    int getValue() const;
    void setValue(int value);

protected:
    void paintEvent(QPaintEvent *event)
    {
        QPainter painter(this);
        painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform | QPainter::TextAntialiasing); // 抗锯齿和使用平滑转换算法

        QPainterPath path;
        path.addRoundedRect(rect(), 3, 3);
        painter.setClipPath(path);

        painter.setPen(Qt::NoPen);
        painter.setBrush(QColor(255, 0, 0));
        QRect rcClient = rect();
        rcClient.setWidth(width() * ((double)m_value / 100.0));
        painter.drawRoundedRect(rcClient, 3, 3);
    }

private:
    int m_value;
};

class CDynamicAlarm : public CAbstractCard
{
    Q_OBJECT
public:
    explicit CDynamicAlarm(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // DYNAMICALARM_H
