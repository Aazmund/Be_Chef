#include "window2.h"
#include "ui_window2.h"

#include <QFile>
#include <QIcon>
#include <QVBoxLayout>

window2::window2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::window2)
{
    ui->setupUi(this);
    this->setWindowTitle("Рецепт");
    this->setWindowIcon(QIcon(":/images/logo.ico"));
}

window2::~window2()
{
    delete ui;
}

void window2::broadcast(int id, QVector<dish> dishes){

    QFile file(":/recipes.txt");
    file.open(QIODevice::ReadOnly);
    QString param1, param2, param3, param4;

    QString str = file.readAll();

    int d = 1;
    for(int i = 0; i < str.length(); i++){
        switch (d) {
        case 1: if(str[i] == "@") d++;
                 else param1 += str[i];
                 break;
        case 2: if(str[i] == "@") d++;
                else param2 += str[i];
                break;
        case 3: if(str[i] == "@") d++;
                else param3 += str[i];
                break;
        case 4: if(str[i] == "@") d++;
                else param4 += str[i];
                break;
        default:break;
        }
    }

    switch (id) {
    case 1:
        ui->label->setPixmap(QPixmap(":/images/borscht.jpg"));
        ui->label_2->setText(dishes[0].getName());
        ui->label_3->setText("Килокалорий в 100гр продукта: " + QString::number(dishes[0].getCcal() / 10));
        ui->label_4->setText("Белки: " + QString::number(dishes[0].getProtein()) + " " + "Жиры: " + QString::number(dishes[0].getFats()) + " " + "Углеводы: " + QString::number(dishes[0].getCarbohydrates()));
        ui->label_5->setText(param1);
        break;
    case 2:
        ui->label->setPixmap(QPixmap(":/images/myaso-po-francuzski.jpg"));
        ui->label_2->setText(dishes[1].getName());
        ui->label_3->setText("Килокалорий в 100гр продукта: " + QString::number(dishes[1].getCcal() / 10));
        ui->label_4->setText("Белки: " + QString::number(dishes[1].getProtein()) + " " + "Жиры: " + QString::number(dishes[1].getFats()) + " " + "Углеводы: " + QString::number(dishes[1].getCarbohydrates()));
        ui->label_5->setText(param2);
        break;
    case 3:
        ui->label->setPixmap(QPixmap(":/images/vegetable_stew.jpg"));
        ui->label_2->setText(dishes[2].getName());
        ui->label_3->setText("Килокалорий в 100гр продукта: " + QString::number(dishes[2].getCcal() / 10));
        ui->label_4->setText("Белки: " + QString::number(dishes[2].getProtein()) + " " + "Жиры: " + QString::number(dishes[2].getFats()) + " " + "Углеводы: " + QString::number(dishes[2].getCarbohydrates()));
        ui->label_5->setText(param3);
        break;
    case 4:
        ui->label->setPixmap(QPixmap(":/images/Olivie.jpg"));
        ui->label_2->setText(dishes[3].getName());
        ui->label_3->setText("Килокалорий в 100гр продукта: " + QString::number(dishes[3].getCcal() / 10));
        ui->label_4->setText("Белки: " + QString::number(dishes[3].getProtein()) + " " + "Жиры: " + QString::number(dishes[3].getFats()) + " " + "Углеводы: " + QString::number(dishes[3].getCarbohydrates()));
        ui->label_5->setText(param4);
        break;
    }

}
