/*

Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.



Example 1:


Input: root = [3,1,4,null,2], k = 1
Output: 1
Example 2:


Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3


*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BruteForce
{
private:
    void inorder(TreeNode *node, vector<int> &arr)
    {
        if (!node)
        {
            return;
        }
        inorder(node->left, arr);
        arr.push_back(node->val);
        inorder(node->right, arr);
        return;
    }

public:
    pair<int, int> findKth(TreeNode *node, int k)
    {
        vector<int> arr;
        inorder(node, arr);
        int kLargest = arr[arr.size() - k];
        int kSmallest = arr[k - 1];

        return make_pair(kSmallest, kLargest);
    }

    // TC O(N)
    // SC O(N)
};

class Optimal
{
private:
    // Helper function to perform reverse inorder
    // traversal to find Kth largest element
    void reverseInorder(TreeNode *node, int &counter, int k, int &kLargest)
    {
        if (!node || counter >= k)
            return;

        // Traverse right subtree
        reverseInorder(node->right, counter, k, kLargest);

        // Increment counter after
        // visiting right subtree
        counter++;

        // Check if current node
        // is the Kth largest
        if (counter == k)
        {
            kLargest = node->val;
            return;
        }

        // Traverse left subtree if
        // Kth largest is not found yet
        reverseInorder(node->left, counter, k, kLargest);
    }

    // Helper function to perform inorder
    // traversal to find Kth smallest element
    void inorder(TreeNode *node, int &counter, int k, int &kSmallest)
    {
        if (!node || counter >= k)
            return;

        // Traverse left subtree
        inorder(node->left, counter, k, kSmallest);

        // Increment counter after visiting left subtree
        counter++;

        // Check if current node is the Kth smallest
        if (counter == k)
        {
            kSmallest = node->val;
            return;
        }

        // Traverse right subtree if
        // Kth smallest is not found yet
        inorder(node->right, counter, k, kSmallest);
    }

public:
    pair<int, int> findKth(TreeNode *root, int k)
    {
        int kSmallest = INT_MIN, kLargest = INT_MIN;
        int counter = 0;
        inorder(root, counter, k, kSmallest);

        counter = 0;
        // aur inorder me N-k th smallest bhi kar skte hai
        reverseInorder(root, counter, k, kLargest);
        return make_pair(kSmallest, kLargest);
    }

    // TC O(N)
    // SC O(1)
};

// Function to perform an in-order traversal
// of a binary tree and print its nodes
void printInOrder(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

int main()
{
    // Creating a BST
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(13);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(2);
    root->left->left->right = new TreeNode(4);
    root->left->right = new TreeNode(6);
    root->left->right->right = new TreeNode(9);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(14);

    cout << "Binary Search Tree: " << endl;
    printInOrder(root);
    cout << endl;

    BruteForce sol;

    // Find the Kth smallest and largest elements
    int k = 3;
    cout << "k: " << k << endl;
    pair<int, int> kthElements = sol.findKth(root, k);

    cout << "Kth smallest element: " << kthElements.first << endl;
    cout << "Kth largest element: " << kthElements.second << endl;

    Optimal solution;

    // Find the Kth smallest and largest elements
    cout << "k: " << k << endl;
    pair<int, int> kthElement = solution.findKth(root, k);

    cout << "Kth smallest element: " << kthElement.first << endl;
    cout << "Kth largest element: " << kthElement.second << endl;

    return 0;
}
