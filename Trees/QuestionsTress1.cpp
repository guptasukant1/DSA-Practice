#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node* right;
    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root){
    cout << "Enter the data of the node: ";
    int data;
    cin >> data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }
    cout << "Input for left child of " << data << " : ";
    root->left = buildTree(root->left);
    cout << "Input for right child of " << data << " : ";
    root->right = buildTree(root->right);
    return root;
}

// $ TC: O(n^2) -> O(nlogn)
// $ Construct a tree from inorder and preorder
// | Find the root from the preorder and then find the left and right subtree from the inorder
// | Then recursively call the function for left and right subtree
// | The position
int findPosition(int in[], int element, int n){
    for(int i = 0; i < n; i++){
        if(in[i] == element) return i;
    }
    return -1;
}
void createMapping(int in[], map<int, vector<int>> &nodeToIndex, int n)
{
    for(int i = 0; i < n; i++){
        // nodeToIndex[in[i]] = i;
        // ! This will not work in case of repeating values in the in[] array.
        // $ To handle this, we can store the indices of each element in a vector.
        nodeToIndex[in[i]].push_back(i);
    }
}
node *solveInPre(int in[], int pre[], int &preOrderIndex, int InorderStart, int InorderEnd, int n, map<int, vector<int>> &nodeToIndex)
{
    if (preOrderIndex >= n || InorderStart > InorderEnd)
        return NULL;

    // $ Create a root node from the preorder. The preOrderIndex is updated after the root is created
    int element = pre[preOrderIndex++];
    node *root = new node(element);
    // ! Find the position of the element in the inorder
    // int position = findPosition(in, element, n);
    // * To avoid calling the findPosition function again, we can use a map to store the position of the elements in the inorder
    vector<int> position = nodeToIndex[element];
    int i;
    // $ loop through the positions to find the position in the range of the inorder subtree
    // $ If a match is found, break the loop and use the index to find the left and right subtree
    for (i = 0; i < n; i++)
    {
        if (position[i] >= InorderStart && position[i] <= InorderEnd)
            break;
    }

    // $ Find the left and right subtree
    // $ The position[i]th element will make sure that the tree is made by using the correct index of the given element.
    root->left = solveInPre(in, pre, preOrderIndex, InorderStart, position[i] - 1, n, nodeToIndex);
    root->right = solveInPre(in, pre, preOrderIndex, position[i] + 1, InorderEnd, n, nodeToIndex);

    return root;
}
node* buildTreeFromInPre(int in[], int pre[], int n){
    int preOrderIndex = 0;
    map<int, vector<int>> nodeToIndex;
    // $ Create a mapping of the elements in the inorder with the values as a vector of vertices
    createMapping(in, nodeToIndex, n);
    node* ans = solveInPre(in, pre, preOrderIndex, 0, n -1, n, nodeToIndex);
    return ans;
}

// $ TC: O(nlogn)
// $ Construct a tree from inorder and postorder
void createMapping1(int in[], map<int, vector<int>> nodeToIndex, int n)
{
    for (int i = 0; i < n; i++)
    {
        nodeToIndex[in[i]].push_back(i);
    }
}
node *solveInPost(int in[], int post[], int &postOrderIndex, int InorderStart, int InorderEnd, int n, map<int, vector<int>> &nodeToIndex)
{
    if (postOrderIndex < 0 || InorderStart > InorderEnd)
        return NULL;

    int element = post[postOrderIndex--];
    node *root = new node(element);
    vector<int> position = nodeToIndex[element];
    int i;
    for (i = 0; i < n; i++)
    {
        if (position[i] >= InorderStart && position[i] <= InorderEnd)
            break;
    }
    root->right = solveInPost(in, post, postOrderIndex, position[i] + 1, InorderEnd, n, nodeToIndex);
    root->left = solveInPost(in, post, postOrderIndex, InorderStart, position[i] - 1, n, nodeToIndex);
    return root;
}
node *buildTreeFromInPost(int in[], int post[], int n)
{
    int postOrderIndex = 0;
    map<int, vector<int>> nodeToIndex;
    createMapping1(in, nodeToIndex, n);
    node *ans = solveInPost(in, post, postOrderIndex, n - 1, 0, n, nodeToIndex);
    return ans;
}

// $ Burning a binary tree
// $ TC: O(n)
// $ SC: O(n) + O(n)
// | Given a binary tree and a target node, the task is to find the minimum time required to burn the complete binary tree if the target node is set on fire.
// * createParentMapping is used to create a mapping of the nodes with their parent nodes and also returns the target node.
node *createParentMapping(node *root, int target, map<node *, node *> &nodeToParent)
{
    node *result = NULL;
    queue<node *> q;
    q.push(root);
    nodeToParent[root] = NULL;

    while (!q.empty())
    {
        node *front = q.front();
        q.pop();

        if (front->data == target)
            result = front;
        if (front->left)
        {
            nodeToParent[front->left] = front;
            q.push(front->left);
        }
        if (front->right)
        {
            nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }
    return result;
}
// * burnTree is used to find the minimum time required to burn the complete binary tree if the target node is set on fire.
int burnTree(node *root, map<node *, node *> nodeToParent)
{
    map<node *, bool> visited;
    queue<node *> q;
    q.push(root);
    visited[root] = true;

    int ans = 0;

    while (!q.empty())
    {
        bool flag = 0;

        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            node *front = q.front();
            q.pop();
            if (front->left && !visited[front->left])
            {
                flag = 1;
                q.push(front->left);
                visited[front->left] = true;
            }
            if (front->right && !visited[front->right])
            {
                flag = 1;
                q.push(front->right);
                visited[front->right] = true;
            }
            if (nodeToParent[front] && !visited[nodeToParent[front]])
            {
                flag = 1;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = true;
            }
            if (flag)
                ans++;
        }
    }
    return ans;
}
int minTime(node *root, int target)
{
    map<node *, node *> nodeToParent;
    node *targetNode = createParentMapping(root, target, nodeToParent);

    int ans = burnTree(targetNode, nodeToParent);
    return ans;
}













// $ Morris Traversal
// | Morris Traversal is used to traverse the tree without using any extra space.
// | The idea is to use the right pointer of the predecessor to store the current node.


int main(){
    node* root = NULL;
    root = buildTree(root);
}
