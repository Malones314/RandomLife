#include<iostream>
#include<string>
#include "Tool.h"
using namespace std;
Tool::Tool(string name_, int totalTimes_, int value_, int number_, int which_) {
    which = which_;
    name.assign(name_);
    totalTimes = totalTimes_;
    times = 0;
    value = value_;
    number = number_;
}

Tool::Tool() {
    which = 0;
    number = 0;
    times = 0;   //还可以使用几次
    totalTimes = 0;
    value = 0;
    name.assign("*");
}
void Tool::showItself() {
    cout << name << " \t编号：" << which << endl;
    cout << "还可以使用：" << times << " 次" << endl;
    cout << "价值：" << value << "元" << endl;
    cout << "剩余数量：" << number << endl;
}
void Tool::addMyTool(string name_, int totalTimes_, int value_, int number_, int which_) {
    which = which_;
    name.assign(name_);
    totalTimes = totalTimes_;
    times = 0;
    value = value_;
    number = number_;
}
void Tool::useIt ( int k ) {
    while ( times < k && number > 0 ) 
        decrease ( );
     times -= k;
}
void Tool::plusOne ( ) {
    number++;
}
void Tool::decrease ( ) {
    number--;
    times += totalTimes;
}
