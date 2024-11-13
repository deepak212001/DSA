/*

You are given a BST(Binary Search Tree) with n number of nodes and value x. your task is to find the greatest value node of the BST which is smaller than or equal to x.
Note: when x is smaller than the smallest node of BST then returns -1.

Example:

Input:
n = 7               2
                     \
                      81
                    /     \
                 42       87
                   \       \
                    66      90
                   /
                 45
x = 87
Output:
87
Explanation:
87 is present in tree so floor will be 87.
Example 2:

Input:
n = 4                     6
                           \
                            8
                          /   \
                        7       9
x = 11
Output:
9
Your Task:-
You don't need to read input or print anything. Complete the function floor() which takes the integer n and BST and integer x returns the floor value.

*/


                            
#include <iostream>
#include <vector>
#include <climits> 
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/*
What is ours, we will get it and what is not ours, 
no matter how much we pray for it, no matter 
how much we cry, we will never get it.

Let the one who is leaving go, the one who has 
decided to leave will leave today or tomorrow, 
no matter how much you try to stop him, he will 
leave one day
*/


class Solution {
public:
    int floorInBST(TreeNode* root, int key)
    {
        int floor = -1;
        
        while(root)
        {
            if(root->val == key)
            {
                floor = root->val;
                return floor;
            }
            if(key > root->val)
            {
                floor = root->val;
                root = root->right;
            }
            else
            {
                root = root->left;
            }
        }
        return floor;
        // TC O(log2N)
        // SC O(1)
    }
};



// Function to perform an in-order traversal
// of a binary tree and print its nodes
void printInOrder(TreeNode* root) {
    // Check if the current node
    // is null (base case for recursion)
    if (root == nullptr) {
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

int main() {
    // Creating a BST
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(13);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(2);
    root->left->left->right = new TreeNode(4);
    root->left->right = new TreeNode(6);
    root->left->right->right = new TreeNode(9);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(14);
    
    cout << "Binary Search Tree: "<< endl;
    printInOrder(root);
    cout << endl;

    Solution solution;
    
    // Searching for a value in the BST
    int target = 8;
    int ciel = solution.floorInBST(root, target);
    
    if(ciel != -1){
        cout << "Floor of " << target << " is: " << ciel << endl;
    }
    else{
        cout << "No floor found!";
    }
    
    return 0;
}
       