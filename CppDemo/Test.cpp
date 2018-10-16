#include "stdafx.h"
#include <stdio.h>
#include <time.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void test1(stack<TreeNode*>& qq) {
	TreeNode a(1);
	TreeNode* b = &a;
	qq.push(b);
}
void test2(stack<TreeNode*>& qq) {
	TreeNode* b = new TreeNode(1);
	qq.push(b);
}
int main(int argc, char *argv[])
{
	//The traversing and inserting
	unordered_map<string, int> my_Map;
	my_Map.insert(map<string, int>::value_type("a", 1));
	my_Map.insert(pair<string, int>("b", 2));
	my_Map.insert(make_pair<string, int>("c", 3));
	my_Map.insert(make_pair<string, int>("d", 5));
	unordered_map<string, int>::iterator map_it;
	map_it = my_Map.begin();
	map_it->second = 10;
	my_Map["b"] = 11;
	my_Map.erase("d");
	map_it = my_Map.find("a");
	if (map_it == my_Map.end()) {
		cout << "not found" << endl;
	}
	if (!my_Map.count("a")) {
		cout << "not found" << endl;
	}
	for (unordered_map<string, int>::iterator my_Itr = my_Map.begin(); my_Itr != my_Map.end(); ++my_Itr) {
		cout << my_Itr->first << "\t" << my_Itr->second << endl;
	}

	for (auto i : my_Map) {
		cout << i.first << "\t" << i.second << endl;
	}
	for (map<string, int>::value_type i : my_Map) {
		cout << i.first << "\t" << i.second << endl;
	}
	for (pair<string, int> i : my_Map) {
		cout << i.first << "\t" << i.second << endl;
	}

	cout << my_Map.size() << endl;
	cout << my_Map.empty() << endl;
	my_Map.clear();

	// The initialization of value
	map<int, int> int_map;
	int_map[0]++;
	for (int i = 0; i < 10; i++) {
		cout << int_map[i] << endl;
	}

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

