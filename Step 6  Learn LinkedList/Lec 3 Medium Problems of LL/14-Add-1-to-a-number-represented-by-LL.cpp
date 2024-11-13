/*
 Add one to a number represented as Linked List


You're given a positive integer represented in the form of a singly linked-list of digits. The length of the number is 'n'.



Add 1 to the number, i.e., increment the given number by one.



The digits are stored such that the most significant digit is at the head of the linked list and the least significant digit is at the tail of the linked list.



Example:
Input: Initial Linked List: 1 -> 5 -> 2

Output: Modified Linked List: 1 -> 5 -> 3

Explanation: Initially the number is 152. After incrementing it by 1, the number becomes 153.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
3
1 5 2


Sample Output 1:
1 5 3


Explanation For Sample Input 1:
Initially the number is 152. After incrementing it by 1, the number becomes 153.


Sample Input 2:
2
9 9


Sample Output 2:
1 0 0


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

int addHelper(Node* temp)
{
    if(temp==nullptr)
        return 1;
    
    int carry=addHelper(temp->next);
    temp->data+=carry;
    if(temp->data <10)
        return 0;
    
    temp->data=0;
    return 1;
}

Node* add1(Node* head)
{
    int carry=addHelper(head);

    if(carry==1)
    {
        Node* newHead=new Node(1,head);
        head=newHead;
    }
    return head;

    // TC O(N)
    // SC O(N)
}

int main()
{
    vector<int> arr = {2, 8, 4, 5};
    vector<int> arr1 = {9,9,9};


    Node* head=convertArrTOLL(arr);
    printLL(head);
    Node* head1=convertArrTOLL(arr1);
    printLL(head1);

    head=add1(head);
    printLL(head);
   
    head1=add1(head1);
    printLL(head1);
   

    return 0;
}


/*
Mine 

Node* reverse(Node* head)
{
    Node* cur=head;
    Node* prev=nullptr;
    Node* save;
    while(cur)
    {
        save=cur->next;
        cur->next=prev;
        prev=cur;
        cur=save;
    }
    return prev;
}

Node *addOne(Node *head)
{
    Node* revl=reverse(head);
    Node* temp=revl;
    int carry=0;
    while(temp)
    {
        if(temp->data<9)
        {
            temp->data++;
            break;
        }
        else
        {
            temp->data=0;
            carry=1;
            if(temp->next ==nullptr)
            {
                Node* dummy=new Node(carry);
                temp->next=dummy;
                break;
            }
        }
        temp=temp->next;
    }
    return reverse(revl);
}


*/