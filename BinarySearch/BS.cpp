#include <bits/stdc++.h>
using namespace std;

void binaryIter(int[], int, int, int);
void binaryRecur(int[], int, int, int);
int firstOcc(int[], int, int, int);
int lastOcc(int[], int, int, int);
int mountainPeak(int[], int, int);
int pivotelement(int[], int, int);
int pivotindex(int[], int, int);
void searchinsortrot(int[], int, int);
long long int squareroot(long long int);
double precisionpart(int, int, int);

int main()
{
    // int t;
    // cin >> t;
    // int arr[t];
    // for (int i = 0; i < t; i++)
    // {
    //     cin >> arr[i];
    // }
    // int first = 0;
    // int last = t - 1;
    // int n;
    // cout << "Enter the number to be searched: " << endl;
    // cin >> n;
    // binaryIter(arr, first, last, n);
    // binaryRecur(arr, first, last, n);

    // cout << "Peak Element index: " << mountainPeak(arr, first, last) << endl;
    // sort(arr, arr + t);
    // for (int i = 0; i < t; i++)
    // {
    //     cout << arr[i] << endl;
    // }
    // cout << "First: " << firstOcc(arr, first, last, n) << endl;
    // cout << "Last: " << lastOcc(arr, first, last, n) << endl;
    // cout << "Total Occurence of " << n << ": "<< lastOcc(arr, first, last, n) - firstOcc(arr, first, last, n) + 1 << endl;


    // cout << "Pivot Element index: " << pivotelement(arr, first, last) << endl;
    // searchinsortrot(arr, n, t);


    long long int n1;
    cout << "Enter the number whose square root is to be found: " << endl;
    cin >> n1;
    int temp = squareroot(n1);
    int precision;
    cout << "Enter the precision of the answer: " << endl;
    cin >> precision;
    cout << "Square root of " << n1 << " is: " << precisionpart(n1, precision, temp) << endl;
}

void binaryIter(int arr[], int f, int l, int n)
{
    int flag = 0;
    while (f < l)
    {
        int mid = (f + l) / 2;
        if (arr[mid] == n)
        {
            cout << "Element found: " << arr[mid] << endl;
            flag = 1;
            break;
        }
        else if (arr[mid] > n)
        {
            l = mid - 1;
        }
        else if (arr[mid]<n)
        {
            f = mid + 1;
        }
    }
    if (flag == 0)
    {
        cout << "Element not found" << endl;
    }
}

void binaryRecur(int arr[], int f, int l, int n)
{
    int flag = 0;
    if (f < l)
    {
        int mid = (f + l) / 2;
        if (arr[mid] == n)
        {
            cout << "Element found: " << arr[mid] << endl;
            flag = 1;
        }
        else if (arr[mid] > n)
        {
            binaryRecur(arr, f, mid - 1, n);
        }
        else if (arr[mid] < n)
        {
            binaryRecur(arr, mid + 1, l, n);
        }
        else
        {
            cout << "Element not found" << endl;
        }
    }
}

int firstOcc(int arr[], int f, int l, int n){
    int ans = 0;
    while(f<=l){
        int mid = (f + l) / 2;
        if(arr[mid]== n){
            ans = mid;
            l = mid - 1;
        }
        else if(arr[mid]>n){
            l = mid - 1;
        } else if(arr[mid]<n){
            f = mid + 1;
        }
    }
    return ans;
}

int lastOcc(int arr[], int f, int l, int n){
    int ans = 0;
    while(f<=l){
        int mid = (f + l) / 2;
        if(arr[mid]== n){
            ans = mid;
            f = mid + 1;
        }
        else if(arr[mid]>n){
            l = mid - 1;
        } else if(arr[mid]<n){
            f = mid + 1;
        }
    }
    return ans;
}

int mountainPeak(int arr[], int f, int l){
    while(f<l){
        int mid = (f + l) / 2;
        if(arr[mid]<arr[mid+1]){
            f = mid + 1;
        }
        else{
            l = mid;
        }
    }
    return f;
}

