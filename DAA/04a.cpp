#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to solve the 0/1 Knapsack problem
int knapSack(int W, vector<int>& wt, vector<int>& val) {
    int n = val.size();
    vector<vector<int>> table(n + 1, vector<int>(W + 1, 0));

    // Build table in a bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                table[i][j] = 0;
            } else if (wt[i - 1] <= j) {
                table[i][j] = max(val[i - 1] + table[i - 1][j - wt[i - 1]], table[i - 1][j]);
            } else {
                table[i][j] = table[i - 1][j];
            }
        }
    }

    return table[n][W];
}

int main() {
    vector<int> val = {50, 100, 150, 200};
    vector<int> wt = {8, 16, 32, 40};
    int W = 64;

    cout << "Maximum value in Knapsack = " << knapSack(W, wt, val) << endl;

    return 0;
}
