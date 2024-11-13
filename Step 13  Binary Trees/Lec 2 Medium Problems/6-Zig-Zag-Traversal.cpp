/*

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).



Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []


*/

#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>

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
    // Function to perform zigzag level
    // order traversal of a binary tree
    vector<vector<int>> ZigZagLevelOrder(Node *root)
    {
        vector<vector<int>> result;
        if (root == NULL)
        {
            return result;
        }

        queue<Node *> nodesQueue;
        nodesQueue.push(root);

        bool leftToRight = true;
        while (!nodesQueue.empty())
        {
            int size = nodesQueue.size();

            vector<int> row(size);

            for (int i = 0; i < size; i++)
            {

                Node *node = nodesQueue.front();
                nodesQueue.pop();

                int index = leftToRight ? i : (size - 1 - i);

                row[index] = node->data;
                if (node->left)
                {
                    nodesQueue.push(node->left);
                }
                if (node->right)
                {
                    nodesQueue.push(node->right);
                }
            }

            leftToRight = !leftToRight;
            result.push_back(row);
        }

        return result;

        // TC O(N)
        // SC O(N)
    }
};

// Helper function to print the result
void printResult(const vector<vector<int>> &result)
{
    for (const auto &row : result)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main()
{
    // Creating a sample binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution solution;

    // Get the zigzag level order traversal
    vector<vector<int>> result = solution.ZigZagLevelOrder(root);

    // Print the result
    printResult(result);

    return 0;
}