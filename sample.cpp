#include "sample.h"

Sample::Sample()
{
    name = "";
    percent = 0;
    all_ind = 0;
    collision = 0;
}

void Sample::setName(QString name){
    this->name = name;
}

QString Sample::getName(){
    return this->name;
}

void Sample::setAll_ind(int all_ind){
    this->all_ind = all_ind;
}

void Sample::addCollision(int coll){
    this->collision += coll;
}

void Sample::showStat(){
    qDebug() << this->name;
    qDebug() << this->all_ind;
    qDebug() << this->collision;
    qDebug() << this->percent;
}

void Sample::calcPercent(){
    this->percent = (this->collision / this->all_ind) * 100;
}
