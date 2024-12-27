#include<bits/stdc++.h>
using namespace std;

// $ Find the 2nd smallest and 2nd highest element

// $ BFA
// $ TC: O(nlogn) | SC: O(1)
void getElements(int arr[], int n) {
    if(n == 0 || n == 1) cout << -1 << " " << -1 << endl;
    sort(arr, arr + n);
    cout << "2nd Highest: " << arr[n - 2] << endl;
    cout << "2nd Lowest: " << arr[1] << endl;
}

// $ BeA
// $ TC: O(n) | SC: O(1)
void getElementsBeA(int arr[], int n) {
    if(n == 0 || n == 1) cout << -1 << " " << -1 << endl;
    int largest = INT_MIN, large2 = INT_MIN, smallest = INT_MAX, small2 = INT_MAX;

    for(int i = 0; i < n; i++) {
        smallest = min(arr[i], smallest);
        largest = max(arr[i], largest);
    }

    for(int i = 0; i < n; i++) {
        if(arr[i] > large2 && arr[i] != largest) {
            large2 = arr[i];
        }
        if(arr[i] < small2 && arr[i] != smallest) {
            small2 = arr[i];
        }
    }

    cout << "2nd Highest: " << large2 << endl;
    cout << "2nd Lowest: " << small2 << endl;
}

// $ OA
// $ TC: O(n) | SC: O(1)
void getElementsOA(int arr[], int n) {
    if(n < 2) cout << -1 << " " << -1 << endl;
    int largest = INT_MIN, large2 = INT_MIN, smallest = INT_MAX, small2 = INT_MAX;
    for(int i = 0; i < n; i++) {
        if(arr[i] < smallest) {
            small2 = smallest;
            smallest = arr[i];
        }
        else if(arr[i] < small2 && arr[i] != smallest) {
            small2 = arr[i];
        }

        if(arr[i] > largest) {
            large2 = largest;
            largest = arr[i];
        }
        else if(arr[i] > large2 && arr[i] != largest) {
            large2 = arr[i];
        }
    }
    cout << "2nd Highest: " << large2 << endl;
    cout << "2nd Lowest: " << small2 << endl;
}

int main() {
    int arr[]={1,2,4,6,7,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    getElements(arr,n);
    int arr1[]={1,2,4,6,7,5};
    int n1=sizeof(arr1)/sizeof(arr1[0]);
    getElementsBeA(arr1,n1);
    getElementsOA(arr1, n1);
}