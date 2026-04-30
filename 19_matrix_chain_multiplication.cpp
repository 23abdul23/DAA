/*
Basic Question: Find the minimum number of scalar multiplications needed for matrix chain multiplication.
Topic: Dynamic Programming
Idea Used: Use recursion with memoization on subchains and try every split point to keep the minimum cost.
*/
//iit2024243
//
//Abdul Azeem Ansari
//

#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &arr, vector<vector<long long>> &dp, int i, int j){
	if (i >= j)
		return 0;

	if (dp[i][j] != -1)
		return dp[i][j];


	long long ans = INT_MAX;

	for (int k = i; k < j; k++){
		long long cost = solve(arr, dp, i, k) + solve(arr, dp ,k+1, j) + arr[i-1] * arr[k]* arr[j];

		ans = min(ans, cost);
	}
	dp[i][j] = ans;

	return ans;
}

int main(){
	vector<int> arr;
	int n;
	cin >> n;

	while (n--){
		int x;
		cin >> x;
		arr.push_back(x);
	}

	n = arr.size();

	vector<vector<long long>> dp(n, vector<long long> (n,-1));

	cout << solve(arr, dp, 1, n-1);

	return 0;
}
