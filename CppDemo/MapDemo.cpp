#include "stdafx.h"
struct pair_hash {
	template <class T1, class T2>
	std::size_t operator () (const std::pair<T1, T2> &p) const {
		auto h1 = std::hash<T1>{}(p.first);
		auto h2 = std::hash<T2>{}(p.second);

		// Mainly for demonstration purposes, i.e. works but is overly simple
		// In the real world, use sth. like boost.hash_combine
		return h1 ^ h2;
	}
};
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

	/*
	If you want to create an unordered_map to map pairs with integers.
	You need to provide a suitable hash function for your key type.
	This line:
		unordered_map<pair<int, int>, int> unmap;
	will have compile error:
	'std::hash<_Kty>::hash(const std::hash<_Kty> &)': attempting to reference a deleted function
	*/
	unordered_map<pair<int, int>, int, pair_hash> unmap;
	system("pause");
	return 0;
}

/*
	The map template defines the third parameter, which is our collation.
	The default is to try std::less<>, sorting the keys instead of value.
	If we want to sort the key (string) case insensitive, we can write it like this.
	It is just like the collation in PriorityQueueDemo.cpp
	Its default collation is greater, from less to bigger.
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

/*
summary:
unordered_map is just like HashMap in java, and map is just like TreeMap in java.
*/
