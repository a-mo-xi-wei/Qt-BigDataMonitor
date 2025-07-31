#include "abstractcard.h"
#include <QPainter>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPainterPath>

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

CAbstractCard::CAbstractCard(QWidget *parent) : QWidget(parent)
{
    m_labelTitle = new QLabel(this);
    m_widgetMain = new QWidget(this);

    m_labelTitle->setAttribute(Qt::WA_TranslucentBackground);
    m_widgetMain->setAttribute(Qt::WA_TranslucentBackground);

    QVBoxLayout *layoutMain = new QVBoxLayout(this);
    layoutMain->setContentsMargins(10, 0, 10, 0);
    layoutMain->setSpacing(0);
    layoutMain->addWidget(m_labelTitle);
    layoutMain->addWidget(CreateSeparator());
    layoutMain->addWidget(m_widgetMain);

    m_labelTitle->setFixedHeight(40);
    m_labelTitle->setText("");
    m_labelTitle->setAlignment(Qt::AlignCenter);
    m_labelTitle->setStyleSheet("font-size:18px;color:#ffffff;");

    setStyleSheet("QLabel{background: rgba(255, 255, 255, 0); color:#ffffff;}");
}

void CAbstractCard::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform | QPainter::TextAntialiasing); // 抗锯齿和使用平滑转换算法

    painter.setPen(QColor(25,186,139,255 * 0.17));
    painter.setBrush(QColor(255, 255, 255, 8));
    painter.drawRect(rect());

    painter.setBrush(QBrush(QPixmap(":/image/res/line.png")));
    painter.drawRect(rect());

    QPainterPath path;
    const int len = 5;
    path.addPolygon(QPolygonF() << QPoint(0, len) << QPoint(0, 0) << QPoint(len, 0));
    path.addPolygon(QPolygonF() << QPoint(width() - len, 0) << QPoint(width(), 0) << QPoint(width(), len));
    path.addPolygon(QPolygonF() << QPoint(0, height() - len) << QPoint(0, height()) << QPoint(len, height()));
    path.addPolygon(QPolygonF() << QPoint(width() - len, height()) << QPoint(width(), height()) << QPoint(width(), height() - len));

    painter.setBrush(Qt::NoBrush);
    painter.setPen(QPen(QColor("#02a6b5"), 2));
    painter.drawPath(path);
}

void CAbstractCard::setTitle(QString strTitle)
{
    m_labelTitle->setText(strTitle);
}

QWidget *CAbstractCard::CreateSeparator(bool bVertical, QWidget *parent)
{
    QWidget *line = new QWidget(parent);
    if (bVertical)
        line->setFixedWidth(1);
    else
        line->setFixedHeight(1);
    line->setStyleSheet("background: rgba(255, 255, 255, 0.2);");
    return line;
}
