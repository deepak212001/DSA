/*
Rotate a Linked List


25

0
In this article, we will solve the problem: "Rotate a Linked List"

Problem Statement: Given the head of a linked list, rotate the list to the right by k places.

Examples:

Example 1:
Input:
    head = [1,2,3,4,5]
    k = 2
Output:
 head = [4,5,1,2,3]
Explanation:
 We have to rotate the list to the right twice.


Example 2:
Input:
    head = [1,2,3]
    k = 4
Output:
head = [3,1,2]
Explanation:
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
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *BruteForce(Node *head, int k)
{
    if (head == nullptr || head->next == nullptr || k == 0)
        return head;

    int cnt = 0;
    Node *temp = head;
    while (temp)
    {
        temp = temp->next;
        cnt++;
    }
    k = k % cnt;
    if (k == 0)
        return head;
    while (k != 0)
    {
        k--;
        temp = head;
        while (temp->next->next)
        {
            temp = temp->next;
        }
        Node *end = temp->next;
        temp->next = nullptr;
        end->next = head;
        head = end;
    }
    return head;

    // TC O(N) +O(N * ( N%K ))
    // SC O(1)
}
Node *Optimal(Node *head, int k)
{
    if (head == nullptr || head->next == nullptr || k == 0)
        return head;

    int cnt = 1;
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
        cnt++;
    }
    temp->next = head;
    k = k % cnt;
    int end = cnt - k;

    while (end != 0)
    {
        end--;
        temp = temp->next;
    }
    head = temp->next;
    temp->next = nullptr;

    return head;

    // TC  O(N) + O(N - (N%k))
    // SC O(1)
}

int main()
{
    vector<int> arr = {2, 8, 4, 5, 6, 1};

    Node *head = convertArrTOLL(arr);
    printLL(head);

    head = BruteForce(head, 10);
    printLL(head);

    // head=Optimal(head,4);
    // printLL(head);

    return 0;
}