#include "database.h"
//#include "datatypes.h"

Database::Database()
{
    const QString DRIVER("QSQLITE");
    if (QSqlDatabase::isDriverAvailable(DRIVER)){
        qDebug("QSQLITE driver available");
    }else{
        qDebug("QSQLITE driver not available");
        return;
    }

    db = QSqlDatabase::addDatabase(DRIVER);
    db.setDatabaseName("./cuacs_db.sql");
//    if (!db.open()){
//        qWarning() << "ERROR: " << db.lastError();
//        return;
//    }

    db.open();
    //dropTables();
    if (!(db.tables().contains(QLatin1String("client")))){
        qDebug("********************************");
        qDebug("Table does not exist");
        qDebug("********************************");
        initTables();
        initValues();
    }else{
        qDebug("********************************");
        qDebug("Table does EXIST");
        qDebug("********************************");
    }
    db.close();
}

void Database::dropTables(){

    QSqlQuery query;
    db.open();
    query = QSqlQuery(db);

    query.exec("DROP TABLE staff;");
    query.exec("DROP TABLE client;");
    query.exec("DROP TABLE animal;");
    db.close();
}

int Database::initTables(){
    QSqlQuery query;
    const QString DRIVER("QSQLITE");
    //QSqlDatabase db2;
    //db2 = QSqlDatabase::addDatabase(DRIVER);
    //db2.setDatabaseName("./cuacs_db.sql");
    db.open();
    query = QSqlQuery(db);



    // Initialize the database. If the tables are present then nothing will happen.

    if(!query.exec("CREATE TABLE staff (id INTEGER PRIMARY KEY, name TEXT)")){
        qWarning() << "ERROR: " << query.lastError().text();
    }

    if(!query.exec("CREATE TABLE client (id INTEGER PRIMARY KEY, name TEXT, home TEXT, email TEXT, breed TEXT, species TEXT,"
                   "homePhone INTEGER, mobilePhone INTEGER, age INTEGER, gender INTEGER, economicBackground INTEGER,"
                   "activity INTEGER, experience INTEGER, patience INTEGER, house INTEGER, time INTEGER, strength INTEGER,"
                   "preferredClimate INTEGER,"
                   "dependencyPreference INTEGER, livingPreference INTEGER, energyPreference INTEGER, "
                   "intelligencePreference INTEGER, difficultyPreference INTEGER, "
                   "noisePreference INTEGER, specialRequirements INTEGER"
                   ")")){
        qWarning() << "ERROR: " << query.lastError().text();
    }
    if(!query.exec("CREATE TABLE animal (id INTEGER PRIMARY KEY, name TEXT, species TEXT, breed TEXT, colour TEXT, special TEXT,"
                   "gender INTEGER, age INTEGER, weight INTEGER, height INTEGER, energy INTEGER, temperament INTEGER,"
                   "kid INTEGER, habits INTEGER, history INTEGER, dependency INTEGER, disease INTEGER, space INTEGER,"
                   "climate INTEGER, care INTEGER, cleanliness INTEGER, medical INTEGER, health INTEGER, "
                   "intelligence INTEGER, difficulty INTEGER, feeding INTEGER, noise INTEGER"
                   ")")){
        qWarning() << "ERROR: " << query.lastError().text();
    }
    query.finish();
    db.close();
    return(0);
}

int Database::pushClient(ClientData client){
    QSqlQuery query;
    const QString DRIVER("QSQLITE");
    //QSqlDatabase db2;
    //db2 = QSqlDatabase::addDatabase(DRIVER);
    //db2.setDatabaseName("./cuacs_db.sql");
    db.open();
    query = QSqlQuery(db);
    qDebug("Pushing client into database.");

    if(!query.prepare("INSERT INTO client VALUES(:id, :name, :home, :email, :breed, :species,"
                      ":homePhone, :mobilePhone, :age, :gender, :economicBackground,"
                      ":activity, :experience, :patience, :house, :time, :strength,"
                      ":preferredClimate, :dependencyPreference, :livingPreference,"
                      ":energyPreference, :intelligencePreference, :difficultyPreference,"
                      ":noisePreference, :specialRequirements"
                      ")")){

        qWarning() << "ERROR: " << query.lastError().text();
        return(1);
    }

    query.bindValue(":id", client.clientId);
    query.bindValue(":name", QString::fromStdString(client.clientName));
    query.bindValue(":home", QString::fromStdString(client.clientAddr));
    query.bindValue(":email", QString::fromStdString(client.clientEmail));
    query.bindValue(":breed", QString::fromStdString(client.breed));
    query.bindValue(":species", QString::fromStdString(client.species));
    query.bindValue(":homePhone", client.clientAttr[0]);
    query.bindValue(":mobilePhone", client.clientAttr[1]);
    query.bindValue(":age", client.clientAttr[2]);
    query.bindValue(":gender", client.clientAttr[3]);
    query.bindValue(":economicBackground", client.clientAttr[4]);
    query.bindValue(":activity", client.clientAttr[5]);
    query.bindValue(":experience", client.clientAttr[6]);
    query.bindValue(":patience", client.clientAttr[7]);
    query.bindValue(":house", client.clientAttr[8]);
    query.bindValue(":time", client.clientAttr[9]);
    query.bindValue(":strength", client.clientAttr[10]);
    query.bindValue(":preferredClimate", client.clientAttr[11]);
    query.bindValue(":dependencyPreference", client.clientAttr[12]);
    query.bindValue(":livingPreference", client.clientAttr[13]);
    query.bindValue(":energyPreference", client.clientAttr[14]);
    query.bindValue(":intelligencePreference", client.clientAttr[15]);
    query.bindValue(":difficultyPreference", client.clientAttr[16]);
    query.bindValue(":noisePreference", client.clientAttr[17]);
    query.bindValue(":specialRequiremets", client.clientAttr[18]);

    if(!query.exec()){
        qWarning() << "ERROR: " << query.lastError().text();
        query.finish();
        return(1);
    }
    query.finish();
    db.close();
    return(0);
}

int Database::pushStaff(StaffData staff){
    QSqlQuery query;
    query = QSqlQuery(db);
    qDebug("Pushing staff into database.");

    if(!query.prepare("INSERT INTO staff VALUES(:id, :name)")){
        qWarning() << "ERROR: " << query.lastError().text();
        return(1);
    }

    query.bindValue(":id", staff.staffId);
    query.bindValue(":name", QString::fromStdString(staff.staffName));

    if(!query.exec()){
        qWarning() << "ERROR: " << query.lastError().text();
        query.finish();
        return(1);
    }
    query.finish();
    db.close();
    return(0);
}

int Database::pushAnimal(AnimalData animal){
    QSqlQuery query;
    const QString DRIVER("QSQLITE");
    //QSqlDatabase db2;
    //db2 = QSqlDatabase::addDatabase(DRIVER);
    //db2.setDatabaseName("./cuacs_db.sql");
    db.open();
    query = QSqlQuery(db);
    qDebug("Pushing animal into database.");

    if(!query.prepare("INSERT INTO animal VALUES (:id, :name, :species, :breed, :colour, :special,"
                      ":gender, :age, :weight, :height, :energy, :temperament, :kid, :habits, :history,"
                      ":dependency, :disease, :space, :climate, :care, :cleanliness, :medical, :health,"
                      ":intelligence, :difficulty, :feeding, :noise"
                      ")")){
        qWarning() << "ERROR: " << query.lastError().text();
        return(1);
    }

    query.bindValue(":id", animal.animalId);
    query.bindValue(":name", QString::fromStdString(animal.animalName));
    query.bindValue(":species", QString::fromStdString(animal.typeOfAnimal));
    query.bindValue(":breed", QString::fromStdString(animal.breed));
    query.bindValue(":colour", QString::fromStdString(animal.colour));
    query.bindValue(":special", QString::fromStdString(animal.specialSkill));
    query.bindValue(":gender", animal.animalAttr[0]);
    query.bindValue(":age", animal.animalAttr[1]);
    query.bindValue(":weight",animal.animalAttr[2]);
    query.bindValue(":height", animal.animalAttr[3]);
    query.bindValue(":energy", animal.animalAttr[4]);
    query.bindValue(":temperament", animal.animalAttr[5]);
    query.bindValue(":kid", animal.animalAttr[6]);
    query.bindValue(":habits", animal.animalAttr[7]);
    query.bindValue(":history", animal.animalAttr[8]);
    query.bindValue(":dependency", animal.animalAttr[9]);
    query.bindValue(":disease", animal.animalAttr[10]);
    query.bindValue(":space", animal.animalAttr[11]);
    query.bindValue(":climate", animal.animalAttr[12]);
    query.bindValue(":care", animal.animalAttr[13]);
    query.bindValue(":cleanliness", animal.animalAttr[14]);
    query.bindValue(":medical", animal.animalAttr[15]);
    query.bindValue(":health", animal.animalAttr[16]);
    query.bindValue(":intelligence", animal.animalAttr[17]);
    query.bindValue(":difficulty", animal.animalAttr[18]);
    query.bindValue(":feeding", animal.animalAttr[19]);
    query.bindValue(":noise", animal.animalAttr[20]);

    if(!query.exec()){
        qWarning() << "ERROR: " << query.lastError().text();
        query.finish();
        return(1);
    }
    query.finish();
    db.close();
    return(0);
}

