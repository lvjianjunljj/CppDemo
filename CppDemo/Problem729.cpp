#include "stdafx.h"
/*
Implement a MyCalendar class to store your events. A new event can be added if adding the event will not cause a double booking.

Your class will have the method, book(int start, int end). Formally, this represents a booking on the half open interval [start, end), the range of real numbers x such that start <= x < end.

A double booking happens when two events have some non-empty intersection (ie., there is some time that is common to both events.)

For each call to the method MyCalendar.book, return true if the event can be added to the calendar successfully without causing a double booking. Otherwise, return false and do not add the event to the calendar.

Your class will be called like this: MyCalendar cal = new MyCalendar(); MyCalendar.book(start, end)
Example 1:
MyCalendar();
MyCalendar.book(10, 20); // returns true
MyCalendar.book(15, 25); // returns false
MyCalendar.book(20, 30); // returns true
Explanation:
The first event can be booked.  The second can't because time 15 is already booked by another event.
The third event can be booked, as the first event takes every time less than 20, but not including 20.
Note:

The number of calls to MyCalendar.book per test case will be at most 1000.
In calls to MyCalendar.book(start, end), start and end are integers in the range [0, 10^9].
*/
// The most boring solution with map.
class MyCalendar1 {
public:
	MyCalendar1() {

	}

	bool book(int start, int end) {
		if (m.count(start)) return false;
		for (pair<int, int> p : m) {
			if (p.first < start) {
				if (p.second > start) {
					return false;
				}
			}
			else {
				if (p.first < end) {
					return false;
				}
				break;
			}
		}
		m[start] = end;
		return true;
	}
private:
	map<int, int> m;
};
// Make the code more simple.
class MyCalendar2 {
public:
	MyCalendar2() {

	}

	bool book(int start, int end) {
		if (m.count(start)) return false;
		for (pair<int, int> p : m) {
			if (start >= p.second) continue;
			if (end <= p.first) break;
			return false;
		}
		m[start] = end;
		return true;
	}
private:
	map<int, int> m;
};
// The same thought with unordered_map.
class MyCalendar3 {
public:
	MyCalendar3() {

	}

	bool book(int start, int end) {
		if (m.count(start)) return false;
		for (pair<int, int> p : m) {
			if (start >= p.second || end <= p.first) continue;
			return false;
		}
		m[start] = end;
		return true;
	}
private:
	unordered_map<int, int> m;
};
// This is the most simple solution, and its time cost is not a little less than the former 
class MyCalendar4 {
public:
	bool book(int start, int end) {
		for (pair<int, int> p : pv) {
			if (max(p.first, start) < min(p.second, end)) return false;
		}
		pv.push_back(pair<int, int>(start, end));
		return true;
	}
private:
	vector<pair<int, int>> pv;
};
class MyCalendar5 {
public:
	MyCalendar5() {
		auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
			return a.second <= b.first;
		};
		s = set<pair<int, int>, bool(*)(const pair<int, int>&, const pair<int, int>&)>(cmp);
	}

	bool book(int start, int end) {
		if (s.count(pair<int, int>(start, end))) {
			return false;
		}
		else {
			s.insert(pair<int, int>(start, end));
			return true;
		}
	}
private:
	set<pair<int, int>, bool(*)(const pair<int, int>&, const pair<int, int>&)> s;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */

// It is a boring problem, but the function in the last solution is useful to me. 
// The similar problem is question731 and question732