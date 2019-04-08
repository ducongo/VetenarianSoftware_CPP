#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <string>

using namespace std;

class Attribute
{
  public:
    Attribute(string n,int s,int pri,string dis);
    ~Attribute();

    string getName();
    string getScore();
    string getPriority();

    void setScore(string);

  private:
    int score;
    string name;
    int priority;
    string discription;

};

  #endif
