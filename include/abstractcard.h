#ifndef CABSTRACTCARD_H
#define CABSTRACTCARD_H

#include <QWidget>
#include <QLabel>

class CAbstractCard : public QWidget
{
    Q_OBJECT
public:
    explicit CAbstractCard(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *);

    void setTitle(QString strTitle);
    inline QWidget *getMainWnd() { return m_widgetMain; }

    QWidget *CreateSeparator(bool bVertical = false, QWidget *parent = 0);

private:
    QLabel *m_labelTitle;
    QWidget *m_widgetMain;
};

#endif // CABSTRACTCARD_H
