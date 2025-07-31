#include "histroychart.h"
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
#include <QDebug>

#include "alarmsummary.h"

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

CHistroyChart::CHistroyChart(QWidget *parent) : CAbstractCard(parent)
{
    setTitle("实时报警数据");

    QVBoxLayout *layoutMain = new QVBoxLayout(getMainWnd());
    layoutMain->setContentsMargins(10, 0, 10, 0);
    layoutMain->setSpacing(10);

    {
        m_chart = new QChartView(createSplineChart());
        m_chart->setRenderHint(QPainter::Antialiasing);
        m_chart->setAttribute(Qt::WA_TranslucentBackground);
        layoutMain->addWidget(m_chart);
    }

    startTimer(1000);
}

QChart *CHistroyChart::createSplineChart() const
{
    QChart *chart = new QChart();
    chart->setMargins(QMargins(0, 0, 0, 0));
    chart->setBackgroundBrush(Qt::transparent);
//    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->setTitle("");

    chart->setTitle("");
    QString name("Series ");
    int nameIndex = 0;

    DataTable m_dataTable = generateRandomData(2, 1800, 20);
    for (const DataList &list : m_dataTable)
    {
        QSplineSeries *series = new QSplineSeries(chart);
        for (const Data &data : list)
            series->append(data.first);
        series->setName(nameIndex == 0 ? "人员报警" : "车辆报警");
        nameIndex++;
        chart->addSeries(series);
    }

    chart->createDefaultAxes();
    chart->axes(Qt::Horizontal).first()->setRange(0, 20);
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

void CHistroyChart::InsertChartData()
{
    {
        QList<QAbstractSeries *>  listSeries = m_chart->chart()->series();
        if (listSeries.count() > 0)
        {
            QLineSeries *pSeries = (QLineSeries *)listSeries.at(0);

            while (pSeries->count() >= 20)
                pSeries->remove(0);

            pSeries->append(pSeries->at(pSeries->count() - 1).x() + 1, QRandomGenerator::global()->bounded(1800));

            QList<QPointF> listPt = pSeries->points();
            if (listPt.count() > 0)
                m_chart->chart()->axisX()->setRange(listPt.at(0).x(), listPt.at(0).x() + 20);
            else
                m_chart->chart()->axisX()->setRange(0, 20);
        }
        if (listSeries.count() > 1)
        {
            QLineSeries *pSeries = (QLineSeries *)listSeries.at(1);

            while (pSeries->count() >= 20)
                pSeries->remove(0);

            pSeries->append(pSeries->at(pSeries->count() - 1).x() + 1, QRandomGenerator::global()->bounded(1800));


            QList<QPointF> listPt = pSeries->points();
            if (listPt.count() > 0)
                m_chart->chart()->axisX()->setRange(listPt.at(0).x(), listPt.at(0).x() + 20);
            else
                m_chart->chart()->axisX()->setRange(0, 20);
        }


    }
}

void CHistroyChart::timerEvent(QTimerEvent *event)
{
    InsertChartData();
}
