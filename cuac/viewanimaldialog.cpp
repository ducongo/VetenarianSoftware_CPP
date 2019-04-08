#include "viewanimaldialog.h"
#include "ui_viewanimaldialog.h"
#include "animal.h"
#include "animalprofileeditdialog.h"
#include "erroruserdialog.h"

ViewAnimalDialog::ViewAnimalDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewAnimalDialog)
{
    ui->setupUi(this);
    ui->image->setStyleSheet("background-image: url(:/img/images/pet.png)");
}

ViewAnimalDialog::~ViewAnimalDialog()
{
    delete ui;
}

void ViewAnimalDialog::loadData(Animal* animal){

    a = animal;
    resetLabels();

    ui->name->setText(ui->name->text().append(QString::fromStdString(animal->getName())));
    ui->specie->setText(ui->specie->text().append(QString::fromStdString(animal->getSpecies())));
    ui->breed->setText(ui->breed->text().append(QString::fromStdString(animal->getBreed())));
    ui->colour->setText(ui->colour->text().append(QString::fromStdString(animal->getColour())));
    ui->special_skill->setText(ui->special_skill->text().append(special_skill[animal->getSkill() - 1]));
    ui->age->setText(ui->age->text().append(QString::number(animal->getAge())));
    ui->weight->setText(ui->weight->text().append(QString::number(animal->getWeight())));
    ui->height->setText(ui->height->text().append(QString::number(animal->getHeight())));
    ui->energy_level->setText(ui->energy_level->text().append(energy_level[animal->getEnergy_level() - 1]));
    ui->temperament->setText(ui->temperament->text().append(temperament[animal->getTemperament() - 1]));
    ui->kid_friendly->setText(ui->kid_friendly->text().append(kid_friendly[animal->getKid_friendly() - 1]));
    ui->level_of_dependency->setText(ui->level_of_dependency->text().append(level_of_dependency[animal->getLevel_of_dependency() - 1]));
    ui->prone_to_disease->setText(ui->prone_to_disease->text().append(prone_to_disease[animal->getProne_to_disease() - 1]));
    ui->living_space_needed->setText(ui->living_space_needed->text().append(living_space_needed[animal->getLiving_space() - 1]));
    ui->feeding_cost->setText(ui->feeding_cost->text().append(feeding_cost[animal->getFeeding_cost() - 1]));
    ui->bad_habits->setText(ui->bad_habits->text().append(bad_habits[animal->getBad_habits() - 1]));
    ui->climate->setText(ui->climate->text().append(climate[animal->getClimate()-1]));
    ui->level_of_care_needed->setText(ui->level_of_care_needed->text().append(level_of_care_needed[animal->getLevel_of_care() - 1]));
    ui->neatness->setText(ui->neatness->text().append(neatness[animal->getNeatness() - 1]));
    ui->current_health_condition->setText(ui->current_health_condition->text().append(current_health_condition[animal->getCurrent_health_condition() - 1]));
    ui->intelligence_level->setText(ui->intelligence_level->text().append(intelligence_level[animal->getIntelligence_level() - 1]));
    ui->difficulty_to_train->setText(ui->difficulty_to_train->text().append(difficulty_to_train[animal->getDifficulty_to_train() -1]));
    ui->noise_level->setText(ui->noise_level->text().append(noise_level[animal->getNoise_level()-1]));
    qDebug("Noise LEVELLLLLLLLLLLL: %d", animal->getNoise_level());


}

void ViewAnimalDialog::resetLabels(){

    ui->name->setText("Name: ");
    ui->specie->setText("Specie: ");
    ui->breed->setText("Breed: ");
    ui->colour->setText("Colour: ");
    ui->special_skill->setText("Special skill: ");
    ui->age->setText("Age: ");
    ui->weight->setText("Weight: ");
    ui->height->setText("Height: ");
    ui->energy_level->setText("Energy Level: ");
    ui->temperament->setText("Temperament: ");
    ui->kid_friendly->setText("Kid Friendly: ");
    ui->level_of_dependency->setText("Level of Dependency: ");
    ui->prone_to_disease->setText("Prone to Disease: ");
    ui->living_space_needed->setText("House size: ");
    ui->feeding_cost->setText("Feeding Cost: ");
    ui->bad_habits->setText("Bad Habits: ");
    ui->climate->setText("Climate: ");
    ui->level_of_care_needed->setText("Level of Care Needed: ");
    ui->neatness->setText("Neatness: ");
    ui->current_health_condition->setText("Current Health Condition: ");
    ui->intelligence_level->setText("Intellihence Level: ");
    ui->difficulty_to_train->setText("Difficulty to Train: ");
    ui->noise_level->setText("Noise Level: ");

}

void ViewAnimalDialog::on_update_button_clicked()
{

    if (control->getCurrentUID() == 0){
        AnimalProfileEditDialog d;
        d.animal = a;
        d.control = control;
        d.loadData(a);
        d.setModal(true);
        d.exec();
        qDebug("WE RETURNING TO THE CALLING DIALOG");

        resetLabels();
        loadData(a);
    }else{

        ErrorUserDialog e;
        e.setText("You can't modify other clients profiles!");
        e.setModal(true);
        e.exec();
    }


}
