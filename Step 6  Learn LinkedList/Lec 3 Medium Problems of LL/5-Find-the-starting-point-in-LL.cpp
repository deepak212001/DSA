/*
Starting point of loop in a Linked List


52

0
Problem Statement: Given the head of a linked list that may contain a cycle, return the starting point of that cycle. If there is no cycle in the linked list return null.

Examples
Example 1:
Input: LL: 1  2  3  4  5 

Output: 3
Explanation: This linked list contains a loop of size 3 starting at node with value 3.
Example 2:
Input: LL: LL: 1 -> 2 -> 3 -> 4 -> 9 -> 9
                

Output: NULL
Explanation:  This linked list does not contain  a loop hence has no starting point. 

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

void print(Node* temp)
{
    if(temp)
        cout << "Detected a loop at node with data: " << temp->data << endl;
    else
        cout << "NoT Detected a loop in this linked list" << endl;
    
}

Node* BruteForce(Node* head)
{
    if(head==nullptr || head->next==nullptr)
        return head;

    Node* temp=head;
    unordered_map<Node*,int> mp;

    while(temp)
    {
        if(mp.find(temp)!=mp.end())
            return temp;

        mp[temp]=1;
        temp=temp->next;
    }
    return nullptr;

    // TC O(N)
    // SC O(N)
}


Node* Optimal(Node* head)
{
    if(head==nullptr )
        return nullptr;

    Node* slow=head;
    Node* fast=head;
    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            slow=head;
            while(slow!=fast)
            {
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        }
    }
    return nullptr;

    // TC O(N)
    // SC O(1)
}


int main()
{
    vector<int> arr = {2, 8, 4, 5};
    Node* head=createLL();
    Node* head2=convertArrTOLL(arr);
    
    Node* temp=BruteForce(head);
    print(temp);
    temp=BruteForce(head2);
    print(temp);
    
    temp=Optimal(head);
    print(temp);
    temp=Optimal(head2);
    print(temp);
    
    


    return 0;
}