#ifndef ARRAY_H
#define ARRAY_H
#include "database.h"
#include "animal.h"
//using namespace std;

#define MAX_SIZE  200

template <class T>
class Array
{
  public:
    Array();
    //~Array();

    void add(T*);
    int getSize();
    T* get(int);
    void dbGet();

  private:
    int size;
    T* data[MAX_SIZE];
    //Database db;
};

template <class T>
Array<T>::Array(){

  size = 0;
}

//template <class T>
//Array<T>::~Array(){}

template <class T>
void Array<T>::add(T* i){
  data[size] = i;
  size++;
}

template <class T>
int Array<T>::getSize(){
  return size;
}

template <class T>
T* Array<T>::get(int i){
  return data[i];
}

template <class T>
void Array<T>::dbGet(){

}

#endif













