#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

// $ Finding the Job Sequence to obtain the max profit while being in the deadline

struct Job{
    int id, dead, profit;
};

// $ Optimal Approach [sort the arr by max profit and select the max deadline to create temp arr -> use it to iterate over all the jobs and setting the]
// $ [max profit job at max deadline so that remaining jobs can be set at lower deadlines.]
// $ TC: O(n*logn + n*m) | SC: O(m)
class Solution{
public:
    bool static comparison(Job a, Job b){
        return (a.profit > b.profit);
    }

    pii JobScheduling(Job arr[], int n){
        sort(arr, arr + n, comparison);
        int maxi = arr[0].dead;
        for(int i = 1; i < n; i++) maxi = max(maxi, arr[i].dead);

        int tempArr[maxi + 1];
        for(int i = 0; i <= maxi; i++) tempArr[i] = -1;

        int count = 0, profit = 0;
        for(int i = 0; i < n; i++){
            for(int j = arr[i].dead; j > 0; j--){
                if(tempArr[j] == -1){
                    tempArr[j] = i;
                    count++;
                    profit += arr[i].profit;
                    break;
                }
            }
        }
        return make_pair(count, profit);
    }
};

int main() {
    int n = 4;
    Job arr[n] = {{1,4,20},{2,1,10},{3,2,40},{4,2,30}};

    Solution ob;
    pair < int, int > ans = ob.JobScheduling(arr, n);
    cout << ans.first << " " << ans.second << endl;
}