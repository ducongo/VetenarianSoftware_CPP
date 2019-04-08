#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_pushButton_clicked()
{

}

void LoginDialog::on_pushButton_2_clicked()
{

}

void LoginDialog::on_staff_clicked()
{
    home->is_staff_member = 1;
    control->setCurrentUID(0);
    LoginDialog::close();
}

void LoginDialog::on_client_clicked()
{
    if((ui->uid->text()).toInt() > 0){
        home->is_staff_member = 2;
        control->setCurrentUID((ui->uid->text()).toInt());
        LoginDialog::close();
    }else{
        ui->error_label->setText("The User ID you provided is not valid");
    }

}

void LoginDialog:: setMax(int MAX){
    max = MAX;
    ui->uid->setMinimum(0);
    ui->uid->setMaximum(max);
    ui->uid->setValue(0);
}
