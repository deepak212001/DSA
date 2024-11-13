/*
Example 1:
Input:Binary Tree: 4 2 5 3 -1 7 6 -1 9 -1 -1 8 -1 1


Output: [4 2 3 9 1 5 7 6 8]
Explanation: We traverse the binary tree in the order of Root, Left then Right recursively resulting in the following traversal:

Example 2:
Input:Binary Tree: 1 2 3 4 5 6 7 -1 -1 8 -1 -1 -1 9 10


Output: [1 2 4 5 8 3 6 7 9 10]
Explanation: We traverse the binary tree in the order of Root, Left then Right recursively resulting in the following traversal:


*/

#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <map>

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
    vector<int> getPreorder(TreeNode *root)
    {
        vector<int> preorder;
        TreeNode *cur = root;

        while (cur != NULL)
        {
            if (cur->left == NULL)
            {
                preorder.push_back(cur->val);
                cur = cur->right;
            }
            else
            {
                TreeNode *prev = cur->left;
                while (prev->right && prev->right != cur)
                {
                    prev = prev->right;
                }

                if (prev->right == NULL)
                {
                    prev->right = cur;
                    preorder.push_back(cur->val);
                    cur = cur->left;
                }
                else
                {
                    prev->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return preorder;
    }
    // TC O(2N)
    // SC O(1)
};

int main()
{

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);

    Solution sol;

    vector<int> preorder = sol.getPreorder(root);

    cout << "Binary Tree Morris Preorder Traveral: ";
    for (int i = 0; i < preorder.size(); i++)
    {
        cout << preorder[i] << " ";
    }
    cout << endl;

    return 0;
}
