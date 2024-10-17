#include<bits/stdc++.h>
using namespace std;

// $ Lemonade Change
// | each lemonade costs $5. Customers are standing in a queue to buy from you and order one at a time (in the order specified by bills).
// | Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill.
// | You must provide the correct change to each customer so that the net transaction is that the customer pays $5.
// $ TC: O(n) | SC: O(1)
bool lemonadeChange(vector<int> &bills){
    int fives = 0;
    int tens = 0;
    for(int i = 0; i < bills.size(); i++){
        if(bills[i] == 5) fives++;
        else if(bills[i] == 10) {
            if(fives){
                fives--;
                tens++;
            }
            else return false;
        }
        else{
            if(fives && tens) {
                fives--;
                tens--;
            }
            else if(fives >= 3) fives -+ 3;
            else return false;
        }
    }
    return true;
}

int main() {
    vector<int> bills = {5, 5, 5, 10, 20};
    cout << "Queues of customers: ";
    for(int bill : bills){
        cout << bill << " ";
    }
    cout << endl;
    bool ans = lemonadeChange(bills);
    if(ans) cout << "It is possible to provide change for all customers." << endl;
    else cout << "It is not possible to provide change for all customers." << endl;
}