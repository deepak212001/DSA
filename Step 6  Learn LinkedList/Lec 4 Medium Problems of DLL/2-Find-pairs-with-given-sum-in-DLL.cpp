/*


*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val, Node *nextp = nullptr, Node *prevp = nullptr)
    {
        data = val;
        next = nextp;
        prev = prevp;
    }
};

void printDLL(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node *convertArrTODLL(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;

    // TC O(N)
}

vector<pair<int, int>> BruteForce(Node *head, int k)
{
    vector<pair<int, int>> ans;
    Node *temp = head;
    while (temp)
    {
        Node *temp1 = temp->next;
        while (temp1)
        {
            if (temp->data + temp1->data == k)
                ans.push_back({temp->data, temp1->data});

            temp1 = temp1->next;
        }
        temp = temp->next;
    }
    return ans;

    // TC O(N^2)
    // SC O(1)
}

Node *find(Node *head)
{
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    return temp;
}
vector<pair<int, int>> Optimal(Node *head, int k)
{
    vector<pair<int, int>> ans;
    Node *left = head;
    Node *right = find(head);

    while (left->data < right->data)
    {
        if (left->data + right->data == k)
        {
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        }

        if (left->data + right->data < k)
            left = left->next;
        if (left->data + right->data > k)
            right = right->prev;
    }
    return ans;

    // TC O(N)+O(N)
    // SC O(1)
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 9};

    Node *head = convertArrTODLL(arr);
    printDLL(head);

    vector<pair<int, int>> ans = BruteForce(head, 5);
    for (auto it : ans)
    {
        cout << "sum of " << it.first << " and " << it.second << endl;
    }
    cout << endl;
    ans = BruteForce(head, 5);
    for (auto it : ans)
    {
        cout << "sum of " << it.first << " and " << it.second << endl;
    }

    return 0;
}