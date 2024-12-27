#include<bits/stdc++.h>
using namespace std;

// $ Max element in array
// $ TC: O(n) | SC: O(1)
int findLargestElement(int arr[], int n){
    int maxi = INT_MIN;
    for(int i = 0; i < n; i++){
        if(arr[i] > maxi) maxi = arr[i];
    }
    return maxi;
}

int main() {
    int arr1[] = {2,5,1,3,0};
    int n = 5;
    int max = findLargestElement(arr1, n);
    cout << "The largest element in the array is: " << max << endl;

    int arr2[] =  {8,10,5,7,9};
    n = 5;
    max = findLargestElement(arr2, n);
    cout << "The largest element in the array is: " << max<<endl;
}