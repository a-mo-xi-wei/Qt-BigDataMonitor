#include "circulardialsummary.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSequentialAnimationGroup>
#include "circulardial.h"


#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

CCirculardialSummary::CCirculardialSummary(QWidget *parent) : CAbstractCard(parent)
{
    setTitle("状态汇总");

    QHBoxLayout *layoutMain = new QHBoxLayout(getMainWnd());
    layoutMain->setMargin(6);
    layoutMain->setSpacing(10);

    {
        QLabel *label1 = new QLabel("温度", this);
        label1->setAlignment(Qt::AlignCenter);
        label1->setFixedHeight(16);

        label1->setStyleSheet("QLabel{color:rgba(255, 255, 255, 100); font-size:12px;}");

        CircularDial *dial = new CircularDial(this);
        dial->setNLow(60);
        dial->setNHigh(120);
        dial->setNMax(180);
        dial->setStrFormat("℃");

        QVBoxLayout *layoutRow = new QVBoxLayout();
        layoutRow->addWidget(dial, 1);
        layoutRow->addWidget(label1);
        layoutRow->setContentsMargins(0, 0, 0, 0);
        layoutRow->setSpacing(0);

        layoutMain->addLayout(layoutRow);

        {
            QPropertyAnimation *animation1 = new QPropertyAnimation(dial, "DialValue");
            animation1->setDuration(3000);
            animation1->setStartValue(0);
            animation1->setEndValue(180);
            animation1->setEasingCurve(QEasingCurve::OutQuad);

            QPropertyAnimation *animation2 = new QPropertyAnimation(dial, "DialValue");
            animation2->setDuration(5000);
            animation2->setStartValue(180);
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
        QLabel *label1 = new QLabel("湿度", this);
        label1->setAlignment(Qt::AlignCenter);
        label1->setFixedHeight(16);

        label1->setStyleSheet("QLabel{color:rgba(255, 255, 255, 100); font-size:12px;}");

        CircularDial *dial = new CircularDial(this);
        dial->setNLow(40);
        dial->setNHigh(80);
        dial->setNMax(100);
        dial->setStrFormat("%");

        QVBoxLayout *layoutRow = new QVBoxLayout();
        layoutRow->addWidget(dial, 1);
        layoutRow->addWidget(label1);
        layoutRow->setContentsMargins(0, 0, 0, 0);
        layoutRow->setSpacing(0);

        layoutMain->addLayout(layoutRow);

        {
            QPropertyAnimation *animation1 = new QPropertyAnimation(dial, "DialValue");
            animation1->setDuration(3500);
            animation1->setStartValue(0);
            animation1->setEndValue(100);
            animation1->setEasingCurve(QEasingCurve::OutQuad);

            QPropertyAnimation *animation2 = new QPropertyAnimation(dial, "DialValue");
            animation2->setDuration(6000);
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
        QLabel *label1 = new QLabel("CPU", this);
        label1->setAlignment(Qt::AlignCenter);
        label1->setFixedHeight(16);

        label1->setStyleSheet("QLabel{color:rgba(255, 255, 255, 100); font-size:12px;}");

        CircularDial *dial = new CircularDial(this);
        dial->setNLow(20);
        dial->setNHigh(60);
        dial->setNMax(100);
        dial->setStrFormat("%");

        QVBoxLayout *layoutRow = new QVBoxLayout();
        layoutRow->addWidget(dial, 1);
        layoutRow->addWidget(label1);
        layoutRow->setContentsMargins(0, 0, 0, 0);
        layoutRow->setSpacing(0);

        layoutMain->addLayout(layoutRow);

        {
            QPropertyAnimation *animation1 = new QPropertyAnimation(dial, "DialValue");
            animation1->setDuration(2000);
            animation1->setStartValue(0);
            animation1->setEndValue(100);
            animation1->setEasingCurve(QEasingCurve::OutQuad);

            QPropertyAnimation *animation2 = new QPropertyAnimation(dial, "DialValue");
            animation2->setDuration(5000);
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
        QLabel *label1 = new QLabel("内存", this);
        label1->setAlignment(Qt::AlignCenter);
        label1->setFixedHeight(16);

        label1->setStyleSheet("QLabel{color:rgba(255, 255, 255, 100); font-size:12px;}");

        CircularDial *dial = new CircularDial(this);
        dial->setNLow(60);
        dial->setNHigh(90);
        dial->setNMax(100);
        dial->setStrFormat("%");

        QVBoxLayout *layoutRow = new QVBoxLayout();
        layoutRow->addWidget(dial, 1);
        layoutRow->addWidget(label1);
        layoutRow->setContentsMargins(0, 0, 0, 0);
        layoutRow->setSpacing(0);

        layoutMain->addLayout(layoutRow);

        {
            QPropertyAnimation *animation1 = new QPropertyAnimation(dial, "DialValue");
            animation1->setDuration(4000);
            animation1->setStartValue(0);
            animation1->setEndValue(100);
            animation1->setEasingCurve(QEasingCurve::OutQuad);

            QPropertyAnimation *animation2 = new QPropertyAnimation(dial, "DialValue");
            animation2->setDuration(6000);
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
}
