/*

Given a BST and a number X, find Ceil of X.
Note: Ceil(X) is a number that is either equal to X or is immediately greater than X.

If Ceil could not be found, return -1.

Example 1:

Input:
      5
    /   \
   1     7
    \
     2 
      \
       3
X = 3
Output: 3
Explanation: We find 3 in BST, so ceil
of 3 is 3.
Example 2:

Input:
     10
    /  \
   5    11
  / \ 
 4   7
      \
       8
X = 6
Output: 7
Explanation: We find 7 in BST, so ceil
of 6 is 7.

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


/*

Sometimes we spend too much time to complete
an easy task and when the deadline approaches,
we rush and end up making some small mistakes.
In the end, we are left with only regrets

*/
class Solution
{
public:
    int findCeil(TreeNode *root, int key)
    {
        int ceil = -1;

        while (root)
        {
            if (root->val == key)
            {
                ceil = root->val;
                return ceil;
            }
            if (key > root->val)
            {
                root = root->right;
            }
            else
            {
                // If the key is smaller, update ceil
                // and move to the left subtree
                ceil = root->val;
                root = root->left;
            }
        }
        // Return the computed ceiling value
        return ceil;

        // TC O(log2N)
        // SC O(1)
    }
};

// Function to perform an in-order traversal
// of a binary tree and print its nodes
void printInOrder(TreeNode *root)
{
    // Check if the current node
    // is null (base case for recursion)
    if (root == nullptr)
    {
        // If null, return and
        // terminate the function
        return;
    }

    // Recursively call printInOrder
    // for the left subtree
    printInOrder(root->left);

    // Print the value of the current node
    cout << root->val << " ";

    // Recursively call printInOrder
    // for the right subtree
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

    Solution solution;

    // Searching for a value in the BST
    int target = 8;
    int ciel = solution.findCeil(root, target);

    if (ciel != -1)
    {
        cout << "Ceiling of " << target << " is: " << ciel << endl;
    }
    else
    {
        cout << "No ceiling found!";
    }

    return 0;
}
