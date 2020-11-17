#ifndef WINDOW2_H
#define WINDOW2_H

#include <QVector>
#include <QWidget>
#include <sample.h>
#include <dish.h>
namespace Ui {
class window2;
}

class window2 : public QWidget
{
    Q_OBJECT

public:
    explicit window2(QWidget *parent = nullptr);
    ~window2();
    void setResults(QVector<Sample>);

    void broadcast(int, QVector<dish>);

private:
    Ui::window2 *ui;
};

#endif // WINDOW2_H
