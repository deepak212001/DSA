/*

Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.



Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation:
Column -1: Only node 9 is in this column.
Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.
Column 1: Only node 20 is in this column.
Column 2: Only node 7 is in this column.
Example 2:


Input: root = [1,2,3,4,5,6,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation:
Column -2: Only node 4 is in this column.
Column -1: Only node 2 is in this column.
Column 0: Nodes 1, 5, and 6 are in this column.
          1 is at the top, so it comes first.
          5 and 6 are at the same position (2, 0), so we order them by their value, 5 before 6.
Column 1: Only node 3 is in this column.
Column 2: Only node 7 is in this column.
Example 3:


Input: root = [1,2,3,4,6,5,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation:
This case is the exact same as example 2, but with nodes 5 and 6 swapped.
Note that the solution remains the same since 5 and 6 are in the same location and should be ordered by their values.


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
    vector<vector<int>> findVertical(Node *root)
    {
        map<int, map<int, multiset<int>>> nodes;

        // Queue for BFS traversal,
        queue<pair<Node *, pair<int, int>>> todo;
        todo.push({root, {0, 0}});

        // BFS traversal
        while (!todo.empty())
        {
            auto p = todo.front();
            todo.pop();
            Node *temp = p.first;

            // Extract the vertical and level information
            // x -> vertical
            int x = p.second.first;
            // y -> level
            int y = p.second.second;

            nodes[x][y].insert(temp->data);

            // Process left child
            if (temp->left)
            {
                todo.push({temp->left, {x - 1, y + 1}});
            }

            // Process right child
            if (temp->right)
            {
                todo.push({temp->right, {x + 1, y + 1}});
            }
        }

        vector<vector<int>> ans;
        for (auto p : nodes)
        {
            vector<int> col;
            for (auto q : p.second)
            {
                // Insert node values
                // into the column vector
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            // Add the column vector
            // to the final result
            ans.push_back(col);
        }
        return ans;

        // TC O(N * log2N * log2N * log2N)
        // SC O(N+ N/2)
    }
};

// Helper function to
// print the result
void printResult(const vector<vector<int>> &result)
{
    for (auto level : result)
    {
        for (auto node : level)
        {
            cout << node << " ";
        }
        cout << endl;
    }
    cout << endl;
}

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

    // Get the Vertical traversal
    vector<vector<int>> verticalTraversal =
        solution.findVertical(root);

    // Print the result
    cout << "Vertical Traversal: ";
    printResult(verticalTraversal);

    return 0;
}