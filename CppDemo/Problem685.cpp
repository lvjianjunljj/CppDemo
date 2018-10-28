#include "stdafx.h"
/*
In this problem, a rooted tree is a directed graph such that, there is exactly one node (the root) for which all other nodes are descendants of this node, plus every node has exactly one parent, except for the root node which has no parents.

The given input is a directed graph that started as a rooted tree with N nodes (with distinct values 1, 2, ..., N), with one additional directed edge added. The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] that represents a directed edge connecting nodes u and v, where u is a parent of child v.

Return an edge that can be removed so that the resulting graph is a rooted tree of N nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array.

Example 1:
Input: [[1,2], [1,3], [2,3]]
Output: [2,3]
Explanation: The given directed graph will be like this:
  1
 / \
v   v
2-->3
Example 2:
Input: [[1,2], [2,3], [3,4], [4,1], [1,5]]
Output: [4,1]
Explanation: The given directed graph will be like this:
5 <- 1 -> 2
	 ^    |
	 |    v
	 4 <- 3
Note:
The size of the input 2D-array will be between 3 and 1000.
Every integer represented in the 2D-array will be between 1 and N, where N is the size of the input array.
*/
class Solution {
public:
	// I can solve this problem based on the thought of problem684, but the solution is not fancy.
	vector<int> findRedundantDirectedConnection1(vector<vector<int>>& edges) {
		int repeat_point = 0;
		set<int> points;
		for (vector<int> edge : edges) {
			if (points.count(edge[1]))
				repeat_point = edge[1];
			points.insert(edge[1]);
		}
		vector<int> uni(edges.size());
		for (int i = 0; i < uni.size(); i++) uni[i] = i;
		for (vector<int> edge : edges) {
			if (edge[1] == repeat_point) continue;
			int index1 = edge[0] - 1;
			int index2 = edge[1] - 1;
			while (index1 != uni[index1]) index1 = uni[index1];
			while (index2 != uni[index2]) index2 = uni[index2];
			if (index1 == index2) return edge;
			uni[index1] = index2;
		}
		for (vector<int> edge : edges) {
			if (edge[1] == repeat_point) {
				int index1 = edge[0] - 1;
				int index2 = edge[1] - 1;
				while (index1 != uni[index1]) index1 = uni[index1];
				while (index2 != uni[index2]) index2 = uni[index2];
				if (index1 == index2) return edge;
				uni[index1] = index2;
			}
		}
		return edges[0];
	}
	// This solution is not very simple, and its thought is the same as my solution.
	vector<int> findRedundantDirectedConnection2(vector<vector<int>>& edges) {
		int n = edges.size();
		vector<int> parent(n + 1, 0), candA, candB;
		// step 1, check whether there is a node with two parents
		for (auto &edge : edges) {
			if (parent[edge[1]] == 0)
				parent[edge[1]] = edge[0];
			else {
				candA = { parent[edge[1]], edge[1] };
				candB = edge;
				edge[1] = 0;
			}
		}
		// step 2, union find
		for (int i = 1; i <= n; i++) parent[i] = i;
		for (auto &edge : edges) {
			if (edge[1] == 0) continue;
			int u = edge[0], v = edge[1], pu = root(parent, u);
			// Now every node only has 1 parent, so root of v is implicitly v
			if (pu == v) {
				if (candA.empty()) return edge;
				return candA;
			}
			parent[v] = pu;
		}
		return candB;
	}
private:
	int root(vector<int>& parent, int k) {
		if (parent[k] != k)
			parent[k] = root(parent, parent[k]);
		return parent[k];
	}
};

// The similar problem is question729 and question684