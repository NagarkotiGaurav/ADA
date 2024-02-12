// #include <bits/stdc++.h>
// using namespace std;

// int knapSack(int capacity, vector<int> weights, vector<int> values, int n) {
//     // Create a table to store the maximum value for each remaining capacity
//     vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

//     // Iterate through each item
//     for (int i = 1; i <= n; i++) {
//         // Iterate through each remaining capacity
//         for (int w = 0; w <= capacity; w++) {
//             // If the current item's weight is greater than the remaining capacity,
//             // we cannot include this item, so we use the value from the previous
//             // item. Otherwise, we have the choice to include or exclude the
//             // current item.
//             if (weights[i - 1] > w) {
//                 dp[i][w] = dp[i - 1][w];
//             } else {
//                 dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
//             }
//         }
//     }

//     // The maximum value is stored in the bottom-right corner of the table
//     return dp[n][capacity];
// }

// int main() {
//     int capacity = 50;
//     vector<int> weights = {5, 1, 3, 2};
//     vector<int> values = {12, 10, 20, 15};
//     int n = weights.size();

//     cout << "Maximum value: " << knapSack(capacity, weights, values, n) << endl;

//     return 0;
// }


// #include <bits/stdc++.h>
// using namespace std;

// int knapSack(int capacity, vector<int> weights, vector<int> values, int n) {
//     // Create a table to store the maximum value for each remaining capacity
//     vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

//     // Create a table to store the binary form of the selected items
//     vector<vector<int>> binary(n + 1, vector<int>(capacity + 1, 0));

//     // Iterate through each item
//     for (int i = 1; i <= n; i++) {
//         // Iterate through each remaining capacity
//         for (int w = 0; w <= capacity; w++) {
//             // If the current item's weight is greater than the remaining capacity,
//             // we cannot include this item, so we use the value from the previous
//             // item. Otherwise, we have the choice to include or exclude the
//             // current item.
//             if (weights[i - 1] > w) {
//                 dp[i][w] = dp[i - 1][w];
//                 binary[i][w] = binary[i - 1][w];
//             } else {
//                 dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
//                 binary[i][w] = binary[i - 1][w - weights[i - 1]];
//                 if (dp[i][w] == dp[i - 1][w - weights[i - 1]] + values[i - 1]) {
//                     binary[i][w] = binary[i - 1][w - weights[i - 1]] | (1 << (i - 1));
//                 }
//             }
//         }
//     }

//     // The maximum value is stored in the bottom-right corner of the table
//     int maxValue = dp[n][capacity];

//     // Print the binary form of the selected items
//     cout << "Selected items: ";
//     for (int i = 0; i < n; i++) {
//         if (binary[n][capacity] & (1 << i)) {
//             cout << weights[i] << " ";
//         }
//     }
//     cout << endl;

//     return maxValue;
// }

// int main() {
//     int capacity = 50;
//     vector<int> weights = {10, 20, 30};
//     vector<int> values = {60, 100, 120};
//     int n = weights.size();

//     cout << "Maximum value: " << knapSack(capacity, weights, values, n) << endl;

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int knapSack(int capacity, vector<int> weights, vector<int> values, int n) {
    // Create a table to store the maximum value for each remaining capacity
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Create a table to store the binary form of the selected items
    vector<vector<int>> binary(n + 1, vector<int>(capacity + 1, 0));

    // Iterate through each item
    for (int i = 1; i <= n; i++) {
        // Iterate through each remaining capacity
        for (int w = 0; w <= capacity; w++) {
            // If the current item's weight is greater than the remaining capacity,
            // we cannot include this item, so we use the value from the previous
            // item. Otherwise, we have the choice to include or exclude the
            // current item.
            if (weights[i - 1] > w) {
                dp[i][w] = dp[i - 1][w];
                binary[i][w] = binary[i - 1][w];
            } else {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
                binary[i][w] = binary[i - 1][w - weights[i - 1]];
                if (dp[i][w] == dp[i - 1][w - weights[i - 1]] + values[i - 1]) {
                    binary[i][w] = binary[i - 1][w - weights[i - 1]] | (1 << (i - 1));
                }
            }
        }
    }

    // The maximum value is stored in the bottom-right corner of the table
    int maxValue = dp[n][capacity];

    // Print the selected items in zero-one form
    cout << "Selected items: ";
    for (int i = 0; i < n; i++) {
        if (binary[n][capacity] & (1 << i)) {
            cout << "1 ";
        } else {
            cout << "0 ";
        }
    }
    cout << endl;

    return maxValue;
}

int main() {
    int capacity = 50;
    vector<int> weights = {10, 20, 30};
    vector<int> values = {60, 100, 120};
    int n = weights.size();

    cout << "Maximum value: " << knapSack(capacity, weights, values, n) << endl;

    return 0;
}