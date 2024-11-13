/*
Find intersection of Two Linked Lists


42

0
Problem Statement: Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

Examples:

Example 1:
Input:
List 1 = [1,3,1,2,4], List 2 = [3,2,4]
Output:
2
Explanation: Here, both lists intersecting nodes start from node 2.

Example 2:
Input:
 List1 = [1,2,7], List 2 = [2,8,1]
Output:
 Null
Explanation: Here, both lists do not intersect and thus no intersection node is present.

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

void insertNode(Node* &head,int val) 
{
    Node* newNode = new Node(val);
    
    if(head == NULL) {
        head = newNode;
        return;
    }
    
    Node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    
    temp->next = newNode;
    return;
}

void printLL(Node* head) {
    while (head!= NULL) 
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout<<endl;
}

Node* BruteForce(Node* head1,Node* head2) {
    unordered_set<Node*> st;
    while(head1 != NULL) 
    {
        st.insert(head1);
        head1 = head1->next;
    }
    while(head2 != NULL) 
    {
        if(st.find(head2) != st.end()) 
            return head2;

        head2 = head2->next;
    }
    return NULL;

    // TC O(N+M)
    // SC O(N)

}

int diff(Node* head1, Node* head2)
{
    int len1=0,len2=0;
    while(head1 || head2)
    {
        if(head1)
        {
            len1++;
            head1=head1->next;
        }
        if(head2)
        {
            len2++;
            head2=head2->next;
        }

    }
    return len1-len2;

}

Node* Better(Node* head1,Node* head2) 
{
    int d=diff(head1,head2);

    if(d<0)
    {
        while(d!=0)
        {
            head2=head2->next;
            d++;
        }
    }
    else
    {
        while(d!=0)
        {
            d--;
            head1=head1->next;
        }
    }

    while(head1)
    {
        if(head1==head2)
            return head1;
        head1=head1->next;
        head2=head2->next;
    }
    return head1;

    // TC O(2 max(length of list1,length of list2))+O(abs(length of list1-length of list2))+O(min(length of list1,length of list2))
    // SC O(1)

}

Node* Optimal(Node* head1,Node* head2) 
{
    if(head1==nullptr || head2==nullptr)
        return nullptr;

    Node* temp1=head1;
    Node* temp2=head2;

    while(temp1!=temp2)
    {
        temp1=temp1->next;
        temp2=temp2->next;

        if(temp1==temp2)
            return temp1;
        
        if(temp1==nullptr)
            temp1=head2;
        
        if(temp2==nullptr)
            temp2=head1;

    }
    return temp1;

    // TC O(N1+N2)
    // SC O(1)
}

int main()
{
    Node* head = nullptr;
    insertNode(head,1);
    insertNode(head,3);
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,4);
    Node* head1 = head;
    head = head->next->next->next;
    Node* headSec = nullptr;
    insertNode(headSec,3);
    Node* head2 = headSec;
    headSec->next = head;
    //printing of the lists
    cout<<"List1: "; printLL(head1);
    cout<<"List2: "; printLL(head2);

    Node* answerNode = BruteForce(head1,head2);
    if(answerNode == nullptr )
        cout<<"No intersection\n";
    else
        cout<<"The intersection point is "<<answerNode->data<<endl;
   
    answerNode = Better(head1,head2);
    if(answerNode == nullptr )
        cout<<"No intersection\n";
    else
        cout<<"The intersection point is "<<answerNode->data<<endl;
   
    answerNode = Optimal(head1,head2);
    if(answerNode == nullptr )
        cout<<"No intersection\n";
    else
        cout<<"The intersection point is "<<answerNode->data<<endl;
   

    return 0;
}