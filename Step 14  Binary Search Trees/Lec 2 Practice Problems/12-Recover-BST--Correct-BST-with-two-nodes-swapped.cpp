/*

You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.



Example 1:


Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
Example 2:


Input: root = [3,1,4,null,null,2]
Output: [2,1,4,null,null,3]
Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.

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
    TreeNode *first, *middle, *last, *prev;

public:
    void inorder(TreeNode *root)
    {
        if (!root)
            return;

        inorder(root->left);

        if (prev && root->val < prev->val)
        {
            if (!first)
            {
                first = prev;
                middle = root;
            }
            else
                last = root;
        }

        prev = root;
        inorder(root->right);
    }
    
    void recover(TreeNode *root)
    {
        first = middle = last = nullptr;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if (first && last)
            swap(first->val, last->val);
        else
            swap(first->val, middle->val);

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
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);

    cout << "Binary Search Tree: " << endl;
    printInOrder(root);
    cout << endl;

    Solution sol;
    sol.recover(root);
    printInOrder(root);

    return 0;
}
