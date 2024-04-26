#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

// $ Find next lexicographically greater permutation naive approach
// todo | Find all permutations and sort them and return the next permutation

// $ Find next lexicographically greater permutation better approach
vi nextPerm(vi &A)
{
    next_permutation(A.begin(), A.end());
    return A;
}

// $ Find next lexicographically greater permutation optimal approach
vi nextGreater(vi &A)
{
    int n = A.size();
    int index = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (A[i] < A[i + 1])
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        reverse(A.begin(), A.end());
        return A;
    }
    for (int i = n - 1; i > index; i--)
    {
        if (A[i] > A[index])
        {
            swap(A[i], A[index]);
            break;
        }
    }
    reverse(A.begin(), A.end());
    return A;
}

int main(){
    vi A = {1, 2, 3, 4};
    vi newA = {5, 4, 9, 7};
    vi B = nextPerm(A);
    vi C = nextGreater(newA);
    for(auto x: B) cout << x << " ";
    cout << endl;
    for (auto x : C)
        cout << x << " ";
}