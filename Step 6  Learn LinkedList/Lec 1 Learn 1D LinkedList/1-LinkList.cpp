/*
Memory Space:
Let’s talk about assuming the data stored is integer. Another main difference between an array and a linked list is the memory used. In the case of an array, we are storing integers that consume 4 Bytes for every int, whereas in a linked list, we are storing data and a pointer at every node, so the memory used up will depend on the configuration of the system.

32 Bit System	                    64 Bit System
Int -     4 Bytes	                Int -    4 Bytes
Pointer - 4 Bytes	                Pointer - 8 Bytes
Overall - 8 Bytes	                Overall - 12 Bytes
Therefore, in the case of a 64 Bit system, it occupies or consumes more space than a 32 Bit system.

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


int lengthOfLL(Node* head)
{
    int cnt=0;
    while(head)
    {
        cnt++;
        head=head->next;
    }
    return cnt;
    // TC O(N)
    // SC O(1)
}

bool checkItPresent(Node* head, int val)
{
    while(head)
    {
        if(head->data==val)
            return true;
        head=head->next;
    }
    return false;
    // TC O(N)  WROST CASE WHEN AT END
    // TC O(N/2)  AVERGAE CASE  WHEN AT MID
    // TC O(1)     BEST CASE WHEN AT STARTING
    // SC O(1)
}


int main()
{
    vector<int> arr = {2, 8, 4, 5};

    /*

     // y is object of node type and it is store in stack memory 
    Node y = Node(arr[0]);
    cout << y.data << endl;
    cout << y.next << endl;

        // x is store in heap memory bcz it is dynamic memory
    Node *x = new Node(arr[1],&y);
    cout << x << endl;
    cout << x->data << endl;
    cout << x->next << endl;

    Node *z = new Node(arr[2],x);
    cout << z << endl;
    cout << z->data << endl;
    cout << z->next << endl;
    */

    // array convert into ll

    Node* head=convertArrTOLL(arr);
    // never move head form first node
    Node* temp=head;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;

        // TC O(N)
        // SC O(1)
    }

    cout<<endl<<lengthOfLL(head)<<endl;
    
    int num=50;
    cout<<(checkItPresent(head,num) ? "True" : "    False");

    return 0;
}