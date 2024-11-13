/*
nsert at end of Doubly Linked List


16

0
Problem Statement: Given a doubly linked list, and a value ‘k’, insert a node having value ‘k’ at the end of the doubly linked list.

Examples
Example 1:

Input Format:

DLL: 1 <-> 2 <-> 3 <-> 4

Value to be Inserted: 6


Result: DLL: 1 <-> 2 <-> 3 <-> 4 <-> 6


Explanation: A new node with value 6 has been inserted at the end of the doubly linked list after the tail node.

Example 2:

Input Format:

DLL: 10 <-> 20 <-> 30

Value to be Inserted: 40


Result: DLL: 10 <-> 20 <-> 30 <-> 40


Explanation: In this case, a new node with value 40 is inserted after 30 which is at the end of the doubly linked list.

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

void printDLL(Node* head) {
    while (head!= NULL) 
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout<<endl;
}

Node* convertArrTODLL(vector<int> arr)
{
    Node* head= new Node(arr[0]);
    Node* prev=head;
    for(int i=1;i<arr.size();i++)
    {
        Node* temp=new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
    return head;

    // TC O(N)

}

Node* insertFirst(Node* head, int val)
{
    Node* temp=new Node(val);
    if(head==nullptr)
        return temp;
        
    temp->next=head;
    head->prev=temp;
    return temp;
}

Node* insertLast(Node* head, int val)
{
    if(head==nullptr)
        return new Node(val);
    
    Node* add=new Node(val);
    Node* temp=head;

    while(temp->next)
    {
        temp=temp->next;
    }
    temp->next=add;
    add->prev=temp;

    return head;
}


Node* insertByPosition(Node* head, int k, int val)
{
    if(head==nullptr)
    {
        if(k==1)
            return new Node(val);
        else
            return head;
    }

    if(k==1)
    {
        Node* temp=new Node(val,head);
        head->prev=temp;
        return temp;
    }

    Node* temp=head;
    int cnt=0;
    while(temp)
    {
        cnt++;
        if(cnt==k-1)
        {   
            Node* add=new Node(val,temp->next,temp);
            if(temp->next)
            {
                temp->next->prev=add;
            }
            temp->next=add;
            break;
        }
        temp=temp->next;
    }
    return head;

    // TC O(N)
    // SC O(1)
}


Node* insertBeforeValue(Node* head, int k,int val)
{
    if(head==nullptr)
        return nullptr;

    Node* temp=head;

    if(head->data==k)
    {
        return new Node(val,head);
    }
    
    
    while(temp->next)
    {
        if(temp->next->data==k)
        {
            Node* add=new Node(val,temp->next,temp);
            if(temp->next)
            {
                temp->next->prev=add;
            }
            temp->next=add;
            break;
        }
        temp=temp->next;
    }
    return head;

    // TC O(N)
    // SC O(1)
}



int main()
{
    vector<int> arr = {2,4,5,1};

    Node* head=convertArrTODLL(arr);
    printDLL(head);

    head=insertFirst(head,30);
    printDLL(head);

    head=insertLast(head,40);
    printDLL(head);

    head=insertByPosition(head,4,20);
    printDLL(head);
    
    head=insertBeforeValue(head,4,10);
    printDLL(head);

    head=insertBeforeValue(head,30,50);
    printDLL(head);
    return 0;
}