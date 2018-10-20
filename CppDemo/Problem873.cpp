#include "stdafx.h"
/*
A sequence X_1, X_2, ..., X_n is fibonacci-like if:

n >= 3
X_i + X_{i+1} = X_{i+2} for all i + 2 <= n
Given a strictly increasing array A of positive integers forming a sequence, find the length of the longest fibonacci-like subsequence of A.  If one does not exist, return 0.

(Recall that a subsequence is derived from another sequence A by deleting any number of elements (including none) from A, without changing the order of the remaining elements.  For example, [3, 5, 8] is a subsequence of [3, 4, 5, 6, 7, 8].)



Example 1:

Input: [1,2,3,4,5,6,7,8]
Output: 5
Explanation:
The longest subsequence that is fibonacci-like: [1,2,3,5,8].
Example 2:

Input: [1,3,7,11,12,14,18]
Output: 3
Explanation:
The longest subsequence that is fibonacci-like:
[1,11,12], [3,11,14] or [7,11,18].


Note:

3 <= A.length <= 1000
1 <= A[0] < A[1] < ... < A[A.length - 1] <= 10^9
(The time limit has been reduced by 50% for submissions in Java, C, and C++.)
*/
class Solution {
public:
	// My solution is same as method2, but it is TLE.
	int lenLongestFibSubseq1(vector<int>& A) {
		vector<vector<int>> dp(A.size(), vector<int>(A.size()));
		int res = 0;
		for (int i = A.size() - 2; i >= 0; i--) {
			for (int j = i - 1; j >= 0; j--) {
				for (int k = i + 1; k < A.size(); k++) {
					if (A[j] + A[i] == A[k]) {
						dp[j][i] = max(dp[j][i], 1 + dp[i][k]);
						break;
					}
				}
				res = max(res, dp[j][i]);
			}
		}
		return res > 0 ? res + 2 : 0;
	}

	// It is a boring solution.
	int lenLongestFibSubseq2(vector<int>& A) {
		int res = 0;
		unordered_set<int> s(A.begin(), A.end());
		for (int i = 0; i < A.size() - 2; i++) {
			for (int j = i + 1; j < A.size() - 1; j++) {
				int x = A[i], y = A[j], cur = 2;
				while (s.count(x + y)) {
					// int temp = y;
					// y += x;
					// x = temp;
					y += x;
					x = y - x;
					cur++;
				}
				res = max(res, cur);
			}
		}
		return res > 2 ? res : 0;
	}

	// It is a fantastic solution, but not work when the input num list is unordered.
	int lenLongestFibSubseq3(vector<int>& A) {
		vector<vector<int>> dp(A.size(), vector<int>(A.size()));
		int res = 0;
		for (int i = 3; i < A.size(); i++) {
			int x = 0, y = i - 1;
			while (x < y) {
				if (A[x] + A[y] > A[i]) {
					y--;
				}
				else if (A[x] + A[y] < A[i]) {
					x++;
				}
				else {
					dp[i][y] = dp[y][x] + 1;
					res = max(res, dp[i][y]);
					x++;
					y--;
				}
			}
		}
		return res > 0 ? res + 2 : 0;
	}
};

