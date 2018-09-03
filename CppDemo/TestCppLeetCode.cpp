#include "stdafx.h"

class Solution {
public:
	int uniqueMorseRepresentations(vector<string>& words) {
		string codeList[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
		unordered_set<string> codeSet;
		for (string word : words) {
			string code = "";
			for (char c : word) {
				code += codeList[c - 'a'];
			}
			codeSet.insert(code);
		}
		return codeSet.size();
	}
};

int main() {
	Solution s;
	vector<string> a({ "a","b","a","c" });
	cout << s.uniqueMorseRepresentations(a) << endl;
	system("pause");
	return 1;
}
