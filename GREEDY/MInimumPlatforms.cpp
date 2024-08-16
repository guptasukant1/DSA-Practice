#include<bits/stdc++.h>
using namespace std;

// $ Minimum number of platforms for a railway 

// $ Brute Force Approach [Taking the 2 arrs and checking whether the (current arr is less than next dep) || (next arr is less than current dep) ]
// $ -> set one train and check for remaining trains]
// $ TC: O(n ^ 2) | SC: O(1)
int countPlatforms(int n, int arr[], int dep[]){
    int ans = 1;
    for(int i = 0; i < n; i++){
        int count = 1;
        for(int j = i + 1; j < n; j++){
            if( (arr[i] >= arr[j] && arr[i] <= dep[j]) || (arr[j] >= arr[i] && arr[j] <= dep[i]) ) count++;
        }
        ans = max(ans, count);
    }
    return ans;
}

// $ Optimal Approach [2 ptr to check whether the arr of current is less than prev dep or not -> inc count and i if true else reduce count and inc j]
// $ TC: O() | SC: O()
int countPlatformsOA(int n, int arr[], int dep[]){
    sort(arr, arr + n);
    sort(dep, dep + n);
    int ans = 1, i = 1, j = 0, count = 1;
    while(i < n && j < n){
        if(arr[i] <= dep[j]){
            count++;
            i++;
        }
        else{
            count--;
            j++;
        }
        ans = max(ans, count);
    }
    return ans;
}


int main(){
    int arr[]={900,945,955,1100,1500,1800};
    int dep[]={920,1200,1130,1150,1900,2000};
    int n=sizeof(dep)/sizeof(dep[0]);
    cout<<"Minimum number of Platforms required "<<countPlatforms(n,arr,dep)<<endl;
    cout<<"Minimum number of Platforms required "<<countPlatformsOA(n,arr,dep)<<endl;
}