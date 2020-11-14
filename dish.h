#ifndef DISH_H
#define DISH_H

#include <QObject>
#include "ingredient.h"


class dish{
private:
    int id;
    QString name;
    ingredient *ingredients;
    int weight;
    int *indeWeights;

public:
    dish();

    void setId(int);
    int getId();

    void setName(QString);
    QString getName();

};

#endif // DISH_H
