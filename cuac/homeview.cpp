#include "homeview.h"
#include "ui_homeview.h"
#include "animalprofiledialog.h"
#include "clientprofiledialog.h"
#include "addanimaldialog.h"
#include "addclientdialog.h"
#include "viewanimaldialog.h"
#include "logindialog.h"
#include "erroruserdialog.h"




HomeView::HomeView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HomeView)
{
    ui->setupUi(this);
    ui->listWidgetAnimal->setViewMode(QListWidget::IconMode);
    ui->listWidgetAnimal->setIconSize(QSize(128, 128));
    ui->listWidgetAnimal->setResizeMode(QListWidget::Adjust);

    ui->listWidgetClient->setViewMode(QListWidget::IconMode);
    ui->listWidgetClient->setIconSize(QSize(128, 128));
    ui->listWidgetClient->setResizeMode(QListWidget::Adjust);



}

HomeView::~HomeView()
{
    delete ui;
}

void HomeView::on_runACMButton_clicked()
{
    qDebug("Running ACM Algorithm");
}

void HomeView::on_listWidgetAnimal_itemDoubleClicked(QListWidgetItem *item)
{
    if (is_staff_member != 0){
        qDebug("Animal Selected at index: %d", item->listWidget()->currentRow());
        ViewAnimalDialog profile;
        profile.setModal(true);
        profile.control = control;
        profile.loadData(control->getAnimal(item->listWidget()->currentRow()));
        //profile.loadData(animals->get(item->listWidget()->currentRow()));
        //aprofile.animal = animals->get(item->listWidget()->currentRow());
        profile.exec();
        loadData();
    }else{
        loginPrompt();
    }

}

void HomeView::on_listWidgetClient_itemDoubleClicked(QListWidgetItem *item)
{
    if (is_staff_member != 0){
        qDebug("Animal Selected at index: %d", item->listWidget()->currentRow());
        ClientProfileDialog profile;
        profile.control = control;
        profile.setModal(true);
        profile.loadData(control->getClient(item->listWidget()->currentRow()));
        //aprofile.animal = animals->get(item->listWidget()->currentRow());
        profile.exec();
        loadData();
    }else{
        loginPrompt();
    }

}

void HomeView::on_addAnimal_clicked()
{
    if ((is_staff_member == 1) && (is_staff_member != 0)){
        qDebug("Adding animal");
        AddAnimalDialog d;
        d.control = control;
        d.setModal(true);
        d.exec();
    }else if ((is_staff_member == 2) && (is_staff_member != 0)){
        ErrorUserDialog e;
        e.setModal(true);
        e.exec();
    }else{
        loginPrompt();
    }

}

void HomeView::on_addClient_clicked()
{
    if ((is_staff_member == 1) && (is_staff_member != 0)){
        qDebug("Adding client");
        qDebug("Adding animal");
        AddClientDialog d;
        d.control = control;
        d.setModal(true);
        d.exec();
    }else if ((is_staff_member == 2) && (is_staff_member != 0)){
        ErrorUserDialog e;
        e.setModal(true);
        e.exec();
    }else{

        loginPrompt();
    }

}

void HomeView::on_pushButton_clicked()
{

    loginPrompt();
}

void HomeView::loadData()
{

    int iNum = ui->listWidgetAnimal->count();
    for (int j = 0; j < iNum; j++){
        delete (ui->listWidgetAnimal->takeItem(0));
    }

    for (int i = 0; i < control->getAnimalArraySize(); i++){

        QString path = ":/img/images/pet.png";

        QListWidgetItem *item = new QListWidgetItem(QIcon(path), QString::fromStdString(control->getAnimal(i)->getName() + "\n " + control->getAnimal(i)->getBreed()));

        ui->listWidgetAnimal->addItem(item);

     }

    int iNum2 = ui->listWidgetClient->count();
    for (int z = 0; z < iNum2; z++){
        delete (ui->listWidgetClient->takeItem(0));
    }

    for (int i = 0; i < control->getClientArraySize(); i++){

        QString path = ":/img/images/client.png";

        QListWidgetItem *item = new QListWidgetItem(QIcon(path), QString::fromStdString(control->getClient(i)->getName()));

        ui->listWidgetClient->addItem(item);

     }

    ui->total->setText((QString::fromStdString(std::to_string(control->getAnimalArraySize()))) + " animal(s) ready for adoption");
}

void HomeView::loadArrays(){

    //control->populateAnimalArray();
    //control->populateClientArray();


    loadData();

}

void HomeView::loginPrompt(){
    LoginDialog loginDialog;
    loginDialog.home = this;
    loginDialog.control = control;
    loginDialog.setMax(control->getClientArraySize());
    loginDialog.setModal(true);
    loginDialog.exec();
    ui->current_uid->setText("Cuurent user ID: " + QString::number(control->getCurrentUID()));
    ui->current_uid_2->setText("Cuurent user ID: " + QString::number(control->getCurrentUID()));
}
