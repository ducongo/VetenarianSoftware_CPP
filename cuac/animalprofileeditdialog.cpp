#include "animalprofileeditdialog.h"
#include "ui_animalprofileeditdialog.h"

AnimalProfileEditDialog::AnimalProfileEditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnimalProfileEditDialog)
{
    ui->setupUi(this);
//    addComBoxItems(ui->specie, specie, 5);
//    ui->specie->setCurrentIndex(0);
//    addComBoxItems(ui->breed, breed[0], 5);
//    ui->breed->setCurrentIndex(0);

//    addComBoxItems(ui->special_skill, special_skill, 5);
//    addComBoxItems(ui->energy_level, energy_level, 3);
//    addComBoxItems(ui->kid_friendly, kid_friendly, 3);
//    addComBoxItems(ui->level_of_dependecy, level_of_dependency, 3);
//    addComBoxItems(ui->prone_to_disease, prone_to_disease, 3);
//    addComBoxItems(ui->living_space_needed, living_space_needed, 3);
//    addComBoxItems(ui->feeding_cost, feeding_cost, 3);
//    addComBoxItems(ui->climate, climate, 3);
//    addComBoxItems(ui->level_of_care, level_of_care_needed, 3);
//    addComBoxItems(ui->neatness, neatness, 3);
//    addComBoxItems(ui->current_health_condition, current_health_condition, 3);
//    addComBoxItems(ui->intelligence_level, intelligence_level, 3);
//    addComBoxItems(ui->difficulty_to_train, difficulty_to_train, 3);
//    addComBoxItems(ui->noise_level, noise_level, 3);
//    addComBoxItems(ui->temperament, temperament, 3);
//    addComBoxItems(ui->bad_habits, bad_habits, 3);

}

AnimalProfileEditDialog::~AnimalProfileEditDialog()
{
    delete ui;
}

void AnimalProfileEditDialog::addComBoxItems(QComboBox* b, QString s[], int size, int index){
    //qDebug("PREVIOUS   RUNNING ADD ANIMALLLLLL %c", *(items));
    b->clear();
    for (int i = 0; i < size; i++){
    b->addItem(s[i]);
   }

   b->setCurrentIndex(index);

}
void AnimalProfileEditDialog:: loadData(Animal* a){
    animal = a;
    int x;
    int y;
    bool foundX = false;
    bool foundY = false;

    for(int i = 0; i < 5; i++){
        if (!foundX){
            if (specie[i] == QString::fromStdString(a->getSpecies())){
                x = i;
                foundX = true;
            }
        }

        if (!foundY){
            for (int j = 0; j < 5; j++){
                if (breed[j] == QString::fromStdString(a->getBreed())){
                    y = j;
                    foundY = true;
                }
            }
        }
    }
    ui->name->setText(ui->name->text().append(QString::fromStdString(animal->getName())));
    ui->colour->setText(ui->colour->text().append(QString::fromStdString(animal->getColour())));


    ui->age->setValue(animal->getAge());
    ui->weight->setValue(animal->getWeight());
    ui->height->setValue(animal->getHeight());

    addComBoxItems(ui->specie, specie, 5, x);

    addComBoxItems(ui->breed, breed[x], 5, y);


    addComBoxItems(ui->special_skill, special_skill, 5, animal->getSkill() - 1);
    addComBoxItems(ui->energy_level, energy_level, 3, animal->getEnergy_level() - 1);
    addComBoxItems(ui->kid_friendly, kid_friendly, 3, animal->getKid_friendly() - 1);
    addComBoxItems(ui->level_of_dependecy, level_of_dependency, 3, animal->getLevel_of_dependency() - 1);
    addComBoxItems(ui->prone_to_disease, prone_to_disease, 3, animal->getProne_to_disease() - 1);
    addComBoxItems(ui->living_space_needed, living_space_needed, 3, animal->getLiving_space() - 1);
    addComBoxItems(ui->feeding_cost, feeding_cost, 3, animal->getFeeding_cost() - 1);
    addComBoxItems(ui->climate, climate, 3, animal->getClimate() - 1);
    addComBoxItems(ui->level_of_care, level_of_care_needed, 3, animal->getLevel_of_care() - 1);
    addComBoxItems(ui->neatness, neatness, 3, animal->getNeatness() - 1);
    addComBoxItems(ui->current_health_condition, current_health_condition, 3, animal->getCurrent_health_condition() - 1);
    addComBoxItems(ui->intelligence_level, intelligence_level, 3, animal->getIntelligence_level() - 1);
    addComBoxItems(ui->difficulty_to_train, difficulty_to_train, 3, animal->getDifficulty_to_train() - 1);
    addComBoxItems(ui->noise_level, noise_level, 3, animal->getNoise_level() - 1);
    addComBoxItems(ui->temperament, temperament, 3, animal->getTemperament() - 1);
    addComBoxItems(ui->bad_habits, bad_habits, 3, animal->getBad_habits() - 1);
}

void AnimalProfileEditDialog::on_pushButton_clicked()
{
    AnimalProfileEditDialog::close();
}



void AnimalProfileEditDialog::on_update_clicked()
{
    animal->setName((ui->name->text()).toStdString());
    animal->setSpecies((ui->specie->currentText()).toStdString());
    animal->setBreed((ui->breed->currentText()).toStdString());

    animal->setAge((ui->age->text()).toInt());
    animal->setWeight((ui->weight->text()).toInt());
    animal->setHeight((ui->height->text()).toInt());

    animal->setEnergy_level(ui->energy_level->currentIndex() + 1);
    animal->setKid_friendly(ui->kid_friendly->currentIndex() + 1);
    animal->setLevel_of_dependency(ui->level_of_dependecy->currentIndex() + 1);
    animal->setProne_to_disease(ui->prone_to_disease->currentIndex() + 1);
    animal->setLiving_space(ui->living_space_needed->currentIndex() + 1);
    animal->setFeeding_cost(ui->feeding_cost->currentIndex() + 1);
    animal->setClimate(ui->climate->currentIndex() + 1);
    animal->setLevel_of_care(ui->level_of_care->currentIndex() + 1);
    animal->setNeatness(ui->neatness->currentIndex() + 1);
    animal->setCurrent_health_condition(ui->current_health_condition->currentIndex() + 1);
    animal->setIntelligence_level(ui->intelligence_level->currentIndex() + 1);
    animal->setDifficulty_to_train(ui->difficulty_to_train->currentIndex() + 1);
    animal->setNoise_level(ui->noise_level->currentIndex() + 1);
    animal->setTemperament(ui->temperament->currentIndex() + 1);
    animal->setBad_habits(ui->bad_habits->currentIndex() + 1);

    animal->setColour((ui->colour->text()).toStdString());
    animal->setSkill(ui->special_skill->currentIndex() + 1);

    control->updateAnimal(animal);
    AnimalProfileEditDialog::close();
}

void AnimalProfileEditDialog::on_specie_currentIndexChanged(int index)
{
    if (index == 0){
        addComBoxItems(ui->breed, breed[0], 5, 1);
    }else if (index == 1){
        addComBoxItems(ui->breed, breed[1], 5, 1);
    }else if (index == 2){
        addComBoxItems(ui->breed, breed[2], 5, 1);
    }else if (index == 3){
        addComBoxItems(ui->breed, breed[3], 5, 1);
    }else if (index == 4){
        addComBoxItems(ui->breed, breed[4], 5, 1);
    }

    ui->breed->setCurrentIndex(0);
}
