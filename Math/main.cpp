#include <bits/stdc++.h>
using namespace std;

int countDigi(int n) {
    // * Count Digits in number
    // * TC: log(n)base(10)
    cout << "n: " << n << endl;
    int cnt = 0;
    while (n > 0) {
        cnt++;
        n /= 10;
    }
    return cnt;
}

int countDigiOA(int n) {
    cout << "n: " << n << endl;
    int cnt = (int)(log10(n) + 1);
    // log n base 10 gives count of digits in num 
    return cnt;
}

int main() {
    int n = 8400321;
    // int n = 1000000;
    cout << countDigi(n) << endl;
    cout << countDigiOA(n) << endl;
}

