#include "stdafx.h"
/*
On the first row, we write a 0. Now in every subsequent row, we look at the previous row and replace each occurrence of 0 with 01, and each occurrence of 1 with 10.

Given row N and index K, return the K-th indexed symbol in row N. (The values of K are 1-indexed.) (1 indexed).

Examples:
Input: N = 1, K = 1
Output: 0

Input: N = 2, K = 1
Output: 0

Input: N = 2, K = 2
Output: 1

Input: N = 4, K = 5
Output: 1

Explanation:
row 1: 0
row 2: 01
row 3: 0110
row 4: 01101001
Note:

N will be an integer in the range [1, 30].
K will be an integer in the range [1, 2^(N-1)].
*/
class Solution {
public:
	// The most boring thought, and MLE
	int kthGrammar1(int N, int K) {
		string str = "0";
		for (int i = 0; i < N; i++) {
			string temp = "";
			for (int i = 0; i < str.length(); i++) {
				if (str[i] == '0') {
					temp += "01";
				}
				else {
					temp += "10";
				}
			}
			str = temp;
		}
		return str[K - 1] - '0';
	}
	// Using recursion is the right thought.
	int kthGrammar2(int N, int K) {
		if (N == 0) return 0;
		int prev = kthGrammar2(N - 1, (K + 1) / 2);
		if (K % 2 == 0) {
			if (prev == 0) {
				return 1;
			}
			else {
				return 0;
			}
		}
		else {
			if (prev == 0) {
				return 0;
			}
			else {
				return 1;
			}
		}
		return kthGrammar2(N - 1, (K + 1) / 2) == (K % 2);
	}
	// We can simplify the code very beautifully
	int kthGrammar3(int N, int K) {
		if (N == 0) return 0;
		return kthGrammar3(N - 1, (K + 1) / 2) == (K % 2);
	}
};
