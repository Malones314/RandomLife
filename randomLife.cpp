#include<iostream>
#include<string>
#include<windows.h>
#include<time.h>
#include"Disease.h"
#include"Food.h"
#include"People.h"
#include"Tool.h"
#include"Treatment.h"
#include"Drink.h"
#include"Furniture.h"
#include"Varia.h"
#include"Hobby.h"

using namespace std;
/**
 * Environment          Vistual Studio 2019
 * Date                       2021/3/31
 * Author                   Malones(RuiChen Zhai)
 *通过玩Android游戏《抽卡人生》，想自己写一个类似的项目
 */
 /**
  *2021/3/31
  *开始进行策划、构思，构思大框架
  *
  *2021/4/1
  *写类大框架
  *写People类
  *
  *2021/4/2
  *写People类
  *写Tool、Treatment、Food、Drink、Disease类
  *写randomLife.cpp框架
  *写初始界面
  *写物品、疾病展示
  *
  *2021/4/3
  *写People类Sleep成员函数
  *添加新类Furniture
  *写randomLife.cpp randCard函数部分框架
  *
  *2021/4/4
  *写randomLife.cpp randCard函数
  *写randomLife.cpp activity函数框架和部分内容
  *写randomLife.cpp 超市的框架和部分内容
  *
  *2021/4/5
  *更改重写People类中治疗，吃饭，喝水的函数
  *写main.cpp中工作的框架
  *
  *2021/4/5
  *完善People类中治疗，吃饭，喝水的函数
  *完善各种类
  *
  *2021/4/6
  *定义randomLife.cpp中main里的一些变量，进一步完善各种类
  *
  *2021/4/7
  *检查截止目前所写内容中的错误，写randomLife.cpp中工作部分的框架
  *
  *2021/4/8
  *完善randomLife.cpp中的工作部分内容
  *增加一个一千天判断函数
  *
  *2021/4/9
  *写randomLife.cpp中的爱好、喝水、饮食部分内容
  *改写物品展示部分，简化代码，改写Drink People Food Furniture Tool Treatment类
  *完善store部分
  *
  *2021/4/10
  *写判断物品是否过期以及过期处理
  *优化改写各种类
  *
  *2021/4/11
  *写做饭函数，代码调试
  *
  *
  *******************************************************************/

void firstView ( );   //初始界面
void showYourself ( People* you, Drink myDrink [4], Food myFood [12], Treatment myTreatment [5], Tool myTool [2], Varia myVaria [14],
    Hobby myHobby [2], Furniture myFurniture [6] );   //展示你的属性和拥有物品

void showDisease ( People* you );   //展示你的疾病
void showDrink ( Drink myDrink [4] );   //展示你拥有的水
void showFood ( Food myFood [12] );   //展示你拥有的食物
void showTreatment ( Treatment myTreatment [5] );   //展示你拥有的治疗卡
void showTool ( Tool myTool [2] );   //展示你拥有的工具
void showVaria ( Varia myVaria [14] );   //展示你拥有的原材料
void showHobby ( Hobby myHobby [2] );   //展示你拥有的兴趣物品
void showFurniture ( Furniture myFurniture [6] );   //展示你拥有的家具
void showCook ( );   //展示可选择得做饭得种类
void cookIt ( Drink myDrink[4], Food myFood [12], Varia myVaria [14], Tool myTool [2], int choice );   //做饭
void randCard ( People* you, Drink myDrink [4], Food myFood [12], Treatment myTreatment [5], Tool myTool [2],
    Varia myVaria [14], Hobby myHobby [2], Furniture myFurniture [6] );   //抽卡函数

void showActivity ( int* yourChoice );
void allWorks ( );   //展示所有工作内容以及要求
void showStore ( int number [8], int money [8] );   //展示超市物品

void buySomeThing ( People* you, Food myFood [12], Drink myDrink [4], Tool myTool [2], Varia myVaria [14],
    int number [8], int money [8], int choice );

void sellSomeThing ( People* you, Food myFood [12], Drink myDrink [4], Tool myTool [2], Varia myVaria [14],
    Treatment myTreatment [5], Hobby myHobby [2], int number [8], int money [8], int choice, bool haveStore );

void doWorks ( People* you, Tool myTool [2], Varia myVaria [14], Furniture myFurniture [6], int myChoice );
bool everyOneThousandDays ( People* you );   //一千天后, 失败返回0
void outDate ( People* you, Food myFood [12], Drink myDrink [4] );   //判断是否过期，以及过期后的处理



