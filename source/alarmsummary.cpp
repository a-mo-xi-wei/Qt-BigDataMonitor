#include "alarmsummary.h"
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QAbstractBarSeries>
#include <QtCharts/QPercentBarSeries>
#include <QtCharts/QStackedBarSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLineSeries>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QScatterSeries>
#include <QtCharts/QAreaSeries>
#include <QtCharts/QLegend>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtCore/QRandomGenerator>
#include <QtCharts/QBarCategoryAxis>
#include <QtWidgets/QApplication>
#include <QtCharts/QValueAxis>

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif


CAlarmSummary::CAlarmSummary(QWidget *parent) : CAbstractCard(parent)
{
    setTitle("报警汇总");

    QVBoxLayout *layoutMain = new QVBoxLayout(getMainWnd());
    layoutMain->setContentsMargins(10, 0, 10, 0);
    layoutMain->setSpacing(10);

    {
        QLabel *label1 = new QLabel("1288", this);
        QLabel *label2 = new QLabel("1012", this);
        QLabel *label3 = new QLabel("10%", this);

        label1->setAlignment(Qt::AlignCenter);
        label2->setAlignment(Qt::AlignCenter);
        label3->setAlignment(Qt::AlignCenter);

        label1->setStyleSheet("QLabel{color:#c5ccff; font-size:24px; font-weight: bold;}");
        label2->setStyleSheet("QLabel{color:#c5ccff; font-size:24px; font-weight: bold;}");
        label3->setStyleSheet("QLabel{color:#c5ccff; font-size:24px; font-weight: bold;}");

        QHBoxLayout *layoutRow = new QHBoxLayout();
        layoutRow->addWidget(label1);
        layoutRow->addWidget(CreateSeparator(true, this));
        layoutRow->addWidget(label2);
        layoutRow->addWidget(CreateSeparator(true, this));
        layoutRow->addWidget(label3);
        layoutRow->setContentsMargins(0, 10, 0, 0);

        layoutMain->addLayout(layoutRow);
    }

    {
        QLabel *label1 = new QLabel("本月报警数量", this);
        QLabel *label2 = new QLabel("上月报警数量", this);
        QLabel *label3 = new QLabel("环比增长", this);

        label1->setAlignment(Qt::AlignCenter);
        label2->setAlignment(Qt::AlignCenter);
        label3->setAlignment(Qt::AlignCenter);

        label1->setStyleSheet("QLabel{color:rgba(255, 255, 255, 100); font-size:12px;}");
        label2->setStyleSheet("QLabel{color:rgba(255, 255, 255, 100); font-size:12px;}");
        label3->setStyleSheet("QLabel{color:rgba(255, 255, 255, 100); font-size:12px;}");

        QHBoxLayout *layoutRow = new QHBoxLayout();
        layoutRow->addWidget(label1);
        layoutRow->addWidget(label2);
        layoutRow->addWidget(label3);

        layoutMain->addLayout(layoutRow);
    }

    layoutMain->addWidget(CreateSeparator(false, this));

    {
        QLabel *label1 = new QLabel("1288", this);
        QLabel *label2 = new QLabel("1012", this);
        QLabel *label3 = new QLabel("10%", this);

        label1->setAlignment(Qt::AlignCenter);
        label2->setAlignment(Qt::AlignCenter);
        label3->setAlignment(Qt::AlignCenter);

        label1->setStyleSheet("QLabel{color:#c5ccff; font-size:24px; font-weight: bold;}");
        label2->setStyleSheet("QLabel{color:#c5ccff; font-size:24px; font-weight: bold;}");
        label3->setStyleSheet("QLabel{color:#c5ccff; font-size:24px; font-weight: bold;}");

        QHBoxLayout *layoutRow = new QHBoxLayout();
        layoutRow->addWidget(label1);
        layoutRow->addWidget(CreateSeparator(true, this));
        layoutRow->addWidget(label2);
        layoutRow->addWidget(CreateSeparator(true, this));
        layoutRow->addWidget(label3);
        layoutRow->setContentsMargins(0, 10, 0, 0);

        layoutMain->addLayout(layoutRow);
    }

    {
        QLabel *label1 = new QLabel("本月报警数量", this);
        QLabel *label2 = new QLabel("上月报警数量", this);
        QLabel *label3 = new QLabel("环比增长", this);

        label1->setAlignment(Qt::AlignCenter);
        label2->setAlignment(Qt::AlignCenter);
        label3->setAlignment(Qt::AlignCenter);

        label1->setStyleSheet("QLabel{color:rgba(255, 255, 255, 100); font-size:12px;}");
        label2->setStyleSheet("QLabel{color:rgba(255, 255, 255, 100); font-size:12px;}");
        label3->setStyleSheet("QLabel{color:rgba(255, 255, 255, 100); font-size:12px;}");

        QHBoxLayout *layoutRow = new QHBoxLayout();
        layoutRow->addWidget(label1);
        layoutRow->addWidget(label2);
        layoutRow->addWidget(label3);

        layoutMain->addLayout(layoutRow);
    }

    {
        QLabel *label1 = new QLabel("数据分析", this);
        label1->setAlignment(Qt::AlignCenter);
        label1->setStyleSheet("QLabel{color:#49bcf7; font-size:12px; border: 1px solid rgba(25,186,139,40); background: rgba(255,255,255,12)}");

        QHBoxLayout *layoutRow = new QHBoxLayout();
        layoutRow->addWidget(CreateSeparator(false, this));
        layoutRow->addWidget(label1);
        layoutRow->addWidget(CreateSeparator(false, this));

        layoutMain->addLayout(layoutRow);

        QChartView *chart = new QChartView(createBarChart(10));
        chart->setRenderHint(QPainter::Antialiasing);
        chart->setAttribute(Qt::WA_TranslucentBackground);
        layoutMain->addWidget(chart);
    }
}

