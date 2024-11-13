/*


Example 1:
Input: Binary Tree: 4 2 5 3 -1 7 6 -1 9 -1 -1 8 -1 1

Output:[ [4],[ 2, 5 ],[ 3, 7, 6],[ 9, 8],[ 1 ]]

*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == nullptr)
        {
            return ans;
        }

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                level.push_back(node->val);

                if (node->left != nullptr)
                {
                    q.push(node->left);
                }
                if (node->right != nullptr)
                {
                    q.push(node->right);
                }
            }
            ans.push_back(level);
        }
        return ans;

        // TC O(N)
        // SC O(N)
    }
};

// Function to print
// the elements of a vector
void printVector(const vector<int> &vec)
{
    for (int num : vec)
    {
        cout << num << " ";
    }
    cout << endl;
}

// Main function
int main()
{
    // Creating a sample binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Create an instance
    // of the Solution class
    Solution solution;
    // Perform level-order traversal
    vector<vector<int>> result = solution.levelOrder(root);

    cout << "Level Order Traversal of Tree: " << endl;

    // Printing the level order traversal result
    for (const vector<int> &level : result)
    {
        printVector(level);
    }

    return 0;
}