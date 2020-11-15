#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ingredient.h"
#include "dish.h"
#include "sample.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;

public:
    MainWindow(QWidget *parent = nullptr);

    QVector<ingredient> ingredients;
    QVector<dish> dishes;
    QVector<Sample> results;

    void checkCheckBox(int *);
    void creatIngredientBD();
    void creatDishBD();
    void searchDish(int *);

    ~MainWindow();

private slots:
    void on_pushButton_clicked();

};
#endif // MAINWINDOW_H
