#include "stdafx.h"
/*
Given a string S, return the "reversed" string where all characters that are not a letter stay in the same place, and all letters reverse their positions.



Example 1:

Input: "ab-cd"
Output: "dc-ba"
Example 2:

Input: "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"
Example 3:

Input: "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"


Note:

S.length <= 100
33 <= S[i].ASCIIcode <= 122
S doesn't contain \ or "
*/
class Solution {
public:
	// The standard solution based on two pointer.
	string reverseOnlyLetters1(string S) {
		int start = 0, end = S.length() - 1;
		while (start < end) {
			while (start < end && !isLetter(S[start])) start++;
			while (start < end && !isLetter(S[end])) end--;
			if (start < end) {
				swap(S[start], S[end]);
				start++;
				end--;
			}
		}
		return S;
	}
	// More simple solution with the same thought.
	string reverseOnlyLetters2(string S) {
		for (int i = 0, j = S.length() - 1; i < j; i++, j--) {
			while (i < j && !isalpha(S[i])) i++;
			while (i < j && !isalpha(S[j])) j--;
			swap(S[i], S[j]);
		}
		return S;
	}
private:
	bool isLetter(const char chr) {
		return (chr >= 'a' && chr <= 'z') || (chr >= 'A' && chr <= 'Z');
	}
};