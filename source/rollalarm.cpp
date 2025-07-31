#include "rollalarm.h"
#include <QPainter>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>
#include <QDebug>
#include <QTimer>
#include <QDateTime>


#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif


CRollAlarm::CRollAlarm(QWidget *parent) : CAbstractCard(parent)
{
    setTitle("滚动报警");

    QVBoxLayout *layoutMain = new QVBoxLayout(getMainWnd());
    layoutMain->setMargin(20);
    layoutMain->setSpacing(20);

    {
        CRollWidget *slider = new CRollWidget(this);
        layoutMain->addWidget(slider);

        QTimer *timer = new QTimer(this);
        connect(timer, &QTimer::timeout, [=]
        {
            qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

            QStringList strListName;
            strListName << "安徽" << "上海" << "重庆" << "北京" << "怀宁" << "无为" <<
                           "芜湖" << "安吉" << "浙江" << "宁波" << "合肥" << "湖州" << "延吉" << "四川";

            QStringList strListMsg;
            strListMsg << "人员闯入" << "车辆抓拍" << "数据库异常" << "网络出现故障" << "系统硬盘故障" << "温度异常" << "人员闯入" << "车辆抓拍" << "数据库异常";

            QDateTime currentDateTime = QDateTime::currentDateTime();
            QString formattedDateTime = currentDateTime.toString("yyyy年M月d日 hh:mm:ss");
            slider->append(strListName.at(qrand() % strListName.length()), "机房", strListMsg.at(qrand() % strListMsg.length()), formattedDateTime);
        });
        timer->start(1000);
    }
}

void CRollWidget::append(QString addr1, QString addr2, QString code, QString time)
{
    m_value.append({addr1, addr2, code, time});
    m_value = m_value.mid(m_value.size() - 20);

    QPropertyAnimation *animation1 = new QPropertyAnimation(this, "value");
    animation1->setDuration(500);
    animation1->setStartValue(0);
    animation1->setEndValue(100);
    //animation1->setEasingCurve(QEasingCurve::OutBack);
    animation1->start(QPropertyAnimation::DeleteWhenStopped);
}

void CRollWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform | QPainter::TextAntialiasing); // 抗锯齿和使用平滑转换算法

    QRect rcClient = rect();
    const int LINE_HEIGHT = 32;
    int nRow = rcClient.height() / LINE_HEIGHT;

    painter.setPen(QColor(255,255,255, 150));

    QRect rcRealClient = rcClient;
    if (m_value.length() > nRow)
    {
        rcRealClient = rcClient;
        rcRealClient.setTop(rcRealClient.top() - (LINE_HEIGHT * ((double)value / 100.0)));
    }

    int i = 0;
    foreach (auto item, m_value.mid(m_value.size() - nRow - 1))
    {
        QRect rcText = rcRealClient;
        rcText.setTop(rcText.top() + i * LINE_HEIGHT);
        rcText.setHeight(LINE_HEIGHT);

        QString strText = QString("%1  %2 - %3 - %4").arg(item.time).arg(item.addr1).arg(item.addr2).arg(item.code);

        QFontMetrics elideFont(painter.font());
        int nTextWidth = elideFont.width(strText);
        if (nTextWidth > rcText.width())
        {
            painter.drawText(rcText, Qt::AlignLeft | Qt::AlignVCenter, elideFont.elidedText(strText, Qt::ElideRight,rcText.width()));
        }
        else
        {
            painter.drawText(rcText, Qt::AlignLeft | Qt::AlignVCenter, strText);
        }

        i++;
    }
}

int CRollWidget::getValue() const
{
    return value;
}

void CRollWidget::setValue(int _value)
{
    value = _value;
    update();
}
