/*

Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.



Example 1:


Input: p = [1,2,3], q = [1,2,3]
Output: true
Example 2:


Input: p = [1,2], q = [1,null,2]
Output: false
Example 3:


Input: p = [1,2,1], q = [1,1,2]
Output: false


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

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    bool isIdentical(Node *node1, Node *node2)
    {
        if (node1 == NULL && node2 == NULL)
        {
            return true;
        }
        if (node1 == NULL || node2 == NULL)
        {
            return false;
        }
        return ((node1->data == node2->data) && isIdentical(node1->left, node2->left) && isIdentical(node1->right, node2->right));

        // TC O(N+M)
        // SC O(1)
    }
};

int main()
{
    // Node1
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);

    // Node2
    Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);

    Solution solution;

    if (solution.isIdentical(root1, root2))
    {
        cout << "The binary trees are identical." << endl;
    }
    else
    {
        cout << "The binary trees are not identical." << endl;
    }

    return 0;
}