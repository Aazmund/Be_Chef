#include "dish.h"
#include <QDebug>

double dish::getProtein() const
{
    return protein;
}

void dish::setProtein(double value)
{
    protein += value;
}

double dish::getFats() const
{
    return fats;
}

void dish::setFats(double value)
{
    fats += value;
}

double dish::getCarbohydrates() const
{
    return carbohydrates;
}

void dish::setCarbohydrates(double value)
{
    carbohydrates += value;
}

dish::dish(){
    id = 0;
    name = "";
    ccal = 0;
}

dish::dish(int id, QString name, ingredient obj, int indeWeights){
    this->id = id;
    this->name = name;
    this->ingredients.append(obj);
    this->indeWeights.append(indeWeights);
}

void dish::setId(int id){
    this->id = id;
}

int dish::getId(){
    return id;
}

void dish::setName(QString name){
    this->name = name;
}

QString dish::getName(){
    return this->name;
}

void dish::setIngredient(int id){
    ingredient new_ingredient;
    new_ingredient.setId(id);
    this->ingredients.append(new_ingredient);
}

void dish::setIndeWeights(int weight){
    this->indeWeights.append(weight);
}

bool dish::searchIngredientById(int id){
    for(int i = 0; i < ingredients.length(); i++){
        if(ingredients[i].getId() == id){
            return true;
            break;
        }
    }
    return false;
}

void dish::showIds(){
    for(int i = 0; i < ingredients.length(); i++){
        qDebug() << ingredients[i].getId();
    }
}

void dish::showWs(){
    for(int i = 0; i < indeWeights.length(); i++){
        qDebug() << indeWeights[i];
    }
}

void dish::rmZero(){
    ingredients.remove(ingredients.length() - 1);
    indeWeights.remove(indeWeights.length() - 1);
}

int dish::getIngredientsLen(){
    return ingredients.length();
}

int dish::getCcal(){
    return this->ccal;
}

void dish::c_ccal(){
    for(int i = 0; i < ingredients.length(); i++){
        this->ccal += (ingredients[i].getCcal() * indeWeights[i]);
    }
}

void dish::setIndeCcal(int ccal, int id){
    for(int i = 0; i < ingredients.length(); i++){
        if(ingredients[i].getId() == id){
            ingredients[i].setCcal(ccal);
        }
    }
}
