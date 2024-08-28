#include <bits/stdc++.h>
using namespace std;

class twoStacks1Array{
    // Space optimization of array is there.
    // $ let there be 2 tops, 1 from -1 and the other from size of array. push into 1 from L->R
    // $ push into 2 from R->L. Both stacks use a single array and so 1 and 2 refer to the same array but from different top.
    // $ Pop reduces top in 1 but increases in 2. Number of queries for while loop, stack no and query type for stacks.

    public:
        int top1, top2, size, *arr;

        twoStacks1Array(int size=100)
        {
            this->size = size;
            arr = new int[size];
            top1 = -1;
            top2 = size;
        }

        void push1(int a){
            if(top2-top1>1){
                top1++;
                arr[top1] = a;
            }
        }
        void push2(int a){
            if(top2-top1>1){
                top2--;
                arr[top2] = a;
            }
        }

        int pop1(){
            if(top1 == -1) return -1;
            else {
                top1--;
                return arr[top1 + 1];
            }
        }
        int pop2(){
            if(top2 == -1) return -1;
            else {
                top2++;
                return arr[top2 - 1];
            }
        }
};



int main(){

    // $ Two Stacks in an Array.

    int t;
    cin >> t;
    while(t--){
        twoStacks1Array *st = new twoStacks1Array();

        int query;
        cin >> query;
        while(query--){
            cout << "queryno: "<< query<<endl;
            int stackno;
            int querytype=0;
            cin >> stackno;
            cin >> querytype;

            if(querytype == 1){
                int a;
                cin >> a;
                cout << "push"<< stackno << ": " << a<<endl;
                if(stackno == 1 ) st->push1(a);
                else if(stackno == 2 ) st->push2(a);
            }
            if(querytype == 2){
                if(stackno==1) cout << st->pop1() << endl;
                else if(stackno==2) cout << st->pop2() << endl;
            }
        }
    }

}