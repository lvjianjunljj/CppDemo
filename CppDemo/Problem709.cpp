#include "stdafx.h"
/*
Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.



Example 1:

Input: "Hello"
Output: "hello"
Example 2:

Input: "here"
Output: "here"
Example 3:

Input: "LOVELY"
Output: "lovely"
*/
class Solution {
public:
	string toLowerCase(string str) {
		string ans = "";
		for (char c : str) {
			if (c >= 'A' && c <= 'Z') {
				ans += char(c - 'A' + 'a');
			}
			else {
				ans += c;
			}
		}
		return ans;
	}
	// make good use of index in string
	string toLowerCase1(string str) {
		for (int i = 0; i < str.length(); i++) {
			if (str[i] <= 'Z' && str[i] >= 'A') {
				str[i] += 32;
			}
		}
		return str;
	}
	// make good use of pointer in string
	string toLowerCase2(string str) {
		for (char & c : str)
			if (c <= 'Z' && c >= 'A')
				c += 32;
		return str;
	}
};