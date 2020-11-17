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
