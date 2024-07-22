#include<bits/stdc++.h>
using namespace std;

// $ Add 2 Nos in the form of LL

class Node {
public:
    int data;
    Node* next;

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
    Node(){
        data = 0;
        next = nullptr;
    }
};


// $ Optimal Approach
// $ TC: O(max(m, n)) | SC: O(max(m, n))
class Solution{
public:
    Node* addNos(Node* l1, Node* l2){
        Node* dum = new Node();
        Node* temp = dum;

        int carry = 0;
        while( (l1 || l2) || carry){
            int sum = 0;
            if(l1){
                sum += l1 -> data;
                l1 = l1 -> next;
            }

            if(l2){
                sum += l2 -> data;
                l2 = l2 -> next;
            }

            sum += carry;
            carry = sum / 10;
            temp -> next = new Node(sum % 10);
            temp = temp -> next;
        }
        return dum -> next;
    }
};