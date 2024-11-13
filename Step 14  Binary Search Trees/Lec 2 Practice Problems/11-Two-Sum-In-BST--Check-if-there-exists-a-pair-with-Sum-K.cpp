/*

Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.



Example 1:

Input: root = [5,3,6,2,4,null,7], k = 9
Output: true



Example 2:

Input: root = [5,3,6,2,4,null,7], k = 28
Output: false

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
    void getInorder(TreeNode *root, vector<int> &inorder)
    {
        if (!root)
            return;

        getInorder(root->left, inorder);
        inorder.push_back(root->val);
        getInorder(root->right, inorder);
    }
    bool BruteForce(TreeNode *root, int target)
    {
        vector<int> inorder;
        getInorder(root, inorder);
        int i = 0;
        int j = inorder.size();
        while (i < j)
        {
            int sum = inorder[i] + inorder[j];
            if (sum == target)
                return true;
            if (sum > target)
                j--;
            else
                i++;
        }

        return false;
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
// Inorder of bst is always sorted

int main()
{
    // Creating a BST
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    cout << "Binary Search Tree: " << endl;
    printInOrder(root);
    cout << endl;

    Solution sol;

    // Searching for a value in the BST
    if (sol.BruteForce(root, 10))
        cout << "True" << endl;
    else
        cout << "False" << endl;
    return 0;
}
