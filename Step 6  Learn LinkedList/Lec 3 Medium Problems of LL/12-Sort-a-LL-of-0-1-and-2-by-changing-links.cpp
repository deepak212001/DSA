/*
Sort a linked list of 0s, 1s and 2s

Given a linked list of 'N' nodes, where each node has an integer value that can be 0, 1, or 2. You need to sort the linked list in non-decreasing order and the return the head of the sorted list.



Example:
Given linked list is 1 -> 0 -> 2 -> 1 -> 2. 
The sorted list for the given linked list will be 0 -> 1 -> 1 -> 2 -> 2.


Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
7
1 0 2 1 0 2 1


Sample Output 1:
0 0 1 1 1 2 2


Explanation Of Sample Input 1:
Input: 1 -> 0 -> 2 -> 1 -> 0 -> 2 -> 1

Output: 0 -> 0 -> 1 -> 1 -> 1 -> 2 -> 2

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
    int cnt0=0;
    int cnt1=0;
    int cnt2=0;
    
    while(temp)
    {
        if(temp->data==0)
            cnt0++;
        else if(temp->data==1)
            cnt1++;
        else 
            cnt2++;

        temp=temp->next; 
    }
    temp=head;
    while(temp)
    {
        if(cnt0!=0)
        {
            cnt0--;
            temp->data=0;
        }
        else if(cnt1!=0)
        {
            cnt1--;
            temp->data=1;
        }
        else
        {
            temp->data=2;
        }
        temp=temp->next;
    }
    return head;

    // TC O(2N)
    // SC O(1)
    
}


Node* Optimal(Node* head)
{
    if(head==nullptr || head->next==nullptr)
        return head;
    
    Node* zeroHead= new Node(-1);
    Node* zero=zeroHead;
    Node* oneHead= new Node(-1);
    Node* one=oneHead;
    Node* twoHead= new Node(-1);
    Node* two=twoHead;

    Node* temp=head;

    while(temp)
    {
        if(temp->data==0)
        {
            zero->next=temp;
            zero=temp;
        }
        else if(temp->data==1)
        {
            one->next=temp;
            one=temp;
        }
        else
        {
            two->next=temp;
            two=temp;
        }
        temp=temp->next;
        
    }
    zero->next=(oneHead->next) ? (oneHead->next) :(twoHead->next);
    one->next=twoHead->next;
    two->next=nullptr;

    Node* newHead=zeroHead->next;
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return newHead;

    // TC O(N)
    // SC O(1)

}


int main()
{
    vector<int> arr = {2,1,2,1,2,0,0,0,2,1,2};


    Node* head=convertArrTOLL(arr);
    printLL(head);

    head=BruteForce(head);
    printLL(head);

    head=convertArrTOLL(arr);
    printLL(head);

    head=Optimal(head);
    printLL(head);


    return 0;
}