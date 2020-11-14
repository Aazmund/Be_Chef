#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"

#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
        id_arr[5] = 8;
    }
    if(ui->checkBox_7->checkState() == Qt::Checked){
        id_arr[6] = 6;
    }
    if(ui->checkBox_8->checkState() == Qt::Checked){
        id_arr[7] = 7;
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

void MainWindow::creatIngredientVector(){
    QFile file("/Users/alex_su/QTprj/Be_Chef/ingredient.txt");
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

void MainWindow::on_pushButton_clicked()
{
    int id_arr[18];
    checkCheckBox(id_arr);
    creatIngredientVector();
}
