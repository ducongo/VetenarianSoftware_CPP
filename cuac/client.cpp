#include <iomanip>
#include <sstream>
using namespace std;

#include "client.h"
#include <QDebug>

Client::Client(string Name, string Email, string Address, int Age, int Gender, int Cell_phone, int Home_phone
               , int Economic_background
               , int Activity_level
               , int Experience_with_animal
               , int Level_of_patience
               , int House_size
               , int Available_time
               , int Strength
               , string Animal
               , string Breed
               , int Special_requirements
               , int Id)
{
    name = Name;
    email = Email;
    address = Address;
    age = Age;
    gender = Gender;
    cellPhone = Cell_phone;
    homePhone = Home_phone;

    economic_background = Economic_background;
    activity_level =Activity_level;
    experience_with_animals = Experience_with_animal;
    level_of_patience = Level_of_patience;
    house_size = House_size;
    available_time = Available_time;
    strength = Strength;
    animal = Animal;
    breed = Breed;
    special_requriements = Special_requirements;
    id = Id;
    qDebug("Economic background: %d", economic_background);
  //initalizeAttibutes(at);
}

Client::~Client()
{

}

int Client::getID(){return id;}

string Client::getName(){return name;}
string Client::getEmail(){return email;}
string Client::getAddress(){return address;}

int Client::getCellPhone(){return cellPhone;}
int Client::getHomePhone(){return homePhone;}

string Client::getAnimal(){return animal;}
string Client::getBreed(){return breed;}
int Client::getSpecialRequriements(){return special_requriements;}

int Client::getAge(){return age;}
int Client::getGender(){return gender;}
int Client::getEconomicBackground(){return economic_background;}
int Client::getActivityLevel(){return activity_level;}
int Client::getExperienceWithAnimals(){return experience_with_animals;}
int Client::getLevelOfPatience(){return level_of_patience;}
int Client::getHouseSize(){return house_size;}
int Client::getAvailableTime(){return available_time;}
int Client::getStrength(){return strength;}

void Client::setName(string s){ name = s;}
void Client::setEmail(string s){ email = s;}
void Client::setAddress(string s){ address = s;}

void Client::setCellPhone(int i){ cellPhone = i;}
void Client::setHomePhone(int i){ homePhone = i;}

void Client::setAnimal(string s){ animal = s;}
void Client::setBreed(string s){ breed = s;}

void Client::setSpecial_requriements(int i){ special_requriements = i;}

void Client::setAge(int i){ age = i;}
void Client::setGender(int i){ gender = i;}
void Client::setEconomic_background(int i){ economic_background = i;}
void Client::setActivity_level(int i){ activity_level = i;}
void Client::setExperience_with_animals(int i){ experience_with_animals = i;}
void Client::setLevel_of_patience(int i){ level_of_patience = i;}
void Client::setHouse_size(int i){ house_size = i;}
void Client::setAvailable_time(int i){ available_time = i;}
void Client::setStrength(int i){ strength = i;}

Attribute* att[17];

void Client::initalizeAttibutes(int at[]){

  /*att[0] = new Attibute("Energy Level",at[0],0,"(1-Enegitic,2-Typical,3-Slugish)");
  att[1] = new Attibute("Temperament",at[1],0,"(1-Agressive,2-Typical,3-Calm)");
  att[2] = new Attibute("Kid Friendly",at[2],0,"(1-Slugish,2-Typical,3-Enegitic)");
  att[3] = new Attibute("Bad Habits",at[3],0,"(1-Alot,2-Typical,3-little to none)");
  att[4] = new Attibute("Previous Level of Care",at[4],0,"(1-Pampered,2-Typical,3-Maltreated)");
  att[5] = new Attibute("Level of Dependency",at[5],0,"(1-Dependent,2-Typical,3-Independent)");
  att[6] = new Attibute("Prone to Disease",at[6],0,"(1-Very Prone,2-Typical,3-Not very Prone)");
  att[7] = new Attibute("Living Space Needed",at[7],0,"(1-Large,2-Typical,3-Small)");
  att[8] = new Attibute("Climate Sensitivity",at[8],0,"(1-Sensitive,2-Typical,3-Tolerant)");
  att[9] = new Attibute("Level of Care Needed",at[9],0,"(1-Round the clock,2-Typical,3-Minimal)");
  att[10] = new Attibute("Neatness",at[10],0,"(1-Filthy,2-Typical,3-Sanitary)");
  att[11] = new Attibute("Medical History",at[11],0,"(1-Cronic ilnesses,2-Typical,3-Mostly Healthy)");
  att[12] = new Attibute("Current Health Condition",at[12],0,"(1-ill,2-falling ill,3-healthy)");
  att[13] = new Attibute("Intelligence level",at[13],0,"(1-Idiotic,2-Typical,3-Inteligent)");
  att[14] = new Attibute("Difficulty to train",at[14],0,"(1-Hard,2-Typical,3-Easy)");
  att[15] = new Attibute("Feeding Cost",at[15],0,"(1-$$$,2-$$,3-$)");
  att[16] = new Attibute("Noise Level",at[16],0,"(1-Loud,2-Typical,3-Quiet)");*/

}
