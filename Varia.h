#include<iostream>
#include<string>
#ifndef VARIA_H
#define VARIA_H
using namespace std;
class Varia { 
public:
	int number;
	int which;
	string name;
	int value;
	Varia ( );
	Varia ( string name_, int value, int number_, int which_ );
	void addMyVaria ( string name_, int value, int number_, int which_ );
	void changeNumber ( int k );
	void showItself ( );
};
#endif 
