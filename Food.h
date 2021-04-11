#include<iostream>
#include<string>
#ifndef FOOD_H
#define FOOD_H
using namespace std;
//蔬菜，烤肉，五花肉，生肉，无菌蛋，米饭
class Food {
public:
    Food();
    Food(string name_, int addFood_, int addWater_, int addMind, int surpluesShelfLife_, int value_, int addWeight_,
        int addSugar_, int addSalt_, int addHealth_, int probabilitYOfaddHealth_, int probabilityOfDiarrhea_, int number_, int which_);
    int addFood = 0;
    int addMind = 0;
    int addWater = 0;
    int addWeight = 0;
    int addSugar = 0;
    int addSalt = 0;
    int addHealth = 0;
    int probabilityOfDiarrhea;   //eg：25，代表百分之25
    int probabilitYOfaddHealth;
    int surpluesShelfLife = 0;
    int nowSurpluesShelfLife = 0;
    int value = 0;
    int which = 0;
    int number;
    void showItself();
    string name;
    void addMyFood(string name_, int addFood_, int addWater_, int addMind, int surpluesShelfLife_, int value_, int addWeight_,
        int addSugar_, int addSalt_, int addHealth_, int probabilitYOfaddHealth_, int probabilityOfDiarrhea_, int number_, int which_);
    void changeNumber ( int k );
};

#endif // FOOD_H
