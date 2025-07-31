#ifndef VISUALIZEDATA_H
#define VISUALIZEDATA_H

#include <QWidget>

class CDynamicsEarth;
class CTitle;
class CVisualizeData : public QWidget
{
    Q_OBJECT

public:
    CVisualizeData(QWidget *parent = 0);
    ~CVisualizeData();

private:
    void Layout();

private:
    CTitle *m_pTitle;
    CDynamicsEarth *m_pDynamicsEarth;


    // QWidget interface
protected:
    void keyPressEvent(QKeyEvent *event);
};

#endif // VISUALIZEDATA_H
