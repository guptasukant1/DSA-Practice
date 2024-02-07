// Test case 1: Empty tree
node* root1 = NULL;
pair<int, int> result1 = solveMaxSum(root1);
assert(result1.first == 0);
assert(result1.second == 0);

// Test case 2: Tree with a single node
node* root2 = new node(5);
pair<int, int> result2 = solveMaxSum(root2);
assert(result2.first == 5);
assert(result2.second == 0);

// Test case 3: Tree with multiple nodes
node* root3 = new node(1);
root3->left = new node(2);
root3->right = new node(3);
root3->left->left = new node(4);
root3->left->right = new node(5);
root3->right->left = new node(6);
root3->right->right = new node(7);
pair<int, int> result3 = solveMaxSum(root3);
assert(result3.first == 28);
assert(result3.second == 16);

// Test case 4: Tree with negative values
node* root4 = new node(-1);
root4->left = new node(-2);
root4->right = new node(-3);
root4->left->left = new node(-4);
root4->left->right = new node(-5);
root4->right->left = new node(-6);
root4->right->right = new node(-7);
pair<int, int> result4 = solveMaxSum(root4);
assert(result4.first == -4);
assert(result4.second == -2);

// Test case 5: Tree with only left children
node* root5 = new node(1);
root5->left = new node(2);
root5->left->left = new node(3);
root5->left->left->left = new node(4);
pair<int, int> result5 = solveMaxSum(root5);
assert(result5.first == 10);
assert(result5.second == 6);

// Test case 6: Tree with only right children
node* root6 = new node(1);
root6->right = new node(2);
root6->right->right = new node(3);
root6->right->right->right = new node(4);
pair<int, int> result6 = solveMaxSum(root6);
assert(result6.first == 10);
assert(result6.second == 6);

// Clean up the memory
delete root2;
delete root3;
delete root4;
delete root5;
delete root6;