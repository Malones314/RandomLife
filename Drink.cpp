#include<iostream>
#include<string>
#include "Drink.h"
using namespace std;
Drink::Drink(string name_, int addWater_, int addFood_, int addHealth_, int addMind_, int surpluesShelfLife_, int value_,
    int addWeight_, int addSugar_, int probabilityOfDiarrhea_, int probabilitYOfaddHealth_, int number_, int which_) {
    which = which_;
    number = number_;
    name.assign(name_);
    addHealth = addHealth_;
    surpluesShelfLife = surpluesShelfLife_;
    value = value_;
    addMind = addMind_;
    addWater = addWater_;
    addFood = addFood_;
    addWeight = addWeight_;
    addSugar = addSugar_;
    probabilitYOfaddHealth = probabilitYOfaddHealth_;
    probabilityOfDiarrhea = probabilityOfDiarrhea_;
}
Drink::Drink() {
    which = 0;
    number = 0;
    name.assign("*");
    addHealth = 0;
    surpluesShelfLife = 0;
    value = 0;
    addMind = 0;
    addWater = 0;
    addFood = 0;
    addWeight = 0;
    addSugar = 0;
    probabilitYOfaddHealth = 0;
    probabilityOfDiarrhea = 0;
}
void Drink::addMyDrink ( string name_, int addWater_, int addFood_, int addHealth_, int addMind_, int surpluesShelfLife_, int value_,
    int addWeight_, int addSugar_, int probabilityOfDiarrhea_, int probabilitYOfaddHealth_, int number_, int which_ ) {
    which = which_;
    number = number_;
    name.assign ( name_ );
    addHealth = addHealth_;
    surpluesShelfLife = surpluesShelfLife_;
    value = value_;
    addMind = addMind_;
    addWater = addWater_;
    addFood = addFood_;
    addWeight = addWeight_;
    addSugar = addSugar_;
    probabilitYOfaddHealth = probabilitYOfaddHealth_;
    probabilityOfDiarrhea = probabilityOfDiarrhea_;
    nowSurpluesShelfLife = surpluesShelfLife;
    nowSurpluesShelfLife = 0;
}
void Drink::showItself() {
    cout << "名称：" << name << "\t编号：" << which << endl;
    cout << "增加水：" << addWater << "增加饱腹度：" << addFood << endl;
    cout << "增加生命：" << addHealth << "\t增加体重：" << addWeight << endl;
    cout << "增加心情：" << addMind << "\t增加糖：" << addSugar << endl;
    cout << "拉肚子概率：" << probabilityOfDiarrhea << "%\t减少生命值概率：" << probabilitYOfaddHealth << "%\n";
    cout << "保质期：" << nowSurpluesShelfLife << "\t价值：" << value << endl;
    cout << "剩余数量：" << number << endl;
}
void Drink::changeNumber( int k ){
    nowSurpluesShelfLife = surpluesShelfLife;
    number += k;
    if ( number == 0 )
        nowSurpluesShelfLife = 0;
}
