/*

Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.



Example 1:


Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).
Example 2:


Input: root = [1,3,2,5,null,null,9,6,null,7]
Output: 7
Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).
Example 3:


Input: root = [1,3,2,5]
Output: 2
Explanation: The maximum width exists in the second level with length 2 (3,2).


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
    int widthOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;
            
        int ans = 0;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});

        // Perform level-order traversal
        while (!q.empty())
        {
            int size = q.size();
            int mmin = q.front().second;
            int first, last;


            for (int i = 0; i < size; i++)
            {
                
                int cur_id = q.front().second - mmin;
                
                TreeNode *node = q.front().first;
                q.pop();

                if (i == 0)
                    first = cur_id;

                if (i == size - 1)
                    last = cur_id;

                if (node->left)
                    q.push({node->left, cur_id * 2 + 1});

                if (node->right)
                    q.push({node->right, cur_id * 2 + 2});
            }

            ans = max(ans, last - first + 1);
        }

        // Return the maximum
        // width of the binary tree
        return ans;

        // TC O(N)
        // SC O(N)
    }
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

    int maxWidth = sol.widthOfBinaryTree(root);

    cout << "Maximum width of the binary tree is: "
         << maxWidth << endl;

    return 0;
}
