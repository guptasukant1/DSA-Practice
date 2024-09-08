#include<bits/stdc++.h>
using namespace std;
#define ll long long

// $ Pascal's Triangle

// ? Variation 1 [row and col given]
// $ TC: O(c) | SC: O(1)
int ncr(int n, int r){
    ll res = 1;
    for(int i = 0; i < r; i++){
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

int pascalTriangle(int r, int c){
    int element = ncr(r - 1, c - 1);
    return element;
}

// ? Variation 2 [print nth row of pascal's triangle]
int pascalTriangleBeA(int r, int c){

}


// * Variation 1
int main(){
    int r = 5;
    int c = 3;
    int element = pascalTriangle(r, c);
    cout << "The element at position (r,c) is: " << element;
}


