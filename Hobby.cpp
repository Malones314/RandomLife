#include "Hobby.h"
#include<iostream>
#include<string>
using namespace std;
Hobby::Hobby ( ) {
	name.assign ( "*" );
	number = 0;
	which = 0;
	value = 0;
}
Hobby::Hobby ( string name_, int value_, int number_, int which_ ) {
	name.assign ( name_ );
	value = value_;
	number = number_;
	which = which_;
}
void Hobby::addMyHobby ( string name_, int value_, int number_, int which_ ) {
	name.assign ( name_ );
	value = value_;
	number = number_;
	which = which_;
}
void Hobby::changeNumber ( int k ) {
	number += k;
}
void Hobby::showItself ( ) {
	cout << "名称：" << name << "\t编号：" << which << endl;
	cout << "价值：" << value << "\t数量：" << number << endl;

}
