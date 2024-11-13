/*


*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val, Node *add = nullptr)
    {
        data = val;
        next = add;
    }
};

Node *convertArrTOLL(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;

    // TC O(N)
}

void printLL(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* reverseLinkedList(Node* head)
{
    // Recursive
    if (head == nullptr ||  head->next == nullptr)
        return head;

    Node* newhead = reverseLinkedList(head->next);

    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newhead;

    // TC O(N)
    // SC O(1)
}

int main()
{
    vector<int> arr = {2, 8, 4, 5};

    Node *head = convertArrTOLL(arr);
    printLL(head);

    Node *newh = reverseLinkedList(head);
    printLL(newh);
    return 0;
}