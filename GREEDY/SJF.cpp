#include<bits/stdc++.h>
using namespace std;

// $ Shortest Job First CPU Scheduling: List of job durations showing time it takes to complete each job. Implement SJF algo to find the average waiting time for these jobs.
// $ TC: O(nlogn + n) | SC: O(1)
float shortestJobFirst(vector<int> &jobs){
    sort(jobs.begin(), jobs.end());
    float waitT = 0;
    float totalT = 0;
    for(int i = 0; i < jobs.size(); i++) {
        waitT += totalT;
        totalT += jobs[i];
    }
    return waitT / jobs.size();
}

int main() {
    vector<int> jobs = {4, 3, 7, 1, 2};

    cout << "Array Representing Job Durations: ";
    for(int i = 0; i < jobs.size(); i++){
        cout << jobs[i] << " ";
    }
    cout << endl;

    float ans = shortestJobFirst(jobs);
    cout << "Average waiting time: "<< ans;
    cout << endl;
}