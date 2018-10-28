#include "stdafx.h"
#include <stdio.h>
#include <time.h>
using namespace std;
int main(int argc, char *argv[])
{
	set<pair<int, int>> s;
	s.insert(pair<int, int>(1, 2));
	s.insert(pair<int, int>(0, 12));
	for (auto p : s)
		cout << p.first << p.second << endl;
	system("pause");
	return 0;
}