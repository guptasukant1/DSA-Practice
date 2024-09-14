#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

// $ BFS of Graph
// $ TC: O(n + 2e) | SC: O(3n) ~ O(n)
class Solution {
    public:
        vi bfsOfGraph(int V, vi adj[]){
            int vis[V] = {0};
            vis[0] = 1;
            queue<int> q; // * To maintain the list of nodes under consideration
            q.push(0);
            vi bfs; // * Result vi
            while(!q.empty()){
                int node = q.front();
                q.pop();
                bfs.push_back(node);
                for(auto it: adj[node]){
                    if(!vis[it]){
                        vis[it] = 1;
                        q.push(it);
                    }
                }
            }
            return bfs;
        }
};

void addEdge(vi adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vi &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

int main() {
    vi adj[6];    
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 4);

    Solution obj;
    vi ans = obj.bfsOfGraph(5, adj);
    printAns(ans);
}