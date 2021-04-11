#include "People.h"
#include <iostream>
#include <string>
using namespace std;
People::People ( ) {
    dayInPrison = 1;
    mostPhysicalStrength = 100;
    mostHealth = 100;
    caseFragment = 0;
    lifeTime = 19000;
    salt = 0;
    sugar = 0;
    addMind = 0;
    TVNumber = 0;
    everyDayLoseWater = 0.1;
    everyDayLosePhysicalStrength = 0;
    everyDayLoseHealth = 0;
    everyDayLoseFood = 0.1;
    haveStore = false;
    int k;
    k = rand ( ) % 8;
    hobby = k;
    if ( k == 0 )
        addMind = 5;
    k = rand ( ) % 20 - 10;
    health = mostHealth - k;
    k = rand ( ) % 20;
    money = k * 1.0;
    k = rand ( ) % 80;
    physicalStrength = k;
    k = rand ( ) % 20 - 10;
    food = 80.0 + k;
    k = rand ( ) % 20 - 10;
    water = 80.0 + k;
    k = rand ( ) % 20;
    mind = 80 + k;
    k = rand ( ) % 20 - 10;
    weight = 50.0 + k;

    myDisease [0].addMyDisease ( "外伤", 0, 10, 0, 0, 0 );
    myDisease [1].addMyDisease ( "糖尿病", 0, 10, 0, -1, 1 );
    myDisease [2].addMyDisease ( "高血压", 0, 10, 0, -1, 2 );
    myDisease [3].addMyDisease ( "拉肚子", -1, -1, 0, 0, 3 );
    myDisease [4].addMyDisease ( "肥胖", 0, 20, 0, -1, 4 );
    myDisease [5].addMyDisease ( "过瘦", 0, 20, 0, -1, 5 );

}
void People::changeMoney ( double money_ ) {
    money += money_;
}
void People::getDrink ( Drink* myDrink ) {   //喝水，传入水种类
    mind += addMind;
    if ( hobby == 3 )
        mind += 10;
    myDrink->number--;
    int k = 0;   // 拉肚子
    int k_ = 0;   //健康
    k = rand ( ) % 100;
    k_ = rand ( ) % 100;
    water += myDrink->addWater;
    mind += myDrink->addMind;
    food += myDrink->addFood;
    sugar += myDrink->addSugar;
    weight += myDrink->addWeight;
    if ( k_ < myDrink->probabilitYOfaddHealth )
        health += myDrink->addHealth;
    if ( k < myDrink->probabilityOfDiarrhea )
        getDisease ( 3 );
}

void People::getFood ( Food* myFood ) {   //吃食物，传入食物种类
    mind += addMind;
    if ( hobby == 1 )
        mind += 10;
    myFood->number--;
    int k = 0;   // 拉肚子
    int k_ = 0;   //健康
    k = rand ( ) % 100;
    k_ = rand ( ) % 100;
    water += myFood->addWater;
    mind += myFood->addMind;
    food += myFood->addFood;
    sugar += myFood->addSugar;
    salt += myFood->addSalt;
    weight += myFood->addWeight;
    if ( k_ < myFood->probabilitYOfaddHealth )
        health += myFood->addHealth;
    if ( k < myFood->probabilityOfDiarrhea )
        getDisease ( 3 );
}

