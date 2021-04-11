#include<string>
#ifndef DISEASE_H
#define DISEASE_H
#include"People.h"
using namespace std;
class Disease {
public:
    Disease();
    void addMyDisease( string name_, int now_, int most_, int level_, int whenCure_, int number_);
    void showItself();
    Disease( string name_, int now_, int most_, int level_, int whenCure_, int number_);
    void getDisease ( People* you, int k, int kind );   //k为增加的now, kind为种类
    string name;
    int level = 0;
    int number;
    int now = 0;
    int most = 0;   //超过量则上升一个等级
    int whenCure = 0;   //轻中度高血压糖尿病通过锻炼，轻中度工作受伤   10天减一个等级。高度和绝境只能吃药手术
};

#endif // DISEASE_H
