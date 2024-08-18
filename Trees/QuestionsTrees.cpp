#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>

class node{
public:
    int data;
    node* left;
    node *right;
    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* BuildTree(node* root){
    cout << "Enter data for node: ";
    int data;
    cin >> data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = BuildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = BuildTree(root->right);
    return root;
}

// $ TC: O(n)
// $ SC: O(Height of tree)
int heightofTree(node* root){
    if(root == NULL){
        return 0;
    }
    int leftHeight = heightofTree(root->left);
    // $ Finds height of left subtree
    int rightHeight = heightofTree(root->right);
    // $ Finds height of right subtree
    return max(leftHeight, rightHeight) + 1;
}

// $ TC: O(n)
// $ SC: O(Height of tree)
pair<int, int> diameterFast(node* root){
    if(root == NULL){
        pair<int, int> p = make_pair(0,0);
        // $ First element of pair is diameter of tree and second element is height of tree
        return p;
    }

    pair<int, int> left = diameterFast(root->left);
    pair<int, int> right = diameterFast(root->right);

    // $ Diameter of left subtree
    int leftDiameter = left.first;
    // $ Diameter of right subtree
    int rightDiameter = right.first;
    // $ Diameter of current node using heights of left and right subtree
    int currDiameter = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max(currDiameter, max(leftDiameter, rightDiameter));
    ans.second = max(left.second, right.second) + 1;
    return ans;
}

// ! TC: O(n^2)
int diameterofTree(node* root){
    if(root == NULL){
        return 0;
    }
    // int leftHeight = heightofTree(root->left);
    // * Finds height of left subtree
    // int rightHeight = heightofTree(root->right);
    // * Finds height of right subtree
    // int currDiameter = leftHeight + rightHeight + 1;
    int currDiameter = heightofTree(root->left) + heightofTree(root->right) + 1;
    // * Diameter of current node
    int leftDiameter = diameterofTree(root->left);
    // * Diameter of left subtree
    int rightDiameter = diameterofTree(root->right);
    // * Diameter of right subtree
    return max(currDiameter, max(leftDiameter, rightDiameter));
    // $ return diameterFast(root).first;
}

// $ TC: O(n)
pair<int, int> isBalancedFast(node* root){
    if (root == NULL){
        // $ Firt element of pair is the status, whether the tree is balanced or not
        // $ and the second element is the height of the tree
        pair<int, int> p = make_pair(true, 0);
        return p;
    }

    // $ pair of left subtree to check whether balanced or not
    pair<int, int> left = isBalancedFast(root->left);
    // $ pair of right subtree to check whether balanced or not
    pair<int, int> right = isBalancedFast(root->right);

    // $ Status of left subtree
    bool leftAns = left.first;
    // $ Status of right subtree
    bool rightAns = right.first;
    // cout << "Status: " << leftAns << " " << rightAns << endl;
    // $ difference of height of left and right subtrees
    // cout << "Height: " << left.second << " " << right.second << endl;
    bool difference = abs(left.second - right.second) <= 1;

    pair<int, int> ans;
    ans.second = max(left.second, right.second) + 1;
    if (leftAns && rightAns && difference){
        ans.first = true;
    }
    else{
        ans.first = false;
    }
    return ans;
}

// ! TC: O(n^2)
bool balancedTree(node* root){
    if(root == NULL){
        return true;
    }
    bool left = balancedTree(root->left);
    bool right = balancedTree(root->right);

    bool difference = abs(heightofTree(root->left) - heightofTree(root->right)) <= 1;
    if(left && right && difference){
        return true;
    }else{
        return false;
    }
    // $ return isBalancedFast(root).first;
}

// $ TC: O(n)
int identicalTrees(node* root1, node* root2){
    if(root1 == NULL && root2 == NULL){
        return 1;
    }
    if(root1 == NULL || root2 == NULL){
        return 0;
    }
    if(root1->data == root2->data){
        int left = identicalTrees(root1->left, root2->left);
        int right = identicalTrees(root1->right, root2->right);
        if(left && right){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        return 0;
    }
}

// $ TC: O(n)
pair<bool, int> isSumTreeFast(node* root){
    if(root == NULL){
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    if(root->left == NULL && root->right == NULL){
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> left = isSumTreeFast(root->left);
    pair<bool, int> right = isSumTreeFast(root->right);

    bool isLeftSumTree = left.first;
    bool isRightSumTree = right.first;

    bool condition = (root->data == left.second + right.second);

    pair < bool, int> ans;
    if (isLeftSumTree && isRightSumTree && condition){
        ans.first = true;
        // ans.second = root->data + left.second + right.second;
        ans.second = 2*root->data;
    }
    else{
        ans.first = false;
        ans.second = 0;
    }
    return ans;
}

bool isSumTree(node* root){
    return isSumTreeFast(root).first;
}

// $ Spiral Traversal of a tree
// | Here, the tree needs to be printed in a spiral order.
// | All the nodes present at a level are to be printed in one direction.
// | The nodes for the next level are printed in the opposite direction.

// $ TC: O(n)
// $ SC: O(n)
vector<int> spiralTraversal(node* root){
    vector<int> result;
    if(root == NULL){
        return result;
    }
    queue<node* > q;
    q.push(root);
    bool = leftToRight = false;

    while(!q.empty()){
        int size = q.size();
        // $ Done to store the elements and determine whether the elements are being added
        // $ in left to right or right to left
        vector<int> ans(size);

        // $ Process Each level
        for(int i = 0; i<size; i++){
            node *frontNode = q.front();
            q.pop();
            // $ Normal Insert or Reverse insert
            int index = leftToRight ? i : (size - i - 1);
            ans[index] = frontNode->data;

            if(frontNode->left){
                q.push(frontNode->left);
            }
            if(frontNode->right){
                q.push(frontNode->right);
            }
        }
        // $ Reverse the Direction
        leftToRight = !leftToRight;
        for(auto i: ans){
            result.push_back(i);
        }
    }
    return result;
}

void LeftTraversal(node* root, vector<int> &ans){
    if(root == NULL || (root->left == NULL && root->right == NULL)){
        return;
    }

    ans.push_back(root->data);

    if(root->left){
        LeftTraversal(root->left, ans);
    }
    else{
        LeftTraversal(root->right, ans);
    }
}

void LeafTraversal(node* root, vector<int> &ans){
    if (root == NULL ){
        return;
    }

    if (root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
        return;
    }
    LeafTraversal(root->left, ans);
    LeafTraversal(root->right, ans);
}

void RightTraversal(node* root, ans){
    if(root == NULL || (root->left == NULL && root->right == NULL)){
        return;
    }
    if(root->right){
        RightTraversal(root->right, ans);
    }
    else{
        RightTraversal(root->left, ans);
    }
    ans.push_back(root->data);

}

vector<int> boundaryTraversal(node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    ans.push_back(root->data);

    // $ Finding the left boundary
    LeftTraversal(root->left, ans);

    // $ Finding the leaf nodes
    // * Left subtree
    LeafTraversal(root->left, ans);
    // * Right subtree
    LeafTraversal(root->right, ans);

    // $ Finding the right boundary
    RightTraversal(root->right, ans);
    return ans;
}

vector<int> verticalOrder(node* root){
    map<int, map<int, vector<int>>> nodes;
    // $ map of horizontal distance and map of level and vector of nodes of that level
    queue<pair<node *, pair<int, int>>> q;
    // $ queue of node and pair of horizontal distance and level to store the nodes
    vector<int> ans;

    if(root == NULL){
        return ans;
    }

    q.push(make_pair(root, make_pair(0, 0)));

    while(!q.empty()){
        pair<node *, pair<int, int>> temp = q.front();
        q.pop();
        node* frontNode = temp.first;
        int horizontalDistance = temp.second.first;
        int level = temp.second.second;

        nodes[horizontalDistance][level].push_back(frontNode->data);

        if(frontNode->left){
            q.push(make_pair(frontNode->left, make_pair(horizontalDistance - 1, level + 1)));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right, make_pair(horizontalDistance + 1, level + 1)));
        }
    }

    for(auto i: nodes){
        // $ i.first is the horizontal distance
        // $ i.second is the map of level and vector of nodes
        for(auto j: i.second){
            // $ j.first is the level
            // $ j.second is the vector of nodes
            for(auto k: j.second){
                ans.push_back(k);
            }
        }
    }
    return ans;
}

vector<int> topView(node* root){
    vector<int> ans;
    if(!root){
        return ans;
    }
    map<int, int> topNode;
    // $ map of horizontal distance and node data
    queue<pair<node *, int>> q;
    // $ queue of node under consideration and horizontal distance to store the nodes
    q.push(make_pair(root, 0));

    while(!q.empty()){
        pair<node*, int> temp = q.front();
        q.pop();
        node* frontNode = temp.first;
        int horizontalDistance = temp.second;
        // $ if a value of horizontal distance is present in the map, then new value is not inserted
        if(topNode.find(horizontalDistance) == topNode.end()){
            topNode[horizontalDistance] = frontNode->data;
        }

        if(frontNode->left){
            q.push(make_pair(frontNode->left, horizontalDistance - 1));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right, horizontalDistance + 1));
        }

    }
    for(auto i: topNode){
        ans.push_back(i.second);
    }
    return ans;
}

