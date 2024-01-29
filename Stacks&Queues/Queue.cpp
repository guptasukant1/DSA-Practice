#include <bits/stdc++.h>
using namespace std;

// $ Push from rear
// $ Pop from front


int main(){

// $ STL QUEUE

    queue<int> q;
    q.push(1);
    cout << "front: " << q.front() << endl;
    q.push(2);
    q.pop();
    cout << "front: " << q.front() << endl;
    q.push(3);
    q.push(4);
    cout << "size: " << q.size() << endl;
    q.pop();
    cout << "size: " << q.size() << endl;

    if(q.empty()){
        cout << "queue is empty.";
    } else {
        cout << "queue is not empty";
    }
}