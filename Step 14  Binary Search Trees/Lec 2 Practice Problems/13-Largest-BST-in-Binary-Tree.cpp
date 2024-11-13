/*

Given a binary tree. Find the size of its largest subtree which is a Binary Search Tree.
Note: Here Size equals the number of nodes in the subtree.

Examples :

Input:   1
        /  \
        4   4
       / \
      6   8
Output: 1
Explanation: There's no sub-tree with size greater than 1 which forms a BST. All the leaf Nodes are the BSTs with size equal to 1.

Input:    6
        /   \
      6      2
       \    / \
        2  1   3
Output: 3
Explanation: The following sub-tree is a BST of size 3:  2
                                                       /   \
                                                      1     3

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

class NodeValue
{
public:
    int maxNode, minNode, maxSize;
    NodeValue(int minN, int maxN, int maxS)
    {
        maxNode = maxN;
        minNode = minN;
        maxSize = maxS;
    }
};

class Solution
{
    NodeValue largestBSTSubtreeHelper(TreeNode *root)
    {
        if (!root)
        {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }
        auto left = largestBSTSubtreeHelper(root->left);
        auto right = largestBSTSubtreeHelper(root->right);
        if (left.maxNode < root->val && root->val < right.minNode)
        {
            return NodeValue(min(root->val, left.minNode), max(root->val, right.maxNode), left.maxSize + right.maxSize + 1);
        }
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }

public:
    int largestBSTSubtree(TreeNode *root)
    {
        return largestBSTSubtreeHelper(root).maxSize;
        // TC O(N)
        // SC O(1)
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

    cout << sol.largestBSTSubtree(root);

    return 0;
}