void People::getTreatment ( Treatment* myTreatment, bool withCard ) {   //治疗，传入治疗方法，withCard(true)表示手术使用卡片
    int myLevel = 0;
    int kind = myTreatment->number;
    if ( kind != 5 )
        myLevel = myDisease [kind].level;
    if ( kind == 0 || kind == 3 ) {
        myDisease [myTreatment->number].level--;
        myLevel = myDisease [kind].level;
    }
    if ( myTreatment->number != 4 ) {   //不进行手术
        if ( kind == 0 ) {
            if ( myLevel == 0 ) {
                myDisease [0].whenCure = 0;
                myDisease [0].now = 0;
            }
        } else if ( kind == 1 || kind == 2 ) {   //绝境只能靠手术
            if ( myDisease [kind].level < 4 ) {
                myDisease [kind].level--;
                myLevel = myDisease [kind].level;
                everyDayLoseHealth --;
            }
        } else if ( kind == 3 ) {
            if ( myLevel == 0 ) {
                myDisease [0].whenCure = 0;
                myDisease [0].now = 0;
            }
            everyDayLoseFood--;
            everyDayLoseWater--;
        }
    } else {
        if ( withCard ) {
            if ( myLevel == 1 )
                money -= 100;
            else if ( myLevel == 2 )
                money -= 200;
            else if ( myLevel == 3 )
                money -= 400;
            else if ( myLevel == 4 )
                money -= 800;
        } else {
            if ( myLevel == 1 )
                money -= 500;
            else if ( myLevel == 2 )
                money -= 1000;
            else if ( myLevel == 3 )
                money -= 2000;
            else if ( myLevel == 4 )
                money -= 4000;
        }
        everyDayLoseFood = 0.1;
        everyDayLoseHealth = 0;
        everyDayLosePhysicalStrength = 0;
        everyDayLoseWater = 0.1;
        myDisease [kind].level = 0;
        myDisease [kind].now = 0;
        myDisease [kind].whenCure = 0;
        health = mostHealth;
        physicalStrength = mostPhysicalStrength / 2;
    }
}
void People::changeHealth ( int k ) {
    health -= k;
}

//如果已经到绝境肥胖，运动工作减肥依旧要触发绝境条件
void People::getDisease ( int kind ) {   //生病，传入病的种类
    myDisease [kind].level += 1;
    int diseaseLevel;
    diseaseLevel = myDisease [kind].level;
    if ( kind == 0 ) {
        if ( diseaseLevel == 1 )
            health -= 2;
        else if ( diseaseLevel == 2 )
            health -= 3;
        else if ( diseaseLevel == 3 )
            health -= 4;
        else if ( diseaseLevel >= 4 ) {
            myDisease [kind].level = 4;
            health -= 10;
        }
    } else if ( kind == 1 ) {
        if ( diseaseLevel >= 4 ) 
            myDisease [kind].level = 4;
        everyDayLoseHealth++;
    } else if ( kind == 2 ) {
        if ( diseaseLevel >= 4 )
            myDisease [kind].level = 4;
        everyDayLoseHealth++;
    } else if ( kind == 3 ) {
        if ( diseaseLevel >= 4 ) {
            myDisease [kind].level = 4;    
            health -= 5;
        }
        everyDayLoseFood++;
        everyDayLoseWater++;
    } else if ( kind == 4 ) {
        everyDayLosePhysicalStrength += 5;
        if ( diseaseLevel >= 4 ) {
            myDisease [kind].level = 4;
            health -= 20;
        }
    } else if ( kind == 5 ) {
        everyDayLosePhysicalStrength += 5;
        if ( diseaseLevel >= 4 ) {
            myDisease [kind].level = 4;
            health -= 20;
        }
    }
}
void People::sleep ( ) {
    mind += addMind;
    if ( hobby == 4 )
        mind += 10;
    //外伤
    if ( myDisease [0].level ) {
        if ( myDisease [0].whenCure == 0 ) {
            myDisease [0].level--;
        } else
            myDisease [0].whenCure--;
    }

    // 日摄糖量大于2，糖尿病程度加1
    if ( sugar > 2 )
        getDisease ( 1 );

    //日摄盐量大于9，高血压程度加1
    if ( salt > 9 )
        getDisease ( 2 );

    //拉肚子
    if ( myDisease [3].level ) {
        if ( myDisease [3].whenCure == 0 )
            myDisease [3].level--;
        else
            myDisease [3].whenCure--;
    }

    //体重在进食和锻炼、工作后都进行判断

    mind += 5;

    if ( mind < -100 ) {
        everyDayLoseHealth += 10;
        everyDayLoseFood += 10;
        everyDayLosePhysicalStrength += 20;
        everyDayLoseWater += 10;
    } else if ( mind < -200 ) {
        everyDayLoseHealth += 20;
        everyDayLoseFood += 20;
        everyDayLosePhysicalStrength += 40;
        everyDayLoseWater += 20;
    } else if ( mind < -400 ) {
        health = -0x3f3f3f3f;
    } else if ( mind > 200 ) {
        everyDayLoseFood--;
        everyDayLosePhysicalStrength -= 5;
        everyDayLoseWater--;
    }
    if ( everyDayLoseFood < 0 )
        everyDayLoseFood = 0.1;
    if ( everyDayLoseHealth < 0 )
        everyDayLoseHealth = 0;
    if ( everyDayLosePhysicalStrength < 0 )
        everyDayLosePhysicalStrength = 0;
    if ( everyDayLoseWater < 0 )
        everyDayLoseWater = 0.1;
    dayInPrison++;
    lifeTime--;
    health -= everyDayLoseHealth;
    physicalStrength = mostPhysicalStrength - everyDayLosePhysicalStrength;
    water -= everyDayLoseWater;
    food -= everyDayLoseFood;
    if ( water < 0 )
        health--;
    if ( food < 0 )
        health--;
}
void People::watchTV ( ) {
    mind += addMind;
    if ( hobby == 5 )
        mind += 10;
    int k = 0;
    printf ( "你有%d台电视，你找到案件碎片的几率为%lf%%\n", TVNumber, TVNumber * 0.01 / 1000 );
    k = rand ( ) % ( 1000 / TVNumber );
    if ( k == 0 ) {
        cout << "找到了一个案件碎片, 你现在有 : ";
        caseFragment++;
        cout << caseFragment << "个案件碎片。";
    }
}
void People::doExercise ( ) {
    weight -= 10;
    int k = 0;
    k = rand ( ) % 100;
    if ( k < 50 )
        this->myDisease [0].getDisease ( this, 1, 0 );
    mostPhysicalStrength += 1;
    if ( ( mostPhysicalStrength - 100 ) % 10 == 0 )   //体力上限每提升10则加1生命上限
        mostHealth++;
    if ( ( mostPhysicalStrength - 100 ) % 50 == 0 )   //体力上限每提升50则加1寿命
        lifeTime++;
    if ( weight < 50 )
        myDisease [5].getDisease ( this, 10, 5 );
    else
        myDisease [4].getDisease ( this, -10, 4 );
}
void People::getHobby ( int kind ) {
    if ( kind == hobby )
        mind += 40;
    else
        mind += 10;
}

