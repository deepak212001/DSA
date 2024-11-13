/*
Insert at the head of a Linked List


10

0
Problem Statement:  Given a linked list and an integer value val, insert a new node with that value at the beginning (before the head) of the list and return the updated linked list.

Examples
Example 1:

Input Format: 0->1->2, val = 5

Result: 5->0->1->2


Explanation: We need to insert the value 5 before the head of the given Linked List.

Example 2:

Input Format:12->5->8->7, val = 100

Result: 100->12->5->8->7

Explanation: Again, we need to insert the value 100 before the head of the Linked List.

*/

/*
Delete Last Node of Linked List


31

3
Problem Statement: Given a linked list, delete the tail of the linked list and print the updated linked list.

Examples
Example 1:

Examples:

Input Format: 0->1->2

Result: 0->1


Explanation: The tail of the list is the last node. After removing the tail, and updating the linked list, this result is what we get.

Example 2:

Input Format: 12->5->8->7

Result: 12->5->8

Explanation: Again, after deleting the tail and updating the linked list, the list ends at the second last node, which is the new tail.

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

Node* convertArrToLL(vector<int> arr)
{
    Node* head= new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++)
    {
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;

    // TC O(N)

}

void printLL(Node* head) {
    while (head != NULL) 
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout<<endl;
}

Node* insertFirst(Node* head, int val)
{
    // Node* temp=new Node(val,head);
    // head=temp;
    // return head;

    return new Node(val,head);
}

Node* insertLast(Node* head, int val)
{
    if(head==nullptr || head->next==nullptr )
        return new Node(val,head);
    Node* add=new Node(val);
    Node* temp=head;

    while(temp->next)
    {
        temp=temp->next;
    }
    temp->next=add;
    add->next=nullptr;

    return head;
}

Node* insertByPosition(Node* head, int k, int val)
{
    if(head==nullptr)
    {
        if(k==1)
            return new Node(val,head);
        else
            return head;
    }

    if(k==1)
            return new Node(val,head);

    Node* temp=head;
    int cnt=0;
    while(temp)
    {
        cnt++;
        if(cnt==k-1)
        {   
            Node* add=new Node(val,temp->next);
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
            Node* add=new Node(val,temp->next);
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
    vector<int> arr = {2, 8, 4,9 };
    Node* head=convertArrToLL(arr);
    printLL(head);

    head=insertFirst(head,30);
    printLL(head);

    head=insertLast(head,40);
    printLL(head);

    head=insertByPosition(head,7,20);
    printLL(head);

    head=insertBeforeValue(head,4,10);
    printLL(head);

    head=insertBeforeValue(head,90,50);
    printLL(head);

    

    return 0;
}