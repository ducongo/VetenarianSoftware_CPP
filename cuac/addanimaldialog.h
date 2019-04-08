#ifndef ADDANIMALDIALOG_H
#define ADDANIMALDIALOG_H

#include <QDialog>
#include "animal.h"
#include "array.h"
#include "homeview.h"
#include "database.h"
#include <QComboBox>

namespace Ui {
class AddAnimalDialog;
}

class AddAnimalDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddAnimalDialog(QWidget *parent = 0);
    ~AddAnimalDialog();
    Control* control;



private slots:
    void on_pushButton_clicked();

    void on_specie_currentIndexChanged(int index);

private:
    Ui::AddAnimalDialog *ui;
    void addComBoxItems(QComboBox*, QString[], int);

    QString energy_level[3] = {"Low", "Mwdium", "High"};
    QString temperament[3] = {"Easily excitable", "Average", "Very Relazed"};
    QString kid_friendly[3] = {"Impatient", "Moderate", "Patient"};
    QString level_of_dependency[3] = {"Under 30 minutes", "30 minutes to 2 hours", "3+ daily hours"};
    QString prone_to_disease[3] = {"Rare immune disorder", "Bad genetics", "Not prone"};
    QString living_space_needed[3] = {"Apartment", "House with yard", "Ranch"};//"Abused", "Badly Trained", "Loved"
    QString feeding_cost[3] = {"Expensive($100+)", "Moderate($500)", "Cheap(under $50)"};
    QString bad_habits[3] = {"Trouble-maker", "Annoying", "Well behaved"};
    QString climate[3] = {"Cold weather", "Moderate weather", "Tropical weather"};
    QString level_of_care_needed[3] = {"Intense grooming and medical", "Frequent grooming", "Rare grooming"};
    QString neatness[3] = {"Filthy", "Neat", "Very Clean"};
    QString current_health_condition[3] = {"Fighting disease", "Weakened immune system", "Healthy"};
    QString intelligence_level[3] = {"Stupid", "Average", "Exceptional"};
    QString difficulty_to_train[3] = {"Defiant", "Challenging", "Easy"};
    QString noise_level[3] = {"Noisy(100+ db)", "Moderate(80-100db)", "Quiet(under 80db)"};
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

#endif // ADDANIMALDIALOG_H
