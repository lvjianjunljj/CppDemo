#include "stdafx.h"
/*
You have a list of points in the plane. Return the area of the largest triangle that can be formed by any 3 of the points.

Example:
Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
Output: 2
Explanation:
The five points are show in the figure below. The red triangle is the largest.


Notes:

3 <= points.length <= 50.
No points will be duplicated.
 -50 <= points[i][j] <= 50.
Answers within 10^-6 of the true value will be accepted as correct.
*/
class Solution {
public:
	// you should know the method to calculate the area with the coordinate of three point 
	double largestTriangleArea(vector<vector<int>>& points) {
		int n = points.size();
		double ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				for (int k = j + 1; k < n; k++) {
					ans = max(ans, abs(points[i][0] * points[j][1] +
						points[j][0] * points[k][1] +
						points[k][0] * points[i][1] -
						points[i][0] * points[k][1] -
						points[j][0] * points[i][1] -
						points[k][0] * points[j][1]) / 2.0);
				}
			}
		}
		return ans;
	}
};