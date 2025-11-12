#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

class Node {
public:
    char data;
    Node* left;
    Node* right;
    
    Node(char value) {
        data = value;
        left = right = NULL;
    }
};

class ExpressionTree {
private:
    Node* root;
    
    bool isOperator(char c) {
        return (c == '+' || c == '-' || c == '*' || c == '/');
    }
    
    // Build tree from prefix expression
    Node* buildTree(string prefix) {
        stack<Node*> st;
        
        // Read from right to left for prefix
        for(int i = prefix.length()-1; i >= 0; i--) {
            char c = prefix[i];
            Node* newNode = new Node(c);
            
            if(isOperator(c)) {
                newNode->left = st.top(); st.pop();
                newNode->right = st.top(); st.pop();
            }
            st.push(newNode);
        }
        return st.top();
    }
    
    // Recursive traversals
    void inorderRec(Node* node) {
        if(node) {
            if(isOperator(node->data)) cout << "(";
            inorderRec(node->left);
            cout << node->data << " ";
            inorderRec(node->right);
            if(isOperator(node->data)) cout << ")";
        }
    }
    
    void preorderRec(Node* node) {
        if(node) {
            cout << node->data << " ";
            preorderRec(node->left);
            preorderRec(node->right);
        }
    }
    
    void postorderRec(Node* node) {
        if(node) {
            postorderRec(node->left);
            postorderRec(node->right);
            cout << node->data << " ";
        }
    }
    
    // Non-recursive traversals
    void inorderNonRec() {
        stack<Node*> st;
        Node* current = root;
        
        while(current != NULL || !st.empty()) {
            while(current != NULL) {
                st.push(current);
                current = current->left;
            }
            
            current = st.top();
            st.pop();
            cout << current->data << " ";
            current = current->right;
        }
    }
    
    void preorderNonRec() {
        if(root == NULL) return;
        
        stack<Node*> st;
        st.push(root);
        
        while(!st.empty()) {
            Node* current = st.top();
            st.pop();
            cout << current->data << " ";
            
            if(current->right) st.push(current->right);
            if(current->left) st.push(current->left);
        }
    }
    
    void postorderNonRec() {
        if(root == NULL) return;
        
        stack<Node*> st1, st2;
        st1.push(root);
        
        while(!st1.empty()) {
            Node* current = st1.top();
            st1.pop();
            st2.push(current);
            
            if(current->left) st1.push(current->left);
            if(current->right) st1.push(current->right);
        }
        
        while(!st2.empty()) {
            cout << st2.top()->data << " ";
            st2.pop();
        }
    }
    
    // Swap left and right pointers
    Node* swapPointers(Node* node) {
        if(node == NULL) return NULL;
        
        // Swap left and right
        Node* temp = node->left;
        node->left = node->right;
        node->right = temp;
        
        // Recursively swap for subtrees
        swapPointers(node->left);
        swapPointers(node->right);
        
        return node;
    }

public:
    ExpressionTree() { root = NULL; }
    
    void buildFromPrefix(string expression) {
        root = buildTree(expression);
        cout << "Expression tree built successfully!\n";
    }
    
    void traverseInorderRec() {
        cout << "Inorder (Recursive): ";
        inorderRec(root);
        cout << endl;
    }
    
    void traversePreorderRec() {
        cout << "Preorder (Recursive): ";
        preorderRec(root);
        cout << endl;
    }
    
    void traversePostorderRec() {
        cout << "Postorder (Recursive): ";
        postorderRec(root);
        cout << endl;
    }
    
    void traverseInorderNonRec() {
        cout << "Inorder (Non-Recursive): ";
        inorderNonRec();
        cout << endl;
    }
    
    void traversePreorderNonRec() {
        cout << "Preorder (Non-Recursive): ";
        preorderNonRec();
        cout << endl;
    }
    
    void traversePostorderNonRec() {
        cout << "Postorder (Non-Recursive): ";
        postorderNonRec();
        cout << endl;
    }
    
    void swapTree() {
        root = swapPointers(root);
        cout << "Left and right pointers swapped at every node!\n";
    }
};

int main() {
    ExpressionTree et;
    int choice;
    string expression;
    
    cout << "=== EXPRESSION TREE OPERATIONS ===\n";
    
    // Build tree first
    cout << "Enter prefix expression (e.g., +-a*bc/def): ";
    cin >> expression;
    et.buildFromPrefix(expression);
    
    do {
        cout << "\n1. Inorder Traversal (Recursive)\n";
        cout << "2. Preorder Traversal (Recursive)\n";
        cout << "3. Postorder Traversal (Recursive)\n";
        cout << "4. Inorder Traversal (Non-Recursive)\n";
        cout << "5. Preorder Traversal (Non-Recursive)\n";
        cout << "6. Postorder Traversal (Non-Recursive)\n";
        cout << "7. Swap Left/Right Pointers\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                et.traverseInorderRec();
                break;
                
            case 2:
                et.traversePreorderRec();
                break;
                
            case 3:
                et.traversePostorderRec();
                break;
                
            case 4:
                et.traverseInorderNonRec();
                break;
                
            case 5:
                et.traversePreorderNonRec();
                break;
                
            case 6:
                et.traversePostorderNonRec();
                break;
                
            case 7:
                et.swapTree();
                break;
                
            case 8:
                cout << "Exiting program. Goodbye!\n";
                break;
                
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while(choice != 8);
    
    return 0;
}