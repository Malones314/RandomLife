#include<iostream>
#include<string>
#ifndef TREATMENT_H
#define TREATMENT_H
using namespace std;
//使用药品,手术
//如果是手术可以选择双倍价钱无需卡片
//肥胖和过瘦只能慢慢康复
class Treatment {
public:
    Treatment();
    Treatment(string name_, int addHealth_, int value_, int number);
    int addHealth = 0;
    int value = 0;
    int which = 0;   //0外伤 1糖尿病 2高血压 3拉肚子 5手术
    int number = 0;
    void addMyTreatment(string name_, int addHealth_, int value_, int number_, int which_);
    void showItself();
    void changeNumber ( int k );
    string name;
};

#endif // TREATMENT_H
