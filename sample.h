#ifndef SAMPLE_H
#define SAMPLE_H

#include <QString>
#include "ingredient.h"
#include <QDebug>


class Sample
{
private:
    QString name;
    float percent;
    float all_ind;
    float collision;
public:
    Sample();
    void setName(QString);
    QString getName();
    void setPercent(float);
    float getPercent();
    void addCollision(int);
    void setAll_ind(int);
    void showStat();
    void calcPercent();

};

#endif // SAMPLE_H
