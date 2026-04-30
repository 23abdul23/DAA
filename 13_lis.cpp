/*
Basic Question: Find the length of the Longest Increasing Subsequence in an array.
Topic: Dynamic Programming
Idea Used: Use recursion with memoization on current index and previous chosen index to maximize subsequence length.
*/
//iit2024243
//Abdul Azeem Ansari
//TC: O(n**2)
//
//SC: O(n**2)

#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &dp, int i, int j, vector<int> &arr){
    int n = arr.size();

    if (j == n)
        return 0;

    if (dp[i + 1][j] != -1)
        return dp[i + 1][j];

    int ntake = solve(dp, i, j + 1, arr);
    
    int take = 0;
    if (i == -1 || arr[j] > arr[i]){
        take = 1 + solve(dp, j, j + 1, arr);
    }

    return dp[i + 1][j] = max(take, ntake);
}

int main(){
    int n;
    if (!(cin >> n)) return 0;
    
    vector<int> arr(n);
    for(int k = 0; k < n; k++){
        cin >> arr[k];
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    int a = solve(dp, -1, 0, arr);
    cout << a << endl;
    
    return 0;
}
