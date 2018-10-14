#include "stdafx.h"
/*
Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
Note:

1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.
Follow up:

Can you solve it in O(N) time and O(1) space?
*/
class Solution {
public:
	// The corrent thought is from the back to the front
	bool backspaceCompare(string S, string T) {
		int backspaceS = 0, backspaceT = 0, indexS = S.length() - 1, indexT = T.length() - 1;
		while (indexS >= 0 || indexT >= 0) {
			while (indexS >= 0 && (backspaceS > 0 || S[indexS] == '#')) {
				if (S[indexS--] == '#') {
					backspaceS++;
				}
				else {
					backspaceS--;
				}
			}
			while (indexT >= 0 && (backspaceT > 0 || T[indexT] == '#')) {
				if (T[indexT--] == '#') {
					backspaceT++;
				}
				else {
					backspaceT--;
				}
			}
			if (indexS < 0 && indexT < 0) {
				return true;
			}
			else if (indexS < 0 || indexT < 0) {
				return false;
			}
			else if (S[indexS] != T[indexT]) {
				return false;
			}
			indexS--;
			indexT--;
		}
		return true;
	}
	// It is so simple
	bool backspaceCompare2(string S, string T) {
		for (int i = S.length() - 1, j = T.length() - 1;; i--, j--) {
			for (int b = 0; i >= 0 && (b || S[i] == '#'); --i) b += S[i] == '#' ? 1 : -1;
			for (int b = 0; j >= 0 && (b || T[j] == '#'); --j) b += T[j] == '#' ? 1 : -1;
			if (i < 0 || j < 0 || S[i] != T[j]) return i == -1 && j == -1;
		}
	}
};