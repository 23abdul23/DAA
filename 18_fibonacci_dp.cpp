/*
Basic Question: Compute the nth Fibonacci number using dynamic programming.
Topic: Dynamic Programming
Idea Used: Store previously computed Fibonacci values in a vector and extend it only when a larger n is requested.
*/
//iit2024243
//Abdul Azeem Ansari
//

#include <bits/stdc++.h>
using namespace std;

int fibbN(int x, vector<int> &arr){
	int n = arr.size();
	
	if (x-1 < n)
		return arr[x-1];
	else{
		int t = n;
		while(t < x){
			arr.push_back(arr[n-1] + arr[n-2]);
			n++;
			t++;
		}
		return arr[x-1];
	}

}

int main(){
	vector<int> arr = {0,1,1,2};
	int x;
		
	while (true){
		printf("Find nth Fibb Number: ");
		cin >> x;
	
		printf("%dth Fibb: %d\n", x, fibbN(x, arr));
	}

	return 0;
}
