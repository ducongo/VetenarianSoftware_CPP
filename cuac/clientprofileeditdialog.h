#ifndef CLIENTPROFILEEDITDIALOG_H
#define CLIENTPROFILEEDITDIALOG_H

#include <QDialog>
#include "client.h"
#include "control.h"
#include <QComboBox>


namespace Ui {
class ClientProfileEditDialog;
}

class ClientProfileEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ClientProfileEditDialog(QWidget *parent = 0);
    ~ClientProfileEditDialog();
    Control* control;
    Client* client;
    void loadData(Client*);


private slots:
    void on_specie_valueChanged(int arg1);

    void on_pushButton_clicked();

    void on_update_clicked();

private:
    Ui::ClientProfileEditDialog *ui;
    void addComBoxItems(QComboBox* b, QString[], int, int);
    QString special_skill[5] = {"Seeing eye", "Drug sniffing", "Hunting", "Security", "Showing"};
    QString specie[5] = {"Dog", "Cat", "Bird", "Bear", "Fish"};
    QString breed[5][5] = {{"Black Labrador","German Shepherd","Corgi","Shiba",""}, {"Calico","Lion","Tiger","Leopard","Panther"}, {"Parrot","Flamingo","Eagle","Vukture","Raven"}, {"Grizzly","Polar","Black","Panda","Koala"}, {"Goldfish","Carp","Koi","Dwarf Lanternshark","Sea Horse"}};

    QString economic_background[3] = {"Upper class", "Middle class", "Lower Class"};
    QString activity_level[3] = {"Extremely active", "Average runner", "Lazy"};
    QString experience_with_animal[3] = {"Previous owner", "New pet owner", "Animal handler"};
    QString level_of_patience[3] = {"Short tempered", "impatient", "Patient"};
    QString house_size[3] = {"Apartment", "House with yeard", "Ranch/Farm"};
    QString available_time[3] = {"30 minutes", "30 mins - 2 hours", "2 hours or more"};
    QString strength[3] = {"Powerlifter", "Average joe", "Weak"};
};

#endif // CLIENTPROFILEEDITDIALOG_H
