#include "clientprofileeditdialog.h"
#include "ui_clientprofileeditdialog.h"

ClientProfileEditDialog::ClientProfileEditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientProfileEditDialog)
{
    ui->setupUi(this);
    ui->home_phone->setValidator(new QIntValidator(0, 999999999, this));
    ui->cell_phone->setValidator(new QIntValidator(0, 999999999, this));
}

ClientProfileEditDialog::~ClientProfileEditDialog()
{
    delete ui;
}

void ClientProfileEditDialog::on_specie_valueChanged(int arg1)
{
    ui->breed->clear();
    if (arg1 == 1){
        ui->breed->addItem("Black Labrador");
        ui->breed->addItem("German Shepherd");
        ui->breed->addItem("Corgi");
        ui->breed->addItem("Shiba Inu");
        ui->breed->addItem("Bulldog");
    }else if (arg1 == 2){
        ui->breed->addItem("Calico");
        ui->breed->addItem("Lion");
        ui->breed->addItem("Tiger");
        ui->breed->addItem("Leopard");
        ui->breed->addItem("Panther");
    }else if (arg1 == 3){
        ui->breed->addItem("Parrot");
        ui->breed->addItem("Flamingo");
        ui->breed->addItem("Eagle");
        ui->breed->addItem("Vulture");
        ui->breed->addItem("Raven");
    }else if (arg1 == 4){
        ui->breed->addItem("Grizzly");
        ui->breed->addItem("Polar");
        ui->breed->addItem("Black");
        ui->breed->addItem("Black");
        ui->breed->addItem("Koala");
    }else if (arg1 == 5){
        ui->breed->addItem("Goldish");
        ui->breed->addItem("Carp");
        ui->breed->addItem("Koi");
        ui->breed->addItem("Dwarf Lanternshark");
        ui->breed->addItem("Sea horse");
    }
}

void ClientProfileEditDialog::loadData(Client* c){
    client = c;

    int x;
    int y;
    bool foundX = false;
    bool foundY = false;

    for(int i = 0; i < 5; i++){
        if (!foundX){
            if (specie[i] == QString::fromStdString(c->getAnimal())){
                x = i;
                foundX = true;
            }
        }

        if (!foundY){
            for (int j = 0; j < 5; j++){
                if (breed[j] == QString::fromStdString(c->getBreed())){
                    x = i;
                    foundY = true;
                    addComBoxItems(ui->specie, specie, 5, x);
                    addComBoxItems(ui->breed, breed[x], 5, y);

                }
            }
        }
    }




    ui->name->setText(QString::fromStdString(client->getName()));
    ui->email->setText(QString::fromStdString(client->getEmail()));
    ui->address->setText(QString::fromStdString(client->getAddress()));
    ui->age->setValue(client->getAge());
    ui->gender->setValue(client->getGender());
    ui->cell_phone->setText(QString::number(client->getCellPhone()));
    ui->home_phone->setText(QString::number(client->getHomePhone()));

    addComBoxItems(ui->economic_background, economic_background, 3, (client->getEconomicBackground())-1);
    addComBoxItems(ui->activity_level, activity_level, 3, (client->getActivityLevel())-1);
    addComBoxItems(ui->experience_with_animals, experience_with_animal, 3, (client->getExperienceWithAnimals())-1);
    addComBoxItems(ui->level_of_patience, level_of_patience, 3, (client->getLevelOfPatience())-1);
    addComBoxItems(ui->house_size, house_size, 3, (client->getHouseSize())-1);
    addComBoxItems(ui->available_time, available_time, 3, (client->getAvailableTime())-1);
    addComBoxItems(ui->strength, strength, 3, (client->getStrength())-1);
    addComBoxItems(ui->special_requirement, special_skill, 5, (client->getSpecialRequriements())-1);
    addComBoxItems(ui->specie, specie, 3, 2);
    if (client->getAnimal() == "Dog"){
        ui->breed->addItem("Black Labrador");
        ui->breed->addItem("German Shepherd");
        ui->breed->addItem("Corgi");
        ui->breed->addItem("Shiba Inu");
        ui->breed->addItem("Bulldog");
    }else if (client->getAnimal() == "Cat"){
        ui->breed->addItem("Calico");
        ui->breed->addItem("Lion");
        ui->breed->addItem("Tiger");
        ui->breed->addItem("Leopard");
        ui->breed->addItem("Panther");
    }else if (client->getAnimal() == "Bird"){
        ui->breed->addItem("Parrot");
        ui->breed->addItem("Flamingo");
        ui->breed->addItem("Eagle");
        ui->breed->addItem("Vulture");
        ui->breed->addItem("Raven");
    }else if (client->getAnimal() == "Bear"){
        ui->breed->addItem("Grizzly");
        ui->breed->addItem("Polar");
        ui->breed->addItem("Black");
        ui->breed->addItem("Black");
        ui->breed->addItem("Koala");
    }else if (client->getAnimal() == "Fish"){
        ui->breed->addItem("Goldish");
        ui->breed->addItem("Carp");
        ui->breed->addItem("Koi");
        ui->breed->addItem("Dwarf Lanternshark");
        ui->breed->addItem("Sea horse");
    }else{
        ui->breed->addItem("Black Labrador");
        ui->breed->addItem("German Shepherd");
        ui->breed->addItem("Corgi");
        ui->breed->addItem("Shiba Inu");
        ui->breed->addItem("Bulldog");
    }

    ui->breed->setCurrentText(QString::fromStdString(client->getBreed()));

}

