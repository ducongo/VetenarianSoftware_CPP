#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <datatypes.h>

class Database
{
    public:
        Database();
        void dropTables();
        int initTables();
        int pushAnimal(AnimalData);
        int updateAnimal(AnimalData);
        int pushClient(ClientData);
        int updateClient(ClientData);
        int pushStaff(StaffData);
        int initValues();
        AnimalData** pullAnimals();
        ClientData** pullClients();
        StaffData** pullStaff();
    private:
        QSqlDatabase db;

};

#endif // DATABASE_H
