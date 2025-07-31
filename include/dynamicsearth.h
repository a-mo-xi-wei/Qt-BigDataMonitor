#ifndef DYNAMICSEARTH_H
#define DYNAMICSEARTH_H

#include <QWidget>

class CDynamicsEarth : public QWidget
{
    Q_OBJECT
public:
    explicit CDynamicsEarth(QWidget *parent = nullptr);

signals:

public slots:

    // QWidget interface
public:
    int getAngle() const;
    void setAngle(int value);

protected:
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *event);
    void resizeEvent(QResizeEvent *event);

private:
    QPixmap m_pixBg;
    QPixmap m_pixMask1;
    QPixmap m_pixMask2;

    int angle;
};

#endif // DYNAMICSEARTH_H
