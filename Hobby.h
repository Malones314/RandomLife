#ifndef HOBBY_H
#define HOBBY_H
#include<iostream>
#include<string>
using namespace std;
class Hobby{
public:
	Hobby ( );
	Hobby ( string name_, int value_, int number_, int which_ );
	int number;
	int which;
	string name;
	int value;
	void showItself ( );
	void addMyHobby ( string name_, int value_, int number_, int which_ );
	void changeNumber ( int k );
};
#endif
