#include <iostream>
#include <stack>
using namespace std;

struct Node {
    char data;
    Node *left, *right;
    Node(char x) : data(x), left(NULL), right(NULL) {}
};

class ExprTree {
    Node* root;
    
    bool isOp(char c) { return c=='+'||c=='-'||c=='*'||c=='/'; }
    
    Node* build(string pre) {
        stack<Node*> st;
        for(int i=pre.length()-1; i>=0; i--) {
            Node* n = new Node(pre[i]);
            if(isOp(pre[i])) {
                n->left = st.top(); st.pop();
                n->right = st.top(); st.pop();
            }
            st.push(n);
        }
        return st.top();
    }
    
    void in(Node* n) {
        if(n) {
            if(isOp(n->data)) cout << "(";
            in(n->left);
            cout << n->data << " ";
            in(n->right);
            if(isOp(n->data)) cout << ")";
        }
    }
    
    void pre(Node* n) {
        if(n) {
            cout << n->data << " ";
            pre(n->left);
            pre(n->right);
        }
    }
    
    void post(Node* n) {
        if(n) {
            post(n->left);
            post(n->right);
            cout << n->data << " ";
        }
    }
    
    void swap(Node* n) {
        if(n) {
            Node* temp = n->left;
            n->left = n->right;
            n->right = temp;
            swap(n->left);
            swap(n->right);
        }
    }

public:
    ExprTree() : root(NULL) {}
    
    void create(string exp) { root = build(exp); }
    void inorder() { cout << "Inorder: "; in(root); cout << endl; }
    void preorder() { cout << "Preorder: "; pre(root); cout << endl; }
    void postorder() { cout << "Postorder: "; post(root); cout << endl; }
    void mirror() { swap(root); cout << "Tree mirrored!\n"; }
};

int main() {
    ExprTree t;
    string exp;
    int choice;
    
    cout << "Enter prefix expression: ";
    cin >> exp;
    t.create(exp);
    
    do {
        cout << "\n1.Inorder 2.Preorder 3.Postorder 4.Mirror 5.Exit\nChoice: ";
        cin >> choice;
        switch(choice) {
            case 1: t.inorder(); break;
            case 2: t.preorder(); break;
            case 3: t.postorder(); break;
            case 4: t.mirror(); break;
            case 5: cout << "Bye!\n"; break;
            default: cout << "Invalid!\n";
        }
    } while(choice != 5);
    
    return 0;
}