/*
Introduction to Doubly Linked List

*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val, Node *nextp = nullptr, Node *prevp = nullptr)
    {
        data = val;
        next = nextp;
        prev = prevp;
    }
};

void printDLL(Node* head) {
    while (head!= NULL) 
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout<<endl;
}

Node* convertArrTODLL(vector<int> arr)
{
    Node* head= new Node(arr[0]);
    Node* prev=head;
    for(int i=1;i<arr.size();i++)
    {
        Node* temp=new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
    return head;

    // TC O(N)

}


int main()
{
    vector<int> arr = {2, 8, 4, 5};

    Node* head=convertArrTODLL(arr);
    printDLL(head);

    return 0;
}