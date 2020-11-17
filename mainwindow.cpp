#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "QPainter"
#include "window2.h"

#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    creatIngredientBD();
    creatDishBD();
    setAll();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::setAll(){

  ui->checkBox->setText(ingredients[0].getName());
  ui->checkBox_2->setText(ingredients[1].getName());
  ui->checkBox_3->setText(ingredients[2].getName());
  ui->checkBox_4->setText(ingredients[3].getName());
  ui->checkBox_5->setText(ingredients[4].getName());
  ui->checkBox_6->setText(ingredients[5].getName());
  ui->checkBox_7->setText(ingredients[6].getName());
  ui->checkBox_8->setText(ingredients[7].getName());
  ui->checkBox_9->setText(ingredients[8].getName());
  ui->checkBox_10->setText(ingredients[9].getName());
  ui->checkBox_11->setText(ingredients[10].getName());
  ui->checkBox_12->setText(ingredients[11].getName());
  ui->checkBox_13->setText(ingredients[12].getName());
  ui->checkBox_14->setText(ingredients[13].getName());
  ui->checkBox_15->setText(ingredients[14].getName());
  ui->checkBox_16->setText(ingredients[15].getName());
  ui->checkBox_17->setText(ingredients[16].getName());


  for(int i = 0; i < dishes.length(); i++){
      dishes[i].c_ccal();
      qDebug() << dishes[i].getCcal();
  }

  ui->pic_1->setPixmap(QPixmap(":/images/borscht.jpg"));
    ui->t1->setText(dishes[0].getName());
    ui->properties_1->setText("Килокалорий в 100гр продукта: " + QString::number(dishes[0].getCcal() / 10));
    ui->label_3->setText("Белки: " + QString::number(dishes[0].getProtein()) + " " + "Жиры: " + QString::number(dishes[0].getFats()) + " " + "Углеводы: " + QString::number(dishes[0].getCarbohydrates()));

    ui->pic_2->setPixmap(QPixmap(":/images/myaso-po-francuzski.jpg"));
    ui->t2->setText(dishes[1].getName());
    ui->properties_2->setText("Килокалорий в 100гр продукта " + QString::number(dishes[1].getCcal() / 10));
    ui->label_4->setText("Белки: " + QString::number(dishes[1].getProtein()) + " " + "Жиры: " + QString::number(dishes[1].getFats()) + " " + "Углеводы: " + QString::number(dishes[1].getCarbohydrates()));


    ui->pic_3->setPixmap(QPixmap(":/images/vegetable_stew.jpg"));
    ui->t3->setText(dishes[2].getName());
    ui->properties_3->setText("Килокалорий в 100гр продукта " + QString::number(dishes[2].getCcal() / 10));
    ui->label_5->setText("Белки: " + QString::number(dishes[2].getProtein()) + " " + "Жиры: " + QString::number(dishes[2].getFats()) + " " + "Углеводы: " + QString::number(dishes[2].getCarbohydrates()));


    ui->pic_4->setPixmap(QPixmap(":/images/Olivie.jpg"));
    ui->t4->setText(dishes[3].getName());
    ui->properties_4->setText("Килокалорий в 100гр продукта " + QString::number(dishes[3].getCcal() / 10));
    ui->label_6->setText("Белки: " + QString::number(dishes[3].getProtein()) + " " + "Жиры: " + QString::number(dishes[3].getFats()) + " " + "Углеводы: " + QString::number(dishes[3].getCarbohydrates()));

  auto wrapper = new QVBoxLayout;
  ui->widget->setLayout(wrapper);

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
                          for(int i = 0; i < ingredients.length(); i++){
                              if(ingredients[i].getId() == result.toInt()){
                                  new_dish.setProtein(ingredients[i].getProtein());
                                  new_dish.setFats(ingredients[i].getFats());
                                  new_dish.setCarbohydrates(ingredients[i].getCarbohydrates());
                              }
                          }
                          str.remove(0, index + 1);
            new_dish.setIndeWeights(str.toInt());

            //поиск калории
            for(int i = 0; i < ingredients.length(); i++){
                if(ingredients[i].getId() == result.toInt()){
                    new_dish.setIndeCcal(ingredients[i].getCcal(), result.toInt());
                }
            }

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
    wastedCheck();

//    if(ui->PP->checkState() == Qt::Checked){
//        for (int i = 0; i < results.length(); i++) {
//            if(results[i].getName() == "Борщ" || results[i].getName() == "Мясо по-французки" || results[i].getName() == "Оливье"){
//                results.remove(i);
//            }
//        }
//    }


//    window->setResults(results);

}

void MainWindow::on_commandLinkButton_clicked(){
    auto window = new window2;
    window->broadcast(1, dishes);
    window->show();
}

void MainWindow::on_commandLinkButton_2_clicked(){
    auto window = new window2;
    window->broadcast(2, dishes);
    window->show();
}

void MainWindow::on_commandLinkButton_3_clicked(){
    auto window = new window2;
    window->broadcast(3, dishes);
    window->show();
}

void MainWindow::on_commandLinkButton_4_clicked(){
    auto window = new window2;
    window->broadcast(4, dishes);
    window->show();
}

void MainWindow::wastedCheck(){
    ui->frame->setEnabled(true);
    ui->frame_2->setEnabled(true);
    ui->frame_3->setEnabled(true);
    ui->frame_4->setEnabled(true);
    if(ui->PP->checkState() == Qt::Checked){
        ui->frame->setEnabled(false);
        ui->frame_2->setEnabled(false);
        ui->frame_3->setEnabled(true);
        ui->frame_4->setEnabled(false);
    }
    if(results[0].getPercent() < 65) ui->frame->setEnabled(false);
    if(results[1].getPercent() < 65) ui->frame_2->setEnabled(false);
    if(results[2].getPercent() < 65) ui->frame_3->setEnabled(false);
    if(results[3].getPercent() < 65) ui->frame_4->setEnabled(false);

    for(int i = 0; i < results.length(); i++){
        results[i].setPercent(0);
    }
}
