/*
Reverse Linked List in groups of Size K


Problem Statement: Given the head of a singly linked list of `n` nodes and an integer `k`, where k is less than or equal to `n`. Your task is to reverse the order of each group of `k` consecutive nodes, if `n` is not divisible by `k`, then the last group of remaining nodes should remain unchanged.

Examples
Example 1:

Input Format:

LL: 1  2  3  4  5  6  7  8  9  10
K = 3


Output: 3  2  1  6  5  4  9  8  7  10


Explanation:

Group 1: Reverse nodes 1 -> 2 -> 3 to become 3 -> 2 -> 1.
Group 2: Reverse nodes 4 -> 5 -> 6 to become 6 -> 5 -> 4.
Group 3: Reverse nodes 7 -> 8 -> 9 to become 9 -> 8 -> 7.
Node 10 remains as is since there are no more groups of size K remaining.
Example 2:

Input Format:

LL: 5  4  3  7  9  2

K = 4


Output: 7 3 4 5 9 2


Explanation: 

Group 1: Reversed nodes 5 -> 4 -> 3 -> 7 to become 7 -> 3 -> 4 -> 5.
Group 2: Nodes 9 -> 2 remain unchanged as they are not a complete group of size K.
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

void printLL(Node* head)
{
    Node* temp=head;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;

    }
    cout<<endl;
}
Node* reverseLinkedList(Node *head)
{
    
   Node* temp = head;  
   Node* prev = NULL;  
   
   while(temp != NULL)
   {  
       Node* front = temp->next;
       temp->next = prev;  
       prev = temp;  
       temp = front; 
   }

   return prev;  
}

Node* getKthNode(Node* temp, int k)
{
    
    k -= 1; 
    
    while(temp != NULL && k > 0)
    {
        k--; 
        temp = temp -> next; 
    }
    
    return temp; 
}

Node* kReverse(Node* head, int k)
{
    
    Node* temp = head; 
    Node* prevLast = NULL; 
    
    while(temp != NULL)
    {
        Node* kThNode = getKthNode(temp, k); 
        if(kThNode == NULL)
        {
            if(prevLast)
                prevLast -> next = temp; 
        
            break; 
        }
        
        Node* nextNode = kThNode -> next; 
        kThNode -> next = NULL; 
        reverseLinkedList(temp); 
        
        if(temp == head)
            head = kThNode;
        else
            prevLast -> next = kThNode; 
        
        prevLast = temp; 
        temp = nextNode; 
    }

    return head; 

    // TC O(2N)
    // SC O(1)
}


int main()
{
    vector<int> arr = {2, 8, 4, 5};

    Node* head=convertArrTOLL(arr);
    printLL(head);

    head=kReverse(head,3);
    printLL(head);

    return 0;
}