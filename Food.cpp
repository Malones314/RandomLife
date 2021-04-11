#include<iostream>
#include<string>
#include "Food.h"
using namespace std;
Food::Food(string name_, int addFood_, int addWater_, int addMind_, int surpluesShelfLife_, int value_, int addWeight_,
    int addSugar_, int addSalt_, int addHealth_, int probabilitYOfaddHealth_, int probabilityOfDiarrhea_, int number_, int which_) {
    which = which_;
    number = number_;
    name.assign(name_);
    addFood = addFood_;
    surpluesShelfLife = surpluesShelfLife_;
    value = value_;
    addWater = addWater_;
    addMind = addMind_;
    addWeight = addWeight_;
    addSugar = addSugar_;
    addSalt = addSalt_;
    addHealth = addHealth_;
    probabilitYOfaddHealth = probabilitYOfaddHealth_;
    probabilityOfDiarrhea = probabilityOfDiarrhea_;
    nowSurpluesShelfLife = surpluesShelfLife;
}
Food::Food() {
    name.assign("*");
    addFood = 0;
    surpluesShelfLife = 0;
    value = 0;
    addWater = 0;
    addMind = 0;
    addWeight = 0;
    addSugar = 0;
    addSalt = 0;
    addHealth = 0;
    probabilitYOfaddHealth = 0;
    probabilityOfDiarrhea = 0;
    number = 0;
    which = 0;
    nowSurpluesShelfLife = surpluesShelfLife;
}
void Food::addMyFood ( string name_, int addFood_, int addWater_, int addMind_, int surpluesShelfLife_, int value_, int addWeight_,
    int addSugar_, int addSalt_, int addHealth_, int probabilitYOfaddHealth_, int probabilityOfDiarrhea_, int number_, int which_ ) {
    which = which_;
    number = number_;
    nowSurpluesShelfLife = 0;
    name.assign ( name_ );
    addFood = addFood_;
    surpluesShelfLife = surpluesShelfLife_;
    value = value_;
    addWater = addWater_;
    addMind = addMind_;
    addWeight = addWeight_;
    addSugar = addSugar_;
    addSalt = addSalt_;
    addHealth = addHealth_;
    probabilitYOfaddHealth = probabilitYOfaddHealth_;
    probabilityOfDiarrhea = probabilityOfDiarrhea_;
}
void Food::showItself( ) {
    cout << "名称：" << name << "\t编号：" << which << endl;
    cout << "增加水：" << addWater << "\t增加饱腹度：" << addFood << endl;
    cout << "增加生命：" << addHealth << "\t增加心情：" << addMind << endl;
    cout << "增加体重：" << addWeight << endl;
    cout << "增加盐：" << addSalt << "\t增加糖：" << addSugar << endl;
    cout << "拉肚子概率：" << probabilityOfDiarrhea << "%\t减少生命值概率：" << probabilitYOfaddHealth << "%\n";
    cout << "保质期：" << nowSurpluesShelfLife << "\t价值：" << value << endl;
    cout << "剩余数量：" << number << endl;
}

void Food::changeNumber( int k ) {
    surpluesShelfLife = surpluesShelfLife;
    number+= k;
    if ( number == 0 )
        nowSurpluesShelfLife = 0;
}
