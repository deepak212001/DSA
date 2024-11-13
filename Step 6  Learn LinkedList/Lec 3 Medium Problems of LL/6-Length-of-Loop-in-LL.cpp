/*
Length of Loop in Linked List


7

1
Problem Statement: Given the head of a linked list, determine the length of a loop present in the linked list; if not present, return 0.

Examples
Example 1:

Input Format:

LL: 1  2  3  4  5 


Output: 3
Explanation: A cycle exists in the linked list starting at node 3 -> 4 -> 5 and then back to 3. There are 3 nodes present in this cycle.

Example 2:

Input Format:

LL: 1  2  3  4  9  9


Output: 0

Explanation: In this example, the linked list is linear and does not have a loop hence return 0.

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

Node *convertArrTOLL(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;

    // TC O(N)
}

Node* createLL()
{
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
     // Create a loop
    fifth->next = third; 


    return head;

}



int BruteForce(Node* head)
{
    if(head==nullptr )
        return false;

    Node* temp=head;
    unordered_map<Node*,int> mp;
    int timer=0;
    while(temp)
    {
        if(mp.find(temp)!=mp.end())
            return timer-mp[temp];

        mp[temp]=timer;
        timer++;
        temp=temp->next;
    }
    return false;

    // TC O(N * 2 * log(N))
    // SC O(N)
}

int findLength(Node* slow, Node* fast)
{
    int cnt=1;
    fast = fast->next;
    while(slow!=fast)
    {
        cnt++;
        fast=fast->next;
    }
    return cnt;
}

int Optimal(Node* head)
{
    if(head==nullptr )
        return 0;

    Node* slow=head;
    Node* fast=head;
    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
            return findLength(slow,fast);
    }
    return 0;

    // TC O(N)
    // SC O(1)
}

int main()
{
    vector<int> arr = {2, 8, 4, 5};
    Node* head=createLL();
    Node* head2=convertArrTOLL(arr);
    
    cout<<BruteForce(head)<<endl;
    cout<<BruteForce(head2)<<endl;
    
    cout<<Optimal(head)<<endl;
    cout<<Optimal(head2)<<endl;
   

    return 0;
}