int pivotelement(int arr[], int f, int l){
    // !!!!!!!!!
    // $ Either pivot is the element whose next element is smaller than it is or the element whose previous element is bigger than it is.
    // !!!!!!!!!
    while(f<l){
        int mid = (f + l) / 2;
        if(arr[mid]>=arr[0]) f = mid + 1;
        else l = mid;
    }
    return f;
}

int pivotindex(int arr[], int first, int last){
    // $ the element for which the sum of elements to the right and left is equal.

}

void searchinsortrot(int arr[], int n, int t){
    int f = 0;
    int l = t - 1;
    while(f<l){
        int mid = (f+l)/2;
        if(arr[mid]>=arr[0]){
            f = mid + 1;
        }
        else
            l = mid;
    }
    int pivot = f;
    cout << "pivot: " << pivot << endl;
    int fn = 0;
    int ln = t - 1;
    int flag = 0;
    if (arr[pivot] <= n && arr[ln] > n){
        while (pivot <= ln)
        {
            int mid = (pivot + ln) / 2;
            if (arr[mid] == n)
            {
                cout << "Element found: " << arr[mid] << endl;
                flag = 1;
                break;
            }
            else if (arr[mid] > n)
            {
                ln = mid - 1;
            }
            else if (arr[mid]<n)
            {
                pivot = mid + 1;
            }
        }
    }
    else
    {
        int nl = pivot - 1;
        while (fn <= nl)
        {
            int mid = (fn + nl) / 2;
            if (arr[mid] == n)
            {
                cout << "Element found: " << arr[mid] << endl;
                flag = 1;
                break;
            }
            else if (arr[mid] > n)
            {
                nl = mid - 1;
            }
            else if (arr[mid]< n)
            {
                fn = mid + 1;
            }
        }
    }
    if (flag == 0)
    {
        cout << "Element not found" << endl;
    }
}

long long int squareroot(long long int n1){
    int f = 0;
    int l = n1-1;
    long long int ans = 0;
    while (f<=l)
    {
        long long int mid = (f + l) / 2;
        long long int square = mid*mid;
        if(square == n1){
            return mid;
        } else if( square < n1 ){
            ans = mid;
            f = mid + 1;
        }
        else
            l = mid - 1;
    }
    if (n1 == 1)
        return 1;
    else
        return ans;
}

double precisionpart(int n1, int pr, int sol){
    double fac = 1;
    double ans1 = 0;
    for (int i = 0; i < pr; i++)
    {
        fac /= 10;
        for (double j = sol; j * j < n1; j += fac)
        {
            ans1 = j;
        }
    }
    return ans1;
}






// #include <bits/stdc++.h>
// using namespace std;

// string isSubset(int a1[], int a2[], int n, int m);

// int main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         int n, m;
//         cin >> n;
//         cin>> m;
//         int a1[n], a2[m];

//         for (int i = 0; i < n; i++)
//         {
//             cin >> a1[i];
//         }
//         for (int i = 0; i < m; i++)
//         {
//             cin >> a2[i];
//         }

//         cout << isSubset(a1, a2, n, m) << endl;
//     }
//     return 0;
// }
// string isSubset(int a1[], int a2[], int n, int m)
// {
//     sort(a1, a1 + n);
//     sort(a2, a2 + m);

//     int s1 = 0;
//     int e1 = n - 1;
//     int s2 = 0;
//     int e2 = m - 1;

//     if (m > n) return "No";

//     int f = 0;
//     while (s2 <= e2)
//     {
//         if (a1[s1] == a2[s2])
//         {
//             s1++;
//             s2++;
//         }
//         else if (a1[s1] < a2[s2])
//         {
//             s1++;
//         }
//         else if(a1[s1] > a2[s2])
//         {
//             f = 1;
//             return "No";
//         }
//     }
//     if(f==0) return "Yes";
// }
