#include <iomanip>
#include <sstream>
using namespace std;

#include "animal.h"

Animal::Animal(string Name,string Species,string Breed,int Age,int Weight,int Height,string Colour,
               int Skill,
               int Energy_level,
               int Kid_friendly,
               int Level_of_dependency,
               int Prone_to_disease,
               int Living_space,
               int Feeding_cost,
               int Climate,
               int Level_of_care,
               int Neatness,
               int Current_health_condition,
               int Intelligence_level,
               int Difficulty_to_train,
               int Noise_level,
               int Temperament,
               int Bad_habits,
               int ID)
{
  name = Name;
  species = Species;
  breed = Breed;
  age = Age;
  weight = Weight;
  height = Height;
  colour = Colour;
  specialSkill = Skill;

  energy_level = Energy_level;
  kid_friendly = Kid_friendly;
  level_of_dependency = Level_of_dependency;
  prone_to_disease = Prone_to_disease;
  living_space = Living_space;
  feeding_cost = Feeding_cost;
  climate = Climate;
  level_of_care = Level_of_care;
  neatness = Neatness;
  current_health_condition = Current_health_condition;
  intelligence_level = Intelligence_level;
  difficulty_to_train = Difficulty_to_train;
  noise_level = Noise_level;
  temperament = Temperament;
  bad_habits = Bad_habits;

  id = ID;

  //initalizeAttibutes(at);
}

Animal::~Animal()
{

}

string Animal::getName(){return name;}
string Animal::getSpecies(){return species;}
string Animal::getBreed(){return breed;}

int Animal::getID(){return id;}

int Animal::getAge(){return age;}
int Animal::getWeight(){return weight;}
int Animal::getHeight(){return height;}
int Animal::getEnergy_level(){return energy_level;}
int Animal::getKid_friendly(){return kid_friendly;}
int Animal::getLevel_of_dependency(){return level_of_dependency;}
int Animal::getProne_to_disease(){return prone_to_disease;}
int Animal::getLiving_space(){return living_space;}
int Animal::getFeeding_cost(){return feeding_cost;}
int Animal::getClimate(){return climate;}
int Animal::getLevel_of_care(){return level_of_care;}
int Animal::getNeatness(){return neatness;}
int Animal::getCurrent_health_condition(){return current_health_condition;}
int Animal::getIntelligence_level(){return intelligence_level;}
int Animal::getDifficulty_to_train(){return difficulty_to_train;}
int Animal::getNoise_level(){return noise_level;}
int Animal::getTemperament(){return temperament;}
int Animal::getBad_habits(){return bad_habits;}

string Animal::getColour(){return colour;}
int Animal::getSkill(){return specialSkill;}

void Animal::setName(string s){name = s;}
void Animal::setSpecies(string s){species = s;}
void Animal::setBreed(string s){breed = s;}

void Animal::setAge(int i){age = i;}
void Animal::setWeight(int i){weight = i;}
void Animal::setHeight(int i){ height = i;}
void Animal::setEnergy_level(int i){ energy_level = i;}
void Animal::setKid_friendly(int i){ kid_friendly = i;}
void Animal::setLevel_of_dependency(int i){ level_of_dependency = i;}
void Animal::setProne_to_disease(int i){ prone_to_disease = i;}
void Animal::setLiving_space(int i){ living_space = i;}
void Animal::setFeeding_cost(int i){ feeding_cost = i;}
void Animal::setClimate(int i){ climate = i;}
void Animal::setLevel_of_care(int i){ level_of_care = i;}
void Animal::setNeatness(int i){ neatness = i;}
void Animal::setCurrent_health_condition(int i){ current_health_condition = i;}
void Animal::setIntelligence_level(int i){ intelligence_level = i;}
void Animal::setDifficulty_to_train(int i){ difficulty_to_train = i;}
void Animal::setNoise_level(int i){ noise_level = i;}
void Animal::setTemperament(int i){ temperament = i;}
void Animal::setBad_habits(int i){ bad_habits = i;}

void Animal::setColour(string s){colour = s;}
void Animal::setSkill(int i){ specialSkill = i;}

void Animal::initalizeAttibutes(int at[]){

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
