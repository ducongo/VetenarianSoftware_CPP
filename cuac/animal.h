#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

#include "attribute.h"

using namespace std;

class Animal
{
  public:
    Animal(string, string, string, int, int, int, string, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int);
    ~Animal();

    string getName();
    string getSpecies();
    string getBreed();

    int getID();

    int getAge();
    int getWeight();
    int getHeight();
    int getEnergy_level();
    int getKid_friendly();
    int getLevel_of_dependency();
    int getProne_to_disease();
    int getLiving_space();
    int getFeeding_cost();
    int getClimate();
    int getLevel_of_care();
    int getNeatness();
    int getCurrent_health_condition();
    int getIntelligence_level();
    int getDifficulty_to_train();
    int getNoise_level();
    int getTemperament();
    int getBad_habits();

    string getColour();
    int getSkill();

    void setName(string);
    void setSpecies(string);
    void setBreed(string);

    void setAge(int);
    void setWeight(int);
    void setHeight(int);
    void setEnergy_level(int);
    void setKid_friendly(int);
    void setLevel_of_dependency(int);
    void setProne_to_disease(int);
    void setLiving_space(int);
    void setFeeding_cost(int);
    void setClimate(int);
    void setLevel_of_care(int);
    void setNeatness(int);
    void setCurrent_health_condition(int);
    void setIntelligence_level(int);
    void setDifficulty_to_train(int);
    void setNoise_level(int);
    void setTemperament(int);
    void setBad_habits(int);

    void setColour(string s);
    void setSkill(int);

    //Attribute* att[17];

  private:

    string name;
    string species;
    string breed;

    int age;
    int weight;
    int height;
    int energy_level;
    int kid_friendly;
    int level_of_dependency;
    int prone_to_disease;
    int living_space;
    int feeding_cost;
    int climate;
    int level_of_care;
    int neatness;
    int current_health_condition;
    int intelligence_level;
    int difficulty_to_train;
    int noise_level;
    int temperament;
    int bad_habits;

    string colour;
    int specialSkill;

    int id;

    void initalizeAttibutes(int[]);

};

  #endif
