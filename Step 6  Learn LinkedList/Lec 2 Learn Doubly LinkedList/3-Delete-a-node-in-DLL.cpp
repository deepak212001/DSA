/*
Delete Last Node of a Doubly Linked List

Problem Statement: Given a Doubly Linked List. Delete the last of a Doubly Linked List.

Examples
Example 1: DLL: 1 <-> 3 <-> 4 <-> 1


Result: DLL: 1 <-> 3 <-> 4


Explanation: After deleting the tail node we will get a doubly linked list. The node at the end of the doubly linked list will no longer be a part of it.

Input Format: DLL: 7 <-> 5

Result: DLL: 7

Explanation: 7 will be the only node left after we delete the tail node of the doubly linked list.

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
    if(head==nullptr)
        cout<<"Empty"<<endl;
    
    while (head)
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

Node *removeFirst(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr;

    Node *temp = head;
    head = head->next;
    head->prev=nullptr;
    temp->next =nullptr;
    delete temp;
    return head;
}

Node* removeLast(Node* head)
{
    if(head==nullptr || head->next==nullptr )
        return nullptr;
    Node* temp=head;

    while(temp->next)
    {
        temp=temp->next;
    }
    temp->prev->next=nullptr;
    free(temp);

    return head;
}

Node* dltByPosition(Node* head, int k)
{
    if(head==nullptr || (head->next==nullptr && k==1))
        return nullptr;

    Node* temp=head;

    if(k==1)
    {
        head=head->next;
        head->prev=nullptr;
        delete temp;
        return head;
    }
    int cnt=0;
    while(temp)
    {
        cnt++;
        if(cnt==k)
        {
            if(temp->next)
            {
                temp->next->prev=temp->prev;
            }
            temp->prev->next=temp->next;
            delete temp;
            break;
        }
        temp=temp->next;
    }
    return head;


    // TC O(N)
    // SC O(1)
}

Node* dltByValue(Node* head, int k)
{
    if(head==nullptr)
        return nullptr;

    Node* temp=head;

    if(head->data==k)
    {
        head=head->next;
        head->prev=nullptr;
        delete temp;
        return head;
    }
    
    while(temp)
    {
        if(temp->data==k)
        {
            temp->prev->next=temp->next;
            if(temp->next)
            {
                temp->next->prev=temp->prev;
            }
            delete temp;
            break;
        }
        temp=temp->next;
    }
    return head;

    // TC O(N)
    // SC O(1)
}

void dltnode(Node* head)
{
    // give that node who want to dlt
    

    head->prev->next=head->next;
    if(head->next==nullptr)
    {
        // if last node
        head->prev=nullptr;
        delete head;
        return;
    }
    head->next->prev=head->prev;

    head->next=head->prev=nullptr;
    delete head;
}


int main()
{
    vector<int> arr = {2, 8, 9, 10, 7,20,30, 4, 5};

    Node *head = convertArrTODLL(arr);
    printDLL(head);

    head=removeFirst(head);
    printDLL(head);

    head=removeLast(head);
    printDLL(head);
 
    head=dltByPosition(head,5);
    printDLL(head);
 
    head=dltByValue(head,10);
    printDLL(head);
    
    cout<<" by node: \n";
    dltnode(head->next->next);
    printDLL(head);

    return 0;
}