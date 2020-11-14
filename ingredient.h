#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <QObject>
#include <QString>



class ingredient: QObject
{
    Q_OBJECT;

private:
    int id;
    QString name;
    double ccal;
    double protein;
    double fats;
    double carbohydrates;

public:
    ingredient();

    int getId();
    void setId(int);

    QString getName();
    void setName(QString);

    double getCcal();
    void setCcal(double);

    double getProtein();
    void setProtein(double);

    double getFats();
    void setFats(double);

    double getCarbohydrates();
    void setCarbohydrates(double);


};

#endif // INGREDIENT_H