//古有悟空受压500年，今有你含冤受到500年刑期，你的生活靠着抽卡，是否可以通过抽卡存活，或是洗刷冤屈
int main ( ) {

    srand ( time ( 0 ) );

    system ( "title Random Life" );

    //得到同样的物品刷新过期时间

    People you;

    Drink myDrink [4];
    myDrink [0].addMyDrink ( "凉白开", 20, 0, 0, 0, 5, 2, 0, 0, 0, 0, 0, 0 );
    myDrink [1].addMyDrink ( "污水", 20, -10, -10, -10, 0x3f3f3f, 0, 0, 0, 50, 10, 0, 1 );
    myDrink [2].addMyDrink ( "自来水", 20, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 2 );
    myDrink [3].addMyDrink ( "可乐", 20, 2, 0, 10, 200, 3, 3, 5, 0, 0, 0, 3 );

    Food myFood [13];
    myFood [0].addMyFood ( "鸡蛋", 3, 0, 0, 10, 1, 0, 0, 0, 3, 100, 0, 0, 0 );
    myFood [1].addMyFood ( "生肉", 20, 0, -5, 5, 10, 5, 0, 0, -5, 100, 50, 0, 1 );
    myFood [2].addMyFood ( "烤肉", 20, 0, 10, 5, 15, 10, 0, 3, -2, 1, 0, 0, 2 );
    myFood [3].addMyFood ( "红烧肉", 20, 0, 10, 5, 20, 15, 0, 3, -2, 2, 0, 0, 3 );
    myFood [4].addMyFood ( "腌肉", 20, 0, 10, 30, 35, 10, 0, 10, 0, 0, 0, 0, 4 );
    myFood [5].addMyFood ( "蔬菜", 15, 0, 0, 7, 1, -1, 0, 0, 3, 100, 0, 0, 4 );
    myFood [6].addMyFood ( "米饭", 25, 0, 0, 7, 5, 5, 0, 0, 0, 0, 0, 0, 6 );
    myFood [7].addMyFood ( "水果", 5, 5, 10, 8, 5, -1, 1, 0, 10, 100, 0, 0, 7 );
    myFood [8].addMyFood ( "熟肉", 20, 0, 5, 5, 20, 10, 0, 3, 0, 0, 0, 0, 8 );
    myFood [9].addMyFood ( "熟腌肉", 20, 0, 10, 5, 30, 10, 0, 7, 0, 0, 0, 0, 9 );
    myFood [10].addMyFood ( "炒菜", 15, 0, 5, 3, 3, 1, 0, 0, 5, 100, 0, 0, 10 );
    myFood [11].addMyFood ( "大杂烩", 40, 0, 20, 3, 70, 7, 0, 3, 20, 100, 0, 0, 11 );
    myFood [12].addMyFood ( "盐", 0, 0, 5, 1000, 0, 0, 0, 100, -20, 100, 0, 0, 12 );

    Tool myTool [3];
    myTool [0].addMyTool ( "木锤", 20, 40, 0, 0 );
    myTool [1].addMyTool ( "钻木取火", 5, 20, 0, 1 );
    myTool [2].addMyTool ( "蜡烛", 10, 2, 0, 2 );   //可用10天, 夜晚可以工作

    Treatment myTreatment [5];
    myTreatment [0].addMyTreatment ( "外伤卡", 10, 20, 0, 0 );
    myTreatment [1].addMyTreatment ( "糖尿病卡", 10, 30, 0, 1 );
    myTreatment [2].addMyTreatment ( "高血压卡", 10, 30, 0, 2 );
    myTreatment [3].addMyTreatment ( "拉肚子卡", 10, 30, 0, 3 );
    myTreatment [4].addMyTreatment ( "手术卡", 100, 300, 0, 4 );

    Furniture myFurniture [6];
    myFurniture [0].addMyFurniture ( "板凳", 10, 0, 0 );
    myFurniture [1].addMyFurniture ( "桌子", 20, 0, 1 );
    myFurniture [2].addMyFurniture ( "床", 40, 0, 2 );
    myFurniture [3].addMyFurniture ( "双人床", 100, 0, 3 );
    myFurniture [4].addMyFurniture ( "水缸", 40, 0, 4 );
    myFurniture [5].addMyFurniture ( "有净水器的水缸", 80, 0, 5 );

    Hobby myHobby [2];
    myHobby [0].addMyHobby ( "绘画", 20, 0, 0 );
    myHobby [1].addMyHobby ( "书法", 20, 0, 1 );

    Varia myVaria [14];
    myVaria [0].addMyVaria ( "木头", 2, 0, 0 );
    myVaria [1].addMyVaria ( "锅", 5, 0, 1 );
    myVaria [2].addMyVaria ( "净水器", 20, 0, 2 );
    myVaria [3].addMyVaria ( "电力", 1, 0, 3 );
    myVaria [4].addMyVaria ( "小木板", 2, 0, 4 );
    myVaria [5].addMyVaria ( "木板", 5, 0, 5 );
    myVaria [6].addMyVaria ( "大木板", 10, 0, 6 );
    myVaria [7].addMyVaria ( "超大木板", 20, 0, 7 );
    myVaria [8].addMyVaria ( "小木块", 1, 0, 8 );
    myVaria [9].addMyVaria ( "木块", 2, 0, 9 );
    myVaria [10].addMyVaria ( "大木块", 10, 0, 10 );
    myVaria [11].addMyVaria ( "超大木块", 20, 0, 11 );
    myVaria [12].addMyVaria ( "柴火", 0, 0, 12 );
    myVaria [13].addMyVaria ( "木屑", 0, 0, 13 );

    int k = 0;

    k = rand ( ) % 6;
    string allHobbies [8] = { "发呆", "吃饭", "制造", "喝水", "睡觉", "看电视", "绘画", "书法" };
    you.hobby = k;   //随机兴趣
    firstView ( );
    randCard ( &you, myDrink, myFood, myTreatment, myTool, myVaria, myHobby, myFurniture );
    showYourself ( &you, myDrink, myFood, myTreatment, myTool, myVaria, myHobby, myFurniture );

    double dayHour = 8.0;
    int iStoreEachNumber [12] = { 10, 5, 5, 20, 10, 5, 1, 30, 1, 1, 1, 5 };
    int iStoreEachMoneyBuyNormal [8] = { 30, 50, 100, 20, 50, 20, 50, 2000, };   //没买超市的价格
    int iStoreEachMoneyBuyOwner [8] = { 15, 30, 50, 3, 5, 3, 20, 2000 };   //买过超市的价格
    int iStoreEachMoneySell [8] = { 10, 15, 35, 2, 3, 3, 10 };   //卖东西的价格，0代表超市不卖
    while ( you.lifeTime > -1 && you.health > 0 ) {
        if ( myFurniture [2].number ) {
            dayHour = 6.0;
            if ( myFurniture [3].number )
                dayHour = 4.0;                
        }
        //进行任何活动都要减少5体力5饮水5饱腹度，工作锻炼额外减少10体力
        system ( "cls" );
        cout << "进入监狱第 " << you.dayInPrison << " 天" << endl;
        cout << "你的生命还剩 " << you.lifeTime << "天" << endl;
        cout << "距离1000天贡献10000元和90生命以及100天寿命还剩 " << 1000 - you.dayInPrison << " 天" << endl;
        if ( you.dayInPrison % 1000 == 0 ) {
            if ( everyOneThousandDays ( &you ) == 0 )
                break;
        }
        randCard ( &you, myDrink, myFood, myTreatment, myTool, myVaria, myHobby, myFurniture );
        int activity = 0x3f3f3f3f;
        double lastHourTotal = 17.0;
        double lastHour;
        if ( myTool [2].number > 0 || myTool [2].times > 0 ) {
            cout << "是否使用蜡烛？" << endl;
            bool useit = false;
            cin >> useit;
            if( useit ){
                myTool [2].useIt ( 1 );
                lastHourTotal = 21.0;
            }
        }
        for ( lastHour = lastHourTotal; dayHour < lastHour; lastHour = lastHourTotal ) {
            showYourself ( &you, myDrink, myFood, myTreatment, myTool, myVaria, myHobby, myFurniture );
            int choice = -1;
            cout << "现在时间：" << ( int ) dayHour << " : " << ( dayHour - ( int ) dayHour ) * 60 << endl << endl;
            showActivity ( &activity );
            int buyOrSell = -1;
            cout << endl;

            system ( "cls" );
            you.showYourself ( );

            //活动
            if ( activity == 1 ) {   //吃饭
                cout << "吃饭消耗1小时" << endl;
                dayHour++;
                showFood ( myFood );

            } else if ( activity == 2 ) {   //喝水
                cout << "喝水消耗15分钟" << endl;
                dayHour += 0.25;
                showDrink ( myDrink );

            } else if ( activity == 3 ) {   //工作
                int workHour = 4;
                if ( myFurniture [0].number ) {
                    if ( myFurniture [1].number )
                        workHour = 2;
                    else
                        workHour = 3;
                } else
                    if ( myFurniture [1].number )
                        workHour = 3;
                dayHour += workHour;
                cout << "工作" << workHour << "小时" << endl;
                allWorks ( );

            } else if ( activity == 4 ) {   //锻炼
                cout << "锻炼消耗2小时" << endl;
                dayHour += 2;
                you.doExercise ( );
                continue;

            } else if ( activity == 5 ) {   //爱好
                cout << "爱好消耗1小时" << endl;
                dayHour++;
                showHobby ( myHobby );

            } else if ( activity == 6 ) {   //治病
                cout << "治病消耗6小时" << endl;
                dayHour += 6;
                showDisease ( &you );

            } else if ( activity == 7 ) {   //去超市
                dayHour += 4;
                cout << "去超市消耗4小时" << endl;
                cout << "你还有：" << you.money << " 元" << endl;
                cout << endl << "你是要买(1)还是卖(0) ? " << endl;
                cin >> buyOrSell;
                if ( buyOrSell ) {
                    if ( you.haveStore )
                        showStore ( iStoreEachNumber, iStoreEachMoneyBuyOwner );
                    else
                        showStore ( iStoreEachNumber, iStoreEachMoneyBuyNormal );
                } else
                    showStore ( iStoreEachNumber, iStoreEachMoneySell );
            } else if ( activity == 8 ) {
                if ( you.TVNumber > 0 && myVaria[3].number > 0 ) {
                    cout << "看电视消耗2小时" << endl;
                    dayHour += 2;
                    you.watchTV ( );
                } else
                    cout << "你没有电视。" << endl;
            } else if ( activity == 9 ) {
                cout << "做饭" << endl;
                showFood ( myFood );
                myTool [1].showItself ( );
                myVaria [1].showItself ( );
            } else if ( activity == 10 ) {
                cout << "睡觉" << endl;
                break;
            }
            cout << endl << "输入你的选择，若要返回则输入-1" << endl;
            cin >> choice;
            
            if ( choice != -1 ) {
                if ( activity == 1 ) {
                    showFood ( myFood );
                    if ( myFood [choice].addWeight > 0 ) {
                        you.myDisease [4].getDisease ( &you, myFood [choice].addWeight, 4 );
                        you.myDisease [5].getDisease ( &you, -myFood [choice].addWeight, 5 );
                    } else if ( myFood [choice].addWeight < 0 ) {
                        you.myDisease [5].getDisease ( &you, -myFood [choice].addWeight, 5 );
                        you.myDisease [4].getDisease ( &you, myFood [choice].addWeight, 4 );
                    }
                } else if ( activity == 2 ) {
                    you.getDrink ( &myDrink [choice] );
                    if ( myDrink [choice].addWeight > 0 ) {
                        you.myDisease [4].getDisease ( &you, myDrink [choice].addWeight, 4 );
                        you.myDisease [5].getDisease ( &you, -myDrink [choice].addWeight, 5 );
                    } else if ( myDrink [choice].addWeight < 0 ) {
                        you.myDisease [5].getDisease ( &you, -myDrink [choice].addWeight, 5 );
                        you.myDisease [4].getDisease ( &you, myDrink [choice].addWeight, 4 );
                    }
                } else if ( activity == 3 ) {   //工作
                    doWorks ( &you, myTool, myVaria, myFurniture, choice );
                } else if ( activity == 5 ) {   //爱好
                    //如果爱好是绘画书法，则使用绘画书法添加40mind 否则添加10
                    if ( choice == 0 || choice == 1 )
                        myHobby [choice].changeNumber ( -1 );
                    you.getHobby ( choice );
                } else if ( activity == 6 ) {   //治病
                    showTreatment ( myTreatment );
                    cout << "是否使用卡片?(1/0)" << endl;
                    bool useCardOrNot = false;
                    cin >> useCardOrNot;
                    you.getTreatment ( &myTreatment [choice], useCardOrNot );
                } else if ( activity == 7 ) {   //超市
                    if ( buyOrSell ) {
                        if ( you.haveStore )
                            buySomeThing ( &you, myFood, myDrink, myTool, myVaria, iStoreEachNumber, iStoreEachMoneyBuyOwner, choice );
                        else
                            buySomeThing ( &you, myFood, myDrink, myTool, myVaria, iStoreEachNumber, iStoreEachMoneyBuyNormal, choice );
                    } else
                        sellSomeThing ( &you, myFood, myDrink, myTool, myVaria, myTreatment, myHobby, iStoreEachNumber, iStoreEachMoneySell, choice, you.haveStore );
                } else if ( activity == 8 ) {   //做饭烧水
                    cookIt ( myDrink, myFood, myVaria, myTool, choice );
                }
            }
            showActivity ( &activity );
        }
        //睡觉过后
        //判断物品是否过期物品过期直接消失，并且减1心情
        //dayInPrison++
        you.sleep ( );
        outDate ( &you, myFood, myDrink );
    }
    return 0;
}

