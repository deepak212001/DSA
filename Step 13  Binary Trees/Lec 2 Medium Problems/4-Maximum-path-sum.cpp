/*
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.



Example 1:


Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
Example 2:


Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.

*/

#include <iostream>
#include <algorithm>
#include <climits>

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
    int findMaxPathSum(Node *root, int &maxi)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int leftMaxPath = max(0, findMaxPathSum(root->left, maxi));
        int rightMaxPath = max(0, findMaxPathSum(root->right, maxi));

        maxi = max(maxi, leftMaxPath + rightMaxPath + root->data);

        // cout << maxi << "  " << leftMaxPath << "   " << rightMaxPath << "   " << root->data << endl;

        return max(leftMaxPath, rightMaxPath) + root->data;
    }

    int maxPathSum(Node *root)
    {
        int maxi = INT_MIN;
        findMaxPathSum(root, maxi);

        return maxi;

        // TC O(N)
        // SC O(1)
    }
};

int main()
{
    // Creating a sample binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);

    // Creating an instance of the Solution class
    Solution solution;

    // Finding and printing the maximum path sum
    int maxPathSum = solution.maxPathSum(root);
    cout << "Maximum Path Sum: " << maxPathSum << endl;

    return 0;
}
