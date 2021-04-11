#include <QDateTimeAxis>
#include <QToolTip>

#include "hashratecharview.h"


hashrateCharView::hashrateCharView(QWidget *parent) :
    QChartView(parent)
{
    setRenderHint(QPainter::Antialiasing);
    setMouseTracking(true);
    setInteractive(true);
    setRubberBand(RectangleRubberBand);

}

hashrateCharView::hashrateCharView(QChart *chart, QWidget *parent) :
    QChartView(chart, parent)
{
    setRenderHint(QPainter::Antialiasing);
    //setMouseTracking(true);
    //setInteractive(true);
    setRubberBand(QChartView::NoRubberBand);
}

void hashrateCharView::setChart(QChart *chart)
{
    QChartView::setChart(chart);
}

void hashrateCharView::setChart(QChart *chart, int mode){
    setChart(chart);
    graphMode = mode;
}

void hashrateCharView::mouseMoveEvent(QMouseEvent *event)
{

    if(graphMode == 0){
        QPointF point = chart()->mapToValue(event->pos());

        QDateTimeAxis *axisX = qobject_cast<QDateTimeAxis *>(chart()->axisX());


        QToolTip::showText(event->globalPos(),
                           QString::number(point.y()),
                           this, rect() );

        QChartView::mouseMoveEvent(event);
    }
    else if(graphMode == 1){
        QChartView::mouseMoveEvent(event);
    }

}


void hashrateCharView::wheelEvent(QWheelEvent *event)
{

    if(event->angleDelta().y() > 0)
    {
        chart()->zoomIn();

    }
    else
        chart()->zoomOut();

    event->accept();
}
