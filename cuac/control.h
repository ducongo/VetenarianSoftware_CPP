#ifndef CONTROL_H
#define CONTROL_H

#include <string>

#include "animal.h"
#include "client.h"
#include "array.h"
#include "database.h"

class HomeView;


using namespace std;

class Control
{
  public:
    Control();

    void addAnimal(Animal*);
    void addClient(Client*);

    void updateAnimal(Animal*);
    void upDateClient(Client*);

    Animal* getAnimal(int);
    Client* getClient(int);
    HomeView* getHomeView();

    void populateAnimalArray();
    void populateClientArray();

    int getAnimalArraySize();
    int getClientArraySize();

    void setHomeView(HomeView*);
    void setCurrentUID(int);

    int getCurrentUID();

    string checking = "THIS FIELD SHOULD NOT BE EMPTY";
    QString energy_level[3] = {"Low", "Mwdium", "High"};
    QString temperament[3] = {"Easily excitable", "Average", "Very Relazed"};
    QString kid_friendly[3] = {"Impatient", "Moderate", "Patient"};
    QString level_of_dependency[3] = {"Under 30 minutes", "30 minutes to 2 hours", "3+ daily hours"};
    QString prone_to_disease[3] = {"Rare immune disorder", "Bad genetics", "Not prone"};
    QString living_space_needed[3] = {"Apartment", "House with yard", "Ranch"};//"Abused", "Badly Trained", "Loved"
    QString feeding_cost[3] = {"Expensive($100+)", "Moderate($500)", "Cheap(under $50)"};
    QString bad_habits[3] = {"Trouble-maker", "Annoying", "Well behaved"};
    QString climate[3] = {"Cold weather", "Moderate weather", "Tropical weather"};
    QString level_of_care_needed[3] = {"Intense grooming and medical", "Frequent grooming", "Rare grooming"};
    QString neatness[3] = {"Filthy", "Neat", "Very Clean"};
    QString current_health_condition[3] = {"Fighting disease", "Weakened immune system", "Healthy"};
    QString intelligence_level[3] = {"Stupid", "Average", "Exceptional"};
    QString difficulty_to_train[3] = {"Defiant", "Challenging", "Easy"};
    QString noise_level[3] = {"Noisy(100+ db)", "Moderate(80-100db)", "Quiet(under 80db)"};
    QString special_skill[5] = {"Seeing eye", "Drug sniffing", "Hunting", "Security", "Showing"};


    QString economic_background[3] = {"Upper class", "Middle class", "Lower Class"};
    QString activity_level[3] = {"Extremely active", "Average runner", "Lazy"};
    QString experience_with_animal[3] = {"Previous owner", "New pet owner", "Animal handler"};
    QString level_of_patience[3] = {"Short tempered", "impatient", "Patient"};
    QString house_size[3] = {"Apartment", "House with yeard", "Ranch/Farm"};
    QString available_time[3] = {"30 minutes", "30 mins - 2 hours", "2 hours or more"};
    QString strength[3] = {"Powerlifter", "Average joe", "Weak"};






  private:
    Array<Animal>* animals;
    Array<Client>* clients;
    Database* db;
    HomeView* home;
    int currentUID;


};

  #endif

/*
tring* energy_level = new string[3]{"Low", "Mwdium", "High"};
    QString temperament[3] = new string[3]{"Easily excitable", "Average", "Very Relazed"};
    string kid_friendly[3] = new string[3]{"Impatient", "Moderate", "Patient"};
    string level_of_dependency[3] = new string[3]{"Under 30 minutes", "30 minutes to 2 hours", "3+ daily hours"};
    string prone_to_disease[3] = new string[3]{"Rare immune disorder", "Bad genetics", "Not prone"};
    string living_space_needed[3] = new string[3]{"Apartment", "House with yard", "Ranch"};//"Abused", "Badly Trained", "Loved"
    string feeding_cost[3] = new string[3]{"Expensive($100+)", "Moderate($500)", "Cheap(under $50)"};
    string bad_habits[3] = new string[3]{"Trouble-maker", "Annoying", "Well behaved"};
    string climate[3] = new string[3]{"Cold weather", "Moderate weather", "Tropical weather"};
    string level_of_care_needed[3] = new string[3]{"Intense grooming and medical", "Frequent grooming", "Rare grooming"};
    string neatness[3] = new string[3]{"Filthy", "Neat", "Very Clean"};
    string current_health_condition[3] = new string[3]{"Fighting disease", "Weakened immune system", "Healthy"};
    string intelligence_level[3] = new string[3]{"Stupid", "Average", "Exceptional"};
    string difficulty_to_train[3] = new string[3]{"Defiant", "Challenging", "Easy"};
    string noise_level[3] = new string[3]{"Noisy(100+ db)", "Moderate(80-100db)", "Quiet(under 80db)"};
    string special_skill[5] = new string[5]{"Seeing eye", "Drug sniffing", "Hunting", "Security", "Showing"};


    string economic_background[3] = new string[3]{"Upper class", "Middle class", "Lower Class"};
    string activity_level[3] = new string[3]{"Extremely active", "Average runner", "Lazy"};
    string experience_with_animal[3] = new string[3]{"Previous owner", "New pet owner", "Animal handler"};
    string level_of_patience[3] = new string[3]{"Short tempered", "impatient", "Patient"};
    string house_size[3] = new string[3]{"Apartment", "House with yeard", "Ranch/Farm"};
    string available_time[3] = new string[3]{"30 minutes", "30 mins - 2 hours", "2 hours or more"};
    string strength[3] = new string[3]{"Powerlifter", "Average joe", "Weak"};

*/
