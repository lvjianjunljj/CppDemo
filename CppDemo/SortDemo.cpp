#include "stdafx.h"

// key word "const" show that the input cannot be changed
bool maxIntSort(const int a, const int b) {
	return a > b;
}
bool minIntSort(int a, int b) {
	return a < b;
}

bool maxIntVectorSort(const vector<int> v1, const vector<int> v2) {
	return v1[0] > v2[0];
}

bool minIntVectorSort(const vector<int> v1, const vector<int> v2) {
	return v1[0] < v2[0];
}

/*
Note:
In compare function, f(a, b) and f(b, a) cannot both return true, so the fucntion
bool minIntSort(int a, int b) {
	return a <= b;
}
will throw exception when run sort funtion with this compare function.
I think we do not need to judge the equals happening have two reason:
1. Maybe it consider equals happening when the compare function f(a, b) and f(b, a) both return false
2. Normally unstable sort use the quick sort and stable sort use the merge sort, quick sort and merge sort do not need 
judge the equals happening between two number, the equals happening between can be summarized to be larger, 
or can be summarized to less(as long as it is unified). So I think the compare function in Java returning 0 to represent
the equals happening is so extra.

Remarks:
In this example, the num count is not big enough to distinguish the diference between unstable sort and stable sort.
*/

int main_Sort() {
	cout << "The simplest sorting by big to small" << endl;
	int arr[] = { 2, 4, 3, 1, 6, 5 };
	sort(arr, arr + 6, maxIntSort);

	for (int x = 0; x < 6; x++)
	{
		cout << arr[x] << " ";
	}
	cout << endl << endl;

	cout << "The simplest sorting by small to big" << endl;
	sort(arr, arr + 6, minIntSort);

	for (int x = 0; x < 6; x++)
	{
		cout << arr[x] << " ";
	}
	cout << endl << endl;

	vector<vector<int>> grid;
	grid.push_back(vector<int>({ 3, 2, 1 }));
	grid.push_back(vector<int>({ 2, 1, 3 }));
	grid.push_back(vector<int>({ 3, 1, 3 }));
	grid.push_back(vector<int>({ 1, 1, 3 }));
	grid.push_back(vector<int>({ 3, 5, 2 }));
	grid.push_back(vector<int>({ 3, 5, 4 }));
	grid.push_back(vector<int>({ 3, 5, 3 }));
	grid.push_back(vector<int>({ 3, 5, 9 }));
	grid.push_back(vector<int>({ 3, 5, 8 }));
	grid.push_back(vector<int>({ 3, 3, 7 }));
	grid.push_back(vector<int>({ 4, 3 ,5 }));
	vector<vector<int>> grid2(grid);

	cout << "The unstable sort of vector element" << endl;
	sort(grid.begin(), grid.end(), maxIntVectorSort);
	for (int i = 0; i < grid.size(); i++) {
		cout << grid[i][0] << " " << grid[i][1] << " " << grid[i][2] << endl;
	}
	cout << endl;

	cout << "The stable sort of vector element" << endl;
	stable_sort(grid2.begin(), grid2.end(), maxIntVectorSort);
	for (int i = 0; i < grid2.size(); i++) {
		cout << grid2[i][0] << " " << grid2[i][1] << " " << grid2[i][2] << endl;
	}


	system("pause");
	return 1;
}