int Database::updateAnimal(AnimalData animal){
    QSqlQuery query;
    db.open();
    query = QSqlQuery(db);
    qDebug("Updating animal in the database");


    if(!query.prepare("UPDATE animal "
                      "SET name=:name, species=:species, breed=:breed, colour=:colour, special=:special, "
                      "gender=:gender, age=:age, weight=:weight, height=:height, energy=:energy, "
                      "temperament=:temperament, kid=:kid, habits=:habits, history=:history, "
                      "dependency=:dependency, disease=:disease, space=:space, climate=:climate, "
                      "care=:care, cleanliness=:cleanliness, medical=:medical, health=:health, "
                      "intelligence=:intelligence, difficulty=:difficulty, feeding=:feeding, noise=:noise "
                      "WHERE id=:id")){
        qWarning() << "ERROR UPDATING: Dog" << query.lastError().text();
        return(1);
    }else{
        qDebug("Query is prepared");
    }

    query.bindValue(":id", animal.animalId);
    query.bindValue(":name", QString::fromStdString(animal.animalName));
    query.bindValue(":species", QString::fromStdString(animal.typeOfAnimal));
    query.bindValue(":breed", QString::fromStdString(animal.breed));
    query.bindValue(":colour", QString::fromStdString(animal.colour));
    query.bindValue(":special", QString::fromStdString(animal.specialSkill));
    query.bindValue(":gender", animal.animalAttr[0]);
    query.bindValue(":age", animal.animalAttr[1]);
    query.bindValue(":weight",animal.animalAttr[2]);
    query.bindValue(":height", animal.animalAttr[3]);
    query.bindValue(":energy", animal.animalAttr[4]);
    query.bindValue(":temperament", animal.animalAttr[5]);
    query.bindValue(":kid", animal.animalAttr[6]);
    query.bindValue(":habits", animal.animalAttr[7]);
    query.bindValue(":history", animal.animalAttr[8]);
    query.bindValue(":dependency", animal.animalAttr[9]);
    query.bindValue(":disease", animal.animalAttr[10]);
    query.bindValue(":space", animal.animalAttr[11]);
    query.bindValue(":climate", animal.animalAttr[12]);
    query.bindValue(":care", animal.animalAttr[13]);
    query.bindValue(":cleanliness", animal.animalAttr[14]);
    query.bindValue(":medical", animal.animalAttr[15]);
    query.bindValue(":health", animal.animalAttr[16]);
    query.bindValue(":intelligence", animal.animalAttr[17]);
    query.bindValue(":difficulty", animal.animalAttr[18]);
    query.bindValue(":feeding", animal.animalAttr[19]);
    query.bindValue(":noise", animal.animalAttr[20]);

    if(!query.exec()){
        qWarning() << "ERROR UPDATING: Dog" << query.lastError().text();
        query.finish();
        return(1);
    }else{
        qDebug("UPDATED SUCCESFULLY");
    }
    query.finish();
    db.close();
    return 0;
}

int Database::updateClient(ClientData client){
    QSqlQuery query;
    db.open();
    query = QSqlQuery(db);
    qDebug("Updating client");

    if(!query.prepare("UPDATE client "
                      "SET name=:name, email=:email, breed=:breed, species=:species, "
                      "homePhone=:homePhone, mobilePhone=:mobilePhone, age=:age, gender=:gender, "
                      "economicBackground=:economicBackground, activity=:activity, experience=:experience, "
                      "patience=:patience, house=:house, time=:time, strength=:strength, "
                      "preferredClimate=:preferredClimate, dependencyPreference=:dependencyPreference, "
                      "livingPreference=:livingPreference, energyPreference=:energyPreference, "
                      "intelligencePreference=:intelligencePreference, difficultyPreference=:difficultyPreference, "
                      "noisePreference=:noisePreference, specialRequirements=:specialRequirements "
                      "WHERE id=:id")){
        qWarning() << "ERROR UPDATING: cleint" << query.lastError().text();
        return(1);
    }

    query.bindValue(":id", client.clientId);
    query.bindValue(":name", QString::fromStdString(client.clientName));
    query.bindValue(":home", QString::fromStdString(client.clientAddr));
    query.bindValue(":email", QString::fromStdString(client.clientEmail));
    query.bindValue(":breed", QString::fromStdString(client.breed));
    query.bindValue(":species", QString::fromStdString(client.species));
    query.bindValue(":homePhone", client.clientAttr[0]);
    query.bindValue(":mobilePhone", client.clientAttr[1]);
    query.bindValue(":age", client.clientAttr[2]);
    query.bindValue(":gender", client.clientAttr[3]);
    query.bindValue(":economicBackground", client.clientAttr[4]);
    query.bindValue(":activity", client.clientAttr[5]);
    query.bindValue(":experience", client.clientAttr[6]);
    query.bindValue(":patience", client.clientAttr[7]);
    query.bindValue(":house", client.clientAttr[8]);
    query.bindValue(":time", client.clientAttr[9]);
    query.bindValue(":strength", client.clientAttr[10]);
    query.bindValue(":preferredClimate", client.clientAttr[11]);
    query.bindValue(":dependencyPreference", client.clientAttr[12]);
    query.bindValue(":livingPreference", client.clientAttr[13]);
    query.bindValue(":energyPreference", client.clientAttr[14]);
    query.bindValue(":intelligencePreference", client.clientAttr[15]);
    query.bindValue(":difficultyPreference", client.clientAttr[16]);
    query.bindValue(":noisePreference", client.clientAttr[17]);
    query.bindValue(":specialRequirements", client.clientAttr[18]);

    if(!query.exec()){
        qWarning() << "ERROR UPDATING: client" << query.lastError().text();
        query.finish();
        return(1);
    }else{
        qDebug("UPDATED SUCCESFULLY CLIENT");
    }
    query.finish();
    db.close();
    return(0);
}

AnimalData** Database::pullAnimals(){
    AnimalData** animals;
    QSqlQuery query;
    const QString DRIVER("QSQLITE");
    //QSqlDatabase db2;
   // db2 = QSqlDatabase::addDatabase(DRIVER);
    //db2.setDatabaseName("./cuacs_db.sql");
    db.open();
    query = QSqlQuery(db);

    int i = 0;

    qDebug("Pulling animals from database.");
    if(!query.exec("SELECT name, species, breed, colour, special,"
                   "gender, age, weight, height, energy, temperament, kid, habits, history,"
                   "dependency, disease, space, climate, care, cleanliness, medical, health,"
                   "intelligence, difficulty, feeding, noise, id FROM animal")){
        qWarning() << "ERROR: " << query.lastError().text();
        query.finish();
        return NULL;
    }

    // Increment i for malloc below
    while (query.next()) {
          i++;
    }

    animals = (AnimalData**)malloc(i+1 * sizeof(**animals));
    int x = 0;
    for(; x < i; x++){
        animals[x] = new AnimalData;
    }

    x = 0;
    while (query.previous()){
         animals[x]->animalId = query.value(26).toInt();
         animals[x]->animalName = query.value(0).toString().toUtf8().constData();
         animals[x]->typeOfAnimal = query.value(1).toString().toUtf8().constData();
         animals[x]->breed = query.value(2).toString().toUtf8().constData();
         animals[x]->colour = query.value(3).toString().toUtf8().constData();
         animals[x]->specialSkill = query.value(4).toString().toUtf8().constData();
         animals[x]->animalAttr[0] = query.value(5).toInt();
         animals[x]->animalAttr[1] = query.value(6).toInt();
         animals[x]->animalAttr[2] = query.value(7).toInt();
         animals[x]->animalAttr[3] = query.value(8).toInt();
         animals[x]->animalAttr[4] = query.value(9).toInt();
         animals[x]->animalAttr[5] = query.value(10).toInt();
         animals[x]->animalAttr[6] = query.value(11).toInt();
         animals[x]->animalAttr[7] = query.value(12).toInt();
         animals[x]->animalAttr[8] = query.value(13).toInt();
         animals[x]->animalAttr[9] = query.value(14).toInt();
         animals[x]->animalAttr[10] = query.value(15).toInt();
         animals[x]->animalAttr[11] = query.value(16).toInt();
         animals[x]->animalAttr[12] = query.value(17).toInt();
         animals[x]->animalAttr[13] = query.value(18).toInt();
         animals[x]->animalAttr[14] = query.value(19).toInt();
         animals[x]->animalAttr[15] = query.value(20).toInt();
         animals[x]->animalAttr[16] = query.value(21).toInt();
         animals[x]->animalAttr[17] = query.value(22).toInt();
         animals[x]->animalAttr[18] = query.value(23).toInt();
         animals[x]->animalAttr[19] = query.value(24).toInt();
         animals[x]->animalAttr[20] = query.value(25).toInt();

         x++;
    }
    animals[i] = NULL;

    query.finish();
    db.close();
    return animals;
}

ClientData** Database::pullClients(){
    ClientData** clients;
    QSqlQuery query;
    const QString DRIVER("QSQLITE");
    //QSqlDatabase db2;
   // db2 = QSqlDatabase::addDatabase(DRIVER);
    //db2.setDatabaseName("./cuacs_db.sql");
    db.open();
    query = QSqlQuery(db);
    int i = 0;

    qDebug("Pulling clients from database.");
    if(!query.exec("SELECT name, home, email, breed, species, homePhone, mobilePhone,"
                   "age, gender, economicBackground, activity, experience, patience, house, time,"
                   "strength, id , preferredClimate, dependencyPreference, livingPreference, "
                   "energyPreference, intelligencePreference, difficultyPreference, noisePreference,"
                   "specialRequirements FROM client")){
        qWarning() << "ERROR: " << query.lastError().text();
        query.finish();
        return NULL;
    }

    // Increment i for malloc below
    while (query.next()) {
          i++;
    }

    clients = (ClientData**)malloc(i+1 * sizeof(**clients));
    int x = 0;
    for(; x < i; x++){
        clients[x] = new ClientData;
    }

    x = 0;
    while (query.previous()){
         clients[x]->clientName      = query.value(0).toString().toUtf8().constData();
         clients[x]->clientAddr      = query.value(1).toString().toUtf8().constData();
         clients[x]->clientEmail     = query.value(2).toString().toUtf8().constData();
         clients[x]->breed           = query.value(3).toString().toUtf8().constData();
         clients[x]->species         = query.value(4).toString().toUtf8().constData();
         clients[x]->clientId        = query.value(16).toInt();
         clients[x]->clientAttr[0]   = query.value(5).toInt();
         clients[x]->clientAttr[1]   = query.value(6).toInt();
         clients[x]->clientAttr[2]   = query.value(7).toInt();
         clients[x]->clientAttr[3]   = query.value(8).toInt();
         clients[x]->clientAttr[4]   = query.value(9).toInt();
         clients[x]->clientAttr[5]   = query.value(10).toInt();
         clients[x]->clientAttr[6]   = query.value(11).toInt();
         clients[x]->clientAttr[7]   = query.value(12).toInt();
         clients[x]->clientAttr[8]   = query.value(13).toInt();
         clients[x]->clientAttr[9]   = query.value(14).toInt();
         clients[x]->clientAttr[10]  = query.value(15).toInt();
         clients[x]->clientAttr[11]  = query.value(16).toInt();
         clients[x]->clientAttr[12]  = query.value(17).toInt();
         clients[x]->clientAttr[13]  = query.value(18).toInt();
         clients[x]->clientAttr[14]  = query.value(19).toInt();
         clients[x]->clientAttr[15]  = query.value(20).toInt();
         clients[x]->clientAttr[16]  = query.value(21).toInt();
         clients[x]->clientAttr[17]  = query.value(22).toInt();
         clients[x]->clientAttr[18]  = query.value(23).toInt();

         x++;
    }
    clients[i] = NULL;

    query.finish();
    db.close();
    return clients;
}

