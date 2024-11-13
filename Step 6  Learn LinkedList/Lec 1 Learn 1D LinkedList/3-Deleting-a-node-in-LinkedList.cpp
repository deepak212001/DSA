/*
Delete Last Node of Linked List


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

Node* removeFirst(Node* head)
{
    Node* temp=head;
    head=head->next;
    delete temp;
    return head;
}

Node* removeLast(Node* head)
{
    if(head==nullptr || head->next==nullptr )
        return nullptr;
    Node* temp=head;

    while(temp->next->next)
    {
        temp=temp->next;
    }
    free(temp->next);
    temp->next=nullptr;

    return head;
}

Node* dltByPosition(Node* head, int k)
{
    if(head==nullptr)
        return nullptr;

    Node* temp=head;

    if(k==1)
    {
        head=head->next;
        delete temp;
        return head;
    }
    Node* prev=nullptr;
    int cnt=0;
    while(temp)
    {
        cnt++;
        if(cnt==k)
        {
            prev->next=temp->next;
            delete temp;
            break;
        }
        prev=temp;
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
        delete temp;
        return head;
    }
    Node* prev=nullptr;
    
    while(temp)
    {
        if(temp->data==k)
        {
            prev->next=temp->next;
            delete temp;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;

    // TC O(N)
    // SC O(1)
}


int main()
{
    vector<int> arr = {2, 8, 4, 5,10,12,9 };
    Node* head=convertArrToLL(arr);
    printLL(head);

    head=removeFirst(head);
    printLL(head);

    head=removeLast(head);
    printLL(head);

    head=dltByPosition(head,5);
    printLL(head);

    head=dltByValue(head,10);
    printLL(head);

    head=dltByValue(head,5);
    printLL(head);

    

    return 0;
}