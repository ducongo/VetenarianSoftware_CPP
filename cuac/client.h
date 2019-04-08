#ifndef CLIENT_H
#define CLIENT_H

#include <string>

#include "attribute.h"

using namespace std;

class Client
{
  public:
    Client(string, string, string, int,int, int,int,int,int,int,int,int,int,int,string,string,int, int);
    ~Client();

    string getName();
    string getEmail();
    string getAddress();

    int getID();

    int getCellPhone();
    int getHomePhone();

    string getAnimal();
    string getBreed();
    int getSpecialRequriements();

    int getAge();
    int getGender();
    int getEconomicBackground();
    int getActivityLevel();
    int getExperienceWithAnimals();
    int getLevelOfPatience();
    int getHouseSize();
    int getAvailableTime();
    int getStrength();

    void setName(string);
    void setEmail(string);
    void setAddress(string);

    void setCellPhone(int);
    void setHomePhone(int);

    void setAnimal(string);
    void setBreed(string);
    void setSpecial_requriements(int);

    void setAge(int);
    void setGender(int);
    void setEconomic_background(int);
    void setActivity_level(int);
    void setExperience_with_animals(int);
    void setLevel_of_patience(int);
    void setHouse_size(int);
    void setAvailable_time(int);
    void setStrength(int);


    Attribute* att[17];

  private:
    int id;

    string name;
    string email;
    string address;

    int cellPhone;
    int homePhone;

    string animal;
    string breed;
    int special_requriements;

    int age;
    int gender;
    int economic_background;
    int activity_level;
    int experience_with_animals;
    int level_of_patience;
    int house_size;
    int available_time;
    int strength;

    void initalizeAttibutes(int[]);

};

  #endif

