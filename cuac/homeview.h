#ifndef HOMEVIEW_H
#define HOMEVIEW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include "animal.h"
#include "client.h"
#include "array.h"
#include "database.h"
#include "control.h"

namespace Ui {
class HomeView;
}

class HomeView : public QMainWindow
{
    Q_OBJECT

public:
    explicit HomeView(QWidget *parent = 0);
    ~HomeView();
    Control* control;
    int is_staff_member = 0;
    void loadArrays();
    void loadData();
    void loginPrompt();

private slots:
    void on_runACMButton_clicked();

    void on_listWidgetAnimal_itemDoubleClicked(QListWidgetItem *item);

    void on_listWidgetClient_itemDoubleClicked(QListWidgetItem *item);

    void on_addAnimal_clicked();

    void on_addClient_clicked();

    void on_pushButton_clicked();

private:
    Ui::HomeView *ui;
};

#endif // HOMEVIEW_H
