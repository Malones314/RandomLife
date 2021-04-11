#include<iostream>
#include<string>
#ifndef TOOL_H
#define TOOL_H
using namespace std;
//电视机可能得到案件细节重点碎片(50个，收集齐全即可洗刷冤屈)

class Tool {
public:
    Tool();
    int which;
    int times = 0;   //还可以使用几次
    int totalTimes = 0;
    int value = 0;
    int number;
    void addMyTool(string name_, int totalTimes_, int value_, int number_, int which_);
    Tool(string name_, int totalTimes_, int value_, int number_, int which_);
    void showItself();
    void plusOne ( );
    void decrease ( );
    void useIt ( int k );
    string name;
};

#endif // TOOL_H
