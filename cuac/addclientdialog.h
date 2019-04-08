#ifndef ADDCLIENTDIALOG_H
#define ADDCLIENTDIALOG_H

#include <QDialog>
#include "client.h"
#include "array.h"
#include "homeview.h"
#include "database.h"
#include <QComboBox>

namespace Ui {
class AddClientDialog;
}

class AddClientDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddClientDialog(QWidget *parent = 0);
    ~AddClientDialog();
    Control* control;


private slots:
    void on_pushButton_clicked();

    void on_specie_valueChanged(int arg1);

    void on_breed_currentIndexChanged(int index);

    void on_specie_currentIndexChanged(int index);

private:
    Ui::AddClientDialog *ui;

    void addComBoxItems(QComboBox*, QString[], int);
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

#endif // ADDCLIENTDIALOG_H
