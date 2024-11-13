/*
Remove N-th node from the end of a Linked List


50

1
Problem Statement: Given a linked list and an integer N, the task is to delete the Nth node from the end of the linked list and print the updated linked list.

Examples
Example 1:

Input Format: 5->1->2, N=2

Result: 5->2


Explanation: The 2nd node from the end of the linked list is 1. Therefore, we get this result after removing 1 from the linked list.

Example 2:

Input Format: 1->2->3->4->5, N=3

Result: 1->2->4->5

Explanation: The 3rd node from the end is 3, therefore, we remove 3 from the linked list.

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

Node* BruteForce(Node* head,int k)
{
    if(head==nullptr)
        return head;
    
    int cnt=0;
    Node* temp=head;

    while(temp)
    {
        cnt++;
        temp=temp->next;
    }

    if(cnt==k)
    {
        // that means you remove first node 
        Node* newHead=head->next;
        head->next=nullptr;
        delete head;
        return newHead;
    }

    int res=cnt-k;
    temp=head;
    while(temp)
    {
        res--;
        if(res==0)
            break;
        
        temp=temp->next;
    }
    Node* dltNode=temp->next;
    temp->next=dltNode->next;
    dltNode->next=nullptr;

    delete dltNode;
    return head;

    // TC O(N) + O(N-K)
    // SC O(1)
}

Node* Optimal(Node* head,int k)
{
    Node* beg=head;
    Node* end=head;
    for(int i=0;i<k;i++)
        end=end->next;
    
    if(end==nullptr)
    {
        // that means you remove first node;
        //k== length of ll

        return head->next;
    }
    while(end->next)
    {
        beg=beg->next;
        end=end->next;
    }
    Node* dltNode=beg->next;
    beg->next=beg->next->next;

    delete dltNode;
    return head;

    // TC O(N)
    // SC O(1)
}


int main()
{
    vector<int> arr = {2, 8, 4, 5,9,6};

    int k=3;
    Node* head=convertArrTOLL(arr);
    printLL(head);

    Node* temp=BruteForce(head,k);
    printLL(temp);

    temp=Optimal(head,k);
    printLL(temp);

    
   

    return 0;
}