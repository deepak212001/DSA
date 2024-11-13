/*
Given a binary tree having n nodes. Check whether all of its nodes have the value equal to the sum of their child nodes. Return 1 if all the nodes in the tree satisfy the given properties, else it return 0.

For every node, data value must be equal to the sum of data values in left and right children. Consider data value as 0 for NULL child.  Also, leaves are considered to follow the property.

Example 1:

Input:
Binary tree
       35
      /   \
     20    15
    /  \  /  \
   15  5 10   5
Output:
1
Explanation:
Here, every node is sum of its left and right child.
Example 2:

Input:
Binary tree
       1
     /   \
    4    3
   /
  5
Output:
0
Explanation:
Here, 1 is the root node and 4, 3 are its child nodes. 4 + 3 = 7 which is not equal to the value of root node. Hence, this tree does not satisfy the given condition.

*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

// TreeNode structure
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    void changeTree(TreeNode *root)
    {
        if (root == NULL)
            return;

        int child = 0;
        if (root->left)
            child += root->left->val;
        if (root->right)
            child += root->right->val;

        if (child >= root->val)
            root->val = child;
        else
        {

            if (root->left)
            {
                root->left->val = root->val;
            }
            else if (root->right)
            {
                root->right->val = root->val;
            }
        }

        changeTree(root->left);
        changeTree(root->right);

        int tot = 0;
        if (root->left)
            tot += root->left->val;
        if (root->right)
            tot += root->right->val;

        if (root->left || root->right)
            root->val = tot;
            
    }
    // TC O(N)
    // SC O(N)
};

// Function to print the inorder
// traversal of the tree
void inorderTraversal(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main()
{
    // Create the binary tree
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution sol;

    // Print the inorder traversal
    // of tree before modification
    cout << "Binary Tree before modification: ";
    inorderTraversal(root);
    cout << endl;

    // Call the changeTree function
    // to modify the binary tree
    sol.changeTree(root);

    // Print the inorder traversal
    // after modification
    cout << "Binary Tree after Children Sum Property: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
