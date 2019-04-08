#ifndef VIEWANIMALDIALOG_H
#define VIEWANIMALDIALOG_H

#include <QDialog>
#include "animal.h"
#include "control.h"


namespace Ui {
class ViewAnimalDialog;
}

class ViewAnimalDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ViewAnimalDialog(QWidget *parent = 0);
    ~ViewAnimalDialog();
    void loadData(Animal*);
    void resetLabels();
    Animal* a;
    Control* control;

private slots:
    void on_update_button_clicked();

private:
    Ui::ViewAnimalDialog *ui;

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



};

#endif // VIEWANIMALDIALOG_H
