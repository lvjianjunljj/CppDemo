#include "stdafx.h"
/*
There are N network nodes, labelled 1 to N.

Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.

Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal? If it is impossible, return -1.

Note:
N will be in the range [1, 100].
K will be in the range [1, N].
The length of times will be in the range [1, 6000].
All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 1 <= w <= 100.
*/
class Solution {
public:
	// Breadth-first search, the maximum depth is N. It is not fast but simple.
	int networkDelayTime1(vector<vector<int>>& times, int N, int K) {
		vector<int> dist(N + 1, INT_MAX);
		dist[K] = 0;
		for (int i = 0; i < N; i++) {
			for (vector<int> e : times) {
				int u = e[0], v = e[1], w = e[2];
				if (dist[u] != INT_MAX && dist[v] > dist[u] + w) {
					dist[v] = dist[u] + w;
				}
			}
		}

		int maxwait = 0;
		for (int i = 1; i <= N; i++)
			maxwait = max(maxwait, dist[i]);
		return maxwait == INT_MAX ? -1 : maxwait;
	}

	// The most fast Dijkstra's algorithm.
	typedef pair<int, int> pii;
	int networkDelayTime2(vector<vector<int>>& times, int n, int k) {
		// I do not know why this line can run in LeetCode.
		//vector<pii> g[n + 1];
		vector<vector<pii>> g(n + 1, vector<pii>());
		for (const auto& t : times) {
			g[t[0]].push_back(make_pair(t[1], t[2]));
		}
		const int inf = 1e9;
		vector<int> dist(n + 1, inf);
		dist[k] = 0;
		priority_queue<pii, vector<pii>, greater<pii> > pq;
		pq.push(make_pair(0, k));
		int u, v, w;
		while (!pq.empty()) {
			pii p = pq.top(); pq.pop();
			u = p.second;
			for (auto& to : g[u]) {
				v = to.first, w = to.second;
				if (dist[v] > dist[u] + w) {
					dist[v] = dist[u] + w;
					pq.push(make_pair(dist[v], v));
				}
			}
		}
		int ans = *max_element(dist.begin() + 1, dist.end());
		return ans == inf ? -1 : ans;
	}
	// My iteration function, there is a little different from function networkDelayTime2
	int networkDelayTime22(vector<vector<int>>& times, int N, int K) {
		typedef pair<int, int> pii;
		vector<vector<pii>> timesVec(N, vector<pii>());
		for (vector<int> time : times) {
			timesVec[time[0] - 1].push_back(pii(time[1], time[2]));
		}
		int res = 0;
		vector<int> resVec(N, INT_MAX);
		resVec[K - 1] = 0;
		priority_queue<pii, vector<pii>, greater<pii>> pq;
		pq.push(pii(K, 0));
		while (!pq.empty()) {
			pii cur = pq.top();
			pq.pop();
			for (pii nextNode : timesVec[cur.first - 1]) {
				if (resVec[nextNode.first - 1] > cur.second + nextNode.second) {
					resVec[nextNode.first - 1] = cur.second + nextNode.second;
					pq.push(pii(nextNode.first, cur.second + nextNode.second));
				}
			}
		}
		for (int time : resVec) {
			res = max(res, time);
		}
		return res == INT_MAX ? -1 : res;
	}

	// Actually I do not know why my function is TLE
	// It tells me that do not use recursive when you can use iteration
	int networkDelayTime3(vector<vector<int>>& times, int N, int K) {
		map<int, map<int, int>> m;
		for (vector<int> time : times) {
			if (!m.count(time[0])) {
				m[time[0]] = map<int, int>();
			}
			if (!m[time[0]][time[1]] || m[time[0]][time[1]] >= time[2]) {
				m[time[0]][time[1]] = time[2];
			}
		}
		vector<int> timesVec(N, -1);
		dfs(K, timesVec, m);
		int res = 0;
		for (int i = 0; i < N; i++) {
			if (timesVec[i] < 0) {
				return -1;
			}
			res = max(res, timesVec[i]);
		}
		return res;
	}
private:
	void dfs(int K, vector<int>& timesVec, map<int, map<int, int>>& m, int curDis = 0) {
		if (timesVec[K - 1] >= 0 && timesVec[K - 1] <= curDis) {
			return;
		}
		timesVec[K - 1] = curDis;
		map<int, int> neighbor = m[K];
		for (map<int, int>::iterator itr = neighbor.begin(); itr != neighbor.end(); ++itr) {
			dfs(itr->first, timesVec, m, itr->second + curDis);
		}

	}
};