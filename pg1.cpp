#include <iostream>
#include <vector>
#include <map>
using namespace std;

class FlightSystem {
private:
    map<string, int> cityIndex;
    vector<string> cities;
    
    // Adjacency Matrix
    vector<vector<int>> matrix;
    
    // Adjacency List  
    vector<vector<pair<int, int>>> list;

public:
    void addCity(string name) {
        if(cityIndex.find(name) == cityIndex.end()) {
            cityIndex[name] = cities.size();
            cities.push_back(name);
            matrix.resize(cities.size(), vector<int>(cities.size(), 0));
            list.resize(cities.size());
            cout << "City added: " << name << endl;
        }
    }

    void addFlight(string cityA, string cityB, int cost) {
        int a = cityIndex[cityA];
        int b = cityIndex[cityB];
        
        // Update matrix
        matrix[a][b] = cost;
        matrix[b][a] = cost;
        
        // Update list
        list[a].push_back({b, cost});
        list[b].push_back({a, cost});
        
        cout << "Flight added: " << cityA << " <-> " << cityB << " (Cost: " << cost << ")" << endl;
    }

    void checkConnected(string cityA, string cityB) {
        int a = cityIndex[cityA];
        int b = cityIndex[cityB];
        
        // Using matrix
        if(matrix[a][b] > 0) {
            cout << "✓ Connected! Cost: " << matrix[a][b] << endl;
        } else {
            cout << "✗ Not connected" << endl;
        }
    }

    void displayMatrix() {
        cout << "\nMatrix:" << endl;
        for(int i = 0; i < cities.size(); i++) {
            for(int j = 0; j < cities.size(); j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void displayList() {
        cout << "\nList:" << endl;
        for(int i = 0; i < cities.size(); i++) {
            cout << cities[i] << " -> ";
            for(auto neighbor : list[i]) {
                cout << cities[neighbor.first] << "(" << neighbor.second << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    FlightSystem flights;
    int choice, cost;
    string city1, city2;
    
    cout << "=== SIMPLE FLIGHT SYSTEM ===" << endl;
    
    while(true) {
        cout << "\n1. Add City\n2. Add Flight\n3. Check Connection\n4. Show Matrix\n5. Show List\n6. Exit\n";
        cout << "Choose: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "City name: ";
                cin >> city1;
                flights.addCity(city1);
                break;
                
            case 2:
                cout << "City 1: ";
                cin >> city1;
                cout << "City 2: ";
                cin >> city2;
                cout << "Cost: ";
                cin >> cost;
                flights.addFlight(city1, city2, cost);
                break;
                
            case 3:
                cout << "City 1: ";
                cin >> city1;
                cout << "City 2: ";
                cin >> city2;
                flights.checkConnected(city1, city2);
                break;
                
            case 4:
                flights.displayMatrix();
                break;
                
            case 5:
                flights.displayList();
                break;
                
            case 6:
                cout << "Goodbye!" << endl;
                return 0;
                
            default:
                cout << "Invalid choice!" << endl;
        }
    }
}