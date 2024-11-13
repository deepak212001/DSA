/*
Segregate even and odd nodes in LinkedList


Problem Statement : Segregate even and odd nodes in LinkedList

Given a LinkedList of integers. Modify the LinkedList in such a way that in Modified LinkedList all the even numbers appear before all the odd numbers in LinkedList.

Also, note that the order of even and odd numbers should remain the same. 

Examples:

Example 1:
Input: 1→2→3→4→5→6→Null
Output: 1→3→5→2→4→6→Null
Explanation : 
Odd Nodes in LinkedList are 1,3,5 and 
Even Nodes in LinkedList are 2,4,6
In Modified LinkedList all even Nodes comes before 
all Odd Nodes. So Modified LinkedList looks like 
 1→3→5→2→4→6→Null. Order of even and odd Nodes is 
maintained in modified LinkedList.

Example 2:
Input: 1→3→5→Null
Output: 1→5→3→Null
Explantion: As there are no Even Nodes in LinkedList, 
The Modified LinkedList is same as Original LinkedList.

Example 3:
Input: 2→4→6→8→Null
Output: 2→6→4→8→Null
Explanation: As there are no Odd Nodes in LinkedList, 
The Modified LinkedList is same as Original LinkedList.
Disclaimer: Don't jump directly to the solution, try it out yourself first.

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
    
    Node* odd=head;
    Node* even=head->next;

    vector<int> arr;

    while (odd && odd->next)
    {
        arr.push_back(odd->data);
        odd=odd->next->next;
    }
    if(odd)
        arr.push_back(odd->data);

    while (even && even->next)
    {
        arr.push_back(even->data);
        even=even->next->next;
    }
    if(even)
        arr.push_back(even->data);

    Node* temp=head;
    int i=0;
    while(temp)
    {
        temp->data=arr[i];
        i++;
        temp=temp->next;
    }

    return head;

    // TC O(N)
    // SC O(N)
    
}

Node* Optimal(Node* head)
{
    if(head==nullptr || head->next==nullptr)
        return head;
    
    Node* odd=head;
    Node* even=head->next;
    Node* oddHead=odd;
    Node* evenHead=even;

    while (even && even->next)
    {
        
        odd->next=odd->next->next;
        even->next=even->next->next;
        odd=odd->next;
        even=even->next;
    }
    odd->next=evenHead;

    return head;

    // TC O(N/2) * 2= O (N)
    // SC O(1)
    
}

int main()
{
    vector<int> arr = {2, 8, 4, 5,10,9};


    Node* head=convertArrTOLL(arr);
    printLL(head);
   
    head=BruteForce(head);
    printLL(head);
   
    head=Optimal(head);
    printLL(head);

    return 0;
}