#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"

#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    creatIngredientBD();
    creatDishBD();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::checkCheckBox(int *id_arr){

    for(int i = 0; i < 18; i++){
        id_arr[i] = 0;
    }

    if(ui->checkBox->checkState() == Qt::Checked){
        id_arr[0] = 1;
    }
    if(ui->checkBox_2->checkState() == Qt::Checked){
        id_arr[1] = 2;
    }
    if(ui->checkBox_3->checkState() == Qt::Checked){
        id_arr[2] = 3;
    }
    if(ui->checkBox_4->checkState() == Qt::Checked){
        id_arr[3] = 4;
    }
    if(ui->checkBox_5->checkState() == Qt::Checked){
        id_arr[4] = 5;
    }
    if(ui->checkBox_6->checkState() == Qt::Checked){
        id_arr[5] = 6;
    }
    if(ui->checkBox_7->checkState() == Qt::Checked){
        id_arr[6] = 7;
    }
    if(ui->checkBox_8->checkState() == Qt::Checked){
        id_arr[7] = 8;
    }
    if(ui->checkBox_9->checkState() == Qt::Checked){
        id_arr[8] = 9;
    }
    if(ui->checkBox_10->checkState() == Qt::Checked){
        id_arr[9] = 10;
    }
    if(ui->checkBox_11->checkState() == Qt::Checked){
        id_arr[10] = 11;
    }
    if(ui->checkBox_12->checkState() == Qt::Checked){
        id_arr[11] = 12;
    }
    if(ui->checkBox_13->checkState() == Qt::Checked){
        id_arr[12] = 13;
    }
    if(ui->checkBox_14->checkState() == Qt::Checked){
        id_arr[13] = 14;
    }
    if(ui->checkBox_15->checkState() == Qt::Checked){
        id_arr[14] = 15;
    }
    if(ui->checkBox_16->checkState() == Qt::Checked){
        id_arr[15] = 16;
    }
    if(ui->checkBox_17->checkState() == Qt::Checked){
        id_arr[16] = 17;
    }
}

void MainWindow::creatIngredientBD(){
    QFile file(":/ingredient.txt");
    file.open(QIODevice::ReadOnly);

    while(!file.atEnd()){

        int buf_id = 0;
        QString buf_name = "";
        double buf_ccal = 0;
        double buf_protein = 0;
        double buf_fats = 0;
        double buf_carbohydrates = 0;

        QString result = "";
        QString str = file.readLine();
        int index = str.indexOf(";");
        for(int i = 0; i < index; i++){
            result += str[i];
        }
        buf_id = result.toInt();
        str.remove(0, index + 1);

        result = "";
        index = str.indexOf(";");
        for(int i = 0; i < index; i++){
            result += str[i];
        }
        buf_name = result;
        str.remove(0, index + 1);

        result = "";
        index = str.indexOf(";");
        for(int i = 0; i < index; i++){
            result += str[i];
        }
        buf_ccal = result.toDouble();
        str.remove(0, index + 1);

        result = "";
        index = str.indexOf(";");
        for(int i = 0; i < index; i++){
            result += str[i];
        }
        buf_protein = result.toDouble();
        str.remove(0, index + 1);

        result = "";
        index = str.indexOf(";");
        for(int i = 0; i < index; i++){
            result += str[i];
        }
        buf_fats = result.toDouble();
        str.remove(0, index + 1);

        result = "";
        index = str.indexOf(";");
        for(int i = 0; i < index; i++){
            result += str[i];
        }
        buf_carbohydrates = result.toDouble();
        str.remove(0, index + 1);

        ingredient new_ingredient(buf_id, buf_name, buf_ccal, buf_protein, buf_fats, buf_carbohydrates);
        ingredients.append(new_ingredient);

    }

    file.close();
}

void MainWindow::creatDishBD(){
    QFile file(":/dish.txt");
    file.open(QIODevice::ReadOnly);

    while(!file.atEnd()){
        int counter = 1;
        dish new_dish;
        QString result = "";
        int index = 0;
        QString str = file.readLine();
        str = str.trimmed();
        new_dish.setName(str);
        new_dish.setId(counter);
        while(str != "@"){
            str = file.readLine();
            str = str.trimmed();
            index = str.indexOf(";");
            for(int i = 0; i < index; i++){
                result += str[i];
            }
            new_dish.setIngredient(result.toInt());
            str.remove(0, index + 1);
            new_dish.setIndeWeights(str.toInt());
            result = "";
        }
        new_dish.rmZero();
        dishes.append(new_dish);
        counter++;
    }
    file.close();
}

void MainWindow::searchDish(int *arr){

    for(int i = 0; i < dishes.length(); i++){
        Sample sample;
        sample.setName(dishes[i].getName());
        sample.setAll_ind(dishes[i].getIngredientsLen());
        results.append(sample);
    }

    for(int i = 0; i < 18; i++){
        if(arr[i] != 0){
            for (int index = 0; index < dishes.length(); index++) {
                if(dishes[index].searchIngredientById(arr[i])){

                    for(int ii = 0; ii < results.length(); ii++){
                        if(results[ii].getName() == dishes[index].getName()){
                            results[ii].addCollision(1);
                        }
                    }

                }
            }
        }
    }
    for(int i = 0; i < results.length(); i++){
        results[i].calcPercent();
        results[i].showStat();
    }
}

void MainWindow::on_pushButton_clicked(){
    int id_arr[18];
    checkCheckBox(id_arr);

//    for(int i = 0; i < dishes.length(); i++){
//        qDebug() << dishes[i].getName();
//        dishes[i].showIds();
//    }

    searchDish(id_arr);
}
