/*

Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.


Example 1:


Input: root = [2,1,3]
Output: true
Example 2:


Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.

*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

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
    bool vaildBST(TreeNode *root)
    {
        return check(root, INT_MIN, INT_MAX);
        // TC O(N)
        // SC O(1)
    }
    bool check(TreeNode *root, int minv, int maxv)
    {
        if (!root)
            return true;
        if (root->val >= maxv || root->val <= minv)
            return false;
        return check(root->left, minv, root->val) && check(root->right, root->val, maxv);
    }
};

void printInOrder(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

int main()
{
    // Creating a BST
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(13);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(2);
    root->left->left->right = new TreeNode(4);
    root->left->right = new TreeNode(6);
    root->left->right->right = new TreeNode(9);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(14);

    cout << "Binary Search Tree: " << endl;
    printInOrder(root);
    cout << endl;

    Solution sol;

    // Searching for a value in the BST
    if (sol.vaildBST(root))
        cout << "Vaild ";
    else
        cout << "Not Vaild";

    return 0;
}
