#include "animalprofiledialog.h"
#include "ui_animalprofiledialog.h"
#include <string>

AnimalProfileDialog::AnimalProfileDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnimalProfileDialog)
{
    qDebug("Called Function SETUPPPPPPP");

//    qDebug("NAME OF ANIMAL: %s", animal->getName());
//    ui->setupUi(this);
//    ui->name->setText(QString::fromStdString(animal->getName()));
//    ui->specie->setText(QString::fromStdString(animal->getSpecies()));
//    ui->breed->setText(QString::fromStdString(animal->getBreed()));
//    ui->age->setText(QString::fromStdString(std::to_string(animal->getAge())));
//    ui->weight->setText(QString::fromStdString(std::to_string(animal->getWeight())));
//    ui->height->setText(QString::fromStdString(std::to_string(animal->getHeight())));
//    ui->colour->setText(QString::fromStdString(animal->getColour()));
//    ui->special_skill->setText(QString::fromStdString(animal->getSkill()));
    //std::to_string()
//    ui->name->setText(ui->name->text().append(QString::fromStdString(animal->getName())));
//    ui->specie->setText(ui->specie->text().append(QString::fromStdString(animal->getSpecies())));
//    ui->breed->setText(ui->breed->text().append(QString::fromStdString(animal->getBreed())));
//    ui->colour->setText(ui->colour->text().append(QString::fromStdString(animal->getColour())));
//    ui->special_skill->setText(ui->special_skill->text().append(QString::number(animal->getSkill())));
//    ui->age->setText(ui->age->text().append(QString::number(animal->getAge())));
//    ui->weight->setText(ui->weight->text().append(QString::number(animal->getWeight())));
//    ui->height->setText(ui->height->text().append(QString::number(animal->getHeight())));
//    ui->energy_level->setText(ui->energy_level->text().append(QString::number(animal->getEnergy_level())));
//    ui->temperament->setText(ui->temperament->text().append(QString::number(animal->getTemperament())));
//    ui->kid_friendly->setText(ui->kid_friendly->text().append(QString::number(animal->getKid_friendly())));
//    ui->level_of_dependency->setText(ui->level_of_dependency->text().append(QString::number(animal->getLevel_of_dependency())));
//    ui->prone_to_disease->setText(ui->prone_to_disease->text().append(QString::number(animal->getProne_to_disease())));
//    ui->living_space_needed->setText(ui->living_space_needed->text().append(QString::number(animal->getLiving_space())));
//    ui->feeding_cost->setText(ui->feeding_cost->text().append(QString::number(animal->getFeeding_cost())));
//    ui->bad_habits->setText(ui->bad_habits->text().append(QString::number(animal->getBad_habits())));
//    ui->climate->setText(ui->climate->text().append(QString::number(animal->getClimate())));
//    ui->level_of_care_needed->setText(ui->level_of_care_needed->text().append(QString::number(animal->getLevel_of_care())));
//    ui->neatness->setText(ui->neatness->text().append(QString::number(animal->getNeatness())));
//    ui->current_health_condition->setText(ui->current_health_condition->text().append(QString::number(animal->getCurrent_health_condition())));
//    ui->intelligence_level->setText(ui->intelligence_level->text().append(QString::number(animal->getIntelligence_level())));
//    ui->difficulty_to_train->setText(ui->difficulty_to_train->text().append(QString::number(animal->getDifficulty_to_train())));
//    ui->noise_level->setText(ui->noise_level->text().append(QString::number(animal->getNoise_level())));


}

AnimalProfileDialog::~AnimalProfileDialog()
{
    delete ui;
}
