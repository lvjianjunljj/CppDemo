#include "stdafx.h"
/*
In a deck of cards, each card has an integer written on it.

Return true if and only if you can choose X >= 2 such that it is possible to split the entire deck into 1 or more groups of cards, where:

Each group has exactly X cards.
All the cards in each group have the same integer.


Example 1:

Input: [1,2,3,4,4,3,2,1]
Output: true
Explanation: Possible partition [1,1],[2,2],[3,3],[4,4]
Example 2:

Input: [1,1,1,2,2,2,3,3]
Output: false
Explanation: No possible partition.
Example 3:

Input: [1]
Output: false
Explanation: No possible partition.
Example 4:

Input: [1,1]
Output: true
Explanation: Possible partition [1,1]
Example 5:

Input: [1,1,2,2,2,2]
Output: true
Explanation: Possible partition [1,1],[2,2],[2,2]

Note:

1 <= deck.length <= 10000
0 <= deck[i] < 10000
*/
class Solution {
public:
	// My method seems like cumbersome but is as fast as the second method 
	bool hasGroupsSizeX1(vector<int>& deck) {
		map<int, int> m;
		for (int i : deck) {
			if (!m.count(i)) {
				m[i] = 0;
			}
			m[i]++;
		}
		vector<int> times;
		int size = 0;
		for (map<int, int>::iterator itr = m.begin(); itr != m.end(); itr++) {
			times.push_back(itr->second);
			size = max(size, itr->second);
		}
		for (int i = 2; i <= size; i++) {
			bool success = true;
			for (int k : times) {
				if (k % i > 0) {
					success = false;
					break;
				}
			}
			if (success) {
				return true;
			}
		}
		return false;
	}
	// It is very simple with the gcd(greatest common divisor).
	bool hasGroupsSizeX2(vector<int>& deck) {
		unordered_map<int, int> count;
		int res = 0;
		for (int i : deck) count[i]++;
		// I do not find the lib for __gcd.
		//for (auto i : count) res = __gcd(i.second, res);
		for (auto i : count) res = gcd(i.second, res);
		return res > 1;
	}
private:
	int gcd(int a, int b)
	{
		if (b == 0) return a;
		a %= b;
		return gcd(b, a);
	}
};