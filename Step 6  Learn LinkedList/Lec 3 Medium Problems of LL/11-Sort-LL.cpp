/*
Sort a Linked List


Problem Statement: Given a linked list, sort its nodes based on the data value in them. Return the head of the sorted linked list.

Examples
Example 1:
Input:Linked List: 3 4 2 1 5

Output:Sorted List: 1 2 3 4 5

Explanation:  The input linked list when sorted from [3, 4, 2, 1, 5] results in a linked list with values: [1, 2, 3, 4, 5].


                
Example 2:
Input:List: 40 20 60 10 50 30

Output: Sorted List: 10 20 30 40 50 60

Explanation:  The input linked list when sorted from [40, 20, 60, 10, 50, 30] results in a linked list with values: [10, 20, 30, 40, 50, 60].

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
    if(head==nullptr | head->next==nullptr)
        return head;
    
    vector<int> arr;
    Node* temp=head;
    while(temp)
    {
        arr.push_back(temp->data);
        temp=temp->next;
    }
    sort(arr.begin(),arr.end());
    temp=head;
    int i=0;
    while(temp)
    {
        temp->data=arr[i];
        i++;
        temp=temp->next;
    }
    return head;

    // TC O(N) + O(NlogN) + O(N)
    // SC O(N)
}


Node* mergeTwoSortedLL(Node* list1, Node* list2)
{
    Node* dummy=new Node(-1);
    Node* temp=dummy;

    while(list1 && list2)
    {
        if(list1->data < list2->data)
        {
            temp->next=list1;
            temp=list1;
            list1=list1->next;
        }
        else
        {
            temp->next=list2;
            temp=list2;
            list2=list2->next; 
        }

    }
    if(list1)
        temp->next=list1;
    else
        temp->next=list2;

    return dummy->next;
}


Node* findMiddle(Node* head)
{
    if(head==nullptr || head->next==nullptr)
        return head;

    Node* slow=head;
    Node* fast=head->next;

    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

Node* Optimal(Node* head)   
{
    if(head==nullptr || head->next==nullptr)
        return head;
    
    Node* middle=findMiddle(head);

    Node* right=middle->next;
    middle->next=nullptr;
    Node* left =head;

    left=Optimal(left);
    right=Optimal(right);

    return mergeTwoSortedLL(left,right);

}


int main()
{
    vector<int> arr = {2, 8, 4, 5};
    vector<int> arr1 = {2, 1, 4, 3};


    Node* head=convertArrTOLL(arr);
    printLL(head);

    head=BruteForce(head);
    printLL(head);
   
    Node* head1=convertArrTOLL(arr1);
    printLL(head1);

    head1=Optimal(head1);
    printLL(head1);
   

    return 0;
}