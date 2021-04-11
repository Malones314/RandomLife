#include<iostream>
#include<string>
#ifndef PEOPLE_H
#define PEOPLE_H
#include"Drink.h"
#include"Food.h"
#include"Treatment.h"

using namespace std;
//生命，金钱，卡牌
//子类：
//心情：心情好有加成，食物充足，水量充足，做喜欢做的事情可加心情，制造减心情(除非爱好为制造，反而可以加心情)，心情为0无法参与制造
//爱好："发呆", "吃饭", "制造", "喝水", "睡觉", "看电视", "绘画", "书法"
class People {
    public:
    People ( );
    void showYourself ( );
    void sleep ( );   //睡觉
    void changeMoney ( double money_ );
    void changeMind ( int );
    void changeWeight ( int );
    void changeHealth ( int k );
    void watchTV ( );   //看电视
    void getDrink ( Drink* myDrink );   //喝水，传入水种类
    void getFood ( Food* myFood );   //吃食物，传入食物种类
    void getTreatment ( Treatment* myTreatment, bool withCard );   //治疗，传入治疗种类, 治疗前判断钱是否足够
    void getDisease ( int kind );   //生病，传入病的种类
    void doExercise ( );   //做运动
    void getHobby ( int );
    int mostPhysicalStrength;   //体力上限，每提升10加1生命上限，没提升50加1天寿命
    int mostHealth;   //生命上限，只能通过体力上限提升
    int health;   //生命
    int physicalStrength;   //体力
    double food;   //饱腹度
    double water;   //饥渴值
    int hobby;   //爱好
    double money;   //金钱
    int mind;   //心情
    double weight;   //体重
    int sugar;   //摄糖
    int salt;   //摄盐
    int lifeTime;   //寿命还剩多少天
    int dayInPrison;   //在监狱的第几天数
    int caseFragment;   //案件碎片
    int TVNumber;   //电视机个数
    bool haveStore;   //是否拥有小卖部
    double everyDayLosePhysicalStrength;
    double everyDayLoseHealth;
    double everyDayLoseFood;
    double everyDayLoseWater;
    int addMind;   //只有兴趣是发呆时候为5,做任何事都加5
    class Disease {
        public:
        Disease ( );
        void addMyDisease ( string name_, int now_, int most_, int level_, int whenCure_, int number_ );
        void showItself ( );
        Disease ( string name_, int now_, int most_, int level_, int whenCure_, int number_ );
        void getDisease ( People* you, int k, int kind );   //k为增加的now, kind为种类
        string name;
        int level = 0;
        int number;
        int now = 0;
        int most = 0;   //超过量则上升一个等级
        int whenCure = 0;   //轻中度高血压糖尿病通过锻炼，轻中度工作受伤   10天减一个等级。高度和绝境只能吃药手术
    };
    Disease myDisease [6];
};
#endif // PEOPLE_H