void randCard ( People* you, Drink myDrink [4], Food myFood [12], Treatment myTreatment [5], Tool myTool [2],
    Varia myVaria [14], Hobby myHobby [2], Furniture myFurniture [6] ) {   //抽卡
    string things [9] = { "治疗", "食物", "水", "工具", "材料", "兴趣", "家具", "钱", "什么也没有" };
    int k = 0;
    //钱可抽到[1,100]
    k = rand ( ) % 9;
    if ( k == 8 ) {
        cout << things [8];
    } else {
        int i = 0;
        if ( k == 7 ) {
            i = rand ( ) % 100 + 1;
            cout << "你抽到了：" << i << " 元。" << endl;
            you->changeMoney ( i );
        } else {
            cout << "你抽到了：" << things [k] << " 卡中的 ";
            if ( k == 0 ) {   //治疗
                i = rand ( ) % 5;
                myTreatment [i].changeNumber ( 1 );
                cout << myTreatment [i].name << endl;
            } else if ( k == 1 ) {   //食物
                i = rand ( ) % 7;
                myFood [i].changeNumber ( 1 );
                cout << myFood [i].name << endl;
            } else if ( k == 2 ) {   //水
                i = rand ( ) % 4;
                myDrink [i].changeNumber ( 1 );
                cout << myDrink [i].name << endl;
            } else if ( k == 3 ) {   //工具
                i = rand ( ) % 3;
                myTool [i].plusOne ( );
                cout << myTool [i].name << endl;
            } else if ( k == 4 ) {   //材料
                i = rand ( ) % 4;
                myVaria [i].changeNumber ( 1 );
                cout << myVaria [i].name << endl;
            } else if ( k == 5 ) {   //兴趣
                i = rand ( ) % 2;
                myHobby [i].changeNumber ( 1 );
                cout << myHobby [i].name << endl;
            } else if ( k == 6 ) {   //家具
                i = rand ( ) % 6;
                myFurniture [i].changeNumber ( 1 );
                cout << myFurniture [i].name << endl;
            }
        }
    }
}
void firstView ( ) {
    cout << "------------------------------";
    cout << endl << endl << "\t随机化的监狱生活" << endl << endl;
    cout << "------------------------------";
    Sleep ( 3000 );
    system ( "cls" );
    cout << "是否开始游戏？(0 or 1)" << endl;
    bool gameBegin = false;
    cin >> gameBegin;
    if ( gameBegin ) {
        system ( "cls" );
        cout << "受到小人陷害，你含冤入狱，这里的监狱和别处不同，" << endl;
        Sleep ( 2000 );
        cout << "这里什么也没有，只有你面前的一个盒子，盒子上面有一行小字" << endl;
        Sleep ( 2000 );
        cout << "“手掌放入凹槽中得到随机卡片，卡片上的物品可以现实出现！”" << endl;
        Sleep ( 2000 );
        cout << "你又看了看盒子后面的清单，卡片上的物品应有尽有，" << endl;
        Sleep ( 2000 );
        cout << "最底部出现了一行小字：" << endl;
        Sleep ( 2000 );
        cout << "“每隔1000天要奉献10000元和90生命以及100天寿命，作为代价。”" << endl;
        Sleep ( 2000 );
        cout << "盒子侧部有个手掌大小的凹槽，凹槽中的纹路与你的掌纹惊人的一致，" << endl;
        Sleep ( 2000 );
        cout << "你没想太多，只想着能活下去，找到一些证明无辜的蛛丝马迹，" << endl;
        Sleep ( 2000 );
        cout << "你缓缓把颤抖的手放入凹槽中。" << endl;
        Sleep ( 1000 );
        system ( "cls" );
        cout << "\t游戏开始！";
        Sleep ( 500 );
        system ( "cls" );
    } else {
        system ( "cls" );
        cout << "退出";
    }
}


