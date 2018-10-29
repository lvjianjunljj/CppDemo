#include "stdafx.h"
#include <stdio.h>
#include <time.h>
using namespace std;

int main(int argc, char *argv[])
{
	map<int, int, greater<int>> m;
	m[1] = 2;
	m[2] = 3;
	for (auto p : m)
		cout << p.first << p.second << endl;
	system("pause");
	return 0;
}