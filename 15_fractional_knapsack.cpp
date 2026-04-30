/*
Basic Question: Solve the Fractional Knapsack problem for given weights, values, and capacity.
Topic: Greedy Algorithm
Idea Used: Sort items by value-to-weight style ratio and take the most profitable items fully or fractionally.
*/
//iit2024243
//Abdul Azeem 
//
//TC: O(n)
//SC: O(n)
#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> wt;
	vector<pair<double,double>> rat;

	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		wt.push_back(x);
	}
	
	//using the ratio of weight/profit
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		rat.push_back({(double)wt[i]/x, x});
	}
	
	sort(rat.begin(), rat.end());

	int k;
	cin >> k;
	
	double ans = 0;

	for (int i = n-1; i>=0;i--){
		if (k == 0){
			break;
		}
		double x = rat[i].second;
		double wt = rat[i].first*x;
		
		if (k >= wt){
			ans += (x);
			k -= wt;
		}
		else if (k > 0 && k < wt){
			ans += (k*x);
			k = 0;
		}

	}

	cout << ans <<endl;
	return 0;
}