/**每过1000天进行
* 减少
* 10000元
* 90生命
* 100天寿命
**/
bool everyOneThousandDays ( People* you ) {
    bool bContinue = false;
    if ( you->money < 10000 || you->health < 90 || you->lifeTime < 100 ) {
        cout << "你无法满足盒子的贡献条件，盒子突然越变越大。" << endl;
        Sleep ( 2000 );
        cout << "盒子底部的开口亮出了刺眼的光，出现了两只恶魔，" << endl;
        Sleep ( 2000 );
        cout << "“愚蠢的贱人，完成不了奉献怎敢使用魔盒” " << endl;
        Sleep ( 1000 );
        cout << "你被恶魔拖入了地狱 ";
        Sleep ( 500 );
        system ( "cls" );
        cout << "Game Over!" << endl;
    } else {
        you->changeMoney ( -10000 );
        you->changeHealth ( -90 );
        you->lifeTime -= 100;
        cout << "你把1000现金放到盒子上, 把手搭在盒子侧部凹槽中，" << endl;
        Sleep ( 2000 );
        cout << "一阵虚弱感慢慢传来，盒子吸着你的手，迟迟没有松开，" << endl;
        Sleep ( 2000 );
        cout << "1分钟过后，吸力终于消失了，你叹了口气，日子还是得继续。";
        system ( "cls" );
        bContinue = 1;
    }
    return bContinue;
}

