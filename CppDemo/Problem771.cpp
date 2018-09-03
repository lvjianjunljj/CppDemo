#include "stdafx.h"
/*
You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:

Input: J = "aA", S = "aAAbbbb"
Output: 3
Example 2:

Input: J = "z", S = "ZZ"
Output: 0
Note:

S and J will consist of letters and have length at most 50.
The characters in J are distinct.
*/
class Solution {
public:
	int numJewelsInStones(string J, string S) {
		set<char> c_set;
		set<char>::iterator ite;
		int ans = 0;
		for (int i = 0; i < J.length(); i++) {
			c_set.insert(J[i]);
		}
		for (int i = 0; i < S.length(); i++) {
			ite = c_set.find(S[i]);
			if (ite != c_set.end()) {
				ans++;
			}
		}
		return ans;

	}
	// The very simple answer
	int numJewelsInStones2(string J, string S) {
		int res = 0;
		unordered_set<char> setJ(J.begin(), J.end());
		for (char s : S) if (setJ.count(s)) res++;
		return res;
	}
};