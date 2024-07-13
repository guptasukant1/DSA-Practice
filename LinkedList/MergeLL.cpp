#include<bits/stdc++.h>
using namespace std;

// $ Merge Two Sorted Linked List

class Node {
    public:
    int data;
    Node* next;
    Node(int data, Node* next){
        this->data = data;
        this->next = next;
    }
    Node(int data){
        this->data = data;
        next = nullptr;
    }
};

// $ Brute Force Approach
// $ TC: O() | SC: O()
Node* mergeLL()[]