void showYourself ( People* you, Drink myDrink [4], Food myFood [12], Treatment myTreatment [5], Tool myTool [2], Varia myVaria [14],
    Hobby myHobby [2], Furniture myFurniture [6] ) {
    string allHobbies [6] = { "发呆", "吃饭", "制造", "喝水", "睡觉", "看电视" };

    cout << endl << "\t属性" << endl << endl;
    cout << "生命： " << you->health << "\t体力： " << you->physicalStrength << endl
        << "水： " << you->water << "\t饱腹度： " << you->food << endl
        << "爱好： " << allHobbies [you->hobby] << "\t心情： " << you->mind << endl
        << "体重： " << you->weight << "\t现金： " << you->money << endl
        << "摄糖： " << you->sugar << "\t摄盐： " << you->salt << endl
        << "剩余存活天数： " << you->lifeTime << "\t今天是在监狱的第：" << you->dayInPrison << endl
        << "每日减少体力： " << you->everyDayLosePhysicalStrength << endl
        << "每日减少生命： " << you->everyDayLoseHealth << endl
        << "每日减少饱腹度： " << you->everyDayLoseFood << endl
        << "每日减少水量：" << you->everyDayLoseWater << endl;

    cout << endl << endl;
    showDisease ( you );
    cout << endl;

    cout << "\t目前所拥有物品:" << endl << endl;
    showDrink ( myDrink );
    cout << endl;
    showFood ( myFood );
    cout << endl;
    showTreatment ( myTreatment );
    cout << endl;
    showTool ( myTool );
    cout << endl;
    showVaria ( myVaria );
    cout << endl;
}
void showDisease ( People* you ) {
    string Level [5] = { "正常，无病", "轻度", "中度", "重度", "绝境" };
    cout << "\t疾病及患病程度" << endl << endl;
    cout << "外伤：" << Level [you->myDisease [0].level] << "\t目前累计程度：" << you->myDisease [0].now << endl
        << "糖尿病：" << Level [you->myDisease [1].level] << "\t目前累计程度：" << you->myDisease [1].now << endl
        << "高血压：" << Level [you->myDisease [2].level] << "\t目前累计程度：" << you->myDisease [2].now << endl
        << "拉肚子：" << Level [you->myDisease [3].level];
    if ( you->myDisease [3].level > 0 )
        cout << "\t离痊愈还剩：" << you->myDisease [3].whenCure << " 天" << endl;
    cout << "肥胖：" << Level [you->myDisease [4].level] << endl;
    cout << "偏瘦：" << Level [you->myDisease [5].level] << endl;
}

