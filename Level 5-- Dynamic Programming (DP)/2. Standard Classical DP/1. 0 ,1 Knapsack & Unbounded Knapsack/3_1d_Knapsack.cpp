#include <bits/stdc++.h>
using namespace std;

int knapsack(int W, vector<int> &wt, vector<int> &val, int n) {
    vector<int> dp(W + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int cap = W; cap >= wt[i]; cap--) { // backward loop is crucial
            dp[cap] = max(dp[cap], dp[cap - wt[i]] + val[i]);
        }
    }
    return dp[W];
}

int main() {
    int n = 4;
    vector<int> wt = {2, 3, 4, 5};
    vector<int> val = {3, 4, 5, 6};
    int W = 5;
    cout << "Max value: " << knapsack(W, wt, val, n) << endl; // 7
    return 0;
}