vector<int> bottomView(node* root){
    vector<int> ans;
    if(!root){
        return ans;
    }
    map<int, int> topNode;
    // $ map of horizontal distance and node data
    queue<pair<node *, int>> q;
    // $ queue of node and horizontal distance to store the nodes
    q.push(make_pair(root, 0));

    while(!q.empty()){
        pair<node*, int> temp = q.front();
        q.pop();
        node* frontNode = temp.first;
        int horizontalDistance = temp.second;

        topNode[horizontalDistance] = frontNode->data;

        if(frontNode->left){
            q.push(make_pair(frontNode->left, horizontalDistance - 1));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right, horizontalDistance + 1));
        }

    }
    for(auto i: topNode){
        ans.push_back(i.second);
    }
    return ans;
}

void solve(node* root, vector<int> &ans, int level){
    if(root == NULL){
        return;
    }

    // $ If the level is equal to the size of the vector, then the node is the first node of that level
    if(level == ans.size()){
        ans.push_back(root->data);
    }

    solve(root->left, ans, level + 1);
    solve(root->right, ans, level + 1);
}

vector<int> leftView(node* root){
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}

void solveRight(node* root, vector<int> &ans, int level){
    if(root == NULL){
        return;
    }

    // $ If the level is equal to the size of the vector, then the node is the first node of that level
    if(level == ans.size()){
        ans.push_back(root->data);
    }

    solveRight(root->right, ans, level + 1);
    solveRight(root->left, ans, level + 1);
}

