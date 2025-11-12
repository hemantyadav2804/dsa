#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsackDP(int capacity, vector<int>& weights, vector<int>& values, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    
    for(int i = 1; i <= n; i++) {
        for(int w = 1; w <= capacity; w++) {
            if(weights[i-1] <= w) {
                dp[i][w] = max(values[i-1] + dp[i-1][w-weights[i-1]], dp[i-1][w]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    
    // Backtrack to find selected items
    int w = capacity;
    cout << "Selected items: ";
    for(int i = n; i > 0 && w > 0; i--) {
        if(dp[i][w] != dp[i-1][w]) {
            cout << i << " ";
            w -= weights[i-1];
        }
    }
    cout << endl;
    
    return dp[n][capacity];
}

int main() {
    vector<int> weights, values;
    int capacity, n, choice;
    
    cout << "=== 0-1 KNAPSACK SOLVER (DP) ===\n";
    
    do {
        cout << "\n1. Enter Knapsack Capacity\n";
        cout << "2. Add Items\n";
        cout << "3. Solve using DP\n";
        cout << "4. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "Enter capacity: ";
                cin >> capacity;
                break;
                
            case 2:
                cout << "Number of items: ";
                cin >> n;
                weights.resize(n);
                values.resize(n);
                for(int i = 0; i < n; i++) {
                    cout << "Item " << i+1 << " (value weight): ";
                    cin >> values[i] >> weights[i];
                }
                break;
                
            case 3:
                if(weights.empty()) {
                    cout << "Please add items first!\n";
                } else {
                    int maxVal = knapsackDP(capacity, weights, values, n);
                    cout << "Maximum value: " << maxVal << endl;
                }
                break;
                
            case 4:
                cout << "Exiting...\n";
                break;
                
            default:
                cout << "Invalid choice!\n";
        }
    } while(choice != 4);
    
    return 0;
}