#include "stdafx.h"
namespace TestCppMapSet {
	class TreeNode {
	public:
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int val) {
			this->val = val;
		}
		TreeNode() {
			this->val = 0;
		}
	};
	class TrieNode {
	public:
		vector<TrieNode*> children;
		bool end;
		TrieNode() {
			children = *(new vector<TrieNode*>(26));
		}
	};
	int main_MapSet() {
		map<string, int> my_Map;
		my_Map.insert(map<string, int>::value_type("a", 1));
		my_Map.insert(pair<string, int>("b", 2));
		my_Map.insert(make_pair<string, int>("c", 3));
		my_Map.insert(make_pair<string, int>("d", 5));
		map<string, int>::iterator map_it;
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
		for (map<string, int>::iterator my_Itr = my_Map.begin(); my_Itr != my_Map.end(); ++my_Itr) {
			cout << my_Itr->first << "\t" << my_Itr->second << endl;
		}
		
		for (auto i : my_Map) {
			cout << i.first << "\t" << i.second << endl;
		}
		for (map<string, int>::value_type i : my_Map) {
			cout << i.first << "\t" << i.second << endl;
		}

		cout << my_Map.size() << endl;
		cout << my_Map.empty() << endl;
		my_Map.clear();

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
		TrieNode *root = new TrieNode();
		TrieNode a = *root;
		system("pause");
		return 0;
	}
}
