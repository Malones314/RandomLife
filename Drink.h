#include<iostream>
#include<string>
#ifndef DRINK_H
#define DRINK_H
using namespace std;
class Drink {
public:
    int addWater = 0;   //可加的水份
    int addHealth = 0;   //负数时为减少生命
    int surpluesShelfLife = 0;   //初始保质期
    int nowSurpluesShelfLife = 0;
    int value;   //快过期时可以卖给商店
    int addMind;   //可加的心情
    int addFood;
    int addWeight;
    int addSugar;
    int probabilityOfDiarrhea;   //eg：25，代表百分之25
    int probabilitYOfaddHealth;
    int number;
    int which;
    string name;
    Drink(string name_, int addWater_, int addhealth, int addMind, int surpluesShelfLife, int value_, int addFood_,
        int addWeight_, int addSugar_, int probabilityOfDiarrhea_, int probabilitYOfaddHealth_, int number_, int which_);
    Drink();
    void addMyDrink(string name_, int addWater_, int addhealth, int addMind, int surpluesShelfLife, int value_, int addFood_,
        int addWeight_, int addSugar_, int probabilityOfDiarrhea_, int probabilitYOfaddHealth_, int number_, int which_);
    void showItself();
    void changeNumber ( int k );
};

#endif // DRINK_H