void showDrink ( Drink myDrink [4] ) {   //展示你拥有的水
    cout << endl << "\t你所拥有的水" << endl << endl;
    for ( int i = 0; i < 4; i++ )
        cout << myDrink [i].name << "\t编号：" << myDrink [i].which << endl
        << "个数：" << myDrink [i].number << "过期还剩：" << myDrink [i].nowSurpluesShelfLife << endl;
}
void showFood ( Food myFood [12] ) {   //展示你拥有的食物
    cout << endl << "\t你所拥有的食物" << endl << endl;
    for ( int i = 0; i < 12; i++ )
        cout << myFood [i].name << "\t编号：" << myFood [i].which << endl
        << "个数: " << myFood [i].number << "过期还剩：" << myFood[i].nowSurpluesShelfLife << endl;
}
void showTreatment ( Treatment myTreatment [5] ) {   //展示你拥有的治疗卡
    cout << endl << "\t你所拥有的治疗卡" << endl << endl;
    for ( int i = 0; i < 5; i++ )
        cout << myTreatment [i].name << "\t编号：" << myTreatment [i].which << endl
        << "个数：" << myTreatment [i].number << endl;
}
void showTool ( Tool myTool [2] ) {   //展示你拥有的工具
    cout << endl << "\t你所拥有的工具" << endl << endl;
    for ( int i = 0; i < 3; i++ )
        cout << myTool [i].name << "\t编号：" << myTool [i].which << endl
        << "个数：" << myTool [i].number << "\t价值：" << myTool[i].value << endl;
}
void showVaria ( Varia myVaria [14] ) {   //展示你拥有的原材料
    cout << endl << "\t你所拥有的材料" << endl << endl;
    for ( int i = 0; i < 14; i++ )
        cout << myVaria [i].name << "\t编号：" << myVaria [i].which << endl
        << "个数：" << myVaria [i].number << endl;
}
void showHobby ( Hobby myHobby [2] ) {   //展示你拥有的兴趣物品
    cout << endl << "\t你所拥有的兴趣物品" << endl << endl;
    for ( int i = 0; i < 2; i++ )
        cout << myHobby [i].name << "\t编号：" << myHobby [i].which << endl
        << "个数：" << myHobby [i].number << endl;
}
void showFurniture ( Furniture myFurniture [6] ) {   //展示你拥有的家具
    cout << endl << "\t你所拥有的家具" << endl << endl;
    for ( int i = 0; i < 6; i++ )
        cout << myFurniture [i].name << "\t编号：" << myFurniture [i].which << endl
        << "个数：" << myFurniture [i].number << endl;
}
void showCook ( ) {
    cout << "1.熟肉（1生肉1盐4柴火）\t2.熟腌肉（1腌肉4柴火）" << endl;
    cout << "3.炒菜（1蔬菜1盐2柴火）\t4.大杂烩（1肉1菜1蛋1盐8柴火）" << endl;
    cout << "5.烧水（1自来水1柴火）" << endl;
}
void cookIt ( Drink myDrink[4], Food myFood [12], Varia myVaria [14], Tool myTool [2], int choice ) {
    myTool [1].decrease ( );
    bool couldCood = true;
    if ( choice == 1 ) {
        if ( myFood [1].number > 0 && myFood [12].number > 0 && myVaria [12].number > 3 ) {
            myFood [1].changeNumber ( -1 );
            myFood [12].changeNumber ( -1 );
            myVaria [12].changeNumber ( -4 );
        } else
            couldCood = false;
    } else if ( choice == 2 ) {
        if ( myFood [4].number > 0 && myVaria [12].number > 3 ) {
            myFood [4].changeNumber ( -1 );
            myVaria [12].changeNumber ( -4 );
        } else
            couldCood = false;
    } else if ( choice == 3 ) {
        if ( myFood [5].number > 0 && myFood [12].number > 0 && myVaria [12].number > 1 ) {
            myFood [5].changeNumber ( -1 );
            myFood [12].changeNumber ( -1 );
            myVaria [12].changeNumber ( -2 );
        } else
            couldCood = false;
    } else if ( choice == 4 ) {
        if ( myFood [1].number > 0 && myFood [12].number > 0 && myFood [0].number > 0 && myFood [5].number > 0 && myVaria [12].number > 7 ) {
            myFood [0].changeNumber ( -1 );
            myFood [5].changeNumber ( -1 );
            myFood [1].changeNumber ( -1 );
            myFood [12].changeNumber ( -1 );
            myVaria [12].changeNumber ( -8 );
        } else
            couldCood = false;
    } else if ( choice == 5 ) {
        if ( myDrink [2].number > 0 && myVaria [12].number > 0 ) {
            myDrink [2].changeNumber ( -1 );
            myDrink [0].changeNumber ( 1 );
            myVaria [12].changeNumber ( -1 );
        } else
            couldCood = false;
    }
}
void showActivity ( int* yourChoice ) {
    cout << endl << "1.吃饭      2.喝水\n3.工作      4.锻炼\n5.爱好      6.治病\n7.去超市    8.看电视\n9.做饭      10.睡觉\n" << endl
        << "若无活动进行输入-1" << endl
        << "你的选择是：";
    int activity;
    cin >> activity;
    cout << endl;
    *yourChoice = activity;
}
void allWorks ( ) {
    cout << "\t所有的工作选择：" << endl;
    cout << "1 木材  ->  0.25超大木块，0.5大木板，1木板，2木块，2小木板，4小木块，8柴火，16木屑 \n";
    cout << "1. 4个小木块"
        << endl << "消耗：1木材" << endl;
    cout << "2. 2个木块"
        << endl << "消耗：1木材" << endl;
    cout << "3.2个小木板"
        << endl << "消耗：1木材" << endl;
    cout << "4.1个木板"
        << endl << "消耗：1木材" << endl;
    cout << "5.1个大木板"
        << endl << "消耗：2木材" << endl;
    cout << "6.一个超大木板"
        << endl << "消耗：4木材" << endl;
    cout << "7.8个柴火"
        << endl << "消耗：1木材" << endl;
    cout << "8.16个木屑"
        << endl << "消耗：1木材" << endl;
    cout << "9. 木锤（基础工具，没有木锤只能造木块和小木块，可用20次）"
        << endl << "消耗：1木块 1小木块" << endl;
    cout << "10.板凳（工作时间减少25%）"
        << endl << "消耗：1小木板 4小木块" << endl;
    cout << "11.桌子（工作时间减少25%）"
        << endl << "消耗：1木板 4木块" << endl;
    cout << "12.床（睡觉时间减少25%）"
        << endl << "消耗：2大木板 4木块" << endl;
    cout << "13.双人床（睡觉时间减少50%）"
        << endl << "消耗：1床 2大木块 2木块 4小木块" << endl;
    cout << "14.水缸(自来水和凉白开的存储时间加5)"
        << endl << "消耗：2超大木块" << endl;
    cout << "15.带有净水器的水缸（自来水和凉白开的存储时间加10）"
        << endl << "消耗：1水缸1净水器" << endl;

}
/**工作
*  you 用于体重减少，判断是否得外伤，判断是否体重过轻
 * myFood 所拥有的食物
 * myDrink 所拥有的水
 * myTool 所拥有的工具
 * myVaria 所拥有的材料
*/
void doWorks ( People* you, Tool myTool [2], Varia myVaria [14], Furniture myFurniture [6], int yourChoice1 ) {
    you->myDisease [0].getDisease ( you, 1, 0 );
    you->myDisease [4].getDisease ( you, -5, 4 );
    you->myDisease [5].getDisease ( you, 5, 5 );
    showTool ( myTool );
    showVaria ( myVaria );
    showFurniture ( myFurniture );
    bool couldBuild = false;
    int buildTimes = 0;
    for ( buildTimes = 0; yourChoice1 != -1 && buildTimes < 2; cin >> yourChoice1 ) {
        buildTimes++;
        if ( yourChoice1 == 1 && myVaria [0].number > 0 ) {   //4小木块
            myVaria [0].changeNumber ( -1 );
            myVaria [8].changeNumber ( 4 );
            couldBuild = true;
        } else if ( yourChoice1 == 2 && myVaria [0].number > 0 ) {   //2木块
            myVaria [0].changeNumber ( -1 );
            myVaria [9].changeNumber ( 2 );
            couldBuild = true;
        } else {
            if ( yourChoice1 == 9 ) {   //1木锤
                if ( myVaria [8].number > 0 && myVaria [9].number > 0 ) {
                    myVaria [8].changeNumber ( -1 );
                    myVaria [9].changeNumber ( -1 );
                    myTool [0].plusOne ( );
                    couldBuild = true;
                }
            } else if ( yourChoice1 == 3 ) {   //2小木板
                if ( myTool [0].number > 0 || myTool [0].times > 0 ) {
                    myTool [0].useIt ( 1 );
                    myVaria [0].changeNumber ( -1 );
                    myVaria [4].changeNumber ( 2 );
                    couldBuild = true;
                }
            } else if ( yourChoice1 == 4 ) {   //1木板
                if ( myTool [0].number > 0 || myTool [0].times > 0 ) {
                    myTool [0].useIt ( 1 );
                    myVaria [0].changeNumber ( -1 );
                    myVaria [5].changeNumber ( 1 );
                    couldBuild = true;
                }
            } else if ( yourChoice1 == 5 ) {   //0.5大木板
                if ( myTool [0].number > 0 || myTool [0].times > 0 ) {
                    myTool [0].useIt ( 1 );
                    myVaria [0].changeNumber ( -2 );
                    myVaria [6].changeNumber ( 1 );
                    couldBuild = true;
                }
            } else if ( yourChoice1 == 6 ) {   //0.25超大木板
                if ( myTool [0].number > 0 || myTool [0].times > 0 ) {
                    myTool [0].useIt ( 1 );
                    myVaria [0].changeNumber ( -4 );
                    myVaria [7].changeNumber ( 1 );
                    couldBuild = true;
                }
            } else if ( yourChoice1 == 7 ) {   //8柴火
                if ( myVaria [0].number > 0 && ( myTool [0].number > 0 || myTool [0].times > 0 ) ) {
                    myTool [0].useIt ( 1 );
                    myVaria [0].changeNumber ( -1 );
                    myVaria [12].changeNumber ( 8 );
                    couldBuild = true;
                }
            } else if ( yourChoice1 == 8 ) {   //16木屑
                if ( myVaria [0].number > 3 && ( myTool [0].number > 0 || myTool [0].times > 0 ) ) {
                    myTool [0].useIt ( 1 );
                    myVaria [0].changeNumber ( -1 );
                    myVaria [13].changeNumber ( 16 );
                    couldBuild = true;
                }
            } else if ( yourChoice1 == 10 ) {   //板凳
                if ( myVaria [4].number > 0 && myVaria [8].number > 3 && ( myTool [0].number > 0 || myTool [0].times > 0 ) ) {
                    myTool [0].useIt ( 1 );
                    myVaria [4].changeNumber ( -1 );
                    myVaria [8].changeNumber ( -4 );
                    myFurniture [0].changeNumber ( 1 );
                    couldBuild = true;
                }
            } else if ( yourChoice1 == 11 ) {   //桌子
                if ( myVaria [5].number > 0 && myVaria [9].number > 3 && ( myTool [0].number > 0 || myTool [0].times > 0 ) ) {
                    myTool [0].useIt ( 1 );
                    myVaria [5].changeNumber ( -1 );
                    myVaria [9].changeNumber ( -4 );
                    myFurniture [1].changeNumber ( 1 );
                    couldBuild = true;
                }
            } else if ( yourChoice1 == 12 ) {    //床
                if ( myVaria [5].number > 1 && myVaria [9].number > 3 && ( myTool [0].number > 0 || myTool [0].times > 0 ) ) {
                    myTool [0].useIt ( 1 );
                    myVaria [5].changeNumber ( -2 );
                    myVaria [9].changeNumber ( -4 );
                    myFurniture [2].changeNumber ( 1 );
                    couldBuild = true;
                }
            } else if ( yourChoice1 == 13 ) {    //双人床
                if ( myVaria [5].number > 1 && myVaria [9].number > 1 && myFurniture [2].number > 0 && myVaria [8].number > 1 && ( myTool [0].number > 0 || myTool [0].times > 0 ) ) {
                    myTool [0].useIt ( 1 );
                    myFurniture [2].number--;
                    myVaria [8].number -= 2;
                    myVaria [5].number -= 2;
                    myVaria [9].number -= 2;
                    myFurniture [3].number++;
                    couldBuild = true;
                }
            } else if ( yourChoice1 == 14 ) {   //水缸
                if ( myVaria [11].number > 1 && ( myTool [0].number > 0 || myTool [0].times > 0 ) ) {
                    myTool [0].useIt ( 1 );
                    myFurniture [4].number++;
                    myVaria [11].number -= 2;
                    couldBuild = true;
                }
            } else if ( yourChoice1 == 15 ) {    //带净水器的水缸
                if ( myFurniture [4].number > 0 && myVaria [2].number > 0 && ( myTool [0].number > 0 || myTool [0].times > 0 ) ) {
                    myTool [0].useIt ( 1 );
                    myFurniture [5].number++;
                    myFurniture [4].number--;
                    myVaria [2].number--;
                    couldBuild = true;
                }
            }
        }
        if ( couldBuild == false )
            cout << "无法制造，材料或者木锤使用次数不够，";
        else
            cout << "制造成功，若还需制造，";
        cout << "请输入你的选择，若要返回则输入-1" << endl;
    }
}

