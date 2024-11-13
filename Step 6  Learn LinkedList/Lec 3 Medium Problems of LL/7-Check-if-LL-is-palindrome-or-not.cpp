/*
Check if the given Linked List is Palindrome


57

1
Examples
Example 1:

Input Format:

LL: 1  2  3  2  1


Output: True

Explanation: A linked list with values "1 2 3 2 1" is a palindrome because its elements read the same from left to right and from right to left, making it symmetrical and mirroring itself.

Example 2:

Input Format:

LL: 1 2 3 3 2 1


Output: True

Explanation: A linked list with values "1 2 3 3 2 1" is a palindrome because it reads the same forwards and backwards.

Example 3:

Input Format:

LL: 1 2 3 2 3


Output: False

Explanation: The linked list "1 2 3 2 3" is not a palindrome because it reads differently in reverse order, where "3 2 3 2 1" is not the same as the original sequence "1 2 3 2 3."

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

void printLL(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

bool BruteForce(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return true;

    stack<int> st;
    Node *temp = head;

    while (temp)
    {
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    while (temp)
    {
        if (temp->data != st.top())
            return false;
        temp = temp->next;
        st.pop();
    }
    return true;

    // TC O(N)
    // SC O(N)
}

Node* reverseLinkedList(Node* head) 
{
    if (head == NULL || head->next == NULL) 
        return head; 
    
    Node* prev=nullptr;
    Node* current=head;
    while(current)
    {
        Node* nextNode=current->next;
        current->next=prev;
        prev=current;
        current=nextNode;
    }

    return prev;
}

bool Optimal(Node* head)
{
    if (head == nullptr || head->next == nullptr)
        return true;

    Node* slow=head;
    Node* fast=head;
    while(fast->next && fast->next->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    Node* newHead=reverseLinkedList(slow->next);
    Node* first=head;
    Node* second=newHead;

    while(second)
    {
        if(first->data != second->data)
        {
            reverseLinkedList(newHead); // for make original ll
            return false;
        }

        first=first->next;
        second=second->next;
    }
    reverseLinkedList(newHead); // for make original ll
    return true;
    
}

int main()
{
    vector<int> arr = {2, 8, 4, 5};
    vector<int> arr2 = {2, 8, 4, 8, 2};

    Node *head = convertArrTOLL(arr);
    printLL(head);
    Node *head2 = convertArrTOLL(arr2);
    printLL(head2);

    if (BruteForce(head))
        cout << "The linked list is a palindrome." << endl;
    else
        cout << "The linked list is not a palindrome." << endl;
    if (BruteForce(head2))
        cout << "The linked list is a palindrome." << endl;
    else
        cout << "The linked list is not a palindrome." << endl;

    if (Optimal(head))
        cout << "The linked list is a palindrome." << endl;
    else
        cout << "The linked list is not a palindrome." << endl;
    if (Optimal(head2))
        cout << "The linked list is a palindrome." << endl;
    else
        cout << "The linked list is not a palindrome." << endl;

    return 0;
}