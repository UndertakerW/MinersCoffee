#ifndef HASHRATECHARVIEW_H
#define HASHRATECHARVIEW_H

#include <QChartView>
#include <QDateTime>
#include "mainwindow.h"

QT_CHARTS_USE_NAMESPACE


class hashrateCharView : public QChartView
{
public:
    hashrateCharView(QWidget* parent = Q_NULLPTR);
    hashrateCharView(QChart *chart, QWidget *parent = Q_NULLPTR);

    void setChart(QChart *chart);
    void setChart(QChart *chart, int mode);
    void setPieCenterLabel(QLabel * label);

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent* event);
    void resizeEvent(QResizeEvent *event);

private:
    QDateTime _startTime;
    QLabel * _centerPieLabel = nullptr;
    int graphMode = 0;
};

#endif // HASHRATECHARVIEW_H
