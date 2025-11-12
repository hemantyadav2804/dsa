#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Item {
    int value, weight;
    double ratio() { return (double)value/weight; }
};

bool compare(Item a, Item b) { return a.ratio() > b.ratio(); }

int main() {
    vector<Item> items;
    int capacity, n, v, w;
    
    cout << "Knapsack capacity: "; cin >> capacity;
    cout << "Number of items: "; cin >> n;
    
    for(int i = 0; i < n; i++) {
        cout << "Item " << i+1 << " (value weight): ";
        cin >> v >> w;
        items.push_back({v, w});
    }
    
    sort(items.begin(), items.end(), compare);
    
    double total = 0.0;
    int current = 0;
    
    cout << "\nItems taken:\n";
    for(auto item : items) {
        if(current + item.weight <= capacity) {
            total += item.value;
            current += item.weight;
            cout << "Whole item: Value=" << item.value << ", Weight=" << item.weight << endl;
        } else {
            int rem = capacity - current;
            total += item.value * ((double)rem / item.weight);
            cout << "Fraction: Value=" << item.value << ", Weight=" << rem << "/" << item.weight << endl;
            break;
        }
    }
    
    cout << "Maximum value: " << total << endl;
    return 0;
}