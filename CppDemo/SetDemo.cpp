#include "stdafx.h"
int main_set() {
	//The traversing and inserting of set
	set<int> my_Set;
	my_Set.insert(1);
	my_Set.insert(1);
	my_Set.insert(2);
	my_Set.insert(3);
	set<int>::iterator ite;
	ite = my_Set.find(1);
	if (ite == my_Set.end())
		cout << "no found" << endl;
	else
		cout << "found" << endl;

	ite = my_Set.find(2);
	if (ite == my_Set.end())
		cout << "no found" << endl;
	else
		cout << "found" << endl;

	my_Set.erase(3);
	if (my_Set.count(3) != 0)
		cout << "no found" << endl;
	else
		cout << "found" << endl;
	for (ite = my_Set.begin(); ite != my_Set.end(); ite++)
	{
		cout << *ite << endl;
	}
	system("pause");
	return 0;
}