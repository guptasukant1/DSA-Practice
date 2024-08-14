#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

// $ N meetings 1 Room [Use a struct of s, e, pos -> create array of struct and map the values from s, e, n then use comparator w.r.t the end times]
// $ [and select the meeting with > start time of meet than the previous end]
// $ TC: O(n + nlogn + n) | SC: O(n )
struct meeting{
    int start, end, pos;
};

class Solution{
public:
    bool static comparator(struct meeting m1, struct meeting m2){
        if(m1.end < m2.end) return true;
        else if(m1.end > m2.end) return false;
        else if(m1.pos < m2.pos) return true;
        return false;
    }

    void maxMeetings(int s[], int e[], int n){
        struct meeting meet[n];
        for(int i = 0; i < n; i++){
            meet[i].start = s[i], meet[i].end = e[i], meet[i].pos = i + 1;
        }
        sort(meet, meet + n, comparator);

        vi ans;
        int limit = meet[0].end;
        ans.push_back(meet[0].pos);

        for(int i = 1; i < n; i++){
            if(meet[i].start > limit){
                limit = meet[i].end;
                ans.push_back(meet[i].pos);
            }
        }
        
        cout << "Order: " << endl;
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i] << " ";
        }
    }
};


int main() {
   Solution obj;
   int n = 6;
   int start[] = {1,3,0,5,8,5};
   int end[] = {2,4,5,7,9,9};
   obj.maxMeetings(start, end, n);
   return 0;
}