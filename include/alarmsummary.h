#ifndef ALARMSUMMARY_H
#define ALARMSUMMARY_H

#include "abstractcard.h"
#include <QtWidgets/QWidget>
#include <QtCharts/QChartGlobal>

QT_CHARTS_BEGIN_NAMESPACE
class QChartView;
class QChart;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

typedef QPair<QPointF, QString> Data;
typedef QList<Data> DataList;
typedef QList<DataList> DataTable;

class CAlarmSummary : public CAbstractCard
{
    Q_OBJECT
public:
    explicit CAlarmSummary(QWidget *parent = nullptr);
    QChart *createBarChart(int valueCount) const;
signals:

public slots:
};

DataTable generateRandomData(int listCount, int valueMax, int valueCount);

#endif // ALARMSUMMARY_H
