#include<bits/stdc++.h>
using namespace std;

// $ Fractional Knapsack Problem
// $ TC: O(nlogn + n) | SC: O(1)
struct Item{
    int value, weight;
};

class Solution{
public:
    bool static comparator(Item a, Item b){
        double r1 = (double) a.value / (double) a.weight;
        double r2 = (double) b.value / (double) b.weight;
        return r1 > r2;
    }
    double fractionalKnapsack(int W, Item arr[], int n){
        sort(arr, arr + n, comparator);

        int currWeight = 0, profit = 0;
        for(int i = 0; i < n; i++){
            if(currWeight + arr[i].weight <= W){
                currWeight += arr[i].weight;
                profit += arr[i].value;
            }
            else{
                int remain = W - currWeight;
                profit += arr[i].value * ((double) remain / (double) arr[i].weight);
                break;
            }
        }
        return profit;
    }
};

int main() {
    int n = 3, weight = 50;
    Item arr[n] = { {100,20},{60,10},{120,30} };
    Solution obj;
    double ans = obj.fractionalKnapsack(weight, arr, n);
    cout << "The maximum value is " << setprecision(2) << fixed << ans;
}