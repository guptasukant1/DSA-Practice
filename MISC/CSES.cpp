#include<bits/stdc++.h>
using namespace std;

// * Question 1: Consider an algorithm that takes as input a positive integer n. If n is even, the algorithm divides it by two, and if n is odd,
// * the algorithm multiplies it by three and adds one. The algorithm repeats this, until n is one. For example, the sequence for n=3 is as follows:
// * 3→10→5→16→8→4→2→1

// int weird(long long int n){
//     if( n == 1 ){
//         cout << n << " ";
//         return 0;
//     }
//     else{
//         cout << n << " ";
//         if(n%2 == 0 && n != 1){
//             n = n / 2;
//         }
//         else if(n%2 != 0 && n != 1){
//             n = ((n * 3) + 1);
//         }
//         weird(n);
//     }
//     return 0;
// }

// int main(){
//     long long int n;
//     cin >> n;
//     weird(n);
// }

// * You are given all numbers between 1,2,…,n except one. Your task is to find the missing number.

// int main(){
//     long long int n;
//     cin >> n;
//     long long int arr[n];
//     long long int sum = 0;
//     long long int sum1 = 0;
//     for(int i = 1; i<=n; i++){
//         sum = sum + i;
//     }
//     for(int i = 0; i < n - 1; i++){
//         cin >> arr[i];
//         sum1 = sum1 + arr[i];
//     }
//     long long int diff = sum - sum1;
//     cout << diff;
// }

// * You are given a DNA sequence: a string consisting of characters A, C, G, and T. Your task is to find the longest repetition in the sequence.
// * This is a maximum-length substring containing only one type of character.

// int main(){
//     string s;
//     cin >> s;
//     int temp = 1;
//     int max = 1;
//     for(int i = 0; i<s.length(); i++){
//         if(s[i] == s[i+1] && (i+1) < s.length()){
//             if( s[i+1] == '\0' ){
//                 temp--;
//             }
//             else temp++;
//         }
//         else if (s[i]!= s[i+1]){
//             if(temp > max){
//                 max = temp;
//             }
//             temp = 1;
//         }
//     }
//     cout << max;
// }

// * You are given an array of nn integers. You want to modify the array so that it is increasing, i.e., every element is at least as large as the previous element.
// * On each move, you may increase the value of any element by one. What is the minimum number of moves required?

// int main(){
//     long long int n;
//     cin >> n;
//     long long int arr[n];
//     for(int i = 0; i < n; i++){
//         cin >> arr[i];
//     }
//     long long int count = 0;
//     for(int i = 1; i < n ; i++){
//     for(int i = 0; i < n ; i++){
//             if (arr[i] < arr[i - 1])
//             if (arr[i] > arr[i + 1] && (i+1)<n)
//             {
//                 count = count + arr[i - 1] - arr[i];
//                 arr[i] = arr[i - 1];
//                 count = count + arr[i] - arr[i + 1];
//                 arr[i + 1] = arr[i];
//             }
//     }
//     cout << count;
// }

// * A permutation of integers 1,2,…,n1,2,…,n is called beautiful if there are no adjacent elements whose difference is 11.
// * Given nn, construct a beautiful permutation if such a permutation exists.

// int main()
// {
//     long long int n;
//     cin >> n;
//     if( n == 4 ){
//         cout << "2 4 1 3\n";
//     }
//     else if( n == 1 ){
//         cout << 1 << endl;
//     }
//     else if(n<4){
//         cout << "NO SOLUTION";
//     }
//     else{
//         for (long long int i = 1; i <= n; i += 2){
//             cout << i << " ";
//         }
//         for(long long int i = 2; i <= n ; i += 2){
//                 cout << i;
//                 if( i +2 <= n)
//                     cout << " ";
//                 else{
//                     cout << endl;
//                 }
//         }
//     }
// }

// *

