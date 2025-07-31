#include "piechart.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTimer>
#include "piewidget.h"
#include "qcustomplot.h"

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

CPieChart::CPieChart(QWidget *parent) : CAbstractCard(parent)
{
    setTitle("故障比例");

    QVBoxLayout *layoutMain = new QVBoxLayout(getMainWnd());
    layoutMain->setContentsMargins(0, 6, 0, 0);
    layoutMain->setSpacing(6);

    {
        QCustomPlot *customPlot = new QCustomPlot(this);

        // set dark background gradient:
        QLinearGradient gradient(0, 0, 0, 400);
        gradient.setColorAt(0, QColor(90, 90, 90));
        gradient.setColorAt(0.38, QColor(105, 105, 105));
        gradient.setColorAt(1, QColor(70, 70, 70));
        customPlot->setBackground(Qt::transparent);

        // create empty bar chart objects:
        QCPBars *regen = new QCPBars(customPlot->xAxis, customPlot->yAxis);
        QCPBars *nuclear = new QCPBars(customPlot->xAxis, customPlot->yAxis);
        QCPBars *fossil = new QCPBars(customPlot->xAxis, customPlot->yAxis);

        regen->setAntialiased(false); // gives more crisp, pixel aligned bar borders
        nuclear->setAntialiased(false);
        fossil->setAntialiased(false);
        regen->setStackingGap(1);
        nuclear->setStackingGap(1);
        fossil->setStackingGap(1);

        // set names and colors:
        fossil->setName("Fossil fuels");
        fossil->setPen(QPen(QColor(111, 9, 176).lighter(170)));
        fossil->setBrush(QColor(111, 9, 176));
        nuclear->setName("Nuclear");
        nuclear->setPen(QPen(QColor(250, 170, 20).lighter(150)));
        nuclear->setBrush(QColor(250, 170, 20));
        regen->setName("Regenerative");
        regen->setPen(QPen(QColor(0, 168, 140).lighter(130)));
        regen->setBrush(QColor(0, 168, 140));

        // stack bars on top of each other:
        nuclear->moveAbove(fossil);
        regen->moveAbove(nuclear);

        // prepare x axis with country labels:
        QVector<double> ticks;
        QVector<QString> labels;
        ticks << 1 << 2 << 3 << 4 << 5 << 6 << 7;
        labels << "安庆" << "怀宁" << "芜湖" << "无为" << "赫店" << "上海" << "北京";

        QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
        textTicker->addTicks(ticks, labels);
        customPlot->xAxis->setTicker(textTicker);


        customPlot->xAxis->setSubTicks(false);
        customPlot->xAxis->setTickLength(0, 4);
        customPlot->xAxis->setRange(0, 8);
        customPlot->xAxis->setBasePen(QPen(Qt::white));
        customPlot->xAxis->setTickPen(QPen(Qt::white));
        customPlot->xAxis->grid()->setVisible(true);
        customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
        customPlot->xAxis->setTickLabelColor(Qt::white);
        customPlot->xAxis->setLabelColor(Qt::white);

        // prepare y axis:
        customPlot->yAxis->setRange(0, 12.1);
        customPlot->yAxis->setPadding(5); // a bit more space to the left border


        customPlot->yAxis->setBasePen(QPen(Qt::white));
        customPlot->yAxis->setTickPen(QPen(Qt::white));
        customPlot->yAxis->setSubTickPen(QPen(Qt::white));
        customPlot->yAxis->grid()->setSubGridVisible(true);
        customPlot->yAxis->setTickLabelColor(Qt::white);
        customPlot->yAxis->setLabelColor(Qt::white);
        customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
        customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

        // Add data:
        QVector<double> fossilData, nuclearData, regenData;
        fossilData  << 0.86 * 10.5 << 0.83 * 5.5 << 0.84 * 5.5 << 0.52 * 5.8 << 0.89 * 5.2 << 0.90 * 4.2 << 0.67 * 11.2;
        nuclearData << 0.08 * 10.5 << 0.12 * 5.5 << 0.12 * 5.5 << 0.40 * 5.8 << 0.09 * 5.2 << 0.00 * 4.2 << 0.07 * 11.2;
        regenData   << 0.06 * 10.5 << 0.05 * 5.5 << 0.04 * 5.5 << 0.06 * 5.8 << 0.02 * 5.2 << 0.07 * 4.2 << 0.25 * 11.2;
        fossil->setData(ticks, fossilData);
        nuclear->setData(ticks, nuclearData);
        regen->setData(ticks, regenData);

        // setup legend:
        customPlot->legend->setVisible(false);
        customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop | Qt::AlignHCenter);
        customPlot->legend->setBrush(QColor(255, 255, 255, 100));
        customPlot->legend->setBorderPen(Qt::NoPen);
        QFont legendFont = font();
        legendFont.setPointSize(10);
        customPlot->legend->setFont(legendFont);
        customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

        layoutMain->addWidget(customPlot);

        QTimer *dataTimer = new QTimer();
        connect(dataTimer, &QTimer::timeout, [=]
        {
            double a = QRandomGenerator::global()->generateDouble() * 10;
            double b = QRandomGenerator::global()->generateDouble() * 10;
            double c = QRandomGenerator::global()->generateDouble() * 10;
            double d = QRandomGenerator::global()->generateDouble() * 10;
            double e = QRandomGenerator::global()->generateDouble() * 10;
            double f = QRandomGenerator::global()->generateDouble() * 10;
            double g = QRandomGenerator::global()->generateDouble() * 10;

            QVector<double> fossilData, nuclearData, regenData;
            fossilData  << 0.16 * a << 0.83 * b << 0.84 * c << 0.52 * d << 0.89 * e << 0.90 * f << 0.67 * g;
            nuclearData << 0.48 * a << 0.12 * b << 0.12 * c << 0.40 * d << 0.09 * e << 0.00 * f << 0.07 * g;
            regenData   << 0.36 * a << 0.05 * b << 0.04 * c << 0.06 * d << 0.02 * e << 0.07 * f << 0.25 * g;
            fossil->setData(ticks, fossilData);
            nuclear->setData(ticks, nuclearData);
            regen->setData(ticks, regenData);

            customPlot->replot();
        });

        dataTimer->start(1000);
    }

    {
        QLabel *label1 = new QLabel("故障分析", this);
        label1->setAlignment(Qt::AlignCenter);
        label1->setStyleSheet("QLabel{color:#49bcf7; font-size:12px; border: 1px solid rgba(25,186,139,40); background: rgba(255,255,255,12)}");

        QHBoxLayout *layoutRow = new QHBoxLayout();
        layoutRow->addWidget(CreateSeparator(false, this));
        layoutRow->addWidget(label1);
        layoutRow->addWidget(CreateSeparator(false, this));

        layoutMain->addLayout(layoutRow);
    }

    {
        CPieWidget *pie1 = new CPieWidget(this);
        pie1->append(0.2, "人员抓拍");
        pie1->append(0.3, "车辆抓拍");
        pie1->append(0.4, "违章抓拍");
        layoutMain->addWidget(pie1);
    }
}
