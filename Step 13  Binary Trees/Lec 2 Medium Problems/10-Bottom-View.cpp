/*

Given a binary tree, return an array where elements represent the bottom view of the binary tree from left to right.

Note: If there are multiple bottom-most nodes for a horizontal distance from the root, then the latter one in the level traversal is considered. For example, in the below diagram, 3 and 4 are both the bottommost nodes at a horizontal distance of 0, here 4 will be considered.

                      20
                    /    \
                  8       22
                /   \     /   \
              5      3   4     25
                     /    \
                 10       14

For the above tree, the output should be 5 10 4 14 25.

Examples :

Input:
       1
     /   \
    3     2
Output: 3 1 2
Explanation: First case represents a tree with 3 nodes and 2 edges where root is 1, left child of 1 is 3 and right child of 1 is 2.

Thus bottom view of the binary tree will be 3 1 2.
Input:
         10
       /    \
      20    30
     /  \
    40   60
Output: 40 20 60 30

*/

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>

using namespace std;

// Node structure for the binary tree
struct Node
{
    int data;
    Node *left;
    Node *right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{
public:

    vector<int> bottomView(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }

        map<int, int> mpp;
        queue<pair<Node *, int>> q;
        q.push({root, 0});

        // BFS traversal
        while (!q.empty())
        {
            
            auto it = q.front();
            q.pop();
            Node *node = it.first;
            int line = it.second;

            mpp[line] = node->data;

            if (node->left != NULL)
            {
                // Push the left child with a decreased
                // vertical position into the queue
                q.push({node->left, line - 1});
            }

            // Process right child
            if (node->right != NULL)
            {
                // Push the right child with an increased
                // vertical position into the queue
                q.push({node->right, line + 1});
            }
        }

        // Transfer values from the
        // map to the result vector
        for (auto it : mpp)
        {
            ans.push_back(it.second);
        }

        return ans;

        // TC O(N)
        // SC O(N/2 + N/2)
    }
};

int main()
{
    // Creating a sample binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(10);
    root->right->left = new Node(9);

    Solution solution;

    // Get the Bottom View traversal
    vector<int> bottomView =
        solution.bottomView(root);

    // Print the result
    cout << "Bottom View Traversal: " << endl;
    for (auto node : bottomView)
    {
        cout << node << " ";
    }

    return 0;
}