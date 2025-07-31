#ifndef HISTROYCHART_H
#define HISTROYCHART_H

#include "abstractcard.h"
#include <QtWidgets/QWidget>
#include <QtCharts/QChartGlobal>

QT_CHARTS_BEGIN_NAMESPACE
class QChartView;
class QChart;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class CHistroyChart : public CAbstractCard
{
    Q_OBJECT

public:
    explicit CHistroyChart(QWidget *parent = nullptr);
    QChart *createSplineChart() const;

    void InsertChartData();

protected:
    void timerEvent(QTimerEvent *event);

private:
    QChartView *m_chart;
};

#endif // HISTROYCHART_H
