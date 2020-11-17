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
    void setAll();


    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_commandLinkButton_clicked();
    void on_commandLinkButton_2_clicked();
    void on_commandLinkButton_3_clicked();
    void on_commandLinkButton_4_clicked();
};
#endif // MAINWINDOW_H
