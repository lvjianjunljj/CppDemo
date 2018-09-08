#include "stdafx.h"
void main_TypeConvert()
{
	//int --> string
	int i = 5;
	string s = to_string(i);
	cout << s << endl;
	//double --> string
	double d = 3.14;
	cout << to_string(d) << endl;
	//long --> string
	long l = 123234567;
	cout << to_string(l) << endl;
	//char --> string
	char c = 'a';
	cout << to_string(c) << endl; 
	//char --> string
	string cStr; cStr += c;
	cout << cStr << endl;


	s = "123.257";
	//string --> int;
	cout << stoi(s) << endl;
	//string --> int
	cout << stol(s) << endl;
	//string --> float
	cout << stof(s) << endl;
	//string --> doubel
	cout << stod(s) << endl;
}