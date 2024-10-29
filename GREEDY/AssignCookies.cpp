#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

// $ Assigning Cookies
// $ TC: O(nlogn + mlogm + n + m) | SC: O(1)
int cookies(vi &greed, vi &cookie){
    int n = greed.size();
    int m = cookie.size();

    int coo = 0, gre = 0;

    sort(greed.begin(), greed.end());
    sort(cookie.begin(), cookie.end());

    while(coo < m && gre < n){
        if(greed[gre] <= cookie[coo]) gre++;
        coo++;
    }
    
    return gre;
}

int main(){
    vi greed = {1, 2, 3, 5, 8};
    vi cookie = {2, 1, 4, 6, 3};
    cout<<cookies(greed, cookie);
}