int Database::initValues(){

    ClientData client1;
    ClientData client2;
    ClientData client3;
    ClientData client4;
    ClientData client5;
    ClientData client6;
    ClientData client7;
    ClientData client8;
    ClientData client9;
    ClientData client10;
    ClientData client11;
    ClientData client12;
    ClientData client13;
    ClientData client14;
    ClientData client15;
    ClientData client16;
    ClientData client17;
    ClientData client18;
    ClientData client19;
    ClientData client20;



    AnimalData animal1;
    AnimalData animal2;
    AnimalData animal3;
    AnimalData animal4;
    AnimalData animal5;
    AnimalData animal6;
    AnimalData animal7;
    AnimalData animal8;
    AnimalData animal9;
    AnimalData animal10;
    AnimalData animal11;
    AnimalData animal12;
    AnimalData animal13;
    AnimalData animal14;
    AnimalData animal15;
    AnimalData animal16;
    AnimalData animal17;
    AnimalData animal18;
    AnimalData animal19;
    AnimalData animal20;
    AnimalData animal21;
    AnimalData animal22;
    AnimalData animal23;
    AnimalData animal24;
    AnimalData animal25;

    client1.clientName = "Kyle";  // Name
    client1.clientAttr[0] = 665994999; // Home phone
    client1.clientAttr[1] = 553817834; // Mobile phone
    client1.clientAttr[2] = 19; // Client's age
    client1.clientAttr[3] =  0; // Gender
    client1.clientAddr = "1049 Bank Street, Ottawa, Ontario"; // Address
    client1.clientEmail = "kyle@rogers.ca"; // Email
    client1.clientId = 1; // Unique identifer
    client1.breed = "None"; // Client's preference for breed
    client1.species = "None"; // Client's preference for specie
    client1.clientAttr[4] = 2; // economic background
    client1.clientAttr[5] = 2; // activity level
    client1.clientAttr[6] = 1; // experience with animals
    client1.clientAttr[7] = 1; // patience level
    client1.clientAttr[8] = 1; // house size
    client1.clientAttr[9] = 2; // available time
    client1.clientAttr[10] = 3; // strength level
    client1.clientAttr[11] = 1; // preferred climate
    client1.clientAttr[12] = 2; // dependency preference
    client1.clientAttr[13] = 1; // living space preference
    client1.clientAttr[14] = 2; // energy level preference
    client1.clientAttr[15] = 2; // intelligence preference
    client1.clientAttr[16] = 1; // difficulty preference
    client1.clientAttr[17] = 1; // nosie preference
    client1.clientAttr[18] = 0; // special requirements

    client2.clientName = "Parfait";
    client2.clientAttr[0] = 735647366;
    client2.clientAttr[1] = 133808184;
    client2.clientAttr[2] = 20;
    client2.clientAttr[3] = 0;
    client2.clientAddr = "4309 49 St, Yellow Knife, Nunavut";
    client2.clientEmail = "parfait@gmail.com";
    client2.clientId = 2;
    client2.breed = "None"; // Client's preference for breed
    client2.species = "None"; // Client's preference for specie
    client2.clientAttr[4] = 3; // economic background
    client2.clientAttr[5] = 1; // activity level
    client2.clientAttr[6] = 2; // experience with animals
    client2.clientAttr[7] = 2; // patience level
    client2.clientAttr[8] = 2; // house size
    client2.clientAttr[9] = 1; // available time
    client2.clientAttr[10] = 2; // strength level
    client2.clientAttr[11] = 3; // preferred climate
    client2.clientAttr[12] = 1; // dependency preference
    client2.clientAttr[13] = 1; // living space preference
    client2.clientAttr[14] = 1; // energy level preference
    client2.clientAttr[15] = 1; // intelligence preference
    client2.clientAttr[16] = 2; // difficulty preference
    client2.clientAttr[17] = 2; // nosie preference
    client2.clientAttr[18] = 0; // special requirements

    client3.clientName = "Victor";
    client3.clientAttr[0] = 663011942;
    client3.clientAttr[1] = 884813436;
    client3.clientAttr[2] = 25;
    client3.clientAttr[3] = 0;
    client3.clientAddr = "381 St-Catherine St W, Montral, Quebec";
    client3.clientEmail = "victor@hotmail.com";
    client3.clientId = 3;
    client3.breed = "None"; // Client's preference for breed
    client3.species = "None"; // Client's preference for specie
    client3.clientAttr[4] = 3; // economic background
    client3.clientAttr[5] = 2; // activity level
    client3.clientAttr[6] = 3; // experience with animals
    client3.clientAttr[7] = 3; // patience level
    client3.clientAttr[8] = 3; // house size
    client3.clientAttr[9] = 1; // available time
    client3.clientAttr[10] = 3; // strength level
    client3.clientAttr[11] = 1; // preferred climate
    client3.clientAttr[12] = 2; // dependency preference
    client3.clientAttr[13] = 1; // living space preference
    client3.clientAttr[14] = 2; // energy level preference
    client3.clientAttr[15] = 2; // intelligence preference
    client3.clientAttr[16] = 1; // difficulty preference
    client3.clientAttr[17] = 1; // nosie preference
    client3.clientAttr[18] = 0; // special requirements

    client4.clientName = "Curtis";
    client4.clientAttr[0] = 666076301;
    client4.clientAttr[1] = 888481346;
    client4.clientAttr[2] = 31;
    client4.clientAttr[3] = 0;
    client4.clientAddr = "601 5 St Sw, Calgary, Alberta"            ;
    client4.clientEmail = "curtis@mcgill.ca";
    client4.clientId = 4;
    client4.breed = "None"; // Client's preference for breed
    client4.species = "None"; // Client's preference for specie
    client4.clientAttr[4] = 1; // economic background
    client4.clientAttr[5] = 1; // activity level
    client4.clientAttr[6] = 2; // experience with animals
    client4.clientAttr[7] = 2; // patience level
    client4.clientAttr[8] = 1; // house size
    client4.clientAttr[9] = 1; // available time
    client4.clientAttr[10] = 1; // strength level
    client4.clientAttr[11] = 1; // preferred climate
    client4.clientAttr[12] = 0; // dependency preference
    client4.clientAttr[13] = 1; // living space preference
    client4.clientAttr[14] = 0; // energy level preference
    client4.clientAttr[15] = 0; // intelligence preference
    client4.clientAttr[16] = 0; // difficulty preference
    client4.clientAttr[17] = 0; // nosie preference
    client4.clientAttr[18] = 0; // special requirements

    client5.clientName = "Phil";
    client5.clientAttr[0] = 502530000;
    client5.clientAttr[1] = 669956636;
    client5.clientAttr[2] = 45;
    client5.clientAttr[3] = 0;
    client5.clientAddr = "100 Queen St W, Toronto, Ontario";
    client5.clientEmail = "phil@cmail.carleton.ca";
    client5.clientId = 5;
    client5.breed = "None"; // Client's preference for breed
    client5.species = "None"; // Client's preference for specie
    client5.clientAttr[4] = 3; // economic background
    client5.clientAttr[5] = 1; // activity level
    client5.clientAttr[6] = 1; // experience with animals
    client5.clientAttr[7] = 3; // patience level
    client5.clientAttr[8] = 2; // house size
    client5.clientAttr[9] = 2; // available time
    client5.clientAttr[10] = 1; // strength level
    client5.clientAttr[11] = 2; // preferred climate
    client5.clientAttr[12] = 0; // dependency preference
    client5.clientAttr[13] = 2; // living space preference
    client5.clientAttr[14] = 1; // energy level preference
    client5.clientAttr[15] = 1; // intelligence preference
    client5.clientAttr[16] = 0; // difficulty preference
    client5.clientAttr[17] = 0; // nosie preference
    client5.clientAttr[18] = 0; // special requirements

    client6.clientName = "Sarah";  // Name
    client6.clientAttr[0] = 100100333; // Home phone
    client6.clientAttr[1] = 132643890; // Mobile phone
    client6.clientAttr[2] = 23; // Client's age
    client6.clientAttr[3] =  1; // Gender
    client6.clientAddr = "20 Huron Road, Mississauga, Ontario"; // Address
    client6.clientEmail = "sarah@rogers.ca"; // Email
    client6.clientId = 6; // Unique identifer
    client6.breed = "None"; // Client's preference for breed
    client6.species = "Dog"; // Client's preference for specie
    client6.clientAttr[4] = 3; // economic background
    client6.clientAttr[5] = 2; // activity level
    client6.clientAttr[6] = 3; // experience with animals
    client6.clientAttr[7] = 1; // patience level
    client6.clientAttr[8] = 2; // house size
    client6.clientAttr[9] = 1; // available time
    client6.clientAttr[10] = 2; // strength level
    client6.clientAttr[11] = 3; // preferred climate
    client6.clientAttr[12] = 0; // dependency preference
    client6.clientAttr[13] = 0; // living space preference
    client6.clientAttr[14] = 2; // energy level preference
    client6.clientAttr[15] = 2; // intelligence preference
    client6.clientAttr[16] = 2; // difficulty preference
    client6.clientAttr[17] = 0; // nosie preference
    client6.clientAttr[18] = 0; // special requirements

    client7.clientName = "Emma";  // Name
    client7.clientAttr[0] = 356990323; // Home phone
    client7.clientAttr[1] = 400100323; // Mobile phone
    client7.clientAttr[2] = 52; // Client's age
    client7.clientAttr[3] =  1; // Gender
    client7.clientAddr = "20 Huron Road, Mississauga, Ontario"; // Address
    client7.clientEmail = "emma@hotmail.com"; // Email
    client7.clientId = 7; // Unique identifer
    client7.breed = "None"; // Client's preference for breed
    client7.species = "Dog"; // Client's preference for specie
    client7.clientAttr[4] = 2; // economic background
    client7.clientAttr[5] = 3; // activity level
    client7.clientAttr[6] = 3; // experience with animals
    client7.clientAttr[7] = 3; // patience level
    client7.clientAttr[8] = 1; // house size
    client7.clientAttr[9] = 3; // available time
    client7.clientAttr[10] = 2; // strength level
    client7.clientAttr[11] = 3; // preferred climate
    client7.clientAttr[12] = 3; // dependency preference
    client7.clientAttr[13] = 0; // living space preference
    client7.clientAttr[14] = 3; // energy level preference
    client7.clientAttr[15] = 2; // intelligence preference
    client7.clientAttr[16] = 1; // difficulty preference
    client7.clientAttr[17] = 1; // nosie preference
    client7.clientAttr[18] = 0; // special requirements

    client8.clientName = "Kaitlyn";  // Name
    client8.clientAttr[0] = 123697332; // Home phone
    client8.clientAttr[1] = 167888999; // Mobile phone
    client8.clientAttr[2] = 26; // Client's age
    client8.clientAttr[3] =  1; // Gender
    client8.clientAddr = "100 Kilborn Avenue, Ottawa, Ontario"; // Address
    client8.clientEmail = "kaitlyn@yahoo.com"; // Email
    client8.clientId = 8; // Unique identifer
    client8.breed = "None"; // Client's preference for breed
    client8.species = "Bear"; // Client's preference for specie
    client8.clientAttr[4] = 2; // economic background
    client8.clientAttr[5] = 3; // activity level
    client8.clientAttr[6] = 2; // experience with animals
    client8.clientAttr[7] = 2; // patience level
    client8.clientAttr[8] = 2; // house size
    client8.clientAttr[9] = 2; // available time
    client8.clientAttr[10] = 3; // strength level
    client8.clientAttr[11] = 2; // preferred climate
    client8.clientAttr[12] = 1; // dependency preference
    client8.clientAttr[13] = 3; // living space preference
    client8.clientAttr[14] = 3; // energy level preference
    client8.clientAttr[15] = 3; // intelligence preference
    client8.clientAttr[16] = 3; // difficulty preference
    client8.clientAttr[17] = 0; // noise preference
    client8.clientAttr[18] = 0; // special requirements

    client9.clientName = "Krystal";  // Name
    client9.clientAttr[0] = 100800777; // Home phone
    client9.clientAttr[1] = 705718745; // Mobile phone
    client9.clientAttr[2] = 80; // Client's age
    client9.clientAttr[3] =  1; // Gender
    client9.clientAddr = "388 Bank Street, Ottawa, Ontario"; // Address
    client9.clientEmail = "krystalmlm@hotmail.com"; // Email
    client9.clientId = 9; // Unique identifer
    client9.breed = "None"; // Client's preference for breed
    client9.species = "Cat"; // Client's preference for specie
    client9.clientAttr[4] = 1; // economic background
    client9.clientAttr[5] = 3; // activity level
    client9.clientAttr[6] = 1; // experience with animals
    client9.clientAttr[7] = 3; // patience level
    client9.clientAttr[8] = 1; // house size
    client9.clientAttr[9] = 3; // available time
    client9.clientAttr[10] = 1; // strength level
    client9.clientAttr[11] = 2; // preferred climate
    client9.clientAttr[12] = 2; // dependency preference
    client9.clientAttr[13] = 1; // living space preference
    client9.clientAttr[14] = 2; // energy level preference
    client9.clientAttr[15] = 1; // intelligence preference
    client9.clientAttr[16] = 1; // difficulty preference
    client9.clientAttr[17] = 0; // noise preference
    client9.clientAttr[18] = 0; // special requirements

    client10.clientName = "Frances";  // Name
    client10.clientAttr[0] = 905775353; // Home phone
    client10.clientAttr[1] = 385223805; // Mobile phone
    client10.clientAttr[2] = 42; // Client's age
    client10.clientAttr[3] =  1; // Gender
    client10.clientAddr = "100 Melborne Crescent, Bradford, Ontario"; // Address
    client10.clientEmail = "fran@gmail.com"; // Email
    client10.clientId = 10; // Unique identifer
    client10.breed = "Calico"; // Client's preference for breed
    client10.species = "Cat"; // Client's preference for specie
    client10.clientAttr[4] = 3; // economic background
    client10.clientAttr[5] = 1; // activity level
    client10.clientAttr[6] = 1; // experience with animals
    client10.clientAttr[7] = 2; // patience level
    client10.clientAttr[8] = 2; // house size
    client10.clientAttr[9] = 3; // available time
    client10.clientAttr[10] = 1; // strength level
    client10.clientAttr[11] = 3; // preferred climate
    client10.clientAttr[12] = 2; // dependency preference
    client10.clientAttr[13] = 2; // living space preference
    client10.clientAttr[14] = 1; // energy level preference
    client10.clientAttr[15] = 2; // intelligence preference
    client10.clientAttr[16] = 0; // difficulty preference
    client10.clientAttr[17] = 1; // noise preference
    client10.clientAttr[18] = 0; // special requirements

    client11.clientName = "Grant";  // Name
    client11.clientAttr[0] = 900500444; // Home phone
    client11.clientAttr[1] = 900400333; // Mobile phone
    client11.clientAttr[2] = 28; // Client's age
    client11.clientAttr[3] =  0; // Gender
    client11.clientAddr = "60 Walkley Road, Ottawa, Ontario"; // Address
    client11.clientEmail = "None"; // Email
    client11.clientId = 11; // Unique identifer
    client11.breed = "None"; // Client's preference for breed
    client11.species = "Fish"; // Client's preference for specie
    client11.clientAttr[4] = 1; // economic background
    client11.clientAttr[5] = 3; // activity level
    client11.clientAttr[6] = 2; // experience with animals
    client11.clientAttr[7] = 1; // patience level
    client11.clientAttr[8] = 2; // house size
    client11.clientAttr[9] = 3; // available time
    client11.clientAttr[10] = 3; // strength level
    client11.clientAttr[11] = 2; // preferred climate
    client11.clientAttr[12] = 1; // dependency preference
    client11.clientAttr[13] = 1; // living space preference
    client11.clientAttr[14] = 2; // energy level preference
    client11.clientAttr[15] = 1; // intelligence preference
    client11.clientAttr[16] = 0; // difficulty preference
    client11.clientAttr[17] = 0; // noise preference
    client11.clientAttr[18] = 1; // special requirements

    client12.clientName = "Ferdinand";  // Name
    client12.clientAttr[0] = 999765345; // Home phone
    client12.clientAttr[1] = 222813901; // Mobile phone
    client12.clientAttr[2] = 33; // Client's age
    client12.clientAttr[3] =  0; // Gender
    client12.clientAddr = "600 Rideau Street, Ottawa, Ontario"; // Address
    client12.clientEmail = "fern@hotmail.com"; // Email
    client12.clientId = 12; // Unique identifer
    client12.breed = "None"; // Client's preference for breed
    client12.species = "None"; // Client's preference for specie
    client12.clientAttr[4] = 3; // economic background
    client12.clientAttr[5] = 1; // activity level
    client12.clientAttr[6] = 1; // experience with animals
    client12.clientAttr[7] = 2; // patience level
    client12.clientAttr[8] = 3; // house size
    client12.clientAttr[9] = 3; // available time
    client12.clientAttr[10] = 2; // strength level
    client12.clientAttr[11] = 3; // preferred climate
    client12.clientAttr[12] = 2; // dependency preference
    client12.clientAttr[13] = 2; // living space preference
    client12.clientAttr[14] = 2; // energy level preference
    client12.clientAttr[15] = 0; // intelligence preference
    client12.clientAttr[16] = 0; // difficulty preference
    client12.clientAttr[17] = 3; // noise preference
    client12.clientAttr[18] = 0; // special requirements

    client13.clientName = "Patricia";  // Name
    client13.clientAttr[0] = 545255550; // Home phone
    client13.clientAttr[1] = 545600666; // Mobile phone
    client13.clientAttr[2] = 27; // Client's age
    client13.clientAttr[3] =  1; // Gender
    client13.clientAddr = "55 Queen Street West, Toronto, Ontario"; // Address
    client13.clientEmail = "patricia_cookies@gmail.com"; // Email
    client13.clientId = 13; // Unique identifer
    client13.breed = "None"; // Client's preference for breed
    client13.species = "None"; // Client's preference for specie
    client13.clientAttr[4] = 3; // economic background
    client13.clientAttr[5] = 1; // activity level
    client13.clientAttr[6] = 3; // experience with animals
    client13.clientAttr[7] = 3; // patience level
    client13.clientAttr[8] = 2; // house size
    client13.clientAttr[9] = 1; // available time
    client13.clientAttr[10] = 2; // strength level
    client13.clientAttr[11] = 3; // preferred climate
    client13.clientAttr[12] = 0; // dependency preference
    client13.clientAttr[13] = 2; // living space preference
    client13.clientAttr[14] = 3; // energy level preference
    client13.clientAttr[15] = 0; // intelligence preference
    client13.clientAttr[16] = 2; // difficulty preference
    client13.clientAttr[17] = 1; // noise preference
    client13.clientAttr[18] = 0; // special requirements

    client14.clientName = "Ray";  // Name
    client14.clientAttr[0] = 106987352; // Home phone
    client14.clientAttr[1] = 691002000; // Mobile phone
    client14.clientAttr[2] = 22; // Client's age
    client14.clientAttr[3] =  0; // Gender
    client14.clientAddr = "500 Main Street, Newmarket, Ontario"; // Address
    client14.clientEmail = "rayisagod@cmail.carleton.ca"; // Email
    client14.clientId = 14; // Unique identifer
    client14.breed = "Polar"; // Client's preference for breed
    client14.species = "Bear"; // Client's preference for specie
    client14.clientAttr[4] = 3; // economic background
    client14.clientAttr[5] = 3; // activity level
    client14.clientAttr[6] = 3; // experience with animals
    client14.clientAttr[7] = 3; // patience level
    client14.clientAttr[8] = 3; // house size
    client14.clientAttr[9] = 3; // available time
    client14.clientAttr[10] = 3; // strength level
    client14.clientAttr[11] = 3; // preferred climate
    client14.clientAttr[12] = 3; // dependency preference
    client14.clientAttr[13] = 3; // living space preference
    client14.clientAttr[14] = 3; // energy level preference
    client14.clientAttr[15] = 3; // intelligence preference
    client14.clientAttr[16] = 3; // difficulty preference
    client14.clientAttr[17] = 3; // noise preference
    client14.clientAttr[18] = 0; // special requirements

    client15.clientName = "Kyoto";  // Name
    client15.clientAttr[0] = 300600892; // Home phone
    client15.clientAttr[1] = 666934929; // Mobile phone
    client15.clientAttr[2] = 40; // Client's age
    client15.clientAttr[3] =  1; // Gender
    client15.clientAddr = "500 Japan Street, Toronto, Ontario"; // Address
    client15.clientEmail = "kyoto@japan.gov"; // Email
    client15.clientId = 15; // Unique identifer
    client15.breed = "None"; // Client's preference for breed
    client15.species = "None"; // Client's preference for specie
    client15.clientAttr[4] = 2; // economic background
    client15.clientAttr[5] = 1; // activity level
    client15.clientAttr[6] = 3; // experience with animals
    client15.clientAttr[7] = 2; // patience level
    client15.clientAttr[8] = 1; // house size
    client15.clientAttr[9] = 3; // available time
    client15.clientAttr[10] = 1; // strength level
    client15.clientAttr[11] = 1; // preferred climate
    client15.clientAttr[12] = 0; // dependency preference
    client15.clientAttr[13] = 0; // living space preference
    client15.clientAttr[14] = 0; // energy level preference
    client15.clientAttr[15] = 0; // intelligence preference
    client15.clientAttr[16] = 2; // difficulty preference
    client15.clientAttr[17] = 2; // noise preference
    client15.clientAttr[18] = 0; // special requirements

    client16.clientName = "Steven";  // Name
    client16.clientAttr[0] = 100225985; // Home phone
    client16.clientAttr[1] = 200132423; // Mobile phone
    client16.clientAttr[2] = 56; // Client's age
    client16.clientAttr[3] =  0; // Gender
    client16.clientAddr = "443 McLaren Street, Ottawa, Ontario"; // Address
    client16.clientEmail = "steven@canada.gov"; // Email
    client16.clientId = 16; // Unique identifer
    client16.breed = "None"; // Client's preference for breed
    client16.species = "None"; // Client's preference for specie
    client16.clientAttr[4] = 2; // economic background
    client16.clientAttr[5] = 1; // activity level
    client16.clientAttr[6] = 3; // experience with animals
    client16.clientAttr[7] = 2; // patience level
    client16.clientAttr[8] = 1; // house size
    client16.clientAttr[9] = 3; // available time
    client16.clientAttr[10] = 1; // strength level
    client16.clientAttr[11] = 3; // preferred climate
    client16.clientAttr[12] = 3; // dependency preference
    client16.clientAttr[13] = 0; // living space preference
    client16.clientAttr[14] = 0; // energy level preference
    client16.clientAttr[15] = 0; // intelligence preference
    client16.clientAttr[16] = 2; // difficulty preference
    client16.clientAttr[17] = 2; // noise preference
    client16.clientAttr[18] = 3; // special requirements

    client17.clientName = "Terry";  // Name
    client17.clientAttr[0] = 334223123; // Home phone
    client17.clientAttr[1] = 932560312; // Mobile phone
    client17.clientAttr[2] = 35; // Client's age
    client17.clientAttr[3] =  0; // Gender
    client17.clientAddr = "123 Beaver Street, Ottawa, Ontario"; // Address
    client17.clientEmail = "terry@cmail.carleton.ca"; // Email
    client17.clientId = 17; // Unique identifer
    client17.breed = "None"; // Client's preference for breed
    client17.species = "Cat"; // Client's preference for specie
    client17.clientAttr[4] = 2; // economic background
    client17.clientAttr[5] = 2; // activity level
    client17.clientAttr[6] = 2; // experience with animals
    client17.clientAttr[7] = 3; // patience level
    client17.clientAttr[8] = 2; // house size
    client17.clientAttr[9] = 1; // available time
    client17.clientAttr[10] = 1; // strength level
    client17.clientAttr[11] = 2; // preferred climate
    client17.clientAttr[12] = 0; // dependency preference
    client17.clientAttr[13] = 2; // living space preference
    client17.clientAttr[14] = 0; // energy level preference
    client17.clientAttr[15] = 2; // intelligence preference
    client17.clientAttr[16] = 3; // difficulty preference
    client17.clientAttr[17] = 3; // noise preference
    client17.clientAttr[18] = 4; // special requirements

    client18.clientName = "Carolyne";  // Name
    client18.clientAttr[0] = 988234213; // Home phone
    client18.clientAttr[1] = 455988432; // Mobile phone
    client18.clientAttr[2] = 33; // Client's age
    client18.clientAttr[3] =  1; // Gender
    client18.clientAddr = "423 St Catherine Street West, Montreal, Quebec"; // Address
    client18.clientEmail = "carolynesmart@mcgill.ca"; // Email
    client18.clientId = 18; // Unique identifer
    client18.breed = "None"; // Client's preference for breed
    client18.species = "None"; // Client's preference for specie
    client18.clientAttr[4] = 2; // economic background
    client18.clientAttr[5] = 3; // activity level
    client18.clientAttr[6] = 1; // experience with animals
    client18.clientAttr[7] = 3; // patience level
    client18.clientAttr[8] = 2; // house size
    client18.clientAttr[9] = 1; // available time
    client18.clientAttr[10] = 2; // strength level
    client18.clientAttr[11] = 3; // preferred climate
    client18.clientAttr[12] = 3; // dependency preference
    client18.clientAttr[13] = 1; // living space preference
    client18.clientAttr[14] = 1; // energy level preference
    client18.clientAttr[15] = 2; // intelligence preference
    client18.clientAttr[16] = 1; // difficulty preference
    client18.clientAttr[17] = 0; // noise preference
    client18.clientAttr[18] = 0; // special requirements

    client19.clientName = "Priya";  // Name
    client19.clientAttr[0] = 123451212; // Home phone
    client19.clientAttr[1] = 448950812; // Mobile phone
    client19.clientAttr[2] = 21; // Client's age
    client19.clientAttr[3] =  1; // Gender
    client19.clientAddr = "22 Alta Vista Drive, Ottawa, Ontario"; // Address
    client19.clientEmail = "priya@rogers.ca"; // Email
    client19.clientId = 19; // Unique identifer
    client19.breed = "Eagle"; // Client's preference for breed
    client19.species = "Bird"; // Client's preference for specie
    client19.clientAttr[4] = 3; // economic background
    client19.clientAttr[5] = 1; // activity level
    client19.clientAttr[6] = 1; // experience with animals
    client19.clientAttr[7] = 3; // patience level
    client19.clientAttr[8] = 2; // house size
    client19.clientAttr[9] = 3; // available time
    client19.clientAttr[10] = 1; // strength level
    client19.clientAttr[11] = 3; // preferred climate
    client19.clientAttr[12] = 3; // dependency preference
    client19.clientAttr[13] = 1; // living space preference
    client19.clientAttr[14] = 0; // energy level preference
    client19.clientAttr[15] = 1; // intelligence preference
    client19.clientAttr[16] = 0; // difficulty preference
    client19.clientAttr[17] = 0; // noise preference
    client19.clientAttr[18] = 0; // special requirements

    client20.clientName = "Bawd";  // Name
    client20.clientAttr[0] = 232423123; // Home phone
    client20.clientAttr[1] = 545431232; // Mobile phone
    client20.clientAttr[2] = 65; // Client's age
    client20.clientAttr[3] =  0; // Gender
    client20.clientAddr = "Garbage Street, Ottawa, Ontario"; // Address
    client20.clientEmail = "whousesyahooanymore@yahoo.ca"; // Email
    client20.clientId = 20; // Unique identifer
    client20.breed = "German"; // Client's preference for breed
    client20.species = "Dog"; // Client's preference for specie
    client20.clientAttr[4] = 1; // economic background
    client20.clientAttr[5] = 1; // activity level
    client20.clientAttr[6] = 1; // experience with animals
    client20.clientAttr[7] = 1; // patience level
    client20.clientAttr[8] = 1; // house size
    client20.clientAttr[9] = 1; // available time
    client20.clientAttr[10] = 1; // strength level
    client20.clientAttr[11] = 1; // preferred climate
    client20.clientAttr[12] = 0; // dependency preference
    client20.clientAttr[13] = 0; // living space preference
    client20.clientAttr[14] = 0; // energy level preference
    client20.clientAttr[15] = 0; // intelligence preference
    client20.clientAttr[16] = 0; // difficulty preference
    client20.clientAttr[17] = 0; // noise preference
    client20.clientAttr[18] = 0; // special requirements

    animal1.animalId = 1;
    animal2.animalId = 2;
    animal3.animalId = 3;
    animal4.animalId = 4;
    animal5.animalId = 5;
    animal6.animalId = 6;
    animal7.animalId = 7;
    animal8.animalId = 8;
    animal9.animalId = 9;
    animal10.animalId = 10;
    animal11.animalId = 11;
    animal12.animalId = 12;
    animal13.animalId = 13;
    animal14.animalId = 14;
    animal15.animalId = 15;
    animal16.animalId = 16;
    animal17.animalId = 17;
    animal18.animalId = 18;
    animal19.animalId = 19;
    animal20.animalId = 20;
    animal21.animalId = 21;
    animal22.animalId = 22;
    animal23.animalId = 23;
    animal24.animalId = 24;
    animal25.animalId = 25;

    animal1.animalName = "Victor";
    animal2.animalName = "Kyle";
    animal3.animalName = "Parfait";
    animal4.animalName = "John";
    animal5.animalName = "Ringo";
    animal6.animalName = "Rogue";
    animal7.animalName = "Bella";
    animal8.animalName = "Lucy";
    animal9.animalName = "Daisy";
    animal10.animalName = "Lily";
    animal11.animalName = "Maggie";
    animal12.animalName = "Molly";
    animal13.animalName = "Charlie";
    animal14.animalName = "Luna";
    animal15.animalName = "Stella";
    animal16.animalName = "Ellie";
    animal17.animalName = "Abby";
    animal18.animalName = "Coco";
    animal19.animalName = "Chloe";
    animal20.animalName = "Sophie";
    animal21.animalName = "Mufin";
    animal22.animalName = "Rootbeer";
    animal23.animalName = "Lizzy";
    animal24.animalName = "Panther";
    animal25.animalName = "Peter";

    animal1.typeOfAnimal="Dog";
    animal2.typeOfAnimal="Cat";
    animal3.typeOfAnimal="Dog";
    animal4.typeOfAnimal="Cat";
    animal5.typeOfAnimal="Bear";
    animal6.typeOfAnimal="Bird";
    animal7.typeOfAnimal="Fish";
    animal8.typeOfAnimal="Bear";
    animal9.typeOfAnimal="Bear";
    animal10.typeOfAnimal="Fish";
    animal11.typeOfAnimal="Dog";
    animal12.typeOfAnimal="Dog";
    animal13.typeOfAnimal="Cat";
    animal14.typeOfAnimal="Fish";
    animal15.typeOfAnimal="Fish";
    animal16.typeOfAnimal="Bear";
    animal17.typeOfAnimal="Bear";
    animal18.typeOfAnimal="Bear";
    animal19.typeOfAnimal="Bird";
    animal20.typeOfAnimal="Cat";
    animal21.typeOfAnimal="Dog";
    animal22.typeOfAnimal="Bear";
    animal23.typeOfAnimal="Dog";
    animal24.typeOfAnimal="Cat";
    animal25.typeOfAnimal="Dog";

    animal1.breed = "Blacklab";
    animal2.breed = "Calico";
    animal3.breed = "Corgi";
    animal4.breed = "Leopard";
    animal5.breed = "Polar";
    animal6.breed = "Parrot";
    animal7.breed = "Goldfish";
    animal8.breed = "Black";
    animal9.breed = "Panda";
    animal10.breed = "Dwarflanternshark";
    animal11.breed = "Shiba Inu";
    animal12.breed = "Bulldog";
    animal13.breed = "Calico";
    animal14.breed = "Carp";
    animal15.breed = "Koi";
    animal16.breed = "Grizzly";
    animal17.breed = "Polar";
    animal18.breed = "Black";
    animal19.breed = "Eagle";
    animal20.breed = "Panther";
    animal21.breed = "Blacklab";
    animal22.breed = "Panda";
    animal23.breed = "Bulldog";
    animal24.breed = "Leopard";
    animal25.breed = "German";

    animal1.colour = "Brown";
    animal2.colour = "Gray";
    animal3.colour = "Blue";
    animal4.colour = "Pink";
    animal5.colour = "Black";
    animal6.colour = "All";
    animal7.colour = "Brown";
    animal8.colour = "Gray";
    animal9.colour = "Blue";
    animal10.colour = "Pink";
    animal11.colour = "Black";
    animal12.colour = "Brown";
    animal13.colour = "Gray";
    animal14.colour = "Blue";
    animal15.colour = "Pink";
    animal16.colour = "Black";
    animal17.colour = "Brown";
    animal18.colour = "Gray";
    animal19.colour = "Blue";
    animal20.colour = "Pink";
    animal21.colour = "Black";
    animal22.colour = "Brown";
    animal23.colour = "Gray";
    animal24.colour = "Blue";
    animal25.colour = "Pink";

    animal1.specialSkill = "Seeing-eye";
    animal11.specialSkill = "Seeing-eye";
    animal12.specialSkill = "Show";
    animal15.specialSkill = "Drug-sniffing";
    animal20.specialSkill = "Hunting";
    animal21.specialSkill = "Security";



    animal1.animalAttr[0] = 1;
    animal2.animalAttr[0] = 1;
    animal3.animalAttr[0] = 1;
    animal4.animalAttr[0] = 1;
    animal5.animalAttr[0] = 1;
    animal6.animalAttr[0] = 1;
    animal7.animalAttr[0] = 1;
    animal8.animalAttr[0] = 1;
    animal9.animalAttr[0] = 1;
    animal10.animalAttr[0] = 1;
    animal11.animalAttr[0] = 1;
    animal12.animalAttr[0] = 1;
    animal13.animalAttr[0] = 1;
    animal14.animalAttr[0] = 1;
    animal15.animalAttr[0] = 1;
    animal16.animalAttr[0] = 1;
    animal17.animalAttr[0] = 1;
    animal18.animalAttr[0] = 1;
    animal19.animalAttr[0] = 1;
    animal20.animalAttr[0] = 1;
    animal21.animalAttr[0] = 1;
    animal22.animalAttr[0] = 1;
    animal23.animalAttr[0] = 1;
    animal24.animalAttr[0] = 1;
    animal25.animalAttr[0] = 1;

    animal1.animalAttr[1] = 9;
    animal2.animalAttr[1] = 6;
    animal3.animalAttr[1] = 7;
    animal4.animalAttr[1] = 2;
    animal5.animalAttr[1] = 3;
    animal6.animalAttr[1] = 4;
    animal7.animalAttr[1] = 5;
    animal8.animalAttr[1] = 8;
    animal9.animalAttr[1] = 11;
    animal10.animalAttr[1] = 12;
    animal11.animalAttr[1] = 2;
    animal12.animalAttr[1] = 3;
    animal13.animalAttr[1] = 18;
    animal14.animalAttr[1] = 16;
    animal15.animalAttr[1] = 15;
    animal16.animalAttr[1] = 4;
    animal17.animalAttr[1] = 11;
    animal18.animalAttr[1] = 7;
    animal19.animalAttr[1] = 9;
    animal20.animalAttr[1] = 10;
    animal21.animalAttr[1] = 12;
    animal22.animalAttr[1] = 13;
    animal23.animalAttr[1] = 3;
    animal24.animalAttr[1] = 5;
    animal25.animalAttr[1] = 4;

    animal1.animalAttr[2] = 100;
    animal2.animalAttr[2] = 10;
    animal3.animalAttr[2] = 90;
    animal4.animalAttr[2] = 6;
    animal5.animalAttr[2] = 400;
    animal6.animalAttr[2] = 3;
    animal7.animalAttr[2] = 1;
    animal8.animalAttr[2] = 251;
    animal9.animalAttr[2] = 300;
    animal10.animalAttr[2] = 20;
    animal11.animalAttr[2] = 20;
    animal12.animalAttr[2] = 30;
    animal13.animalAttr[2] = 18;
    animal14.animalAttr[2] = 30;
    animal15.animalAttr[2] = 8;
    animal16.animalAttr[2] = 5;
    animal17.animalAttr[2] = 11;
    animal18.animalAttr[2] = 401;
    animal19.animalAttr[2] = 450;
    animal20.animalAttr[2] = 300;
    animal21.animalAttr[2] = 26;
    animal22.animalAttr[2] = 40;
    animal23.animalAttr[2] = 35;
    animal24.animalAttr[2] = 366;
    animal25.animalAttr[2] = 66;

    animal1.animalAttr[3] = 36;
    animal2.animalAttr[3] = 13;
    animal3.animalAttr[3] = 40;
    animal4.animalAttr[3] = 12;
    animal5.animalAttr[3] = 50;
    animal6.animalAttr[3] = 7;
    animal7.animalAttr[3] = 2;
    animal8.animalAttr[3] = 36;
    animal9.animalAttr[3] = 41;
    animal10.animalAttr[3] = 18;
    animal11.animalAttr[3] = 30;
    animal12.animalAttr[3] = 33;
    animal13.animalAttr[3] = 24;
    animal14.animalAttr[3] = 13;
    animal15.animalAttr[3] = 8;
    animal16.animalAttr[3] = 72;
    animal17.animalAttr[3] = 80;
    animal18.animalAttr[3] = 49;
    animal19.animalAttr[3] = 19;
    animal20.animalAttr[3] = 39;
    animal21.animalAttr[3] = 34;
    animal22.animalAttr[3] = 65;
    animal23.animalAttr[3] = 25;
    animal24.animalAttr[3] = 40;
    animal25.animalAttr[3] = 42;

    animal1.animalAttr[4] = 1;
    animal2.animalAttr[4] = 3;
    animal3.animalAttr[4] = 2;
    animal4.animalAttr[4] = 2;
    animal5.animalAttr[4] = 1;
    animal6.animalAttr[4] = 3;
    animal7.animalAttr[4] = 3;
    animal8.animalAttr[4] = 3;
    animal9.animalAttr[4] = 1;
    animal10.animalAttr[4] = 1;
    animal11.animalAttr[4] = 1;
    animal12.animalAttr[4] = 1;
    animal13.animalAttr[4] = 2;
    animal14.animalAttr[4] = 1;
    animal15.animalAttr[4] = 3;
    animal16.animalAttr[4] = 2;
    animal17.animalAttr[4] = 2;
    animal18.animalAttr[4] = 3;
    animal19.animalAttr[4] = 2;
    animal20.animalAttr[4] = 1;
    animal21.animalAttr[4] = 2;
    animal22.animalAttr[4] = 3;
    animal23.animalAttr[4] = 3;
    animal24.animalAttr[4] = 2;
    animal25.animalAttr[4] = 1;

    animal1.animalAttr[5] = 3;
    animal2.animalAttr[5] = 3;
    animal3.animalAttr[5] = 2;
    animal4.animalAttr[5] = 3;
    animal5.animalAttr[5] = 1;
    animal6.animalAttr[5] = 1;
    animal7.animalAttr[5] = 3;
    animal8.animalAttr[5] = 1;
    animal9.animalAttr[5] = 2;
    animal10.animalAttr[5] = 2;
    animal11.animalAttr[5] = 2;
    animal12.animalAttr[5] = 2;
    animal13.animalAttr[5] = 3;
    animal14.animalAttr[5] = 3;
    animal15.animalAttr[5] = 2;
    animal16.animalAttr[5] = 2;
    animal17.animalAttr[5] = 2;
    animal18.animalAttr[5] = 1;
    animal19.animalAttr[5] = 1;
    animal20.animalAttr[5] = 2;
    animal21.animalAttr[5] = 3;
    animal22.animalAttr[5] = 2;
    animal23.animalAttr[5] = 2;
    animal24.animalAttr[5] = 3;
    animal25.animalAttr[5] = 1;

    animal1.animalAttr[5] = 1;
    animal2.animalAttr[5] = 1;
    animal3.animalAttr[5] = 1;
    animal4.animalAttr[5] = 3;
    animal5.animalAttr[5] = 2;
    animal6.animalAttr[5] = 1;
    animal7.animalAttr[5] = 1;
    animal8.animalAttr[5] = 2;
    animal9.animalAttr[5] = 2;
    animal10.animalAttr[5] = 3;
    animal11.animalAttr[5] = 3;
    animal12.animalAttr[5] = 3;
    animal13.animalAttr[5] = 3;
    animal14.animalAttr[5] = 2;
    animal15.animalAttr[5] = 2;
    animal16.animalAttr[5] = 3;
    animal17.animalAttr[5] = 3;
    animal18.animalAttr[5] = 2;
    animal19.animalAttr[5] = 1;
    animal20.animalAttr[5] = 1;
    animal21.animalAttr[5] = 1;
    animal22.animalAttr[5] = 2;
    animal23.animalAttr[5] = 2;
    animal24.animalAttr[5] = 3;
    animal25.animalAttr[5] = 2;

    animal1.animalAttr[6] = 1;
    animal2.animalAttr[6] = 2;
    animal3.animalAttr[6] = 1;
    animal4.animalAttr[6] = 3;
    animal5.animalAttr[6] = 2;
    animal6.animalAttr[6] = 2;
    animal7.animalAttr[6] = 3;
    animal8.animalAttr[6] = 3;
    animal9.animalAttr[6] = 3;
    animal10.animalAttr[6] = 3;
    animal11.animalAttr[6] = 3;
    animal12.animalAttr[6] = 3;
    animal13.animalAttr[6] = 3;
    animal14.animalAttr[6] = 3;
    animal15.animalAttr[6] = 3;
    animal16.animalAttr[6] = 3;
    animal17.animalAttr[6] = 3;
    animal18.animalAttr[6] = 2;
    animal19.animalAttr[6] = 3;
    animal20.animalAttr[6] = 1;
    animal21.animalAttr[6] = 3;
    animal22.animalAttr[6] = 2;
    animal23.animalAttr[6] = 2;
    animal24.animalAttr[6] = 2;
    animal25.animalAttr[6] = 2;

    animal1.animalAttr[7] = 1;
    animal2.animalAttr[7] = 2;
    animal3.animalAttr[7] = 2;
    animal4.animalAttr[7] = 2;
    animal5.animalAttr[7] = 1;
    animal6.animalAttr[7] = 1;
    animal7.animalAttr[7] = 2;
    animal8.animalAttr[7] = 2;
    animal9.animalAttr[7] = 1;
    animal10.animalAttr[7] = 2;
    animal11.animalAttr[7] = 3;
    animal12.animalAttr[7] = 3;
    animal13.animalAttr[7] = 3;
    animal14.animalAttr[7] = 3;
    animal15.animalAttr[7] = 3;
    animal16.animalAttr[7] = 3;
    animal17.animalAttr[7] = 3;
    animal18.animalAttr[7] = 3;
    animal19.animalAttr[7] = 3;
    animal20.animalAttr[7] = 3;
    animal21.animalAttr[7] = 2;
    animal22.animalAttr[7] = 2;
    animal23.animalAttr[7] = 2;
    animal24.animalAttr[7] = 3;
    animal25.animalAttr[7] = 2;

    animal1.animalAttr[8] = 2;
    animal2.animalAttr[8] = 3;
    animal3.animalAttr[8] = 2;
    animal4.animalAttr[8] = 2;
    animal5.animalAttr[8] = 1;
    animal6.animalAttr[8] = 3;
    animal7.animalAttr[8] = 1;
    animal8.animalAttr[8] = 1;
    animal9.animalAttr[8] = 2;
    animal10.animalAttr[8] = 2;
    animal11.animalAttr[8] = 2;
    animal12.animalAttr[8] = 2;
    animal13.animalAttr[8] = 3;
    animal14.animalAttr[8] = 3;
    animal15.animalAttr[8] = 3;
    animal16.animalAttr[8] = 3;
    animal17.animalAttr[8] = 3;
    animal18.animalAttr[8] = 2;
    animal19.animalAttr[8] = 2;
    animal20.animalAttr[8] = 2;
    animal21.animalAttr[8] = 1;
    animal22.animalAttr[8] = 2;
    animal23.animalAttr[8] = 3;
    animal24.animalAttr[8] = 2;
    animal25.animalAttr[8] = 1;

    animal1.animalAttr[9] = 3;
    animal2.animalAttr[9] = 2;
    animal3.animalAttr[9] = 2;
    animal4.animalAttr[9] = 3;
    animal5.animalAttr[9] = 2;
    animal6.animalAttr[9] = 3;
    animal7.animalAttr[9] = 3;
    animal8.animalAttr[9] = 3;
    animal9.animalAttr[9] = 2;
    animal10.animalAttr[9] = 2;
    animal11.animalAttr[9] = 3;
    animal12.animalAttr[9] = 1;
    animal13.animalAttr[9] = 1;
    animal14.animalAttr[9] = 2;
    animal15.animalAttr[9] = 3;
    animal16.animalAttr[9] = 1;
    animal17.animalAttr[9] = 3;
    animal18.animalAttr[9] = 3;
    animal19.animalAttr[9] = 3;
    animal20.animalAttr[9] = 2;
    animal21.animalAttr[9] = 2;
    animal22.animalAttr[9] = 3;
    animal23.animalAttr[9] = 2;
    animal24.animalAttr[9] = 1;
    animal25.animalAttr[9] = 2;

    // living sppace 1 is ranch 2 is house 3 is apartment
    animal1.animalAttr[10] = 2;
    animal2.animalAttr[10] = 3;
    animal3.animalAttr[10] = 3;
    animal4.animalAttr[10] = 2;
    animal5.animalAttr[10] = 2;
    animal6.animalAttr[10] = 1;
    animal7.animalAttr[10] = 3;
    animal8.animalAttr[10] = 2;
    animal9.animalAttr[10] = 2;
    animal10.animalAttr[10] = 1;
    animal11.animalAttr[10] = 2;
    animal12.animalAttr[10] = 2;
    animal13.animalAttr[10] = 2;
    animal14.animalAttr[10] = 3;
    animal15.animalAttr[10] = 1;
    animal16.animalAttr[10] = 1;
    animal17.animalAttr[10] = 1;
    animal18.animalAttr[10] = 1;
    animal19.animalAttr[10] = 1;
    animal20.animalAttr[10] = 2;
    animal21.animalAttr[10] = 2;
    animal22.animalAttr[10] = 2;
    animal23.animalAttr[10] = 2;
    animal24.animalAttr[10] = 2;
    animal25.animalAttr[10] = 2;

    // Climate 1 is cold weather 2 is moderate 3 is tropical
    animal1.animalAttr[11] = 1;
    animal2.animalAttr[11] = 2;
    animal3.animalAttr[11] = 3;
    animal4.animalAttr[11] = 1;
    animal5.animalAttr[11] = 2;
    animal6.animalAttr[11] = 3;
    animal7.animalAttr[11] = 3;
    animal8.animalAttr[11] = 3;
    animal9.animalAttr[11] = 1;
    animal10.animalAttr[11] = 2;
    animal11.animalAttr[11] = 2;
    animal12.animalAttr[11] = 1;
    animal13.animalAttr[11] = 1;
    animal14.animalAttr[11] = 1;
    animal15.animalAttr[11] = 2;
    animal16.animalAttr[11] = 3;
    animal17.animalAttr[11] = 1;
    animal18.animalAttr[11] = 3;
    animal19.animalAttr[11] = 2;
    animal20.animalAttr[11] = 2;
    animal21.animalAttr[11] = 1;
    animal22.animalAttr[11] = 2;
    animal23.animalAttr[11] = 2;
    animal24.animalAttr[11] = 3;
    animal25.animalAttr[11] = 3;

    //level of care required 1 is intense 2 is requent 3 is lowest frequency
    animal1.animalAttr[12] = 1;
    animal2.animalAttr[12] = 2;
    animal3.animalAttr[12] = 3;
    animal4.animalAttr[12] = 3;
    animal5.animalAttr[12] = 2;
    animal6.animalAttr[12] = 3;
    animal7.animalAttr[12] = 3;
    animal8.animalAttr[12] = 1;
    animal9.animalAttr[12] = 1;
    animal10.animalAttr[12] = 3;
    animal11.animalAttr[12] = 3;
    animal12.animalAttr[12] = 2;
    animal13.animalAttr[12] = 3;
    animal14.animalAttr[12] = 3;
    animal15.animalAttr[12] = 3;
    animal16.animalAttr[12] = 2;
    animal17.animalAttr[12] = 3;
    animal18.animalAttr[12] = 2;
    animal19.animalAttr[12] = 3;
    animal20.animalAttr[12] = 1;
    animal21.animalAttr[12] = 1;
    animal22.animalAttr[12] = 1;
    animal23.animalAttr[12] = 2;
    animal24.animalAttr[12] = 1;
    animal25.animalAttr[12] = 1;


    // Neatness 1 is filthy 2 is average 3 is very clean
    animal1.animalAttr[13] = 1;
    animal2.animalAttr[13] = 2;
    animal3.animalAttr[13] = 3;
    animal4.animalAttr[13] = 3;
    animal5.animalAttr[13] = 2;
    animal6.animalAttr[13] = 3;
    animal7.animalAttr[13] = 3;
    animal8.animalAttr[13] = 1;
    animal9.animalAttr[13] = 1;
    animal10.animalAttr[13] = 3;
    animal11.animalAttr[13] = 3;
    animal12.animalAttr[13] = 2;
    animal13.animalAttr[13] = 3;
    animal14.animalAttr[13] = 3;
    animal15.animalAttr[13] = 3;
    animal16.animalAttr[13] = 2;
    animal17.animalAttr[13] = 3;
    animal18.animalAttr[13] = 2;
    animal19.animalAttr[13] = 3;
    animal20.animalAttr[13] = 1;
    animal21.animalAttr[13] = 1;
    animal22.animalAttr[13] = 1;
    animal23.animalAttr[13] = 2;
    animal24.animalAttr[13] = 1;
    animal25.animalAttr[13] = 1;

    //Current health 1 is currently fighting diesease 2 is weakened immune 3 is healthy
    animal1.animalAttr[14] = 1;
    animal2.animalAttr[14] = 1;
    animal3.animalAttr[14] = 2;
    animal4.animalAttr[14] = 3;
    animal5.animalAttr[14] = 3;
    animal6.animalAttr[14] = 3;
    animal7.animalAttr[14] = 1;
    animal8.animalAttr[14] = 1;
    animal9.animalAttr[14] = 2;
    animal10.animalAttr[14] = 2;
    animal11.animalAttr[14] = 2;
    animal12.animalAttr[14] = 2;
    animal13.animalAttr[14] = 2;
    animal14.animalAttr[14] = 1;
    animal15.animalAttr[14] = 2;
    animal16.animalAttr[14] = 2;
    animal17.animalAttr[14] = 1;
    animal18.animalAttr[14] = 2;
    animal19.animalAttr[14] = 3;
    animal20.animalAttr[14] = 3;
    animal21.animalAttr[14] = 3;
    animal22.animalAttr[14] = 1;
    animal23.animalAttr[14] = 1;
    animal24.animalAttr[14] = 1;
    animal25.animalAttr[14] = 2;


    // Intelligence Level 1 is stupid 2 average 3 is exceptional
    animal1.animalAttr[15] = 1;
    animal2.animalAttr[15] = 2;
    animal3.animalAttr[15] = 2;
    animal4.animalAttr[15] = 2;
    animal5.animalAttr[15] = 1;
    animal6.animalAttr[15] = 1;
    animal7.animalAttr[15] = 2;
    animal8.animalAttr[15] = 2;
    animal9.animalAttr[15] = 2;
    animal10.animalAttr[15] = 3;
    animal11.animalAttr[15] = 2;
    animal12.animalAttr[15] = 2;
    animal13.animalAttr[15] = 2;
    animal14.animalAttr[15] = 3;
    animal15.animalAttr[15] = 1;
    animal16.animalAttr[15] = 1;
    animal17.animalAttr[15] = 1;
    animal18.animalAttr[15] = 1;
    animal19.animalAttr[15] = 3;
    animal20.animalAttr[15] = 2;
    animal21.animalAttr[15] = 2;
    animal22.animalAttr[15] = 2;
    animal23.animalAttr[15] = 2;
    animal24.animalAttr[15] = 3;
    animal25.animalAttr[15] = 2;

    // Difficulty to train 1 is defiant 2 is chllenging 3 is easy
    animal1.animalAttr[16] = 1;
    animal2.animalAttr[16] = 1;
    animal3.animalAttr[16] = 2;
    animal4.animalAttr[16] = 2;
    animal5.animalAttr[16] = 2;
    animal6.animalAttr[16] = 3;
    animal7.animalAttr[16] = 3;
    animal8.animalAttr[16] = 3;
    animal9.animalAttr[16] = 3;
    animal10.animalAttr[16] = 3;
    animal11.animalAttr[16] = 2;
    animal12.animalAttr[16] = 2;
    animal13.animalAttr[16] = 3;
    animal14.animalAttr[16] = 3;
    animal15.animalAttr[16] = 3;
    animal16.animalAttr[16] = 1;
    animal17.animalAttr[16] = 1;
    animal18.animalAttr[16] = 1;
    animal19.animalAttr[16] = 1;
    animal20.animalAttr[16] = 1;
    animal21.animalAttr[16] = 2;
    animal22.animalAttr[16] = 2;
    animal23.animalAttr[16] = 2;
    animal24.animalAttr[16] = 3;
    animal25.animalAttr[16] = 3;

    // feeding cost 1 is expensive 2 is moderate 3 is cheap
    animal1.animalAttr[17] = 1;
    animal2.animalAttr[17] = 2;
    animal3.animalAttr[17] = 1;
    animal4.animalAttr[17] = 3;
    animal5.animalAttr[17] = 3;
    animal6.animalAttr[17] = 2;
    animal7.animalAttr[17] = 2;
    animal8.animalAttr[17] = 2;
    animal9.animalAttr[17] = 2;
    animal10.animalAttr[17] = 2;
    animal11.animalAttr[17] = 2;
    animal12.animalAttr[17] = 2;
    animal13.animalAttr[17] = 2;
    animal14.animalAttr[17] = 1;
    animal15.animalAttr[17] = 1;
    animal16.animalAttr[17] = 1;
    animal17.animalAttr[17] = 1;
    animal18.animalAttr[17] = 1;
    animal19.animalAttr[17] = 1;
    animal20.animalAttr[17] = 2;
    animal21.animalAttr[17] = 2;
    animal22.animalAttr[17] = 1;
    animal23.animalAttr[17] = 2;
    animal24.animalAttr[17] = 3;
    animal25.animalAttr[17] = 4;


    // noise level 1 is noisy 2 is moderate 3 is quiet
    animal1.animalAttr[18] = 1;
    animal2.animalAttr[18] = 2;
    animal3.animalAttr[18] = 3;
    animal4.animalAttr[18] = 3;
    animal5.animalAttr[18] = 2;
    animal6.animalAttr[18] = 3;
    animal7.animalAttr[18] = 3;
    animal8.animalAttr[18] = 1;
    animal9.animalAttr[18] = 1;
    animal10.animalAttr[18] = 3;
    animal11.animalAttr[18] = 3;
    animal12.animalAttr[18] = 2;
    animal13.animalAttr[18] = 3;
    animal14.animalAttr[18] = 3;
    animal15.animalAttr[18] = 3;
    animal16.animalAttr[18] = 2;
    animal17.animalAttr[18] = 3;
    animal18.animalAttr[18] = 2;
    animal19.animalAttr[18] = 3;
    animal20.animalAttr[18] = 1;
    animal21.animalAttr[18] = 1;
    animal22.animalAttr[18] = 1;
    animal23.animalAttr[18] = 2;
    animal24.animalAttr[18] = 1;
    animal25.animalAttr[18] = 1;

    /*feeding cost*/
    animal1.animalAttr[19] = 1;
    animal2.animalAttr[19] = 2;
    animal3.animalAttr[19] = 3;
    animal4.animalAttr[19] = 3;
    animal5.animalAttr[19] = 2;
    animal6.animalAttr[19] = 3;
    animal7.animalAttr[19] = 3;
    animal8.animalAttr[19] = 1;
    animal9.animalAttr[19] = 1;
    animal10.animalAttr[19] = 3;
    animal11.animalAttr[19] = 3;
    animal12.animalAttr[19] = 2;
    animal13.animalAttr[19] = 3;
    animal14.animalAttr[19] = 3;
    animal15.animalAttr[19] = 3;
    animal16.animalAttr[19] = 2;
    animal17.animalAttr[19] = 3;
    animal18.animalAttr[19] = 2;
    animal19.animalAttr[19] = 3;
    animal20.animalAttr[19] = 1;
    animal21.animalAttr[19] = 1;
    animal22.animalAttr[19] = 1;
    animal23.animalAttr[19] = 2;
    animal24.animalAttr[19] = 1;
    animal25.animalAttr[19] = 1;

    /*Noise level*/
    animal1.animalAttr[20] = 1;
    animal2.animalAttr[20] = 2;
    animal3.animalAttr[20] = 3;
    animal4.animalAttr[20] = 3;
    animal5.animalAttr[20] = 2;
    animal6.animalAttr[20] = 3;
    animal7.animalAttr[20] = 3;
    animal8.animalAttr[20] = 1;
    animal9.animalAttr[20] = 1;
    animal10.animalAttr[20] = 3;
    animal11.animalAttr[20] = 3;
    animal12.animalAttr[20] = 2;
    animal13.animalAttr[20] = 3;
    animal14.animalAttr[20] = 3;
    animal15.animalAttr[20] = 3;
    animal16.animalAttr[20] = 2;
    animal17.animalAttr[20] = 3;
    animal18.animalAttr[20] = 2;
    animal19.animalAttr[20] = 3;
    animal20.animalAttr[20] = 1;
    animal21.animalAttr[20] = 1;
    animal22.animalAttr[20] = 1;
    animal23.animalAttr[20] = 2;
    animal24.animalAttr[20] = 1;
    animal25.animalAttr[20] = 1;

    this->pushAnimal(animal1);
    this->pushAnimal(animal2);
    this->pushAnimal(animal3);
    this->pushAnimal(animal4);
    this->pushAnimal(animal5);
    this->pushAnimal(animal6);
    this->pushAnimal(animal7);
    this->pushAnimal(animal8);
    this->pushAnimal(animal9);
    this->pushAnimal(animal10);
    this->pushAnimal(animal11);
    this->pushAnimal(animal12);
    this->pushAnimal(animal13);
    this->pushAnimal(animal14);
    this->pushAnimal(animal15);
    this->pushAnimal(animal16);
    this->pushAnimal(animal17);
    this->pushAnimal(animal18);
    this->pushAnimal(animal19);
    this->pushAnimal(animal20);
    this->pushAnimal(animal21);
    this->pushAnimal(animal22);
    this->pushAnimal(animal23);
    this->pushAnimal(animal24);
    this->pushAnimal(animal25);
    this->pushClient(client1);
    this->pushClient(client2);
    this->pushClient(client3);
    this->pushClient(client4);
    this->pushClient(client5);
    this->pushClient(client6);
    this->pushClient(client7);
    this->pushClient(client8);
    this->pushClient(client9);
    this->pushClient(client10);
    this->pushClient(client11);
    this->pushClient(client12);
    this->pushClient(client13);
    this->pushClient(client14);
    this->pushClient(client15);
    this->pushClient(client16);
    this->pushClient(client17);
    this->pushClient(client18);
    this->pushClient(client19);
    this->pushClient(client20);

    return(0);
}
