#ifndef DISH_H
#define DISH_H

#include <QObject>
#include "ingredient.h"


class dish{
private:
    int id;
    QString name;
    QVector<ingredient> ingredients;
    QVector<int>indeWeights;

public:
    dish();
    dish(int, QString, ingredient, int);

    void setId(int);
    int getId();

    void setName(QString);
    QString getName();

    void setIngredient(int);
    void setIndeWeights(int);

    int getIngredientsLen();

    bool searchIngredientById(int);

    void showIds();
    void showWs();
    void rmZero();
};

#endif // DISH_H
