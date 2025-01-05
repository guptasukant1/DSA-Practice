#include<bits/stdc++.h>
using namespace std;

// $ Rotate array by k elements

// $ BFA
// $ TC: O() | SC: O()
void RotateRight(int arr[], int n, int k) {
    if(n == 0) return;
    k = k % n;
    cout << k << endl;
    if(k > n) return;
    int temp[k];
    for(int i = n - k; i < n; i++) {
        temp[i - n + k] = arr[i];
    }
}

int main() {
    int n = 7;
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int k = 2;
    RotateRight(arr, n, k);
    cout << "After Rotating the elements to right " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}