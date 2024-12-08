#include<bits/stdc++.h>
using namespace std;

// $ Bubble Sort
// $ TC: O(n^2) | C: O(1)
void bubble_sort(int arr[], int n){
    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j <= i - 1; j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    cout << "After Using bubble sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

// $ Optimised
// $ TC: O(n)[best as check exits after 1 loop] or O(n^2)[worst] | SC: O(1)
void bubble_sort1(int arr[], int n){
    for(int i = n - 1; i >= 0; i--){
        int didSwap = 0;
        for(int j = 0; j <= i - 1; j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                didSwap = 1;
            }
        }
        if(didSwap == 0) break;
    }

    cout << "After Using bubble sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main(){
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before Using Bubble Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    bubble_sort(arr, n);

    int arr1[] = {13, 46, 24, 52, 20, 9};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Before Using Bubble Sort: " << endl;
    for (int i = 0; i < n1; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    
    bubble_sort1(arr1, n1);
}