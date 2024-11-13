/*
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.



Example 1:


Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
Example 2:

Input: root = [1,2]
Output: 1

*/

#include <iostream>
#include <algorithm>

using namespace std;

// Node structure for
// the binary tree
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
    int diameter = 0;

    int calculateHeight(Node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }

        int leftHeight = calculateHeight(node->left);
        int rightHeight = calculateHeight(node->right);

        diameter = max(diameter, leftHeight + rightHeight);

        return 1 + max(leftHeight, rightHeight);
    }

    int BruteForce(Node *root)
    {
        calculateHeight(root);

        return diameter;

        // TC O(N*N)
        // SC O(1)
    }

    int Optimal(Node *root)
    {
        int diameter = 0;
        height(root, diameter);

        return diameter;
    }

    // Function to calculate the height of
    // the tree and update the diameter
    int height(Node *node, int &diameter)
    {
        // Base case: If the node is null,
        // return 0 indicating the
        // height of an empty tree
        if (!node)
        {
            return 0;
        }

        // Recursively calculate the
        // height of left and right subtrees
        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);

        // Update the diameter with the maximum
        // of current diameter or sum of
        // left and right heights
        diameter = max(diameter, lh + rh);

        // Return the height of
        // the current node's subtree
        return 1 + max(lh, rh);

        // TC O(N)
        // SC O(1)
    }
};

// Main function
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

    // Calculate the diameter of the binary tree
    int diameter = solution.BruteForce(root);

    cout << "The diameter of the binary tree is: " << diameter << endl;

    int diameter1 = solution.Optimal(root);

    cout << "The diameter of the binary tree is: " << diameter1 << endl;

    return 0;
}
