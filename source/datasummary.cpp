#include "datasummary.h"
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTimer>
#include <QRandomGenerator>

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

CDataSummary::CDataSummary(QWidget *parent) : CAbstractCard(parent)
{
    setTitle("报警汇总");

    QTimer *timer = new QTimer(this);

    QVBoxLayout *layoutMain = new QVBoxLayout(getMainWnd());
    layoutMain->setContentsMargins(10, 0, 10, 0);
    layoutMain->setSpacing(0);

    {
        QLabel *label1 = new QLabel("6786", this);
        QLabel *label2 = new QLabel("465", this);
        QLabel *label3 = new QLabel("34532", this);

        label1->setAlignment(Qt::AlignCenter);
        label2->setAlignment(Qt::AlignCenter);
        label3->setAlignment(Qt::AlignCenter);

        label1->setStyleSheet("QLabel{color:#efeb7b; font-size:24px; font-weight: bold;}");
        label2->setStyleSheet("QLabel{color:#efeb7b; font-size:24px; font-weight: bold;}");
        label3->setStyleSheet("QLabel{color:#efeb7b; font-size:24px; font-weight: bold;}");

        QHBoxLayout *layoutRow = new QHBoxLayout();
        layoutRow->addWidget(label1);
        layoutRow->addWidget(CreateSeparator(true, this));
        layoutRow->addWidget(label2);
        layoutRow->addWidget(CreateSeparator(true, this));
        layoutRow->addWidget(label3);
        layoutRow->setContentsMargins(0, 0, 0, 0);

        layoutMain->addLayout(layoutRow);

        connect(timer, &QTimer::timeout, [=]
        {
            label1->setText(QString::number(QRandomGenerator::global()->bounded(8000)));
            label2->setText(QString::number(QRandomGenerator::global()->bounded(500)));
            label3->setText(QString::number(QRandomGenerator::global()->bounded(40000)));
        });
    }

    {
        QLabel *label1 = new QLabel("设备接入数", this);
        QLabel *label2 = new QLabel("设备报警点数", this);
        QLabel *label3 = new QLabel("设备联网点数", this);

        label1->setAlignment(Qt::AlignCenter);
        label2->setAlignment(Qt::AlignCenter);
        label3->setAlignment(Qt::AlignCenter);

        label1->setStyleSheet("QLabel{color:#637c9f; font-size:12px;}");
        label2->setStyleSheet("QLabel{color:#637c9f; font-size:12px;}");
        label3->setStyleSheet("QLabel{color:#637c9f; font-size:12px;}");

        QHBoxLayout *layoutRow = new QHBoxLayout();
        layoutRow->addWidget(label1);
        layoutRow->addWidget(label2);
        layoutRow->addWidget(label3);

        layoutMain->addLayout(layoutRow);
    }

    layoutMain->addWidget(CreateSeparator(false, this));

    {
        QLabel *label1 = new QLabel("123", this);
        QLabel *label2 = new QLabel("3457", this);
        QLabel *label3 = new QLabel("233", this);

        label1->setAlignment(Qt::AlignCenter);
        label2->setAlignment(Qt::AlignCenter);
        label3->setAlignment(Qt::AlignCenter);

        label1->setStyleSheet("QLabel{color:#ff0000; font-size:24px; font-weight: bold;}");
        label2->setStyleSheet("QLabel{color:#efeb7b; font-size:24px; font-weight: bold;}");
        label3->setStyleSheet("QLabel{color:#efeb7b; font-size:24px; font-weight: bold;}");

        QHBoxLayout *layoutRow = new QHBoxLayout();
        layoutRow->addWidget(label1);
        layoutRow->addWidget(CreateSeparator(true, this));
        layoutRow->addWidget(label2);
        layoutRow->addWidget(CreateSeparator(true, this));
        layoutRow->addWidget(label3);
        layoutRow->setContentsMargins(0, 0, 0, 0);

        layoutMain->addLayout(layoutRow);

        connect(timer, &QTimer::timeout, [=]
        {
            label1->setText(QString::number(QRandomGenerator::global()->bounded(150)));
            label2->setText(QString::number(QRandomGenerator::global()->bounded(5000)));
            label3->setText(QString::number(QRandomGenerator::global()->bounded(300)));
        });
    }

    {
        QLabel *label1 = new QLabel("故障设备", this);
        QLabel *label2 = new QLabel("运行设备", this);
        QLabel *label3 = new QLabel("新增设备", this);

        label1->setAlignment(Qt::AlignCenter);
        label2->setAlignment(Qt::AlignCenter);
        label3->setAlignment(Qt::AlignCenter);

        label1->setStyleSheet("QLabel{color:#637c9f; font-size:12px;}");
        label2->setStyleSheet("QLabel{color:#637c9f; font-size:12px;}");
        label3->setStyleSheet("QLabel{color:#637c9f; font-size:12px;}");

        QHBoxLayout *layoutRow = new QHBoxLayout();
        layoutRow->addWidget(label1);
        layoutRow->addWidget(label2);
        layoutRow->addWidget(label3);

        layoutMain->addLayout(layoutRow);
    }

    timer->start(1000);
}
