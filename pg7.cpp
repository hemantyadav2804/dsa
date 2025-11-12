#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Marks {
    vector<int> m;
    
    void makeMinHeap() {
        for(int i=m.size()/2-1; i>=0; i--) {
            int small = i, left = 2*i+1, right = 2*i+2;
            if(left < m.size() && m[left] < m[small]) small = left;
            if(right < m.size() && m[right] < m[small]) small = right;
            if(small != i) { swap(m[i], m[small]); makeMinHeap(); }
        }
    }
    
    void makeMaxHeap() {
        for(int i=m.size()/2-1; i>=0; i--) {
            int large = i, left = 2*i+1, right = 2*i+2;
            if(left < m.size() && m[left] > m[large]) large = left;
            if(right < m.size() && m[right] > m[large]) large = right;
            if(large != i) { swap(m[i], m[large]); makeMaxHeap(); }
        }
    }

public:
    void add(int mark) { m.push_back(mark); }
    int getMin() { makeMinHeap(); return m[0]; }
    int getMax() { makeMaxHeap(); return m[0]; }
    void show() { for(int x:m) cout<<x<<" "; cout<<endl; }
};

int main() {
    Marks m; int c, mark;
    cout << "1.Add 2.Min 3.Max 4.Show 5.Exit\n";
    while(true) {
        cout << "Choice: "; cin >> c;
        if(c==1) { cin>>mark; m.add(mark); }
        else if(c==2) cout << "Min: " << m.getMin() << endl;
        else if(c==3) cout << "Max: " << m.getMax() << endl;
        else if(c==4) m.show();
        else if(c==5) break;
        else cout << "Invalid!\n";
    }
    return 0;
}