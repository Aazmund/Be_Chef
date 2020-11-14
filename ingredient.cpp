#include "ingredient.h"

ingredient::ingredient(){
    id = 0;
    name = "";
    ccal = 0;
    protein = 0;
    fats = 0;
    carbohydrates = 0;
}

int ingredient::getId(){
        return this->id;
    }

void ingredient::setId(int id){
    this->id = id;
}

QString ingredient::getName(){
    return this->name;
}

void ingredient::setName(QString name){
    this->name = name;
}

double ingredient::getCcal(){
    return this->ccal;
}

void ingredient::setCcal(double ccal){
    this->ccal = ccal;
}

double ingredient::getProtein(){
    return this->protein;
}

void ingredient::setProtein(double protein){
    this->protein = protein;
}

double ingredient::getFats(){
    return this->fats;
}

void ingredient::setFats(double fats){
    this->fats = fats;
}

double ingredient::getCarbohydrates(){
    return this->carbohydrates;
}

void ingredient::setCarbohydrates(double carbohydrates){
    this->carbohydrates = carbohydrates;
}
