#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

// $ DFS of Graph
// $ TC: O(n + 2e) | SC: O(3n) ~ O(n)
class Solution{

    void dfs(int node, vi adj[], int vis[], vi &ls){
        vis[node] = 1;
        ls.push_back(node);
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis, ls);
            }
        }
    }
    public:
        vi dfsOfGraph(int V, vi adj[]){
            int vis[V] = {0};
            int start = 0;
            vi ls;
            dfs(start, adj, vis, ls);
            return ls;
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
    vi adj[5];
    
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);

    Solution obj;
    vi ans = obj.dfsOfGraph(5, adj);
    printAns(ans);

    return 0;
}