#include "stdafx.h"
/*
We partition a row of numbers A into at most K adjacent (non-empty) groups, then our score is the sum of the average of each group. What is the largest score we can achieve?

Note that our partition must use every number in A, and that scores are not necessarily integers.

Example:
Input:
A = [9,1,2,3,9]
K = 3
Output: 20
Explanation:
The best choice is to partition A into [9], [1, 2, 3], [9]. The answer is 9 + (1 + 2 + 3) / 3 + 9 = 20.
We could have also partitioned A into [9, 1], [2], [3, 9], for example.
That partition would lead to a score of 5 + 2 + 6 = 13, which is worse.


Note:

1 <= A.length <= 100.
1 <= A[i] <= 10000.
1 <= K <= A.length.
Answers within 10^-6 of the correct answer will be accepted as correct.
*/
class Solution {
public:
	double largestSumOfAverages(vector<int>& A, int K) {
		vector<vector<double>> dp(A.size(), vector<double>(K, 0));
		double sum = 0;
		for (int i = 0; i < A.size(); i++) {
			sum += A[i];
			dp[i][0] = sum / (i + 1);
		}
		for (int j = 1; j < K; j++) {
			for (int i = j; i < A.size(); i++) {
				sum = 0;
				for (int x = i; x >= j; x--) {
					sum += A[x];
					dp[i][j] = max(dp[i][j], dp[x - 1][j - 1] + sum / (i + 1 - x));
				}
			}
		}
		return dp[A.size() - 1][K - 1];
	}
};
// At first I think the solution of this problem is very fantastic, maybe greedy or others.
// But finally the standard solution is just like this: the most boring DP without any fantastic thought.