/*
Delete the Middle Node of the Linked List


3

0
Problem Statement: Given the head of a linked list of integers, delete the middle node of the linked list and return the modified head. However, if the linked list has an even number of nodes, delete the second middle node.

Examples
Example 1:

Input Format:

LL: 1  2  3  4  5 


Output: 1 2 4 5


Explanation: Node with value 3 is at the middle node and deleted.

Example 2:

Input Format:

LL: 1  2  3  4


Output: 1 2 4


Explanation: In this example, the linked list has an even number of nodes hence we return the second middle node which is 3.

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

Node* convertArrTOLL(vector<int> arr)
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
    while (head!= NULL) 
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout<<endl;
}


Node* BruteForce(Node* head)
{
    if(head==nullptr || head->next==nullptr)
        return head;
    
    Node* temp=head;
    int cnt=0;
    while(temp)
    {
        cnt++;
        temp=temp->next;
    }
    int  mid=cnt/2;
    temp=head;

    while(temp)
    {
        mid--;
        if(mid==0)
            break;
        
        temp=temp->next;
    }
    Node* dltNode=temp->next;
    temp->next=temp->next->next;
    delete dltNode ;
    return head;

    // TC O(N + N/2)
    // SC O(1)
    
}


Node* Optimal(Node* head)
{
    if(head==nullptr || head->next==nullptr)
        return nullptr;
    
    Node* slow=head;
    Node* fast=head->next->next;

    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* dltNode=slow->next;
    slow->next=slow->next->next;
    delete dltNode ;
    return head;

    // TC O(N/2)
    // SC O(1)
}

int main()
{
    vector<int> arr = {2, 8, 4, 5,6,9};


    Node* head=convertArrTOLL(arr);
    printLL(head);

    head=BruteForce(head);
    printLL(head);

    head=Optimal(head);
    printLL(head);
   

    return 0;
}