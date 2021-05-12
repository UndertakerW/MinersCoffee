#include <QDateTimeAxis>
#include <QToolTip>

#include "chartview.h"


ChartView::ChartView(QWidget *parent) :
    QChartView(parent)
{
    setRenderHint(QPainter::Antialiasing);
    setMouseTracking(true);
    setInteractive(true);
    setRubberBand(RectangleRubberBand);

}

ChartView::ChartView(QChart *chart, QWidget *parent) :
    QChartView(chart, parent)
{
    setRenderHint(QPainter::Antialiasing);
    //setMouseTracking(true);
    //setInteractive(true);
    setRubberBand(QChartView::NoRubberBand);
}

void ChartView::setChart(QChart *chart)
{
    QChartView::setChart(chart);
}

void ChartView::setChart(QChart *chart, int mode){
    setChart(chart);
    graphMode = mode;
}

void ChartView::mouseMoveEvent(QMouseEvent *event)
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


void ChartView::wheelEvent(QWheelEvent *event)
{

    if(event->angleDelta().y() > 0)
    {
        chart()->zoomIn();

    }
    else
        chart()->zoomOut();

    event->accept();
}

void ChartView::resizeEvent(QResizeEvent *event){
    QChartView::resizeEvent(event);
}
