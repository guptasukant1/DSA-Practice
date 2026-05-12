#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

int main() {
    vi v;
    for(int i = 1; i <= 10; i++) {
        v.push_back(i);
    }
    for(auto it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }

    cout << "First elem: " << v.front() << endl;
    cout << "last elem: " << v.back() << endl;
    cout << "Size: " << v.size() << endl;
    cout << "Del last: " << v[v.size() - 1] << endl;
    v.pop_back();

    for(auto it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    v.insert(v.begin(), 5);
    
    cout << endl;
    
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    
    cout << endl;

    cout << v[0] << endl;
    v.erase(v.begin());
    cout << v[0] << endl;

    if(v.empty()) cout << "Vector is empty" << endl;
    else cout << "Vector not empty" << endl;
    
    v.clear();
    
    if(v.empty()) cout << "Vector is empty" << endl;
    else cout << "Vector not empty" << endl;
}