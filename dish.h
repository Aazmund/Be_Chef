#ifndef DISH_H
#define DISH_H

#include <QObject>
#include "ingredient.h"


class dish: QObject{
    Q_OBJECT;
private:
    int id;
    QString name;
    ingredient *ingredients;
    int weight;

public:
    dish();

    void setId(int);
    int getId();

    void setName(QString);
    QString getName();

    int getWeight();
    void setWeight(int);

};

#endif // DISH_H
