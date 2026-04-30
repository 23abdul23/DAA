/*
Basic Question: Find the minimum number of coins needed for a target amount using a greedy strategy.
Topic: Greedy Algorithm
Idea Used: Always pick the largest available denomination first and continue until the amount becomes zero or no choice works.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//O(nlogn+Amount)
void minCoinsGreedy(vector<int> coins, int amount) {
    sort(coins.rbegin(), coins.rend());

    int totalCoins = 0;
    vector<int> result;

    for (int i = 0; i < coins.size(); i++) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            result.push_back(coins[i]);
            totalCoins++;
        }
    }

    if (amount == 0) {
        cout << "Minimum coins (Greedy): " << totalCoins << endl;
        cout << "Coins used: ";
        for (int c : result) cout << c << " ";
        cout << endl;
    } else {
        cout << "Exact change not possible with greedy." << endl;
    }
}

int main() {
    vector<int> denominations = {1, 3, 4};
    int target = 6;
    
    minCoinsGreedy(denominations, target);
    return 0;
}
