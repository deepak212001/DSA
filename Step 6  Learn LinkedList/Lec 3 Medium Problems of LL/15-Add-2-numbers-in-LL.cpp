/*
Add two numbers represented as Linked Lists


Problem Statement: Given the heads of two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

Examples:

Input Format:
(Pointer/Access to the head of the two linked lists)

num1  = 243, num2 = 564

l1 = [2,4,3]
l2 = [5,6,4]

Result: sum = 807; L = [7,0,8]

Explanation: Since the digits are stored in reverse order, reverse the numbers first to get the or                                                original number and then add them as → 342 + 465 = 807. Refer to the image below.




Input Format:
(Pointer/Access to the head of the two linked lists)

l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]

Result: [8,9,9,9,0,0,0,1]

Explanation: Since the digits are stored in reverse order, reverse the numbers first to get the     original number and then add them as → 9999999 + 9999 = 8999001. Refer to the image below.

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

Node *addTwo(Node *list1, Node *list2)
{
    if (list1 == nullptr && list2 == nullptr)
        return list1;

    Node *dummy = new Node(-1);
    Node *temp = dummy;
    int carry = 0;
    while (list1 || list2 || carry !=0  )
    {
        int sum=0;
        if(list1)
        {
            sum+=list1->data;
            list1=list1->next;
        }
        if(list2)
        {
            sum+=list2->data;
            list2=list2->next;
        }
        sum+=carry;
        carry=sum/10;
        Node* newNode=new Node(sum%10);
        temp->next=newNode;
        temp=temp->next;
    }
    Node* head=dummy->next;
    delete dummy;

    return head;

    // TC O(max(N,M))
    // SC O(max(N,M))
}

int main()
{
    vector<int> arr1 = {2, 8, 4, 5};
    Node *head1 = convertArrTOLL(arr1);
    printLL(head1);

    vector<int> arr2 = {3, 1, 6, 2};
    Node *head2 = convertArrTOLL(arr2);
    printLL(head2);

    Node *head = addTwo(head1, head2);
    printLL(head);

    return 0;
}