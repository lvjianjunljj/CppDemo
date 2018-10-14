#include "stdafx.h"
/*
Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all possible strings we could create.

Examples:
Input: S = "a1b2"
Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

Input: S = "3z4"
Output: ["3z4", "3Z4"]

Input: S = "12345"
Output: ["12345"]
Note:

S will be a string with length between 1 and 12.
S will consist only of letters or digits.
*/
class Solution {
public:
	vector<string> letterCasePermutation1(string S) {
		const char* cha_list = S.data();
		vector<string> ans;
		dfs(ans, cha_list, 0, "");
		return ans;
	}
	vector<string> letterCasePermutation2(string S) {
		vector<string> res;
		backtrack(S, 0, res);
		return res;
	}
private:
	void dfs(vector<string>& ans, const char* cha_list, int index, string path) {
		if (*(cha_list + index)) {
			if ((int)(*(cha_list + index)) > 96 && (int)(*(cha_list + index)) < 123) {
				dfs(ans, cha_list, index + 1, path + (char)((int)(*(cha_list + index)) - 32));
			}
			else if ((int)(*(cha_list + index)) > 64 && (int)(*(cha_list + index)) < 91) {
				dfs(ans, cha_list, index + 1, path + (char)((int)(*(cha_list + index)) + 32));
			}
			dfs(ans, cha_list, index + 1, path + *(cha_list + index));
		}
		else {
			ans.push_back(path);
		}
	}
	// pay attention to the function "isalpha" and the operation of string.
	void backtrack(string &s, int i, vector<string> &res) {
		if (i == s.size()) {
			res.push_back(s);
			return;
		}
		backtrack(s, i + 1, res);
		if (isalpha(s[i])) {
			s[i] ^= (1 << 5);
			backtrack(s, i + 1, res);
		}
	}
};
