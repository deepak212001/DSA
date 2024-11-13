/*
Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.



Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
Example 2:

Input: root = [1], target = 1, k = 3
Output: []

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
    void markParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent_track, TreeNode *target)
    {
        queue<TreeNode *> queue;
        queue.push(root);
        while (!queue.empty())
        {
            TreeNode *current = queue.front();
            queue.pop();
            if (current->left)
            {
                parent_track[current->left] = current;
                queue.push(current->left);
            }
            if (current->right)
            {
                parent_track[current->right] = current;
                queue.push(current->right);
            }
        }
    }

public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        unordered_map<TreeNode *, TreeNode *> parent_track;
        markParents(root, parent_track, target);

        unordered_map<TreeNode *, bool> visited;
        queue<TreeNode *> q;
        q.push(target);
        visited[target] = true;
        int curr_level = 0;

        while (!q.empty())
        {
            int size = q.size();
            if (curr_level == k)
                break;

            for (int i = 0; i < size; i++)
            {
                TreeNode *current = q.front();
                q.pop();

                if (current->left && !visited[current->left])
                {
                    q.push(current->left);
                    visited[current->left] = true;
                }
                if (current->right && !visited[current->right])
                {
                    q.push(current->right);
                    visited[current->right] = true;
                }
                if (parent_track[current] && !visited[parent_track[current]])
                {
                    q.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
            curr_level++;
        }
        vector<int> result;
        while (!q.empty())
        {
            TreeNode *current = q.front();
            q.pop();
            result.push_back(current->val);
        }
        return result;

        // TC O(N)
        // SC O(N)
    }
};

// Function to print the inorder
// traversal of the tree
void inorderTraversal(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main()
{
    // Create the binary tree
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

    // Print the inorder traversal
    // of tree before modification
    cout << "Binary Tree : ";
    inorderTraversal(root);
    cout << endl;

    // Call the changeTree function
    // to modify the binary tree
    vector<int> res = sol.distanceK(root, root->left, 2);

    // Print the inorder traversal
    // after modification
    cout << "Node at a distance of 2 in BST : ";
    for (auto it : res)
        cout << it << "  ";
    cout << endl;

    return 0;
}
