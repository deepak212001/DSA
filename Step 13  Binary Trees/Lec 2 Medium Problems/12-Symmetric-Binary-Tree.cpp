/*

Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).



Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false

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
private:
    bool isSymmetricUtil(Node *root1, Node *root2)
    {
        if (root1 == NULL || root2 == NULL)
        {
            return root1 == root2;
        }

        return (root1->data == root2->data) && isSymmetricUtil(root1->left, root2->right) && isSymmetricUtil(root1->right, root2->left);
    }

public:
    bool isSymmetric(Node *root)
    {
        if (!root)
        {
            return true;
        }
        return isSymmetricUtil(root->left, root->right);
    }
    // TC O(N)
    // SC O(1)
};

void printInorder(Node *root)
{
    if (!root)
    {
        return;
    }
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main()
{
    // Creating a sample binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->right->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);

    Solution solution;

    cout << "Binary Tree (Inorder): ";
    printInorder(root);
    cout << endl;

    bool res;
    res = solution.isSymmetric(root);

    if (res)
    {
        cout << "This Tree is Symmetrical" << endl;
    }
    else
    {
        cout << "This Tree is NOT Symmetrical" << endl;
    }

    return 0;
}
