#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>

// $ Vertical Order Traversal of BT
// $ TC: O(n + log(2n) + log(2n)*log(2n)) | SC: O(n + n/2[max nodes per level])
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution{
    public:
    vvi findVertical(Node* root){
        map<int, map<int, multiset<int>>> nodes; // * Store nodes and (vertical, horizontal) info -> vertical: [horizontal: set of nodes] [The elems per vertical level]
        queue<pair<Node*, pair<int, int>>> bfs; // * BFS Traversal queue to store node & (vertical, horizontal) info

        bfs.push({root, {0, 0}});
        while(!bfs.empty()){
            // * Detructure bfs elem
            auto p = bfs.front();
            bfs.pop();
            Node* temp = p.first;
            int x = p.second.first; // * vertical
            int y = p.second.second; // * horizontal
            
            // * Push into map the data
            nodes[x][y].insert(temp -> data);
            if(temp -> left) bfs.push({temp -> left, {x - 1, y + 1}});
            if(temp -> right) bfs.push({temp -> right, {x + 1, y + 1}});
        }
        vvi ans;
        for(auto p: nodes){
            vi col;
            for(auto q: p.second) col.insert(col.end(), q.second.begin(), q.second.end());
            ans.push_back(col);
        }
        return ans;
    }
};

void printResult(const vvi &result) {
    for(auto level: result){
        for(auto node: level){
            cout << node << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(10);
    root->right->left = new Node(9);

    Solution solution;

    vvi verticalTraversal = solution.findVertical(root);

    cout << "Vertical Traversal: ";
    printResult(verticalTraversal);
}