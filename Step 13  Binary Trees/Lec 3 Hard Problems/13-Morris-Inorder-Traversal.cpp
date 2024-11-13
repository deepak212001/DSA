/*
Example 1:
Input:Binary Tree: 4 2 5 3 -1 7 6 -1 9 -1 -1 8 -1 1


Output: [3, 1, 9, 2, 4, 7, 5, 8, 6]
Explanation: We traverse the binary tree in the order of Left, Root then Right recursively resulting in the following traversal:

Example 2:
Input:Binary Tree: 1 2 3 4 5 6 7 -1 -1 8 -1 -1 -1 9 10


Output: [4,2,8,5,1,6,3,9,7,10]
Explanation: We traverse the binary tree in the order of Left, Root then Right recursively resulting in the following traversal:

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
    // Function to perform iterative Morris
    // inorder traversal of a binary tree
    vector<int> getInorder(TreeNode *root)
    {
        // Vector to store the
        // inorder traversal resul
        vector<int> inorder;
        // Pointer to the current node,
        // starting from the root
        TreeNode *cur = root;

        // Loop until the current
        // node is not NULL
        while (cur != NULL)
        {
            // If the current node's
            // left child is NULL
            if (cur->left == NULL)
            {
                // Add the value of the current
                // node to the inorder vector
                inorder.push_back(cur->val);
                // Move to the right child
                cur = cur->right;
            }
            else
            {
                // If the left child is not NULL,
                // find the predecessor (rightmost node
                // in the left subtree)
                TreeNode *prev = cur->left;
                while (prev->right && prev->right != cur)
                {
                    prev = prev->right;
                }

                // If the predecessor's right child
                // is NULL, establish a temporary link
                // and move to the left child
                if (prev->right == NULL)
                {
                    prev->right = cur;
                    cur = cur->left;
                }
                else
                {
                    // If the predecessor's right child
                    // is already linked, remove the link,
                    // add current node to inorder vector,
                    // and move to the right child
                    prev->right = NULL;
                    inorder.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }

        // Return the inorder
        // traversal result
        return inorder;
        // TC O(2N)
        // SC O(1)
    }
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

    vector<int> inorder = sol.getInorder(root);

    cout << "Binary Tree Morris Inorder Traversal: ";
    for (int i = 0; i < inorder.size(); i++)
    {
        cout << inorder[i] << " ";
    }
    cout << endl;

    return 0;
}
