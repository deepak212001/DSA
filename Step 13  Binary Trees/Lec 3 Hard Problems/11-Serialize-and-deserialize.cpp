/*

erialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.



Example 1:


Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]
Example 2:

Input: root = []
Output: []

*/

#include <iostream>
#include <queue>
#include <sstream>
using namespace std;

// Definition for a
// binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    // Encodes the tree into a single string
    string serialize(TreeNode *root)
    {
        // Check if the tree is empty
        if (!root)
        {
            return "";
        }

        // Initialize an empty string
        // to store the serialized data
        string s = "";
        // Use a queue for
        // level-order traversal
        queue<TreeNode *> q;
        // Start with the root node
        q.push(root);

        // Perform level-order traversal
        while (!q.empty())
        {
            // Get the front node in the queue
            TreeNode *curNode = q.front();
            q.pop();

            // Check if the current node is
            // null and append "#" to the string
            if (curNode == nullptr)
            {
                s += "#,";
            }
            else
            {
                // Append the value of the
                // current node to the string
                s += to_string(curNode->val) + ",";
                // Push the left and right children
                // to the queue for further traversal
                q.push(curNode->left);
                q.push(curNode->right);
            }
        }

        // Return the
        // serialized string
        return s;
    }

    // Decode the encoded
    // data to a tree
    TreeNode *deserialize(string data)
    {
        // Check if the
        // serialized data is empty
        if (data.empty())
        {
            return nullptr;
        }

        // Use a stringstream to
        // tokenize the serialized data
        stringstream s(data);
        string str;
        // Read the root value
        // from the serialized data
        getline(s, str, ',');
        TreeNode *root = new TreeNode(stoi(str));

        // Use a queue for
        // level-order traversal
        queue<TreeNode *> q;
        // Start with the root node
        q.push(root);

        // Perform level-order traversal
        // to reconstruct the tree
        while (!q.empty())
        {
            // Get the front node in the queue
            TreeNode *node = q.front();
            q.pop();

            // Read the value of the left
            // child from the serialized data
            getline(s, str, ',');
            // If the value is not "#", create a new
            // left child and push it to the queue
            if (str != "#")
            {
                TreeNode *leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            // Read the value of the right child
            // from the serialized data
            getline(s, str, ',');
            // If the value is not "#", create a
            // new right child and push it to the queue
            if (str != "#")
            {
                TreeNode *rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }

        // Return the reconstructed
        // root of the tree
        return root;

        // TC O(N)
        // SC O(N)
    }
};

void inorder(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Solution solution;
    cout << "Orignal Tree: ";
    inorder(root);
    cout << endl;

    string serialized = solution.serialize(root);
    cout << "Serialized : " << serialized << endl;

    TreeNode *deserialized = solution.deserialize(serialized);
    cout << "Tree after deserialisation : ";
    inorder(deserialized);
    cout << endl;

    return 0;
}
