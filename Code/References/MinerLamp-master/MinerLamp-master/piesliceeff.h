#ifndef PIESLICEEFF_H
#define PIESLICEEFF_H

#include <QtCharts/QPieSlice>

QT_CHARTS_USE_NAMESPACE

class piesliceEff : public QPieSlice
{
public:
    piesliceEff(QObject *parent = Q_NULLPTR);
    piesliceEff(QString label, qreal value, QObject *parent = Q_NULLPTR);

protected:
        void hovered();
};

#endif // PIESLICEEFF_H
