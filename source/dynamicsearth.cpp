#include "dynamicsearth.h"
#include <QPainter>



CDynamicsEarth::CDynamicsEarth(QWidget *parent) : QWidget(parent)
{
    angle = 0;
    startTimer(40);
}

void CDynamicsEarth::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform | QPainter::TextAntialiasing); // 抗锯齿和使用平滑转换算法

    if (!m_pixBg.isNull())
    {
        painter.drawPixmap((width() - m_pixBg.width()) >> 1, (height() - m_pixBg.height()) >> 1, m_pixBg);
    }

    if (!m_pixMask2.isNull())
    {
        painter.save();
        painter.translate(rect().center());
        painter.setOpacity(0.3);
        painter.rotate(-angle);
        painter.drawPixmap(-m_pixMask2.width() >> 1, -m_pixMask2.height() >> 1, m_pixMask2);
        painter.restore();
    }

    if (!m_pixMask1.isNull())
    {
        painter.save();
        painter.translate(rect().center());
        painter.rotate(angle);
        painter.drawPixmap(-m_pixMask1.width() >> 1, -m_pixMask1.height() >> 1, m_pixMask1);
        painter.restore();
    }
}

void CDynamicsEarth::timerEvent(QTimerEvent *event)
{
    angle = (++angle % 360);
    update();
}

void CDynamicsEarth::resizeEvent(QResizeEvent *event)
{
    m_pixBg = QPixmap(":/image/res/map.png").scaledToWidth(244, Qt::SmoothTransformation);
    m_pixMask1 = QPixmap(":/image/res/lbx.png").scaledToWidth(300, Qt::SmoothTransformation);
    m_pixMask2 = QPixmap(":/image/res/jt.png").scaledToWidth(281, Qt::SmoothTransformation);
}

int CDynamicsEarth::getAngle() const
{
    return angle;
}

void CDynamicsEarth::setAngle(int value)
{
    angle = value;
}
