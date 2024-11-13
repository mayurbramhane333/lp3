#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double fractionalKnapsack(int W, vector<int> &weights, vector<int> &values) {
    int n = weights.size();
    vector<pair<double, int>> ratio(n);  // Pair of (value/weight ratio, index)

    // Calculate value-to-weight ratios and store them with item indices
    for (int i = 0; i < n; i++) {
        ratio[i] = { (double)values[i] / weights[i], i };
    }

    // Sort items by value-to-weight ratio in descending order
    sort(ratio.rbegin(), ratio.rend());

    double totalValue = 0.0;  // Total profit

    for (int i = 0; i < n; i++) {
        int idx = ratio[i].second;  // Get original item index from ratio pair

        if (W >= weights[idx]) {  // Take the whole item
            W -= weights[idx];
            totalValue += values[idx];
        } else {  // Take fraction of the item
            totalValue += values[idx] * ((double)W / weights[idx]);
            break;  // Knapsack is full
        }
    }

    return totalValue;
}

int main() {
    int W = 50;  // Capacity of knapsack
    vector<int> weights = {10, 20, 30};  // Weights of items
    vector<int> values = {60, 100, 120}; // Values of items

    cout << "Maximum profit: " << fractionalKnapsack(W, weights, values) << endl;
    return 0;
}
