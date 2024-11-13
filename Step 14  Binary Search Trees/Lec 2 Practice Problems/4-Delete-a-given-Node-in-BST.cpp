/*

Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.


Example 1:


Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

Example 2:

Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
Explanation: The tree does not contain a node with value = 0.
Example 3:

Input: root = [], key = 0
Output: []

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
    TreeNode *deleteFromBST(TreeNode *root, int val)
    {
        if (root == nullptr)
            return root;

        TreeNode *cur = root;
        while (cur)
        {
            if (cur->val > val)
            {
                if (cur->left != nullptr && cur->left->val == val)
                {
                    cur->left = helper(cur->left);
                    break;
                }
                else
                {
                    cur = cur->left;
                }
            }
            else
            {
                if (cur->right != nullptr && cur->right->val == val)
                {
                    cur->right = helper(cur->right);
                    break;
                }
                else
                {
                    cur = cur->right;
                }
            }
        }
        return root;
        // TC O(Height of tree)
        // SC O(1)
    }

    TreeNode *helper(TreeNode *root)
    {
        if (root->left == nullptr)
            return root->right;
        else if (root->right == nullptr)
            return root->left;

        TreeNode *rightside = root->right;
        TreeNode *lastRight = findLastRight(root->left);
        lastRight->right = rightside;
        return root->left;
    }
    TreeNode *findLastRight(TreeNode *root)
    {
        if (root->right == nullptr)
            return root;

        return findLastRight(root->right);
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

    printInOrder(sol.deleteFromBST(root, 14));

    return 0;
}