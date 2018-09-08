#include "stdafx.h"
struct minHeap
{
	bool operator()(int a, int b)
	{
		return a > b;
	}
};
struct maxHeap
{
	bool operator()(int a, int b)
	{
		return a < b;
	}
};

int main_PriorityQueue()
{
	cout << "priority_queue min number output firstly:" << endl;
	// Note the difference from the sort compare rule definition in array
	//priority_queue<int, vector<int>, minHeap > minPriorityQueue;
	priority_queue<int, vector<int>, greater<int> > minPriorityQueue;
	minPriorityQueue.push(4);
	minPriorityQueue.push(5);
	minPriorityQueue.push(2);
	minPriorityQueue.push(6);
	minPriorityQueue.push(3);
	minPriorityQueue.push(7);
	minPriorityQueue.push(1);
	while (minPriorityQueue.size() != 0)
	{
		cout << minPriorityQueue.top() << " ";
		minPriorityQueue.pop();
	}
	cout << endl << endl;
	cout << "priority_queue max number output firstly:" << endl;
	// Note the difference from the sort compare rule definition in array
	//priority_queue<int, vector<int>, maxHeap > maxPriorityQueue;
	priority_queue<int, vector<int>, less<int> > maxPriorityQueue;
	maxPriorityQueue.push(4);
	maxPriorityQueue.push(5);
	maxPriorityQueue.push(2);
	maxPriorityQueue.push(6);
	maxPriorityQueue.push(3);
	maxPriorityQueue.push(7);
	maxPriorityQueue.push(1);
	while (maxPriorityQueue.size() != 0)
	{
		cout << maxPriorityQueue.top() << " ";
		maxPriorityQueue.pop();
	}
	cout << endl;
	system("pause");
	return 1;
}