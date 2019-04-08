#include "homeview.h"
#include "array.h"
#include "animal.h"
#include "client.h"
#include <QApplication>
#include "database.h"
#include "control.h"


int main(int argc, char *argv[])
{
    //Array<Animal>* animals = new Array<Animal>();
   // Array<Client>* clients = new Array<Client>();
    Control* control = new Control();

    QApplication a(argc, argv);

    HomeView w;

    control->setHomeView(&w);
    control->populateAnimalArray();
    control->populateClientArray();

    control->getHomeView()->loadArrays();
    control->getHomeView()->loginPrompt();
    control->getHomeView()->show();
    //w.show();

    //qDebug("LAUNCHING APPLICATION");



    //Animal *rat = new Animal("dor","dor","dor",1,3,2,"dor","dor");

    //animal.add(rat);

    return a.exec();
}
