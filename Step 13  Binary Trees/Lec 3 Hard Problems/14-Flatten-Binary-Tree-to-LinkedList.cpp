/*
Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.


Example 1:


Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [0]
Output: [0]

*/

#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <map>
#include <stack>

using namespace std;

// TreeNode structure
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BruteForce
{
public:
    TreeNode *prev = NULL;

    void flatten(TreeNode *root)
    {
        // Base case: If the current
        // node is NULL, return.
        if (root == NULL)
        {
            return;
        }

        // Recursive call to
        // flatten the right subtree
        flatten(root->right);

        // Recursive call to
        // flatten the left subtree
        flatten(root->left);

        // At this point, both left and right
        // subtrees are flattened, and 'prev'
        // is pointing to the rightmost node
        // in the flattened right subtree.

        // Set the right child of
        // the current node to 'prev'.
        root->right = prev;

        // Set the left child of the
        // current node to NULL.
        root->left = NULL;

        // Update 'prev' to the current
        // node for the next iteration.
        prev = root;

        // TC O(N)
        // SC  O(logN)
    }
};

class Better
{
public:
    // Initialize a global variable
    // 'prev' to keep track of the
    // previously processed node.
    TreeNode *prev = NULL;

    // Function to flatten a binary tree
    // to a right next Linked List structure
    void flatten(TreeNode *root)
    {
        // Base case: If the current
        // node is NULL, return.
        if (root == NULL)
        {
            return;
        }
        // Use a stack for
        // iterative traversal.
        stack<TreeNode *> st;
        // Push the root node
        // onto the stack.
        st.push(root);

        // Continue the loop until
        // the stack is empty.
        while (!st.empty())
        {
            // Get the top node from the stack.
            TreeNode *cur = st.top();
            // Pop the top node.
            st.pop();

            if (cur->right != NULL)
            {
                // Push the right child
                // onto the stack.
                st.push(cur->right);
            }

            if (cur->left != NULL)
            {
                // Push the left child
                // onto the stack.
                st.push(cur->left);
            }

            if (!st.empty())
            {
                // Connect the right child to
                // the next node in the stack.
                cur->right = st.top();
            }

            // Set the left child to NULL to
            // form a right-oriented linked list.
            cur->left = NULL;
        }
        // TC O(N)
        // SC  O(logN)
    }
};

class Optimal
{
public:
    // Function to flatten a binary tree
    // to a right next Linked List structure
    void flatten(TreeNode *root)
    {
        // Initialize a pointer
        // 'curr' to the root of the tree
        TreeNode *curr = root;

        // Iterate until 'curr'
        // becomes NULL
        while (curr)
        {
            // Check if the current
            // node has a left child
            if (curr->left)
            {
                // If yes, find the rightmost
                // node in the left subtree
                TreeNode *pre = curr->left;
                while (pre->right)
                {
                    pre = pre->right;
                }

                // Connect the rightmost node in
                // the left subtree to the current
                //  node's right child
                pre->right = curr->right;

                // Move the entire left subtree to the
                // right child of the current node
                curr->right = curr->left;

                // Set the left child of
                // the current node to NULL
                curr->left = NULL;
            }

            // Move to the next node
            // on the right side
            curr = curr->right;
        }

        // TC O(2N)
        // SC  O(1)
    }
};

// Print the preorder traversal of the
// Orignal Binary Tree
void printPreorder(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

// Print the Binary Tree along the
// Right Pointers after Flattening
void printFlattenTree(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    cout << root->val << " ";
    printFlattenTree(root->right);
}

int main()
{

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->left = new TreeNode(8);

    BruteForce sol;

    cout << "Binary Tree Preorder: ";
    printPreorder(root);
    cout << endl;

    sol.flatten(root);

    cout << "Binary Tree After Flatten: ";
    printFlattenTree(root);
    cout << endl;

    Better solB;
    solB.flatten(root);

    cout << "Binary Tree After Flatten: ";
    printFlattenTree(root);
    cout << endl;

    Optimal solO;
    solO.flatten(root);

    cout << "Binary Tree After Flatten: ";
    printFlattenTree(root);
    cout << endl;

    return 0;
}
