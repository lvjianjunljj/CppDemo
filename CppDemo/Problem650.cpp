#include "stdafx.h"
/*
Initially on a notepad only one character 'A' is present. You can perform two operations on this notepad for each step:

Copy All: You can copy all the characters present on the notepad (partial copy is not allowed).
Paste: You can paste the characters which are copied last time.
Given a number n. You have to get exactly n 'A' on the notepad by performing the minimum number of steps permitted. Output the minimum number of steps to get n 'A'.

Example 1:
Input: 3
Output: 3
Explanation:
Intitally, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Paste operation to get 'AAA'.
Note:
The n will be in the range [1, 1000].
*/
class Solution {
public:
	// initial thought, kind of hard, but it is the same as minSteps2
	int minSteps(int n) {
		int factor = getMinFactor(n);
		int ans = 0;
		if (n > 1) {
			while (factor < n) {
				ans += factor;
				n = n / factor;
				factor = getMinFactor(n);
			}
			ans += factor;
		}
		return ans;
	}
	// The most succinct way
	int minSteps2(int n) {
		if (n == 1) {
			return 0;
		}
		for (int i = 2; i < sqrt(n) + 1; i++) {
			if (n % i == 0) {
				return i + minSteps(n / i);
			}
		}
		return n;
	}
	// The dynamic programming method, it is just using the vector
	int minSteps3(int n) {
		vector<int> dp(n);
		for (int i = 1; i < n; i++) {
			dp[i] = i + 1;
			for (int j = i - 1; j > -1; j--) {
				if ((i + 1) % (j + 1) == 0) {
					dp[i] = dp[j] + (i + 1) / (j + 1);
					break;
				}
			}
		}
		return dp[n - 1];
	}
private:
	int getMinFactor(int n) {
		for (int i = 2; i < sqrt(n) + 1; i++) {
			if (n % i == 0) {
				return i;
			}
		}
		return n;
	}
};