void ClientProfileEditDialog::on_pushButton_clicked()
{
    client->setName((ui->name->text()).toStdString());
    client->setEmail((ui->email->text()).toStdString());
    client->setAddress((ui->address->text()).toStdString());

    client->setCellPhone((ui->cell_phone->text()).toInt());
    client->setHomePhone((ui->home_phone->text()).toInt());

    client->setAnimal((ui->specie->currentText()).toStdString());
    client->setBreed((ui->breed->currentText()).toStdString());
    client->setSpecial_requriements((ui->special_requirement->currentIndex()) + 1);

    client->setAge((ui->age->text()).toInt());
    client->setGender((ui->gender->text()).toInt());
    client->setEconomic_background((ui->economic_background->currentIndex()) + 1);
    client->setActivity_level((ui->activity_level->currentIndex()) + 1);
    client->setExperience_with_animals((ui->experience_with_animals->currentIndex()) + 1);
    client->setLevel_of_patience((ui->level_of_patience->currentIndex()) + 1);
    client->setHouse_size((ui->house_size->currentIndex()) + 1);
    client->setAvailable_time((ui->available_time->currentIndex()) + 1);
    client->setStrength((ui->strength->currentIndex()) + 1);


    ClientProfileEditDialog::close();
}

void ClientProfileEditDialog::addComBoxItems(QComboBox* b, QString s[], int size, int index){
    b->clear();
    for (int i = 0; i < size; i++){
        b->addItem(s[i]);
    }
    qDebug("INDEX FOR COMBOBOX: %d", index);
    b->setCurrentIndex(index);
}


void ClientProfileEditDialog::on_update_clicked()
{


    client->setName((ui->name->text()).toStdString());
    client->setEmail((ui->email->text()).toStdString());
    client->setAddress((ui->address->text()).toStdString());

    client->setCellPhone((ui->cell_phone->text()).toInt());
    client->setHomePhone((ui->home_phone->text()).toInt());

    client->setAnimal((ui->specie->currentText()).toStdString());
    client->setBreed((ui->breed->currentText()).toStdString());
    client->setSpecial_requriements((ui->special_requirement->currentIndex()) + 1);

    client->setAge((ui->age->text()).toInt());
    client->setGender((ui->gender->text()).toInt());
    client->setEconomic_background((ui->economic_background->currentIndex()) + 1);
    client->setActivity_level((ui->activity_level->currentIndex()) + 1);
    client->setExperience_with_animals((ui->experience_with_animals->currentIndex()) + 1);
    client->setLevel_of_patience((ui->level_of_patience->currentIndex()) + 1);
    client->setHouse_size((ui->house_size->currentIndex()) + 1);
    client->setAvailable_time((ui->available_time->currentIndex()) + 1);
    client->setStrength((ui->strength->currentIndex()) + 1);

    control->upDateClient(client);

    ClientProfileEditDialog::close();

}