DataTable generateRandomData(int listCount, int valueMax, int valueCount)
{
    DataTable dataTable;

    // generate random data
    for (int i(0); i < listCount; i++) {
        DataList dataList;
        qreal yValue(0);
        for (int j(0); j < valueCount; j++) {
            yValue = yValue + QRandomGenerator::global()->bounded(valueMax / (qreal) valueCount);
            QPointF value((j + QRandomGenerator::global()->generateDouble()) * ((qreal) valueCount / (qreal) valueCount),
                          yValue);
            QString label = "Slice " + QString::number(i) + ":" + QString::number(j);
            dataList << Data(value, label);
        }
        dataTable << dataList;
    }

    return dataTable;
}

QChart *CAlarmSummary::createBarChart(int valueCount) const
{
    Q_UNUSED(valueCount);
    QChart *chart = new QChart();
    chart->setMargins(QMargins(0, 0, 0, 0));
    chart->setBackgroundBrush(Qt::transparent);
    chart->setTitle("");
    chart->setAnimationOptions(QChart::AllAnimations);

    DataTable m_dataTable = generateRandomData(2, 1800, 7);

    QStackedBarSeries *series = new QStackedBarSeries(chart);
    for (int i(0); i < m_dataTable.count(); i++)
    {
        QBarSet *set = new QBarSet(i == 0 ? "人员报警" : "车辆报警");
        set->setLabelColor(QColor("blue")); // 设置Series文本颜色为蓝色
        for (const Data &data : m_dataTable[i])
            *set << data.first.y();
        series->append(set);
    }
    chart->addSeries(series);

    chart->createDefaultAxes();
    chart->axes(Qt::Vertical).first()->setRange(0, 2000);

    // Add space to label to add space between labels and axis
    QValueAxis *axisY = qobject_cast<QValueAxis*>(chart->axes(Qt::Vertical).first());
    Q_ASSERT(axisY);
    axisY->setLabelFormat("%.1f  ");

    foreach (auto iter, chart->axes())
    {
        iter->setLabelsColor(QColor(255, 255, 255));
    }

    chart->legend()->setLabelColor(QColor(255, 255, 255));

    return chart;
}
