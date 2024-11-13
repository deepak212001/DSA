/*
Find middle element in a Linked List


Problem Statement: Given the head of a linked list of integers, determine the middle node of the linked list. However, if the linked list has an even number of nodes, return the second middle node.

Examples
Example 1:
Input: LL: 1  2  3  4  5 

Output: 3
Explanation: Node with value 3 is the middle node of this linked list.
Example 2:
Input: LL: 1  2  3  4  5  6
                

Output: 4
Explanation:  In this example, the linked list has an even number of nodes hence we return the second middle node which is 4.

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


void printLL(Node* head) {
    while (head!= NULL) 
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout<<endl;
}


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



Node *BruteForce(Node *head) 
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

    int mid=(cnt/2) +1;
    temp=head;

    while(temp)
    {
        mid--;
        if(mid==0)
            break;
        
        temp=temp->next;
    }
    return temp;

    // TC O(N+ N/2) = O(N)
    // SC O(1)
}



Node *Optimal(Node *head) 
{
    if(head==nullptr && head->next==nullptr)
        return head;

    Node* slow=head;
    Node* fast=head;

    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;

    // TC O(N/2) = O(N)
    // SC O(1
}

int main()
{
    vector<int> arr = {2, 8, 4, 5,1};

    Node* head=convertArrTOLL(arr);
    printLL(head);

    Node* middleNode = BruteForce(head);
    cout<<middleNode->data<<endl;

    middleNode = Optimal(head);
    cout<<middleNode->data<<endl;
    return 0;


}