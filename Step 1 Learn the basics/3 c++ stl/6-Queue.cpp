#include<bits/stdc++.h>
using namespace std;

void explainqueue()
{
    queue<int> q;

    q.push(1);   // {1}
    q.push(2);   // {1,2}
    q.emplace(4);   // {1,2,4}
    q.back()+=5;
    cout<<q.back()<<endl; // 9
    //q->{1,2,9}
    cout<<q.front()<<endl; // 1   
    
    
    q.pop();   // {2,9}
    cout<<q.front()<<endl; // 2  
    //size swap empty same as stack
}



int main()
{
    explainqueue();
}