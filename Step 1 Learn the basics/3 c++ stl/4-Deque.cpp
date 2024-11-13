#include<bits/stdc++.h>
using namespace std;

void explainDeque()
{
    deque<int>dq;
    dq.push_back(1);   //{1}
    dq.emplace_back(2);   //{1,2}
    dq.push_front(4);   //{4,1,2}
    dq.emplace_front(3);   //{3,4,1,2}
    for(auto it: dq)
    {
        cout<<it<<" ";
    }   //3 4 1 2 
    cout<<endl;

    dq.pop_back();   //{3,4,1}
    dq.pop_front();   //{4,1}
    for(auto it: dq)
    {
        cout<<it<<" ";
    }   //4 1 
    cout<<endl;    


    cout<<dq.back()<<endl;      //1
    cout<<dq.front()<<endl;     //4
    
    //rest function same as vector
        //begin , end , rbegin. rend, clear, insert, size, swap

}
int main()
{
    explainDeque();
}