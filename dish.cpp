#include "dish.h"

dish::dish(){
    id = 0;
    name = "";
    ingredients = new ingredient[1];
    indeWeights = new int[1];
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
