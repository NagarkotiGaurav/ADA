#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Item {
    int weight;
    int value;
    double ratio;
};

bool compare(const Item& a, const Item& b) {
    return a.ratio > b.ratio;
}

double fractionalKnapsack(int W, vector<Item>& items) {
    double totalValue = 0.0;

    for (int i = 0; i < items.size(); i++) {
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    sort(items.begin(), items.end(), compare);

    for (int i = 0; i < items.size(); i++) {
        if (items[i].weight <= W) {
            totalValue += items[i].value;
            W -= items[i].weight;
        } else {
            double fraction = (double)W / items[i].weight;
            totalValue += items[i].value * fraction;
            break;
        }
    }

    return totalValue;
}

int main() {
    int W = 5;
    vector<Item> items = {{5, 12}, {1, 10}, {3, 20},{2,15}};

    double maxValue = fractionalKnapsack(W, items);

    cout << "Maximum value obtained: " << maxValue << endl;

    return 0;
}