/**展示商店中物品（买或卖）
*iEachNumber ：物品剩余个数
* iMoney：物品价值
****/
void showStore ( int iEachNumber [8], int iMoney [8] ) {
    cout << endl << "\t小卖部" << endl;
    printf ( "0.生肉 ( %d / 10 )\t%d 元\t1.烤肉( %d /  5 )\t%d 元\n", iEachNumber [0], iMoney [0], iEachNumber [1], iMoney [1] );
    printf ( "2.腌肉 ( %d /   5 )\t%d 元\n", iEachNumber [2], iMoney [2] );
    printf ( "3.凉白开( %d / 20 )\t%d 元\t4.可乐( %d / 10 )\t%d 元\n", iEachNumber [3], iMoney [3], iEachNumber [4], iMoney [4] );
    printf ( "6.蜡烛( %d / 5 )\t%d 元\n", iEachNumber [5], iMoney [5] );
    printf ( "7.电力( %d / 30 )\t%d 元\t8.电视( %d / 1)\t%d 元\n", iEachNumber [6], iMoney [6], iEachNumber [7], iMoney [7] );
    cout << "9.超市\t 20万元10.卖更多物品（拥有超市后可选）\n" << endl;
    cout << endl;
}
/**买物品
*  you 用于增加售卖后所得金钱
* myFood 所拥有的食物
* myDrink 所拥有的水
* myTool 所拥有的工具
* myVaria 所拥有的材料
* number：物品剩余个数
* money：物品价格
******/
void buySomeThing ( People* you, Food myFood [12], Drink myDrink [4], Tool myTool [2], Varia myVaria [14], int number [8], int money [8], int choice ) {
    cout << endl;
    if ( choice == 8 ) {
        if ( you->money > 200000 ) {
            you->changeMoney ( -200000 );
            you->haveStore = true;
        } else
            cout << "\n你的钱不够\n" << endl;
    } else {
        if ( choice == 0 ) {
            myFood [1].changeNumber ( 1 );
        } else if ( choice == 1 ) {
            myFood [2].changeNumber ( 1 );
        } else if ( choice == 2 ) {
            myFood [4].changeNumber ( 1 );
        } else if ( choice == 3 ) {
            myDrink [0].changeNumber ( 1 );
        } else if ( choice == 4 ) {
            myDrink [3].changeNumber ( 1 );
        } else if ( choice == 5 ) {
            myTool [2].plusOne ( );
        } else if ( choice == 6 ) {
            myVaria [3].changeNumber ( 1 );
        } else if ( choice == 7 ) {
            you->TVNumber++;
        }
        you->changeMoney ( -money [choice] );
        number [choice]--;
    }
}

