/*

Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.



Example 1:

        Input: root = [1,2,3,4,5,6]
        Output: 6


Example 2:

        Input: root = []
        Output: 0


Example 3:

        Input: root = [1]
        Output: 1


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

class BruteForce
{
public:
    void inorder(TreeNode *root, int &count)
    {
        if (root == NULL)
        {
            return;
        }

        count++;
        inorder(root->left, count);
        inorder(root->right, count);
    }

    int countNodes(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int count = 0;
        inorder(root, count);
        return count;
        // TC O(N)
        // SC O(N)
    }
};

class Optimal
{
public:
    int countNodes(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int lh = findHeightLeft(root);
        int rh = findHeightRight(root);

        // Check if the last level
        // is completely filled
        if (lh == rh)
        {
            // If so, use the formula for
            // total nodes in a perfect
            // binary tree ie. 2^h - 1
            return (1 << lh) - 1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
        // tc O(log N * log N)
        //  SC O(H) ~ O(N)
    }

    // Function to find the left height of a tree
    int findHeightLeft(TreeNode *node)
    {
        int height = 0;
        // Traverse left child until
        // reaching the leftmost leaf
        while (node)
        {
            height++;
            node = node->left;
        }
        return height;
    }

    // Function to find the right height of a tree
    int findHeightRight(TreeNode *node)
    {
        int height = 0;
        // Traverse right child until
        // reaching the rightmost leaf
        while (node)
        {
            height++;
            node = node->right;
        }
        return height;
    }
};

int main()
{
    // Create the binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    BruteForce sol;

    int totalNodes = sol.countNodes(root);

    cout << "Total number of nodes in the Complete Binary Tree: " << totalNodes << endl;

    Optimal solution;

    totalNodes = solution.countNodes(root);

    cout << "Total number of nodes in the Complete Binary Tree: " << totalNodes << endl;

    return 0;
}