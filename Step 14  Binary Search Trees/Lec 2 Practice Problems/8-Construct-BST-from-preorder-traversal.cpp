/*
Given an array arr[] of N nodes representing preorder traversal of some BST. You have to build the BST  from the given preorder traversal.

In Pre-Order traversal, the root node is visited before the left child and right child nodes.


Input: preorder = [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]
Example 2:

Input: preorder = [1,3]
Output: [1,null,3]


Example 1:

Input:
N = 5
arr[]  = {40,30,35,80,100}
Output: 35 30 100 80 40
Explanation: PreOrder: 40 30 35 80 100
Therefore, the BST will be:
              40
           /      \
         30       80
           \        \
           35      100
Hence, the postOrder traversal will
be: 35 30 100 80 40
Example 2:

Input:
N = 8
arr[]  = {40,30,32,35,80,90,100,120}
Output: 35 32 30 120 100 90 80 40
Your Task:
You need to complete the given function and return the root of the tree. The driver code will then use this root to print the post order traversal.

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
    TreeNode *b(vector<int> a)
    {
        TreeNode *root = new TreeNode(a[0]);
        for (int i = 1; i < a.size(); i++)
        {
            TreeNode *cur = root;
            while (cur)
            {
                if (cur->val > a[i])
                {
                    if (cur->left)
                        cur = cur->left;
                    else
                    {
                        cur->left = new TreeNode(a[i]);
                        break;
                    }
                }
                else
                {
                    if (cur->right)
                        cur = cur->right;
                    else
                    {
                        cur->right = new TreeNode(a[i]);
                        break;
                    }
                }
            }
        }

        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &a)
    {
        int i = 0;
        return build(a, i, INT_MAX);
        // TC O(3N)
        // SCO(1)
    }
    TreeNode *build(vector<int> &a, int &i, int bound)
    {
        if (i == a.size() || a[i] > bound)
            return nullptr;
        TreeNode *root = new TreeNode(a[i++]);
        root->left = build(a, i, root->val);
        root->right = build(a, i, bound);
        return root;
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
    vector<int> a = {8, 5, 1, 7, 10, 12};

    Solution sol;

    // Searching for a value in the BST
    cout << "Binary Search Tree: " << endl;
    printInOrder(sol.bstFromPreorder(a));
    cout << "\nBinary Search Tree: " << endl;
    printInOrder(sol.b(a));

    return 0;
}
