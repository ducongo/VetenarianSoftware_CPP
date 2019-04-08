#include "erroruserdialog.h"
#include "ui_erroruserdialog.h"

ErrorUserDialog::ErrorUserDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ErrorUserDialog)
{
    ui->setupUi(this);

}

ErrorUserDialog::~ErrorUserDialog()
{
    delete ui;
}

void ErrorUserDialog::setText(QString s){
    ui->erroText->setText(s);
}
