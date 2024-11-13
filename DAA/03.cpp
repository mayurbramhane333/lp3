#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int value;
    int weight;
    Item(int v, int w) : value(v), weight(w) {}
};

// Function to calculate maximum value and fractions of items to be taken
pair<double, vector<double>> fractionalKnapsack(int capacity, vector<Item>& items) {
    int n = items.size();
    vector<double> fractions(n, 0.0);

    // Calculate value-to-weight ratio and sort items by it in descending order
    vector<int> index(n);
    for (int i = 0; i < n; i++) {
        index[i] = i;
    }
    sort(index.begin(), index.end(), [&](int a, int b) {
        return (double)items[a].value / items[a].weight > (double)items[b].value / items[b].weight;
    });

    double maxValue = 0.0;
    for (int i : index) {
        if (items[i].weight <= capacity) {
            fractions[i] = 1.0;
            maxValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            fractions[i] = (double)capacity / items[i].weight;
            maxValue += items[i].value * fractions[i];
            break;
        }
    }

    return make_pair(maxValue, fractions);
}

int main() {
    int n, capacity;
    cout << "Enter the number of items: ";
    cin >> n;
    
    vector<Item> items;
    cout << "Enter the values and weights of the items:\n";
    for (int i = 0; i < n; i++) {
        int value, weight;
        cout << "Item " << i + 1 << " value: ";
        cin >> value;
        cout << "Item " << i + 1 << " weight: ";
        cin >> weight;
        items.emplace_back(value, weight);
    }

    cout << "Enter the maximum weight of the knapsack: ";
    cin >> capacity;

    pair<double, vector<double>> result = fractionalKnapsack(capacity, items);
    double maxValue = result.first;
    vector<double> fractions = result.second;

    cout << "The maximum value of items that can be carried: " << maxValue << endl;
    cout << "The fractions in which the items should be taken: ";
    for (double fraction : fractions) {
        cout << fraction << " ";
    }
    cout << endl;

    return 0;
}