/** 卖东西
 * you 用于增加售卖后所得金钱
 * myFood 所拥有的食物
 * myDrink 所拥有的水
 * myTool 所拥有的工具
 * myVaria 所拥有的材料
 * number 商店物品剩余数量
 * money 物品可卖的价格
 */

void sellSomeThing ( People* you, Food myFood [12], Drink myDrink [4], Tool myTool [2], Varia myVaria [14],
    Treatment myTreatment [5], Hobby myHobby [2], int number [8], int money [8], int choice, bool haveStore ) {
    cout << endl;
    bool couldSell = false;
    if ( choice == 0 ) {
        if ( myFood [1].number > 0 ) {
            myFood [1].changeNumber ( -1 );
            couldSell = true;
        }
    } else if ( choice == 1 ) {
        if ( myFood [2].number > 0 ) {
            myFood [2].changeNumber ( -1 );
            couldSell = true;
        }
    } else if ( choice == 2 ) {
        if ( myFood [4].number > 0 ) {
            myFood [4].changeNumber ( -1 );
            couldSell = true;
        }
    } else if ( choice == 3 ) {
        if ( myDrink [0].number > 0 ) {
            myDrink [0].changeNumber ( -1 );
            couldSell = true;
        }
    } else if ( choice == 4 ) {
        if ( myDrink [3].number > 0 ) {
            myDrink [3].changeNumber ( -1 );
            couldSell = true;
        }
    } else if ( choice == 5 ) {
        if ( myTool [2].number > 0 ) {
            myTool [2].decrease ( );
            couldSell = true;
        }
    } else if ( choice == 6 ) {
        if ( myVaria [3].number > 0 ) {
            myVaria [3].changeNumber ( -1 );
            couldSell = true;
        }
    } else if ( choice == 10 ) {
        if ( haveStore ) {
            showDrink ( myDrink );
            showFood ( myFood );
            showTool ( myTool );
            showVaria ( myVaria );
            showTreatment ( myTreatment );
            showHobby ( myHobby );
            cout << "卖水（0）, 卖食物（1）， 卖工具（2），卖原材料（3），卖治疗物品（4），卖爱好物品（5）：" << endl;
            int choice1 = -1;
            cin >> choice1;
            cout << "你要卖其中的哪个 ? " << endl;
            int choice2 = -1;
            cin >> choice2;
            if ( choice1 == 0 ) {
                if ( myDrink [choice2].number > 0 ) {
                    couldSell = true;
                    you->changeMoney ( myDrink [choice2].value );
                    myDrink [choice2].changeNumber ( -1 );
                    couldSell = true;
                }
            } else if ( choice1 == 1 ) {
                if ( myFood [choice2].number > 0 ) {
                    you->changeMoney ( myFood [choice2].value );
                    myFood [choice2].changeNumber ( -1 );
                    couldSell = true;
                }
            } else if ( choice1 == 2 ) {
                if ( myTool [choice2].number > 0 ) {
                    you->changeMoney ( myTool [choice2].value );
                    myTool [choice2].decrease ( );
                    couldSell = true;
                }
            } else if ( choice1 == 3 ) {
                if ( myVaria [choice2].number > 0 ) {
                    you->changeMoney ( myVaria [choice2].value );
                    myVaria [choice2].changeNumber ( -1 );
                    couldSell = true;
                }
            } else if ( choice1 == 4 ) {
                if ( myTreatment [choice2].number > 0 ) {
                    you->changeMoney ( myTreatment [choice2].value );
                    myTreatment [choice2].changeNumber ( -1 );
                    couldSell = true;
                }
            } else if ( choice1 == 5 ) {
                if ( myHobby [choice2].number > 0 ) {
                    you->changeMoney ( myHobby [choice2].value );
                    myHobby [choice2].changeNumber ( -1 );
                    couldSell = true;
                }
            }
        } else
            cout << "你还没有买下超市，无法卖你想卖的物品!" << endl;
    }
    if ( choice != 10 )
        if ( couldSell ) {
            you->changeMoney ( money [choice] );
            number [choice]++;
        } else {
            cout << "物品不够，无法出售" << endl;
        }
}
/**物品过期判断
 *you：用于物品过期后的减心情
 *myFood 所拥有的食品
 *myDrink 所拥有的水
 ****/
void outDate ( People* you, Food myFood [12], Drink myDrink [4] ) {
    int i = 0;
    for ( i = 0; i < 12; i++ ) {
        if ( myFood [i].number > 0 ) {
            myFood [i].nowSurpluesShelfLife--;
            if ( myFood [i].nowSurpluesShelfLife == -1 ) {
                if ( myFood->number > 0 ) {
                    myFood [i].changeNumber ( -1 );
                    you->changeMind ( -1 );
                }
            }
        } else
            myFood [i].nowSurpluesShelfLife = 0;
    }
    for ( i = 0; i < 4; i++ ) {
        if ( myDrink [i].number > 0 ) {
            myDrink [i].nowSurpluesShelfLife--;
            if ( myDrink [i].nowSurpluesShelfLife == -1 ) {
                if ( myDrink [i].number > 0 ) {
                    myDrink [i].changeNumber ( -1 );
                    you->changeMind ( -1 );
                }
            }
        } else
            myDrink [i].nowSurpluesShelfLife = 0;
    }
}