vector<int> rightView(node* root){
    vector<int> ans;
    solveRight(root, ans, 0);
    return ans;
}

void solveSumLongest(node* root, int sum, int &maxSum, int len, int &max){
    if(root == NULL){
        if(len > max){
            max = len;
            maxSum = sum;
        }
        else if(len == max){
            maxSum = max(sum, maxSum);
        }
        return;
    }

    sum = sum + root->data;
    solveSumLongest(root->left, sum, maxSum, len + 1, max);
    solveSumLongest(root->right, sum, maxSum, len + 1, max);

}

int sumOfLongRootToLeafPath(node* root){
    int len = 0;
    int max = 0;
    int sum = 0;
    int maxSum = INT_MIN;

    solveSumLongest(root, sum, maxSum, len, max);
    return maxSum;
}


node* lca(node* root, int n1, int n2){
    if(root == NULL){
        return NULL;
    }
    if(root->data == n1 || root->data == n2){
        return root;
    }
    node *left = lca(root->left, n1, n2);
    node *right = lca(root->right, n1, n2);

    if(left && right){
        return root;
    }
    else if(left){
        return left;
    }
    else if(right){
        return right;
    }
    else{
        return NULL;
    }
}

// ! TLE
// void solve(Node* root, int k, vector<int> &path, int sum, int &count){
//     if(!root){
//         return;
//     }
//     sum +=root->data;
//     path.push_back(root->data);
//     int newSum = 0;
//     for(int i = path.size() - 1; i >= 0; i--){
//         newSum += path[i];
//         if(newSum == k) count++;
//     }
//     solve(root->left, k, path, sum, count);
//     solve(root->right, k, path, sum, count);
//     path.pop_back();
// }
// int sumK(Node *root, int k){
//     vector<int> path;
//     int count = 0;
//     int sum = 0;
//     solve(root, k, path, sum, count);
//     return count;
// }

