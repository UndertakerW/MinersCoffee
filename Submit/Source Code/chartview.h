#ifndef CHARTVIEW_H
#define CHARTVIEW_H

#include <QChartView>
#include <QDateTime>
#include "mainwindow.h"

QT_CHARTS_USE_NAMESPACE


class ChartView : public QChartView
{
public:
    ChartView(QWidget* parent = Q_NULLPTR);
    ChartView(QChart *chart, QWidget *parent = Q_NULLPTR);

    void setChart(QChart *chart);
    void setChart(QChart *chart, int mode);

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent* event);
    void resizeEvent(QResizeEvent *event);

private:
    int graphMode = 0;
};

#endif // CHARTVIEW_H
