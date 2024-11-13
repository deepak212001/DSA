/*

Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):

BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
int next() Moves the pointer to the right, then returns the number at the pointer.
Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.

You may assume that next() calls will always be valid. That is, there will be at least a next number in the in-order traversal when next() is called.

 

Example 1:


Input
["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
[[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
Output
[null, 3, 7, true, 9, true, 15, true, 20, false]

Explanation
BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
bSTIterator.next();    // return 3
bSTIterator.next();    // return 7
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 9
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 15
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 20
bSTIterator.hasNext(); // return False
 

*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BSTIterator
{
    stack<TreeNode *> mystack;

public:
    BSTIterator(TreeNode *root)
    {
        pushAll(root);
    }
    bool hasNext()
    {
        return !mystack.empty();
    }
    int next()
    {
        TreeNode *temp = mystack.top();
        mystack.pop();
        pushAll(temp->right);
        return temp->val;
    }

    void pushAll(TreeNode *node)
    {
        for (; node != nullptr; mystack.push(node), node = node->left)
            ;
    }
    // TC O(1)
    // SC O(H)
};

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

    BSTIterator sol(root);

    cout << "The next element is " << sol.next() << endl;
    cout << "The next element is " << sol.next() << endl;
    cout << "The next element is " << sol.next() << endl;
    if (sol.hasNext())
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "The next element is " << sol.next() << endl;
    cout << "The next element is " << sol.next() << endl;
    cout << "The next element is " << sol.next() << endl;
    if (sol.hasNext())
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "The next element is " << sol.next() << endl;
    cout << "The next element is " << sol.next() << endl;
    cout << "The next element is " << sol.next() << endl;
    if (sol.hasNext())
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "The next element is " << sol.next() << endl;
    if (sol.hasNext())
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}
