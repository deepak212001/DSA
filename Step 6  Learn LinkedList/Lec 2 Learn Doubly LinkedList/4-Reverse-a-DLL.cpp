/*
Reverse a Doubly Linked List


21

1
Problem Statement: Given a doubly linked list of size ‘N’ consisting of positive integers, your task is to reverse it and return the head of the modified doubly linked list.

Examples
Example 1:

Input Format:

DLL: 1 <-> 2 <-> 3 <-> 4


Result: DLL: 4 <-> 3 <-> 2 <-> 1


Explanation: The doubly linked list is reversed and its last node is returned at the new head pointer.

Example 2:

Input Format:

DLL: 10 <-> 20 <-> 30


Result: DLL: 30 <-> 20 <-> 10


Explanation: In this case, the doubly linked list is reversed and its former tail is returned as its new head.

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

Node *BruteForce(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    stack<int> st;

    Node *temp = head;
    while (temp)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;

    while (temp)
    {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;

    // TC O(N)
    // SC O(N)
}

Node *Optimal(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *prev = nullptr;
    Node *current = head;

    while (current)
    {
        prev = current->prev;
        current->prev = current->next;
        current->next = prev;

        current = current->prev;
    }

    return prev->prev;

    // TC O(N)
    // SC O(1)

    /*
        FOR LINKLIST

        if(head==nullptr || head->next==nullptr)
        return head;

        Node* prev=nullptr;
        Node* current=head;
        Node* save=current->next;

        while (current)
        {
            save=current->next;
            current->next=prev;
            prev=current;
            current=save;
        }

        return prev ;

        FOR DLL

        if(head==nullptr || head->next==nullptr)
        return head;

        Node* prevn=nullptr;
        Node* current=head;
        Node* save=current->next;

        while (current)
        {
            save=current->next;
            current->next=current->prev;
            current->prev=save;
            prevn=current;
            current=save;
        }

        return prevn ;
    */
}

int main()
{
    vector<int> arr = {2, 8, 4, 5};

    Node *head = convertArrTODLL(arr);
    printDLL(head);

    head = BruteForce(head);
    printDLL(head);

    head = Optimal(head);
    printDLL(head);

    return 0;
}