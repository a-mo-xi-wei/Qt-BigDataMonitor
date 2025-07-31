#ifndef TITLE_H
#define TITLE_H

#include <QWidget>

class CTitle : public QWidget
{
    Q_OBJECT
public:
    explicit CTitle(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *event);
};

#endif // TITLE_H
