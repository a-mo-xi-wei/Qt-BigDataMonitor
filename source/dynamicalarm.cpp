#include "dynamicalarm.h"
#include <QPainter>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>
#include <QDebug>


#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

CDynamicAlarm::CDynamicAlarm(QWidget *parent) : CAbstractCard(parent)
{
    setTitle("红外报警");

    QVBoxLayout *layoutMain = new QVBoxLayout(getMainWnd());
    layoutMain->setMargin(20);
    layoutMain->setSpacing(20);

    {
        CLineSlider *slider = new CLineSlider(this);
        slider->setFixedHeight(8);
        layoutMain->addWidget(slider);

        {
            QPropertyAnimation *animation1 = new QPropertyAnimation(slider, "value");
            animation1->setDuration(1000);
            animation1->setStartValue(0);
            animation1->setEndValue(100);
            animation1->setEasingCurve(QEasingCurve::OutQuad);

            QPropertyAnimation *animation2 = new QPropertyAnimation(slider, "value");
            animation2->setDuration(2000);
            animation2->setStartValue(100);
            animation2->setEndValue(0);
            animation2->setEasingCurve(QEasingCurve::InCubic);

            // 创建动画组并添加动画对象
            QSequentialAnimationGroup *group = new QSequentialAnimationGroup();
            group->addAnimation(animation1);
            group->addAnimation(animation2);
            group->setLoopCount(-1);

            // 启动动画组
            group->start();
        }
    }

    {
        QLabel *label1 = new QLabel("当前报警设置数量:", this);
        QLabel *label2 = new QLabel("123", this);
        QLabel *label3 = new QLabel("新增设备:", this);
        QLabel *label4 = new QLabel("556", this);

        label1->setStyleSheet("QLabel{color:#637c9f; font-size:12px;}");
        label2->setStyleSheet("QLabel{color:#ff0000; font-size:12px;}");
        label3->setStyleSheet("QLabel{color:#637c9f; font-size:12px;}");
        label4->setStyleSheet("QLabel{color:#efeb7b; font-size:12px;}");

        QHBoxLayout *layoutRow = new QHBoxLayout();
        layoutRow->addWidget(label1);
        layoutRow->addWidget(label2);
        layoutRow->addStretch(1);
        layoutRow->addWidget(label3);
        layoutRow->addWidget(label4);
        layoutRow->setSpacing(6);

        layoutMain->addLayout(layoutRow);
    }
}

int CLineSlider::getValue() const
{
    return m_value;
}

void CLineSlider::setValue(int value)
{
    m_value = value;
    update();
}
