#include<bits/stdc++.h>
using namespace std;

// $ Find minimum number of coins to complete the change
// $ TC: O(V) | SC: O(1)

int main(){

    int V = 87;
    vector<int> ans;
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n = sizeof(coins) / sizeof (coins[0]);
    
    for(int i = n - 1; i >= 0; i--){
        while(V >= coins[i]){
            V -= coins[i];
            ans.push_back(coins[i]);
        }
    }   

    cout<<"The minimum number of coins is "<<ans.size()<<endl;
    cout<<"The coins are "<<endl;
    for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
    } 
}