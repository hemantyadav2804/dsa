#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

class BST {
private:
    Node* root;
    
    Node* insert(Node* node, int value) {
        if(node == NULL) return new Node(value);
        
        if(value < node->data) 
            node->left = insert(node->left, value);
        else if(value > node->data)
            node->right = insert(node->right, value);
            
        return node;
    }
    
    int findLongestPath(Node* node) {
        if(node == NULL) return 0;
        return 1 + max(findLongestPath(node->left), findLongestPath(node->right));
    }
    
    int findMin(Node* node) {
        if(node == NULL) return -1;
        while(node->left != NULL) node = node->left;
        return node->data;
    }
    
    bool search(Node* node, int value) {
        if(node == NULL) return false;
        if(node->data == value) return true;
        
        if(value < node->data) 
            return search(node->left, value);
        else 
            return search(node->right, value);
    }
    
    void ascending(Node* node) {
        if(node != NULL) {
            ascending(node->left);
            cout << node->data << " ";
            ascending(node->right);
        }
    }
    
    void descending(Node* node) {
        if(node != NULL) {
            descending(node->right);
            cout << node->data << " ";
            descending(node->left);
        }
    }

public:
    BST() { root = NULL; }
    
    void insert(int value) {
        root = insert(root, value);
        cout << value << " inserted successfully!\n";
    }
    
    void longestPath() {
        cout << "Number of nodes in longest path: " << findLongestPath(root) << endl;
    }
    
    void minimum() {
        int min = findMin(root);
        if(min == -1) 
            cout << "Tree is empty!\n";
        else
            cout << "Minimum value: " << min << endl;
    }
    
    void searchValue(int value) {
        if(search(root, value))
            cout << value << " found in tree!\n";
        else
            cout << value << " not found!\n";
    }
    
    void displayAscending() {
        cout << "Ascending order: ";
        ascending(root);
        cout << endl;
    }
    
    void displayDescending() {
        cout << "Descending order: ";
        descending(root);
        cout << endl;
    }
};

int main() {
    BST tree;
    int choice, value;
    
    cout << "=== BINARY SEARCH TREE OPERATIONS ===\n";
    
    do {
        cout << "\n1. Insert Node\n";
        cout << "2. Find Longest Path\n";
        cout << "3. Find Minimum Value\n";
        cout << "4. Search Value\n";
        cout << "5. Display Ascending Order\n";
        cout << "6. Display Descending Order\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                tree.insert(value);
                break;
                
            case 2:
                tree.longestPath();
                break;
                
            case 3:
                tree.minimum();
                break;
                
            case 4:
                cout << "Enter value to search: ";
                cin >> value;
                tree.searchValue(value);
                break;
                
            case 5:
                tree.displayAscending();
                break;
                
            case 6:
                tree.displayDescending();
                break;
                
            case 7:
                cout << "Exiting program. Goodbye!\n";
                break;
                
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while(choice != 7);
    
    return 0;
}