// $ WITHIN LIMITS
void solve(Node* root, int k, unordered_map<int, int> &mp, int sum, int &count){
    if(!root){
        return;
    }
    sum +=root->data;
    if(mp.count(sum - k)){
        count += mp[sum - k];
    }
    if(sum == k) count++;
    mp[sum]++;

    solve(root->left, k, mp, sum, count);
    solve(root->right, k, mp, sum, count);
    mp[sum]--;
    sum-=root->data;
}

int sumK(Node *root, int k){
    // $ map to store the sum and the number of times it has occured
    unordered_map<int, int> mp;
    int count = 0;
    int sum = 0;
    solve(root, k, mp, sum, count);
    return count;
}

// $ TC: O(n)
// $ SC: O(H)
node* solveKAncestor(node* root, int &k, int node){
    if(!root){
        return NULL;
    }
    if(root->data == node){
        return root;
    }
    node *leftAns = solveKAncestor(root->left, k, node);
    node *rightAns = solveKAncestor(root->right, k, node);

    if(leftAns){
        k--;
        if(k <= 0){
            k = INT_MAX;
            // $ To stop the recursion
            return root;
        }
        return leftAns;
    }
    if(rightAns){
        k--;
        if (k <= 0){
            k = INT_MAX;
            // $ To stop the recursion
            return root;
        }
        return rightAns;
    }
    return NULL;
}

int kthAncestor(node* root, int k, int node){
    node* ans = solveKAncestor(root, k, node);
    if(ans == NULL || ans->data == node){
        // $ If the node is not present or the node is the root node
        // !! Edge Case (1 < k <= 100)
        return - 1;
    }
    else{
        return ans->data;
    }
}


// $ Maximum sum of non adjacent nodes
// | To find the maximum sum we can either inlude the elements of a level or exclude the elements of a level
// | If we include the elements of a level, then we cannot include the elements of the next level
// | We can use a pair to store the maximum sum of including and excluding the elements of a level
pair<int, int> solveMaxSum(node *root){
    if(root == NULL){
        pi p = make_pair(0, 0);
        return p;
    }

    pi left = solveMaxSum(root->left);
    pi right = solveMaxSum(root->right);

    pi res;
    res.first = root->data + left.second + right.second;
    res.second = max(left.first, left.second) + max(right.first, right.second);

    return res;
}

int getMaxSum(node* root){
    pair<int, int> ans = solveMaxSum(root);
    return max(ans.first, ans.second);
}




int main(){
    // ! 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    node *root = NULL;
    root = BuildTree(root);
    cout << "Height of tree is: " << heightofTree(root) << endl;
    cout << "Balanced tree: " << isBalancedFast(root).first << endl;
    cout << "Is the tree a sum tree: " << isSumTree(root) << endl;
}