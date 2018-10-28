#include "stdafx.h"
/*
In this problem, a tree is an undirected graph that is connected and has no cycles.

The given input is a graph that started as a tree with N nodes (with distinct values 1, 2, ..., N), with one additional edge added. The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] with u < v, that represents an undirected edge connecting nodes u and v.

Return an edge that can be removed so that the resulting graph is a tree of N nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array. The answer edge [u, v] should be in the same format, with u < v.

Example 1:
Input: [[1,2], [1,3], [2,3]]
Output: [2,3]
Explanation: The given undirected graph will be like this:
  1
 / \
2 - 3
Example 2:
Input: [[1,2], [2,3], [3,4], [1,4], [1,5]]
Output: [1,4]
Explanation: The given undirected graph will be like this:
5 - 1 - 2
	|   |
	4 - 3
Note:
The size of the input 2D-array will be between 3 and 1000.
Every integer represented in the 2D-array will be between 1 and N, where N is the size of the input array.
*/
class Solution {
public:
	// My solution is a little hard to understand, but it also works.
	vector<int> findRedundantConnection1(vector<vector<int>>& edges) {
		vector<int> uni(edges.size(), -1);
		for (vector<int> edge : edges) {
			int index = edge[0] - 1;
			while (index != edge[1] - 1 && uni[index] >= 0)
				index = uni[index];
			if (index == (edge[1] - 1)) return edge;
			uni[index] = edge[1] - 1;
			index = uni[uni[index]];
			while (index != edge[1] - 1 && index >= 0)
				index = uni[index];
			if (index == (edge[1] - 1)) return edge;
		}
		return edges[0];
	}
	// The most simple solution, the thought is the same as my solution.
	vector<int> findRedundantConnection2(vector<vector<int>>& edges) {
		vector<int> uni(edges.size());
		// Pay attention to this step.
		for (int i = 0; i < uni.size(); i++) uni[i] = i;
		for (vector<int> edge : edges) {
			int index1 = edge[0] - 1;
			int index2 = edge[1] - 1;
			while (index1 != uni[index1]) index1 = uni[index1];
			while (index2 != uni[index2]) index2 = uni[index2];
			if (index1 == index2) return edge;
			uni[index1] = index2;
		}
		return edges[0];
	}
};

// The similar problem is question729 and question685