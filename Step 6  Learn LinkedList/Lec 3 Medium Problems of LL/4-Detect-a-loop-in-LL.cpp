/*


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

Node* createLL()
{
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
     // Create a loop
    fifth->next = third; 


    return head;

}



bool BruteForce(Node* head)
{
    if(head==nullptr )
        return false;

    Node* temp=head;
    unordered_map<Node*,int> mp;

    while(temp)
    {
        if(mp.find(temp)!=mp.end())
            return true;

        mp[temp]=1;
        temp=temp->next;
    }
    return false;

    // TC O(N * 2 * log(N))
    // SC O(N)
}

bool Optimal(Node* head)
{
    if(head==nullptr )
        return false;

    Node* slow=head;
    Node* fast=head;
    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
            return true;
    }
    return false;

    // TC O(N)
    // SC O(1)
}

int main()
{
    vector<int> arr = {2, 8, 4, 5};
    Node* head=createLL();
    Node* head2=convertArrTOLL(arr);
    
    cout<<(BruteForce(head) ? "True \n": "False \n");
    cout<<(BruteForce(head2) ? "True \n": "False \n");
    
    cout<<(Optimal(head) ? "True \n": "False \n");
    cout<<(Optimal(head2) ? "True \n": "False \n");


    return 0;
}