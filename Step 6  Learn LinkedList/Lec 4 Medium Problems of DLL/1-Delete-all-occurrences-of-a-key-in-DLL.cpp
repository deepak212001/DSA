/*

Delete all occurrences of a given key in a doubly linked list


A doubly-linked list is a data structure that consists of sequentially linked nodes, and the nodes have reference to both the previous and the next nodes in the sequence of nodes.


You’re given a doubly-linked list and a key 'k'.


Delete all the nodes having data equal to ‘k’.


Example:
Input: Linked List: 10 <-> 4 <-> 10 <-> 3 <-> 5 <-> 20 <-> 10 and ‘k’ = 10

Output: Modified Linked List: 4 <-> 3 <-> 5 <-> 20

Explanation: All the nodes having ‘data’ = 10 are removed from the linked list.


Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
7
10 4 10 3 5 20 10
10


Sample Output 1:
4 3 5 20


Explanation Of Sample Input 1:
All the nodes having ‘data’ = 10 are removed from the linked list.


Sample Input 2:
7
10 4 10 3 5 20 10
30


Sample Output 2:
10 4 10 3 5 20 10


Explanation Of Sample Input 2:
The linked list does not have any node with ‘data’ = 30. So the linked list is unchanged.


Expected Time Complexity:
The expected time complexity is O(‘n’).

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

Node *deleteAllOccurrences(Node *head, int k)
{
    if (!head)
        return head;

    Node *temp = head;

    while (temp)
    {
        if (temp->data == k)
        {
            if (temp == head)
            {
                head = temp->next;
            }
            Node *nextNode = temp->next;
            Node *prevNode = temp->prev;
            if (nextNode != nullptr)
                nextNode->prev = prevNode;
            if (prevNode != nullptr)
                prevNode->next = nextNode;

            delete temp;

            temp = nextNode;
        }
        else
            temp = temp->next;
    }
    return head;

    // TC O(N)
    // SC O(1)
}

int main()
{
    vector<int> arr = {10, 4, 10, 3, 5, 20, 10};

    Node *head = convertArrTODLL(arr);
    printDLL(head);

    head = deleteAllOccurrences(head, 10);
    printDLL(head);

    return 0;
}