/*
Clone Linked List with Random and Next Pointer


31

0
Problem Statement: Given a linked list where every node in the linked list contains two pointers:

‘next’ which points to the next node in the list.
‘random’ which points to a random node in the list or ‘null’.
Create a ‘deep copy’ of the given linked list and return it.

*/



#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *random; 

    Node(int val, Node *add = nullptr, Node *add1 = nullptr)
    {
        data = val;
        next = add;
        random = add1;
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

void printCLL(Node *head) 
{
    while (head != nullptr) 
    {
        cout << "Data: " << head->data;
        if (head->random != nullptr) 
            cout << ", Random: " << head->random->data;
        else 
            cout << ", Random: nullptr";
        
        cout << endl;
         // Move to the next node
        head = head->next;  
    }
}


Node* BruteForce(Node* head)
{
    Node* temp=head;
    unordered_map<Node*, Node*> mp;

    while(temp)
    {
        Node* newl = new Node(temp->data);
        mp[temp]=newl;
        temp=temp->next;
    }

    temp=head;
    while(temp)
    {
        Node* copyNode=mp[temp];
        copyNode->next=mp[temp->next];
        copyNode->random=mp[temp->random];
        temp=temp->next;
    }

    return mp[head];

    // TC O(2N)
    // SC O(N)+O(N)
}



void insertCopyInBetween(Node* head)
{
    Node* temp=head;
    while(temp)
    {
        Node* nextNode=temp->next;
        Node* copy=new Node(temp->data);

        copy->next=nextNode;
        temp->next=copy;
        temp=nextNode;
    }

}
void connectRandomPointers(Node* head)
{
    Node* temp=head;
    while(temp)
    {
        Node* copyNode=temp->next;

        if(temp->random)
        {
            copyNode->random=temp->random->next;
        }
        else    
            copyNode->random=nullptr;
        
        temp=temp->next->next;
    }
}
Node* getDeepCopyList(Node* head)
{
    Node* temp=head;
    Node* dummy=new Node(-1);
    Node* res=dummy;

    while(temp)
    {
        res->next=temp->next;
        res=res->next;
        temp->next=temp->next->next;
        temp=temp->next;
    }
    return dummy->next;
}
Node* Optimal(Node* head)
{
    if(!head) return nullptr;   
    
     // Step 1: Insert copy of
     // nodes in between
    insertCopyInBetween(head); 
    // Step 2: Connect random
    // pointers of copied nodes
    connectRandomPointers(head);  
    // Step 3: Retrieve the deep
    // copy of the linked list
    return getDeepCopyList(head); 

    // TC O(3N)
    // SC 0(N)
}

int main() 
{
    // Example linked list: 7 -> 14 -> 21 -> 28
    Node* head = new Node(7);
    head->next = new Node(14);
    head->next->next = new Node(21);
    head->next->next->next = new Node(28);

    // Assigning random pointers
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next;
    head->next->next->next->random = head->next;

    cout << "Original Linked List with Random Pointers:" << endl;
    printCLL(head);

    // Clone the linked list
    // Node* clonedList = BruteForce(head);
    // cout << "\nCloned Linked List with Random Pointers:" << endl;
    // printCLL(clonedList);

    // Clone the linked list
    Node* cloned = Optimal(head);
    cout << "\nCloned Linked List with Random Pointers:" << endl;
    printCLL(cloned);

    return 0;
}