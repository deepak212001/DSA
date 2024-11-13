/*


Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.



Example 1:


Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
Example 2:

Input: root = [1,null,3]
Output: [1,3]
Example 3:

Input: root = []
Output: []

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

class BruteForce
{
public:
    vector<int> rightsideView(Node *root)
    {
        vector<int> res;

        vector<vector<int>> levelTraversal = levelOrder(root);

        for (auto level : levelTraversal)
        {
            res.push_back(level.back());
        }

        return res;
    }

    vector<int> leftsideView(Node *root)
    {
        vector<int> res;
        vector<vector<int>> levelTraversal = levelOrder(root);

        for (auto level : levelTraversal)
        {
            res.push_back(level.front());
        }

        return res;
    }

private:
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> ans;

        if (!root)
        {
            return ans;
        }
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++)
            {
                Node *top = q.front();
                level.push_back(top->data);
                q.pop();

                if (top->left != NULL)
                {
                    q.push(top->left);
                }

                if (top->right != NULL)
                {
                    q.push(top->right);
                }
            }
            ans.push_back(level);
        }

        return ans;
    }
};

class Optimal
{
public:
    vector<int> rightsideView(Node *root)
    {
        // Vector to store the result
        vector<int> res;

        // Call the recursive function
        // to populate the right-side view
        recursionRight(root, 0, res);

        return res;
    }

    // Function to return the Left view of the binary tree
    vector<int> leftsideView(Node *root)
    {
        // Vector to store the result
        vector<int> res;

        // Call the recursive function
        // to populate the left-side view
        recursionLeft(root, 0, res);

        return res;
    }

private:
    void recursionLeft(Node *root, int level, vector<int> &res)
    {
        // Check if the current node is NULL
        if (root == NULL)
        {
            return;
        }

        // Check if the size of the result vector
        // is equal to the current level
        if (res.size() == level)
        {
            // If equal, add the value of the
            // current node to the result vector
            res.push_back(root->data);
        }

        // Recursively call the function for the
        // left child with an increased level
        recursionLeft(root->left, level + 1, res);

        // Recursively call the function for the
        // right child with an increased level
        recursionLeft(root->right, level + 1, res);
    }

    void recursionRight(Node *root, int level, vector<int> &res)
    {
        if (root == NULL)
        {
            return;
        }

        if (res.size() == level)
        {
            res.push_back(root->data);
        }
        recursionRight(root->right, level + 1, res);
        recursionRight(root->left, level + 1, res);
    }
    // TC O(log2N)
    // SC O(log2N)
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

    BruteForce solution;

    // Get the Right View traversal
    vector<int> rightView = solution.rightsideView(root);

    // Print the result for Right View
    cout << "Right View Traversal: ";
    for (auto node : rightView)
    {
        cout << node << " ";
    }
    cout << endl;

    // Get the Left View traversal
    vector<int> leftView = solution.leftsideView(root);

    // Print the result for Left View
    cout << "Left View Traversal: ";
    for (auto node : leftView)
    {
        cout << node << " ";
    }
    cout << endl;

    Optimal solve;

    // Get the Right View traversal
    vector<int> rightView1 = solve.rightsideView(root);

    // Print the result for Right View
    cout << "Right View Traversal: ";
    for (auto node : rightView1)
    {
        cout << node << " ";
    }
    cout << endl;

    // Get the Left View traversal
    vector<int> leftView1 = solve.leftsideView(root);

    // Print the result for Left View
    cout << "Left View Traversal: ";
    for (auto node : leftView1)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}