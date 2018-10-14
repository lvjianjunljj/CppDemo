#include "stdafx.h"
/*
Given an array A of integers, for each integer A[i] we may choose any x with -K <= x <= K, and add x to A[i].

After this process, we have some array B.

Return the smallest possible difference between the maximum value of B and the minimum value of B.



Example 1:

Input: A = [1], K = 0
Output: 0
Explanation: B = [1]
Example 2:

Input: A = [0,10], K = 2
Output: 6
Explanation: B = [2,8]
Example 3:

Input: A = [1,3,6], K = 3
Output: 0
Explanation: B = [3,3,3] or B = [4,4,4]


Note:

1 <= A.length <= 10000
0 <= A[i] <= 10000
0 <= K <= 10000
*/
// It is an easy problem
class Solution {
public:
	int smallestRangeI(vector<int>& A, int K) {
		int min_val = INT_MAX, max_val = INT_MIN;
		for (int i : A) {
			if (min_val > i) min_val = i;
			if (max_val < i) max_val = i;
		}
		int dif = max_val - min_val - K * 2;
		return dif > 0 ? dif : 0;
	}
};
// The similar problem is question910 and question632
