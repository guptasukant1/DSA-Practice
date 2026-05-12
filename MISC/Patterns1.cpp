#include <bits/stdc++.h>
using namespace std;

void pattern1(int n) {
    for(int i = 0; i <= n - 1; i++) {
        for(int j = 0; j <= n - 1; j++) {
            cout << "* ";
        }
        cout << endl;
    }   
}

void pattern2(int n) {
    for(int i = 0; i <= n - 1; i++) {
        for(int j = i; j >= 0; j--) {
            cout << "* ";
        }
        cout << endl;
    }   
}

void pattern3(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cout << j;
        }
        cout << endl;
    }   
}

void pattern4(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cout << i;
        }
        cout << endl;
    }   
}

void pattern5(int n) {
    for(int i = 0; i <= n - 1; i++) {
        for(int j = n - i - 1; j >= 0; j--) {
            cout << "* ";
        }
        cout << endl;
    }
}

void pattern6(int n) {
    for(int i = 0; i <= n - 1; i++) {
        for(int j = 1; j <= n - i; j++) {
            cout << j;
        }
        cout << endl;
    }
}

void pattern7(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= n - i - 1; j++) {
            cout << " ";
        }
        for(int j = 0; j < 2 * i - 1; j++) {
            cout << "*";
        }
        for(int j = 0; j <= n - i - 1; j++) {
            cout << " ";
        }
        cout << endl;
    }
}

void pattern8(int n) {
    for(int i = n; i > 0; i--) {
        for(int j = 0; j <= n - i - 1; j++) {
            cout << " ";
        }
        for(int j = 0; j < 2 * i - 1; j++) {
            cout << "*";
        }
        for(int j = 0; j <= n - i - 1; j++) {
            cout << " ";
        }
        cout << endl;
    }
}

void pattern9(int n) {
    for(int i = 1; i <= 2*n - 1; i++) {
        int star = i; // for i < n rows
        if(i > n) star = 2*n - i;

        for(int j = 1; j <= star; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

void pattern10(int n) {
    int start = 1;
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) start = 1;
        else start = 0;
        for(int j = 0; j <= i; j++) {
            cout << start;
            start = 1 - start;
        }
        cout << endl;
    }
}

void pattern11(int n) {
    // !! FAILS FOR N >= 10
    // int spaces = 2 * (n - 1);
    for(int i = 1; i <=n; i++) {
        int width = to_string(n).length();
        for(int j = 1; j <= i; j++) {
            cout << setw(width) << j;
        }
        for(int j = 1; j <= 2*(n - i); j++) {
            cout << setw(width) << " ";
        }
        for(int j = i; j >= 1; j--) {
            cout << setw(width) << j;
        }
        cout << endl;
        // spaces -= 2;
    }
}

void pattern12(int n) {
    int num = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cout << num << " ";
            num++;
        }
        cout << endl;
    }
}

void pattern13(int n) {
    for(int i = 0; i < n; i++) {
        for(char ch = 'A'; ch <= 'A' + i; ch++) {
            cout << ch << " ";
        }
        cout << endl;
    }
}

void pattern14(int n) {
    for(int i = n; i > 0; i--) {
        for(char j = 'A'; j < 'A' + i; j++) {
            cout << j << " ";
        }
        cout << endl;
    } 
}

void pattern15(int n) {
    for(int i = 0; i < n; i++) {
        char ch = 'A' + i;
        for(int j = 0; j <= i; j++) {
            cout << ch << " ";
        }
        cout << endl;
    }
}

void pattern16(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }
        char ch = 'A';
        int mid = (2 * i) / 2;
        for(int j = 0; ) {}
        for() {}
        cout << endl;
    }
}

int main() {
    int n = 5;
    // pattern1(n);
    // pattern2(n);
    // pattern3(n);
    // pattern4(n);
    // pattern5(n);
    // pattern6(n);
    // pattern7(n);
    // pattern8(n);
    // pattern9(n);
    // pattern10(n);
    // pattern11(n);
    // pattern12(n);
    // pattern13(n);
    // pattern14(n);
    pattern15(n);
}