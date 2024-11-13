/*
There is BST given with the root node with the key part as an integer only. You need to find the in-order successor and predecessor of a given key. If either predecessor or successor is not found, then set it to NULL.

Note:- In an inorder traversal the number just smaller than the target is the predecessor and the number just greater than the target is the successor.

Example 1:

Input:
      8
    /   \
   1     9
    \     \
     4    10
    /
   3
key = 8
Output: 4 9
Explanation:
In the given BST the inorder predecessor of 8 is 4 and inorder successor of 8 is 9.
Example 2:

Input:
        10
      /   \
     2    11
   /  \
  1    5
      /  \
     3    6
      \
       4
key = 11
Output: 10 -1
Explanation:In given BST, the inorder predecessor of 11 is 10 whereas it does not have any inorder successor.
Your Task: You don't need to print anything. You need to update pre with the predecessor of the key or NULL if the predecessor doesn't exist and succ to the successor of the key or NULL if the successor doesn't exist. pre and succ are passed as an argument to the function findPreSuc(). Please note, The key may be located either inside or outside the tree.

*/

#include <bits/stdc++.h>
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
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p)
    {
        TreeNode *successor = nullptr;
        while (root)
        {
            if (p->val >= root->val)
                root = root->right;
            else
            {
                successor = root;
                root = root->left;
            }
        }
        return successor;
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
    TreeNode *ans = sol.inorderSuccessor(root, root->left->left);
    cout << ans->val;

    return 0;
}
