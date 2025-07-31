#include "title.h"
#include <QPainter>
#include <QDateTime>


#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif


CTitle::CTitle(QWidget *parent) : QWidget(parent)
{
    setAttribute(Qt::WA_StyledBackground);
    setStyleSheet("background-image: url(:/image/res/head_bg.png); background-repeat: no-repeat; background-position: center; background-attachment: fixed;");

     startTimer(1000);
}

void CTitle::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform | QPainter::TextAntialiasing); // 抗锯齿和使用平滑转换算法

    painter.setPen(QColor(255, 255, 255));
    QFont font = this->font();
    font.setPixelSize(42);
    painter.setFont(font);
    painter.drawText(rect(), Qt::AlignCenter, "大数据监控平台v1.0");

    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString formattedDateTime = currentDateTime.toString("yyyy年M月d日 hh:mm:ss");
    painter.setPen(QColor(255, 255, 255, 140));
    font.setPixelSize(18);
    painter.setFont(font);
    painter.drawText(rect().marginsRemoved(QMargins(10, 10, 10, 10)), Qt::AlignVCenter | Qt::AlignRight, formattedDateTime);
}

void CTitle::timerEvent(QTimerEvent *)
{
    update();
}
