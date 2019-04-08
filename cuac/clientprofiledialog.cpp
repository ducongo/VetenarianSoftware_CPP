#include "clientprofiledialog.h"
#include "ui_clientprofiledialog.h"
#include <string>
#include "clientprofileeditdialog.h"
#include "erroruserdialog.h"

ClientProfileDialog::ClientProfileDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientProfileDialog)
{
    ui->setupUi(this);
     ui->icon->setStyleSheet("background-image: url(:/img/images/client.png)");
}

ClientProfileDialog::~ClientProfileDialog()
{
    delete ui;
}

void ClientProfileDialog::loadData(Client* client){

    c = client;

    ui->name->setText(ui->name->text().append(QString::fromStdString(client->getName())));
    ui->email->setText(ui->email->text().append(QString::fromStdString(client->getEmail())));
    ui->address->setText(ui->address->text().append(QString::fromStdString(client->getAddress())));
    ui->age->setText(ui->age->text().append(QString::number(client->getAge())));
    ui->gender->setText(ui->gender->text().append(QString::number(client->getGender())));
    ui->cell_phone->setText(ui->cell_phone->text().append(QString::number(client->getCellPhone())));
    ui->home_phone->setText(ui->home_phone->text().append(QString::number(client->getHomePhone())));

    ui->economic_background->setText(ui->economic_background->text().append(economic_background[client->getEconomicBackground()-1]));
    ui->activity_level->setText(ui->activity_level->text().append(activity_level[client->getActivityLevel()-1]));
    ui->experience_with_animals->setText(ui->experience_with_animals->text().append(experience_with_animal[client->getExperienceWithAnimals()-1]));
    ui->level_of_patience->setText(ui->level_of_patience->text().append(level_of_patience[client->getLevelOfPatience()-1]));
    ui->house_size->setText(ui->house_size->text().append(house_size[client->getHouseSize()-1]));
    ui->available_time->setText(ui->available_time->text().append(available_time[client->getAvailableTime()]));
    ui->strength->setText(ui->strength->text().append(strength[client->getStrength()-1]));
    ui->specie->setText(ui->specie->text().append(QString::fromStdString(client->getAnimal())));
    ui->breed->setText(ui->breed->text().append(QString::fromStdString(client->getBreed())));
    if((client->getSpecialRequriements() > 0) && (client->getSpecialRequriements() < 0)){
        ui->special_requirement->setText(ui->special_requirement->text().append(special_skill[client->getSpecialRequriements()-1]));
    }

    ui->client_id->setText(ui->client_id->text().append(QString::number(client->getID())));


}






void ClientProfileDialog::on_update_button_clicked()
{
    qDebug("CLIENT IS LOGGED IN");

    if ((control->getCurrentUID() == 0) || (c->getID() == control->getCurrentUID())){
        ClientProfileEditDialog d;
        d.client = c;
        d.control = control;
        d.loadData(c);
        d.setModal(true);
        d.exec();
        qDebug("CLIENT IS LOGGED IN");

        resetLabels();
        loadData(c);
    }else{

        ErrorUserDialog e;
        e.setText("You can't modify other clients profiles!");
        e.setModal(true);
        e.exec();
    }

}

void ClientProfileDialog::resetLabels(){
    ui->name->setText("Name: ");
    ui->specie->setText("Animal: ");
    ui->breed->setText("Breed: ");
    ui->age->setText("Age: ");
    ui->gender->setText("Gender: ");
    ui->address->setText("Address: ");
    ui->cell_phone->setText("Cell Phone: ");
    ui->home_phone->setText("Home Phone: ");
    ui->special_requirement->setText("Special requirement: ");
    ui->economic_background->setText("Economic background: ");
    ui->activity_level->setText("Activity level: ");
    ui->experience_with_animals->setText("Experience with animals: ");
    ui->level_of_patience->setText("Level of patience: ");
    ui->house_size->setText("House size: ");
    ui->available_time->setText("Available time: ");
    ui->strength->setText("Strength: ");
    ui->email->setText("Email: ");
    ui->client_id->setText("Client ID: ");


}
