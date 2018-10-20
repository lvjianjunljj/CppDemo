#include "stdafx.h"
/*
Implement a MyCalendarTwo class to store your events. A new event can be added if adding the event will not cause a triple booking.

Your class will have one method, book(int start, int end). Formally, this represents a booking on the half open interval [start, end), the range of real numbers x such that start <= x < end.

A triple booking happens when three events have some non-empty intersection (ie., there is some time that is common to all 3 events.)

For each call to the method MyCalendar.book, return true if the event can be added to the calendar successfully without causing a triple booking. Otherwise, return false and do not add the event to the calendar.

Your class will be called like this: MyCalendar cal = new MyCalendar(); MyCalendar.book(start, end)
Example 1:
MyCalendar();
MyCalendar.book(10, 20); // returns true
MyCalendar.book(50, 60); // returns true
MyCalendar.book(10, 40); // returns true
MyCalendar.book(5, 15); // returns false
MyCalendar.book(5, 10); // returns true
MyCalendar.book(25, 55); // returns true
Explanation:
The first two events can be booked.  The third event can be double booked.
The fourth event (5, 15) can't be booked, because it would result in a triple booking.
The fifth event (5, 10) can be booked, as it does not use time 10 which is already double booked.
The sixth event (25, 55) can be booked, as the time in [25, 40) will be double booked with the third event;
the time [40, 50) will be single booked, and the time [50, 55) will be double booked with the second event.
Note:

The number of calls to MyCalendar.book per test case will be at most 1000.
In calls to MyCalendar.book(start, end), start and end are integers in the range [0, 10^9].
*/

// The same thought as the first three solution of problem729.
class MyCalendarTwo1 {
public:
	MyCalendarTwo1() {

	}

	bool book(int start, int end) {
		for (pair<int, int> p : rep) {
			if (p.first >= end || p.second <= start) continue;
			return false;
		}
		for (pair<int, int> p : sou) {
			if (p.first >= end || p.second <= start) continue;
			rep[max(p.first, start)] = min(p.second, end);
		}
		sou[start] = max(sou[start], end);
		return true;
	}
private:
	unordered_map<int, int> sou;
	unordered_map<int, int> rep;
};
class MyCalendarTwo2 {
public:
	MyCalendarTwo2() {

	}

	bool book(int start, int end) {
		for (pair<int, int> p : rep) {
			if (p.second <= start) continue;
			if (p.first >= end) break;
			return false;
		}
		for (pair<int, int> p : sou) {
			if (p.second <= start) continue;
			if (p.first >= end) break;
			rep[max(p.first, start)] = min(p.second, end);
		}
		sou[start] = max(sou[start], end);
		return true;
	}
private:
	map<int, int> sou;
	map<int, int> rep;
};

class MyCalendar {
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

// The solution on website with less time cost.
// Actually the thought of this solution is similar with the former.
class MyCalendarTwo3 {
public:
	MyCalendarTwo3() {

	}

	bool book(int start, int end) {
		// The cal must be initialized every time.
		MyCalendar cal;
		for (pair<int, int> p : pv)
			if (max(p.first, start) < min(p.second, end))
				if (!cal.book(max(p.first, start), min(p.second, end)))
					return false;
		pv.push_back(pair<int, int>(start, end));
		return true;
	}
private:
	vector<pair<int, int>> pv;
};

// based on the fantastic solution of problem732, but the thought is not very suitable for this question
class MyCalendarTwo4 {
public:
	MyCalendarTwo4() {

	}

	bool book(int start, int end) {
		ma[start]++;
		ma[end]--;
		int cur = 0;
		for (pair<int, int> p : ma) {
			cur += p.second;
			if (cur > 2) {
				ma[start] --;
				ma[end]++;
				return false;
			}
		}
		return true;
	}
private:
	map<int, int> ma;
};
/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */

 // It is a boring problem, but the function in second solution is useful to me. 
 // The similar problem is question729 and question732