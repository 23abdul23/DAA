/*
Basic Question: Sort a list of integers using Counting Sort.
Topic: Counting Sort
Idea Used: Count frequencies of values, convert counts to positions, and place elements into the output array.
*/
//iit2024243
//
//
//Abdul Azeem Ansari
//TC : O(n)
//SC : O(n)
#include <bits/stdc++.h>

using namespace std;

int main(){

	int n, t;
	cin >> n;
	t = n;
	int Mx = INT_MIN, Mi = INT_MAX;
	vector<int> arr, ans(n,0);
	while (t--){
		int x;
		cin >> x;
		Mx = max(Mx, x);
		Mi = min(Mi, x);

		arr.push_back(x);
	}
//the count matrx for the frequency 
	vector<int> ct(Mx+1, 0);
	
	for(auto i : arr){
		ct[i]++;
	}

	//making the prefifx matrix
	for (int i = 1; i < n; i++){
		ct[i] += ct[i-1];
	}
	//shifting by one 
	for (int i = n-1; i > 0; i--){
		ct[i] = ct[i-1];
	}
	ct[0] = 0;

	for (int i = 0; i < n; i++){
		ans[ct[arr[i]]++] = arr[i];  
	}


	for (auto i: arr)
		cout << i << " ";

	cout << endl;

	for (auto i: ans)
		cout << i << " ";

	return 0;


}
