#ifndef DISH_H
#define DISH_H

#include <QObject>
#include "ingredient.h"
#include <QVector>

class dish{
private:
    int id;
    QString name;
    QVector <ingredient> ingredients;
    QVector <int>indeWeights;
    int ccal;

    double protein;
    double fats;
    double carbohydrates;

public:
    dish();
    dish(int, QString, ingredient, int);

    void setId(int);
    int getId();

    void setName(QString);
    QString getName();

    void setIngredient(int);
    void setIndeWeights(int);
    void setIndeCcal(int, int);

    int getIngredientsLen();

    bool searchIngredientById(int);

    void showIds();
    void showWs();
    void rmZero();

    int getCcal();
    void c_ccal();

    void setProtein();
    void setFats();
    void setCarbohydrates();

    void setProtein(double);
    void setFats(double);
    void setCarbohydrates(double);

    double getProtein();
    double getFats();
    double getCarbohydrates();
};

#endif // DISH_H
