#include "stdafx.h"
/*
Given an array A of non-negative integers, half of the integers in A are odd, and half of the integers are even.

Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is even, i is even.

You may return any answer array that satisfies this condition.



Example 1:

Input: [4,2,5,7]
Output: [4,5,2,7]
Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.


Note:

2 <= A.length <= 20000
A.length % 2 == 0
0 <= A[i] <= 1000
*/

// The same thought as problem905
class Solution {
public:
	vector<int> sortArrayByParityII(vector<int>& A) {
		for (int index = 1, i = 0; i < A.size(); i += 2) {
			if (A[i] % 2) {
				while (A[index] % 2) index += 2;
				swap(A[index], A[i]);
			}
		}
		return A;
	}
};