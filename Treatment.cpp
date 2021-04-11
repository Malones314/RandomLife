#include<iostream>
#include<string>
#include "Treatment.h"
using namespace std;
Treatment::Treatment() {
    which = 0;
    addHealth = 0;
    value = 0;
    number = 0;
    name.assign("*");
}

Treatment::Treatment(string name_, int addHealth_, int value_, int number_) {
    name.assign(name_);
    addHealth = addHealth_;
    value = value_;
    number = number_;
}

void Treatment::addMyTreatment(string name_, int addHealth_, int value_, int number_, int which_) {
    which = which_;
    name.assign(name_);
    addHealth = addHealth_;
    value = value_;
    number = number_;
}

void Treatment::showItself() {
    cout << "治疗卡名称：" << name << "\t编号：" << which << endl;
    cout << "可以加的生命值：" << addHealth << endl;
    cout << "数量：" << number << "\t价值：" << value << " 元" << endl;
}

void Treatment::changeNumber ( int k ) {
    number += k;
}
