#include "Furniture.h"
#include<iostream>
#include<string>
using namespace std;
Furniture::Furniture() {
    which = 0; 
    name.assign("*");
    value = 0;
    number = 0;
}
Furniture::Furniture(string name_, int value_, int number_, int which_) {
    which = which_;
    name.assign(name_);
    value = value_;
    number = number_;
}
void Furniture::addMyFurniture(string name_, int value_, int number_, int which_) {
    which = which_;
    name.assign(name_);
    value = value_;
    number = number_;
}
void Furniture::changeNumber ( int k ) {
    number += k;
}
