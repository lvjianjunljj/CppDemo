#include "stdafx.h"
namespace TestCppMapSet {
	int main_unordered_map_set() {
		//The traversing and inserting of map
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

	/*
		The map template defines the third parameter, which is our collation.
		The default is to try std::less<>, sorting the keys instead of value.
		If we want to sort the key (string) case insensitive, we can write it like this.
		It is just like the collation in PriorityQueueDemo.cpp 
	*/

	// Provide custom collation
	struct CCaseInsensitive {
		bool operator() (const string& str1, const string& str2) const {
			string str1NoCase(str1);
			string str2NoCase(str2);
			transform(str1.begin(), str1.end(), str1NoCase.begin(), tolower);
			transform(str2.begin(), str2.end(), str2NoCase.begin(), tolower);
			return str1NoCase < str2NoCase;
		}
	};

	//Define StrMapNoCase
	typedef map<string, string, CCaseInsensitive> StrMapNoCase;
	typedef StrMapNoCase::value_type MapValue;
	typedef map<string, string> StrMap;


	int main_map() {
		StrMapNoCase map1;
		map1.insert(MapValue("John", "5214563"));
		map1.insert(MapValue("tom", "5214563"));
		map1.insert(MapValue("LiYang", "98874745"));
		map1.insert(MapValue("ABC", "98874745"));

		StrMap map2;
		map2.insert(MapValue("John", "5214563"));
		map2.insert(MapValue("tom", "5214563"));
		map2.insert(MapValue("LiYang", "98874745"));
		map2.insert(MapValue("ABC", "98874745"));

		StrMapNoCase::iterator iter1 = map1.find("abc");
		if (iter1 != map1.end())
			cout << (*iter1).first << endl;


		StrMap::iterator iter2 = map2.find("abc");
		if (iter2 != map2.end())
			cout << (*iter2).first << endl;
		else
			cout << "There is not \"abc\" in map2" << endl;

		system("pause");
		return 0;
	}
	/*
	output:
	ABC
	There is not "abc" in map2
	*/
}
