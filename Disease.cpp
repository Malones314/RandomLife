#include<string>
#include<iostream>
#include "Disease.h"
#include"People.h"
using namespace std;
Disease::Disease() {
    number = 0;
    name.assign("*");
    level = 0;
    now = 0;
    most = 0;   //超过量则上升一个等级
    whenCure = 0;   //轻中度高血压糖尿病通过锻炼，轻中度工作受伤   10天减一个等级。高度和绝境只能吃药手术
}

Disease::Disease( string name_, int now_, int most_, int level_, int whenCure_, int number_) {
    number = number_;
    now = now_;
    most = most_;
    level = level_;
    whenCure = whenCure_;
    name.assign(name_);
}

void Disease::addMyDisease(string name_, int now_, int most_, int level_, int whenCure_, int number_) {
    number = number_;
    name.assign(name_);
    now = now_;
    most = most_;
    level = level_;
    whenCure = whenCure_;
}

void Disease::showItself() {
    string Level[5] = { "正常，无病","轻度", "中度", "重度", "绝境" };
    cout << "疾病名称：" << name << endl
        << "现在累计：" << now << "\t累计多少患病：" << most << endl
        << "现在等级：" << Level[level] << "\t什么时候治疗好：" << whenCure;
}

void Disease::getDisease ( People* you, int k , int kind) {
    now += k;
    if ( now > most  ) { 
        now -= most;
        you->getDisease ( kind );
    }
}
