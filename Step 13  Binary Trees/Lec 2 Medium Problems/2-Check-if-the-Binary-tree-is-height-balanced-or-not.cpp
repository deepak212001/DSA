
#include <iostream>
#include <algorithm>

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
    bool BruteForce(Node *root)
    {
        if (root == nullptr)
        {
            return true;
        }

        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        if (abs(leftHeight - rightHeight) <= 1 && BruteForce(root->left) && BruteForce(root->right))
        {
            return true;
        }

        return false;

        // TC O(N*N)
        // SC O(1)
    }

    int getHeight(Node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        return max(leftHeight, rightHeight) + 1;
    }

    // Function to check if a binary tree is balanced
    bool Optimal(Node *root)
    {
        return dfsHeight(root) != -1;

        // TC O(N)
        // SC O(1)
    }

    int dfsHeight(Node *root)
    {
        if (root == NULL)
            return 0;

        int leftHeight = dfsHeight(root->left);

        if (leftHeight == -1)
            return -1;

        int rightHeight = dfsHeight(root->right);

        if (rightHeight == -1)
            return -1;

        if (abs(leftHeight - rightHeight) > 1)
            return -1;

        return max(leftHeight, rightHeight) + 1;
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

    // Checking if the tree is balanced
    if (solution.BruteForce(root))
    {
        cout << "The tree is balanced." << endl;
    }
    else
    {
        cout << "The tree is not balanced." << endl;
    }

    if (solution.Optimal(root))
    {
        cout << "The tree is balanced." << endl;
    }
    else
    {
        cout << "The tree is not balanced." << endl;
    }

    return 0;
}
