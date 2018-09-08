#include "stdafx.h"
/*
X is a good number if after rotating each digit individually by 180 degrees, we get a valid number that is different from X.  Each digit must be rotated - we cannot choose to leave it alone.

A number is valid if each digit remains a digit after rotation. 0, 1, and 8 rotate to themselves; 2 and 5 rotate to each other; 6 and 9 rotate to each other, and the rest of the numbers do not rotate to any other number and become invalid.

Now given a positive number N, how many numbers X from 1 to N are good?

Example:
Input: 10
Output: 4
Explanation:
There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
Note that 1 and 10 are not good numbers, since they remain unchanged after rotating.
Note:

N  will be in range [1, 10000].
*/
class Solution {
public:
	int rotatedDigits(int N) {
		int ans = 0;
		for (int k = 1; k <= N; k++) {
			int i = k;
			bool have = false, conform = true;
			while (i > 0) {
				int cur = i % 10;
				if (cur == 2 || cur == 5 || cur == 6 || cur == 9) {
					have = true;
				}
				else if (cur == 3 || cur == 4 || cur == 7) {
					conform = false;
					break;
				}
				i = i / 10;
			}
			if (have && conform) {
				ans++;
			}
		}
		return ans;
	}
};