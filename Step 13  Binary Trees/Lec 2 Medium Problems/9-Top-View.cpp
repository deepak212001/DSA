/*

Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

       1
    /     \
   2       3
  /  \    /   \
4    5  6      7

Top view will be: 4 2 1 3 7
Note: Return nodes from leftmost node to rightmost node. Also if 2 nodes are outside the shadow of the tree and are at same position then consider the left ones only(i.e. leftmost).
For ex - 1 2 3 N 4 5 N 6 N 7 N 8 N 9 N N N N N will give 8 2 1 3 as answer. Here 8 and 9 are on the same position but 9 will get shadowed.

Example 1:

Input:
      1
   /    \
  2      3
Output: 2 1 3
Example 2:

Input:
       10
    /      \
  20        30
 /   \    /    \
40   60  90    100
Output: 40 20 10 30 100


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
public:
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }

        map<int, int> mpp;
        queue<pair<Node *, int>> q;
        q.push({root, 0});

        // BFS traversal
        while (!q.empty())
        {

            auto it = q.front();
            q.pop();
            Node *node = it.first;
            int line = it.second;

            if (mpp.find(line) == mpp.end())
            {
                mpp[line] = node->data;
            }
            if (node->left != NULL)
            {
                q.push({node->left, line - 1});
            }
            if (node->right != NULL)
            {
                q.push({node->right, line + 1});
            }
        }

        for (auto it : mpp)
        {
            ans.push_back(it.second);
        }

        return ans;

        // TC O(N)
        // SC O(N / 2 + N / 2)
    }
};

int main()
{
    // Creating a sample binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(10);
    root->right->left = new Node(9);

    Solution solution;

    // Get the top view traversal
    vector<int> topView =
        solution.topView(root);

    // Print the result
    cout << "Top View Traversal: " << endl;
    for (auto node : topView)
    {
        cout << node << " ";
    }

    return 0;
}