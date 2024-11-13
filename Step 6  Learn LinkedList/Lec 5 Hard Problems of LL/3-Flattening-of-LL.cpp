/*
Flattening a Linked List


40

3
Problem Statement: Given a linked list containing ‘N’ head nodes where every node in the linked list contains two pointers:

‘Next’ points to the next node in the list
‘Child’ pointer to a linked list where the current node is the head
Each of these child linked lists is in sorted order and connected by a 'child' pointer. Your task is to flatten this linked list such that all nodes appear in a single layer or level in a 'sorted order'.

*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *child;

    Node(int val, Node *add = nullptr, Node *add1 = nullptr)
    {
        data = val;
        next = add;
        child = add1;
    }
};

Node *convertArrTOLL(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->child = temp;
        mover = temp;
    }
    return head;

    // TC O(N)
}

void printCL(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->child;
    }
    cout << endl;
}
void printLL(Node *head, int depth)
{
    while (head != nullptr)
    {
        cout << head->data;

        if (head->child)
        {
            cout << " -> ";
            printLL(head->child, depth + 1);
        }

        if (head->next)
        {
            cout << endl;
            for (int i = 0; i < depth; ++i)
                cout << "| ";
        }
        head = head->next;
    }
}

Node *BruteForce(Node *head)
{
    vector<int> arr;
    while (head)
    {
        Node *temp = head;
        while (temp)
        {
            arr.push_back(temp->data);
            temp = temp->child;
        }
        head = head->next;
    }

    sort(arr.begin(), arr.end());
    return convertArrTOLL(arr);

    // TC O(N*M) + O(N*M log(N*M)) + O(N*M)
    // SC O(N*M)
}

Node *merge(Node *list1, Node *list2)
{
    Node *dummy = new Node(-1);
    Node *temp = dummy;

    while (list1 && list2)
    {
        if (list1->data < list2->data)
        {
            temp->child = list1;
            temp = list1;
            list1 = list1->child;
        }
        else
        {
            temp->child = list2;
            temp = list2;
            list2 = list2->child;
        }
        temp->next = nullptr;
    }
    if(list1)
        temp->child = list1;
    else
        temp->child = list2;

    if(dummy->child)
        dummy->child->next=nullptr;
    return dummy->child;
}

Node *Optimal(Node *head)
{
    if (head==nullptr || head->next==nullptr)
        return head;

    Node *mergeHead = Optimal(head->next);
    head = merge(mergeHead,head);
    return head;

    // TC: O( N*(2M) ) ~ O(2 N*M)
    // where N is the length of the linked list along the next pointer 
    // M is the length of the linked list along the child pointers.
    // SC O(1)
}

int main()
{
    // Create a linked list with child pointers
    Node *head = new Node(5);
    head->child = new Node(14);

    head->next = new Node(10);
    head->next->child = new Node(4);

    head->next->next = new Node(12);
    head->next->next->child = new Node(20);
    head->next->next->child->child = new Node(13);

    head->next->next->next = new Node(7);
    head->next->next->next->child = new Node(17);

    cout << "Original linked list:" << endl;
    printLL(head, 0);

    // Node* flattened = BruteForce(head);
    // cout << "\nFlattened linked list: ";
    // printCL(flattened);

    Node *flattened1 = Optimal(head);
    cout << "\nFlattened linked list: ";
    printCL(flattened1);

    return 0;
}