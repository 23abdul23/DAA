/*
Basic Question: Sort an unsorted array using Quick Sort.
Topic: Divide and Conquer
Idea Used: Partition the array around a pivot and recursively sort the left and right subarrays.
*/
#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &arr, int l , int r){
	int pivot = arr[r];
	int i = l-1;

	for (int j = l; j < r; j++){
		if (arr[j] <= pivot){
			i++;
			swap(arr[i], arr[j]);
		}	
	}

	swap(arr[r], arr[i+1]);

	return i+1;

}

void qSort(vector<int> &arr, int l, int r){
	
	if (l < r){
		int pvt_i = partition(arr, l, r);

		qSort(arr, l, pvt_i-1);
		qSort(arr, pvt_i+1, r);

	}
}	

int main(){
	int n;
	cin >> n;
	vector<int> arr(n, 0);

	for (int i = 0 ; i < n ; i++){
		cin >> arr[i];
	}
	
	cout << "Current Arr: " << endl;
	for (int i = 0 ; i < n ; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "Quick Sort Started" << endl;
	
	qSort(arr, 0, n-1);
	for (int i = 0 ; i < n ; i++){
		cout << arr[i] << " ";
	}
	return 0;
}
