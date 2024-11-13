/*
Given a Binary Tree of nodes, you need to find all the possible paths from the root node to all the leaf nodes of the binary tree.

Example 1:

Input:
       1
    /     \
   2       3
Output:
1 2
1 3
Explanation:
All possible paths:
1->2
1->3
Example 2:

Input:
         10
       /    \
      20    30
     /  \
    40   60
Output:
10 20 40
10 20 60
10 30


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
    bool getPath(TreeNode *root, vector<int> &arr, int x)
    {
        if (!root)
        {
            return false;
        }

        arr.push_back(root->val);
        if (root->val == x)
        {
            return true;
        }

        if (getPath(root->left, arr, x) || getPath(root->right, arr, x))
        {
            return true;
        }

        // If the target value 'x' is not found
        // in the current path, backtrack
        arr.pop_back();
        return false;
    }

    vector<int> solve(TreeNode *A, int B)
    {
        vector<int> arr;

        if (A == NULL)
        {
            return arr;
        }

        getPath(A, arr, B);
        return arr;
    }

    // TC O(N)
    // SC O(N)
};

int main()
{
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

    int targetLeafValue = 7;

    vector<int> path = sol.solve(root, targetLeafValue);

    cout << "Path from root to leaf with value " << targetLeafValue << ": ";
    for (int i = 0; i < path.size(); ++i)
    {
        cout << path[i];
        if (i < path.size() - 1)
        {
            cout << " -> ";
        }
    }

    return 0;
}
