/*



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
    int findMaxDistance(unordered_map<TreeNode *, TreeNode *> &mp, TreeNode *target)
    {

        unordered_map<TreeNode *, bool> visited;
        queue<TreeNode *> q;
        q.push(target);
        visited[target] = true;
        int maxDis = 0;

        while (!q.empty())
        {
            int size = q.size();
            int flag = 0;
            for (int i = 0; i < size; i++)
            {
                TreeNode *current = q.front();
                q.pop();

                if (current->left && !visited[current->left])
                {
                    flag = 1;
                    q.push(current->left);
                    visited[current->left] = true;
                }
                if (current->right && !visited[current->right])
                {
                    flag = 1;
                    q.push(current->right);
                    visited[current->right] = true;
                }
                if (mp[current] && !visited[mp[current]])
                {
                    flag = 1;
                    q.push(mp[current]);
                    visited[mp[current]] = true;
                }
            }
            if (flag == 1)
                maxDis++;
        }
        return maxDis;
    }
    TreeNode *bfsToMapParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &mp, int start)
    {
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *target;

        while (!q.empty())
        {
            TreeNode *cur = q.front();
            q.pop();
            if (cur->val == start)
                target = cur;
            if (cur->left)
            {
                mp[cur->left] = cur;
                q.push(cur->left);
            }
            if (cur->right)
            {
                mp[cur->right] = cur;
                q.push(cur->right);
            }
        }
        return target;
    }

public:
    int timeToBurnTree(TreeNode *root, int start)
    {
        unordered_map<TreeNode *, TreeNode *> mp;
        TreeNode *target = bfsToMapParents(root, mp, start);

        int maxi = findMaxDistance(mp, target);
        return maxi;

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
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->left->right = new TreeNode(7);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);

    Solution sol;

    // Print the inorder traversal
    // of tree before modification
    cout << "Binary Tree : ";
    inorderTraversal(root);
    cout << endl;

    cout << "Node at a distance of 2 in BST : " << sol.timeToBurnTree(root, 2);
    ;

    return 0;
}