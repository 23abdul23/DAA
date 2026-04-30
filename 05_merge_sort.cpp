/*
Basic Question: Sort an unsorted array using Merge Sort.
Topic: Divide and Conquer
Idea Used: Recursively split the array into halves, sort them, and merge the sorted halves.
*/
#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &arr, int l, int r, int m){

	vector<int> a, b;

	for (int i = l; i <= m; i++){
		a.push_back(arr[i]);
	}

	for (int i = m+1; i <= r; i++){
		b.push_back(arr[i]);
	}

	
	int p = 0, q = 0, i = l;

	while (p < a.size() && q < b.size()){
		
		if (a[p] <= b[q]){
			arr[i] = a[p];
			p++;
		}
		else{
			arr[i] = b[q];
			q++;
		}

		i++;
	}

	while (p < a.size()){
		arr[i] = a[p];
		p++, i++;
	}

	while (q < b.size()){
		arr[i] = b[q];
		q++, i++;
	}
	return;



}
void msort(vector<int> &arr, int l, int r){
	
	if ( l >= r)
		return;

	int m = l + (r-l)/2;

	msort(arr, l, m);
	msort(arr, m+1, r);

	merge(arr, l, r, m);
}	

int main(){
	int n;
	cin >> n;
	vector<int> arr(n, 0);

	for (int i = 0 ; i < n ; i++){
		cin >> arr[i];
	}
	
	cout << "current arr: " << endl;
	for (int i = 0 ; i < n ; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "merge sort started" << endl;
	
	msort(arr, 0, n-1);
	for (int i = 0 ; i < n ; i++){
		cout << arr[i] << " ";
	}

	return 0;

}

	
