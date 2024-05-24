#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int, int>
#define vpii vector<pair<int, int>>
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define MOD 1000000007
#define INF 1e9
#define N 100000
#define deb(x) cout << #x << " " << x << endl;
#define print(v) for(auto x: v) cout << x << " "; cout << endl;



// $ N meetings in one room
// $ Given N meetings with their start and end time, we have to find the maximum number of meetings that can be held in one room.

struct meeting{
    int start, end, pos;
};

// bool comparator(meeting m1, meeting m2){
//     return m1.end < m2.end;
// }

// void maxMeetings(int start[], int end[], int n){
//     meeting meet[n];
//     for(int i=0; i<n; i++){
//         meet[i].start = start[i];
//         meet[i].end = end[i];
//         meet[i].pos = i+1;
//     }

//     sort(meet, meet+n, comparator);

//     vi ans;
//     int limit = meet[0].end;
//     ans.pb(meet[0].pos);

//     for(int i=1; i<n; i++){
//         if(meet[i].start > limit){
//             limit = meet[i].end;
//             ans.pb(meet[i].pos);
//         }
//     }

//     print(ans);
// }


class Solution{
    public:
        bool static comparator(struct meeting m1, meeting m2){
            if(m1.end < m2.end) return true;
            else if(m1.end > m2.end) return false;
            else if(m1.pos < m2.pos) return true;
            return false;
        }
        void maxMeetings(int start[], int end[], int n){
            struct meeting meet[n];
            for (int i = 0; i < n; i++)
            {
                meet[i].start = start[i], meet[i].end = end[i], meet[i].pos = i + 1;
            }
            sort(meet, meet + n, comparator);

        }
};



int main(){

}
