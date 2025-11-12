#include <iostream>
#include <queue>
#include <map>
using namespace std;

struct Node {
    char c; int f;
    Node *l, *r;
    Node(char ch, int fr): c(ch), f(fr), l(0), r(0) {}
};

struct Compare {
    bool operator()(Node* a, Node* b) { return a->f > b->f; }
};

class Huffman {
    Node* root;
    map<char, string> codes;
    
    void genCodes(Node* n, string code) {
        if(!n->l && !n->r) { codes[n->c] = code; return; }
        genCodes(n->l, code+"0"); genCodes(n->r, code+"1");
    }
    
public:
    string encode(string text) {
        map<char, int> freq;
        for(char c:text) freq[c]++;
        
        priority_queue<Node*, vector<Node*>, Compare> pq;
        for(auto p:freq) pq.push(new Node(p.first, p.second));
        
        while(pq.size()>1) {
            Node *l=pq.top(); pq.pop();
            Node *r=pq.top(); pq.pop();
            Node *p=new Node(0, l->f+r->f);
            p->l=l; p->r=r; pq.push(p);
        }
        
        root=pq.top(); codes.clear();
        genCodes(root, "");
        
        string enc="";
        for(char c:text) enc+=codes[c];
        return enc;
    }
    
    string decode(string enc) {
        string dec=""; Node* cur=root;
        for(char b:enc) {
            cur = (b=='0')?cur->l:cur->r;
            if(!cur->l && !cur->r) { dec+=cur->c; cur=root; }
        }
        return dec;
    }
    
    void showCodes() {
        for(auto p:codes) cout<<p.first<<": "<<p.second<<endl;
    }
};

int main() {
    Huffman h; string text, enc; int c;
    cout<<"1.Encode 2.Decode 3.Codes 4.Exit\n";
    while(true) {
        cout<<"Choice: "; cin>>c; cin.ignore();
        if(c==1) {
            cout<<"Text: "; getline(cin,text);
            enc = h.encode(text);
            cout<<"Encoded: "<<enc<<endl;
        }
        else if(c==2) {
            if(enc.empty()) cout<<"Encode first!\n";
            else cout<<"Decoded: "<<h.decode(enc)<<endl;
        }
        else if(c==3) h.showCodes();
        else if(c==4) break;
    }
    return 0;
}