/*
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ¡Ü x, y < 231.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
	   ¡ü   ¡ü

The above arrows point to positions where the corresponding bits are different.
*/
class Solution {
public:
	// This is the achievement of unsigned right shift
	int hammingDistance(int x, int y) {
		unsigned int unx = (unsigned)x;
		unsigned int uny = (unsigned)y;
		int ans = 0;
		while (unx != 0 || uny != 0) {
			ans += ((unx % 2) + (uny % 2)) % 2;
			unx = unx >> 1;
			uny = uny >> 1;
		}
		return ans;
	}
	// make good use of bit manipulation
	int hammingDistance2(int x, int y) {
		int dist = 0, n = x ^ y;
		while (n) {
			++dist;
			n &= n - 1;
		}
		return dist;
	}
};