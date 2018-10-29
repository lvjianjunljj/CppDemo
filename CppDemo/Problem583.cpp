#include "stdafx.h"
/*
Given two words word1 and word2, find the minimum number of steps required to make word1 and word2 the same, where in each step you can delete one character in either string.

Example 1:
Input: "sea", "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
Note:
The length of given words won't exceed 500.
Characters in given words can only be lower-case letters.
*/
class Solution {
public:
	// Very classic DP solution
	int minDistance1(string word1, string word2) {
		int m = word1.length(), n = word2.length();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1));
		for (int i = 1; i <= m; i++) dp[i][0] = i;
		for (int i = 1; i <= n; i++) dp[0][i] = i;
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (word1[i - 1] == word2[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1];
				}
				else {
					dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
				}
			}
		}
		return dp[m][n];
	}
	// We can reduce the space complexity to O(N)
	int minDistance2(string word1, string word2) {
		int m = word2.length();
		vector<int> prev(m + 1), cur(m + 1);
		for (int i = 1; i <= m; i++) prev[i] = i;
		for (int i = 0; i < word1.length(); i++) {
			cur[0] = i + 1;
			for (int j = 0; j < m; j++) {
				if (word1[i] == word2[j])
					cur[j + 1] = prev[j];
				else
					cur[j + 1] = min(cur[j], prev[j + 1]) + 1;
			}
			prev = cur;
		}
		return prev[m];
	}
};