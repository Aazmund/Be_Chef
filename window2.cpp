#include "window2.h"
#include "ui_window2.h"

#include <QVBoxLayout>

window2::window2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::window2)
{
    ui->setupUi(this);
}

window2::~window2()
{
    delete ui;
}

void window2::setResults(QVector<Sample> vector){

    auto layout = new QVBoxLayout;

    for(int i = 0; i < vector.length(); i++){



    }
}
    void window2::broadcast(int id, QVector<dish> dishes){
        switch (id) {
        case 1:
            ui->label->setPixmap(QPixmap(":/images/borscht.jpg"));
            ui->label_2->setText(dishes[0].getName());
            ui->label_3->setText(QString::number(dishes[0].getCcal() / 10));
            break;
        case 2:
            ui->label->setPixmap(QPixmap(":/images/myaso-po-francuzski.jpg"));
            ui->label_2->setText(dishes[1].getName());
            ui->label_3->setText(QString::number(dishes[1].getCcal() / 10));
            break;
        case 3:
            ui->label->setPixmap(QPixmap(":/images/vegetable_stew.jpg"));
            ui->label_2->setText(dishes[2].getName());
            ui->label_3->setText(QString::number(dishes[2].getCcal() / 10));
            break;
        case 4:
            ui->label->setPixmap(QPixmap(":/images/Olivie.jpg"));
            ui->label_2->setText(dishes[3].getName());
            ui->label_3->setText(QString::number(dishes[3].getCcal() / 10));
            break;
        }
}
