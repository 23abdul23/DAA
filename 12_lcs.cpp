/*
Basic Question: Find the length of the Longest Common Subsequence between two strings.
Topic: Dynamic Programming
Idea Used: Use recursion with memoization on string indices and choose match or skip transitions.
*/
//iit2024243
//Abdul Azeem Ansari
//TC: O(n**2)
//
//SC: O(n**2)

#include <bits/stdc++.h>
#include <string.h>
using namespace std;
int solve(vector<vector<int>> &dp, int i, int j, string s, string t){
	if (i >= s.size() || j >= t.size())
		return 0;

	if (dp[i][j] != -1)
		return dp[i][j];

	if (s[i] == t[j]){
		return dp[i][j] = 1+solve(dp, i+1, j+1, s, t);
	}
	else{
		int l = solve(dp, i+1, j, s,t);
		int r = solve(dp, i, j+1, s,t);

		return dp[i][j] = max(l,r);
	}
}

int main(){
	string s, t;

	s = "abcddddddddd";
	t = "dddabcdeeeee";
	cin >> s >> t;
	int n = s.size(), m = t.size();
	vector<vector<int>> dp(n+1, vector<int>(m+1,-1));

	int a =  solve(dp,0,0,s,t);
	cout << a << endl;
	return 0;

}