void People::changeMind ( int k ) {
    mind += k;
}
void People::changeWeight ( int k ) {
    weight += k;
}
void People::Disease::getDisease ( People* you, int k, int kind ) {
    now += k;
    if ( now > most ) {
        now -= most;
        you->getDisease ( kind );
    }
}
void People::Disease::showItself ( ) {
    string Level [5] = { "正常，无病", "轻度", "中度", "重度", "绝境" };
    cout << "疾病名称：" << name << endl
        << "现在累计：" << this->now << "\t累计多少患病：" << most << endl
        << "现在等级：" << Level [level] << "\t什么时候治疗好：" << whenCure;
}
void People::Disease::addMyDisease ( string name_, int now_, int most_, int level_, int whenCure_, int number_ ) {
    number = number_;
    name.assign ( name_ );
    now = now_;
    most = most_;
    level = level_;
    whenCure = whenCure_;
}
People::Disease::Disease ( string name_, int now_, int most_, int level_, int whenCure_, int number_ ) {
    number = number_;
    now = now_;
    most = most_;
    level = level_;
    whenCure = whenCure_;
    name.assign ( name_ );
}
People::Disease::Disease ( ) {
    number = 0;
    name.assign ( "*" );
    level = 0;
    now = 0;
    most = 0;   //超过量则上升一个等级
    whenCure = 0;   //轻中度高血压糖尿病通过锻炼，轻中度工作受伤   10天减一个等级。高度和绝境只能吃药手术
}
void People::showYourself ( ) {
    string allHobbies [6] = { "发呆", "吃饭", "制造", "喝水", "睡觉", "看电视" };
    cout << endl << "\t属性" << endl << endl;
    cout << "生命： " << health << "\t体力： " << physicalStrength << endl
        << "水： " << water << "\t饱腹度： " << food << endl
        << "爱好： " << allHobbies [ hobby] << "\t心情： " << mind << endl
        << "体重： " << weight << "\t现金： " << money << endl
        << "摄糖： " << sugar << "\t摄盐： " << salt << endl
        << "剩余存活天数： " << lifeTime << "\t今天是在监狱的第：" << dayInPrison << endl
        << "每日减少体力： " << everyDayLosePhysicalStrength << endl
        << "每日减少生命： " << everyDayLoseHealth << endl
        << "每日减少饱腹度： " << everyDayLoseFood << endl
        << "每日减少水量：" << everyDayLoseWater << endl;
}
