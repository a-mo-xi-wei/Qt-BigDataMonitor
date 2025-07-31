#include "piewidget.h"
#include <QPainter>
#include <QtMath>
#include <QDebug>

static QColor colorList[] = {"#ff0000", "#46afdb", "#fffc00", "#7627cb", "#23eb6a", "#ff7800", "#46afdb", "#fffc00", "#7627cb", "#23eb6a"};
CPieWidget::CPieWidget(QWidget *parent) : QWidget(parent)
{
    // = { {0.1, "车辆抓拍", "#0ff222"}, {0.2, "人员抓拍", "#33f2dd"}, {0.7, "违章抓拍", "#2f1423"}};
}

void CPieWidget::append(qreal percent, QString name)
{
    m_listItem.append({percent, name});
}

void CPieWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform | QPainter::TextAntialiasing); // 抗锯齿和使用平滑转换算法

    int radius = qMin(rect().width(), rect().height()) / 2; // 半径
    QPointF center = rect().center(); // 圆心

    QRect rcClient = QRect(center.x() - radius, center.y() - radius, radius * 2, radius * 2);
    rcClient = rcClient.adjusted(20, 20, -20, -20);

    QSize size_r = rcClient.size();
    rcClient.setLeft(width() * 0.25);
    rcClient.setWidth(size_r.width());

    int size = rcClient.width() * 0.2;

    painter.save();
    QPainterPath path1;
    path1.addEllipse(rcClient);

    QPainterPath path2;
    path2.addEllipse(rcClient.adjusted(size, size, -size, -size));

    // 使用setClipPath函数设置相减区域
    QPainterPath clipPath = path1.subtracted(path2);

    painter.setClipPath(clipPath);


    // 绘制圆环
    painter.setBrush(QColor("#06a0ab"));
    painter.setPen(Qt::NoPen);
    painter.drawEllipse(rcClient);

    // 绘制扇形
    double startAngle = 0; // 开始角度（弧度）
    double spanAngle = 0; // 跨度角度（弧度）

    int i = 0;
    foreach (auto &item, m_listItem)
    {
        spanAngle = 360 * item.percent;

        painter.setBrush(colorList[i++]);
        painter.drawPie(rcClient, startAngle * 16, spanAngle * 16);

        startAngle += spanAngle;
    }

    painter.restore();

    QRect rcLend(rcClient);
    rcLend.setLeft(rcClient.right() + 20);
    rcLend.setRight(rect().right() - 20);

    i = 0;
    QRect rcItem = rcLend;
    foreach (auto &item, m_listItem)
    {
        rcItem.setHeight(28);

        QRect rcColor = rcItem;
        rcColor.setTop(rcColor.top() + 10);
        rcColor.setBottom(rcColor.bottom() - 10);
        rcColor.setLeft(rcColor.right() - 30);

        painter.setBrush(colorList[i++]);
        painter.setPen(Qt::NoPen);
        painter.drawRect(rcColor);

        QRect rcText = rcItem;
        rcText.setRight(rcColor.left() - 10);
        painter.setPen(Qt::white);
        painter.drawText(rcText, Qt::AlignRight | Qt::AlignVCenter, item.name);

        rcItem.setTop(rcItem.bottom());
    }
}

void CPieWidget::resizeEvent(QResizeEvent *event)
{
}
