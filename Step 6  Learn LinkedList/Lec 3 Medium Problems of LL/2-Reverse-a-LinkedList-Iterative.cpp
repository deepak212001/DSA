/*
Reverse a Linked List


60

0
Problem Statement: Problem Statement: Given the head of a singly linked list, write a program to reverse the linked list, and return the head pointer to the reversed list.

Examples
Example 1:

Input Format:

LL: 1   3   2   4 


Output: 3


Explanation: After reversing the linked list, the new head will point to the tail of the old linked list.

Example 2:

Input Format:

LL: 4


Output: 4


Explanation: In this example, the linked list contains only one node hence reversing this linked list will result in the same list as the original.

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
    stack<int> st;
    while(temp)
    {
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    
    while(temp)
    {
        temp->data=st.top();
        st.pop();
        temp=temp->next;
    }

    return head;

    // TC O(2N)
    // SC O(N)
}


Node* Optimal(Node* head)
{
    // Iterative 

    
    if(head==nullptr || head->next==nullptr)
        return head;

    Node* prev=nullptr;
    Node* current=head;
    while(current)
    {
        Node* nextNode=current->next;
        current->next=prev;
        prev=current;
        current=nextNode;
    }

    return prev;

    // TC O(N)
    // SC O(1)
}


int main()
{
    vector<int> arr = {2, 8, 4, 5};


    Node* head=convertArrTOLL(arr);
    printLL(head);

    head=BruteForce(head);
    printLL(head);

    head=Optimal(head);
    printLL(head);
   

    return 0;
}