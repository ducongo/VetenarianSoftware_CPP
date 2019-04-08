#include "addanimaldialog.h"
#include "ui_addanimaldialog.h"
#include "animal.h"
#include <exception>


AddAnimalDialog::AddAnimalDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddAnimalDialog)
{
    ui->setupUi(this);

    //temoraryString = *(control->energy_level);



    addComBoxItems(ui->specie, specie, 5);
    ui->specie->setCurrentIndex(0);
    addComBoxItems(ui->breed, breed[0], 5);
    ui->breed->setCurrentIndex(0);

    addComBoxItems(ui->special_skill, special_skill, 5);
    addComBoxItems(ui->energy_level, energy_level, 3);
    addComBoxItems(ui->kid_friendly, kid_friendly, 3);
    addComBoxItems(ui->level_of_dependecy, level_of_dependency, 3);
    addComBoxItems(ui->prone_to_disease, prone_to_disease, 3);
    addComBoxItems(ui->living_space_needed, living_space_needed, 3);
    addComBoxItems(ui->feeding_cost, feeding_cost, 3);
    addComBoxItems(ui->climate, climate, 3);
    addComBoxItems(ui->level_of_care, level_of_care_needed, 3);
    addComBoxItems(ui->neatness, neatness, 3);
    addComBoxItems(ui->current_health_condition, current_health_condition, 3);
    addComBoxItems(ui->intelligence_level, intelligence_level, 3);
    addComBoxItems(ui->difficulty_to_train, difficulty_to_train, 3);
    addComBoxItems(ui->noise_level, noise_level, 3);
    addComBoxItems(ui->temperament, temperament, 3);
    addComBoxItems(ui->bad_habits, bad_habits, 3);

    qDebug("SIZING   RUNNING ADD ANIMALLLLLL %d", sizeof(control->bad_habits)/sizeof(control->bad_habits[0]));

}

AddAnimalDialog::~AddAnimalDialog()
{
    delete ui;
}
void AddAnimalDialog::addComBoxItems(QComboBox* b, QString s[], int size){
    //qDebug("PREVIOUS   RUNNING ADD ANIMALLLLLL %c", *(items));
    b->clear();
    for (int i = 0; i < size; i++){
        b->addItem(s[i]);
    }

   b->setCurrentIndex(1);

}

void AddAnimalDialog::on_pushButton_clicked()
{

    Animal *a = new Animal((ui->name->text()).toStdString()
                           , (ui->specie->currentText()).toStdString()
                           , (ui->breed->currentText()).toStdString()
                           , (ui->age->text()).toInt()
                           , (ui->weight->text()).toInt()
                           , (ui->height->text()).toInt()
                           , (ui->colour->text()).toStdString()
                           , (ui->special_skill->currentIndex()) + 1
                           , (ui->energy_level->currentIndex()) + 1
                           , (ui->kid_friendly->currentIndex()) + 1
                           , (ui->level_of_dependecy->currentIndex()) + 1
                           , (ui->prone_to_disease->currentIndex()) + 1
                           , (ui->living_space_needed->currentIndex()) + 1
                           , (ui->feeding_cost->currentIndex()) + 1
                           , (ui->climate->currentIndex()) + 1
                           , (ui->level_of_care->currentIndex()) + 1
                           , (ui->neatness->currentIndex()) + 1
                           , (ui->current_health_condition->currentIndex()) + 1
                           , (ui->intelligence_level->currentIndex()) + 1
                           , (ui->difficulty_to_train->currentIndex()) + 1
                           , (ui->noise_level->currentIndex()) + 1
                           , (ui->temperament->currentIndex()) + 1
                           , (ui->bad_habits->currentIndex()) + 1
                           , control->getAnimalArraySize() + 1);

    control->addAnimal(a);

    //animals->add(a);
    control->getHomeView()->loadData();

    AddAnimalDialog::close();
}






void AddAnimalDialog::on_specie_currentIndexChanged(int index)
{
    if (index == 0){
        addComBoxItems(ui->breed, breed[0], 5);
    }else if (index == 1){
        addComBoxItems(ui->breed, breed[1], 5);
    }else if (index == 2){
        addComBoxItems(ui->breed, breed[2], 5);
    }else if (index == 3){
        addComBoxItems(ui->breed, breed[3], 5);
    }else if (index == 4){
        addComBoxItems(ui->breed, breed[4], 5);
    }

    ui->breed->setCurrentIndex(0);
}
