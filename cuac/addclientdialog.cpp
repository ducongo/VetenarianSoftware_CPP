#include "addclientdialog.h"
#include "ui_addclientdialog.h"
#include "client.h"

AddClientDialog::AddClientDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddClientDialog)
{
    ui->setupUi(this);
    ui->breed->addItem("Black Labrador");
    ui->breed->addItem("German Shepherd");
    ui->breed->addItem("Corgi");
    ui->breed->addItem("Shiba Inu");
    ui->breed->addItem("Bulldog");

    addComBoxItems(ui->economic_background, economic_background, 3);
    addComBoxItems(ui->activity_level, activity_level, 3);
    addComBoxItems(ui->experience_with_animals, experience_with_animal, 3);
    addComBoxItems(ui->level_of_patience, level_of_patience, 3);
    addComBoxItems(ui->house_size, house_size, 3);
    addComBoxItems(ui->available_time, available_time, 3);
    addComBoxItems(ui->strength, strength, 3);
    addComBoxItems(ui->specie, specie, 5);
    addComBoxItems(ui->breed, breed[0], 5);
    addComBoxItems(ui->special_skill, special_skill, 5);

    ui->home_phone->setValidator(new QIntValidator(0, 999999999, this));
    ui->cell_phone->setValidator(new QIntValidator(0, 999999999, this));


}

AddClientDialog::~AddClientDialog()
{
    delete ui;

}

void AddClientDialog::on_pushButton_clicked()
{

    Client* client = new Client((ui->name->text()).toStdString(), (ui->email->text()).toStdString(), (ui->address->text()).toStdString(), (ui->age->text()).toInt(), (ui->gender->text()).toInt(), (ui->cell_phone->text()).toInt(), (ui->home_phone->text()).toInt()
                                ,ui->economic_background->currentIndex()+1
                                ,ui->activity_level->currentIndex()+1
                                ,ui->experience_with_animals->currentIndex()+1
                                ,ui->level_of_patience->currentIndex()+1
                                ,ui->house_size->currentIndex()+1
                                ,ui->available_time->currentIndex()+1
                                ,ui->strength->currentIndex()+1
                                ,(ui->specie->currentText()).toStdString()
                                ,(ui->breed->currentText()).toStdString()
                                ,ui->special_skill->currentIndex()+1
                                ,control->getClientArraySize() + 1);
    control->addClient(client);

    control->getHomeView()->loadData();

    AddClientDialog::close();
}

void AddClientDialog::on_specie_valueChanged(int arg1)
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

void AddClientDialog::on_breed_currentIndexChanged(int index)
{
    //qDebug("INDEXXXXXXX: %d", (ui->breed->currentIndex()));
}

void AddClientDialog::on_specie_currentIndexChanged(int index)
{
    ui->breed->clear();
    if (index == 0){
        ui->breed->addItem("Black Labrador");
        ui->breed->addItem("German Shepherd");
        ui->breed->addItem("Corgi");
        ui->breed->addItem("Shiba Inu");
        ui->breed->addItem("Bulldog");
    }else if (index == 1){
        ui->breed->addItem("Calico");
        ui->breed->addItem("Lion");
        ui->breed->addItem("Tiger");
        ui->breed->addItem("Leopard");
        ui->breed->addItem("Panther");
    }else if (index == 2){
        ui->breed->addItem("Parrot");
        ui->breed->addItem("Flamingo");
        ui->breed->addItem("Eagle");
        ui->breed->addItem("Vulture");
        ui->breed->addItem("Raven");
    }else if (index == 3){
        ui->breed->addItem("Grizzly");
        ui->breed->addItem("Polar");
        ui->breed->addItem("Black");
        ui->breed->addItem("Black");
        ui->breed->addItem("Koala");
    }else if (index == 4){
        ui->breed->addItem("Goldish");
        ui->breed->addItem("Carp");
        ui->breed->addItem("Koi");
        ui->breed->addItem("Dwarf Lanternshark");
        ui->breed->addItem("Sea horse");
    }
}

void AddClientDialog::addComBoxItems(QComboBox* b, QString s[], int size){
    b->clear();
    for (int i = 0; i < size; i++){
    b->addItem(s[i]);
   }

   b->setCurrentIndex(1);
}
