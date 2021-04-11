#include<iostream>
#include<string>
using namespace std;
#ifndef FURNITURE_H
#define FURNITURE_H
class Furniture {
public:
    Furniture();
    Furniture(string name_, int value_, int number_, int which_);
    int value;
    string name;
    int number;
    int which;
    void changeNumber ( int k );
    void addMyFurniture(string name_, int value_, int number_, int which_);
};

#endif // FURNITURE_H
