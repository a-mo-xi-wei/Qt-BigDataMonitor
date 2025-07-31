#ifndef CIRCULARDIAL_H
#define CIRCULARDIAL_H

#include <QWidget>
#include <QLabel>
#include <QPropertyAnimation>

class CircularDial : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(float DialValue READ fDialValue WRITE setFDialValue)
public:
    explicit CircularDial(QWidget *parent = Q_NULLPTR);

    int nLow() const;
    void setNLow(int nLow);

    int nHigh() const;
    void setNHigh(int nHigh);

    int nMax() const;
    void setNMax(int nMax);

    QString strFormat() const;
    void setStrFormat(const QString &strFormat);

    void active();
    void normal();

    float fDialValue() const;
    void setFDialValue(float fDialValue);

private:
    void paintEvent(QPaintEvent *event);
    void paintBg(QPainter &p);

private:
    int m_nLow;
    int m_nHigh;
    int m_nMax;

    float m_fDialValue;
    bool m_bNeedRefreshBg;

    QFont m_iconFont;
    QPropertyAnimation *m_pAnimationOpacity;

    QString m_strFormat;

    QPixmap m_pixBg;
};

#endif // CIRCULARDIAL_H
