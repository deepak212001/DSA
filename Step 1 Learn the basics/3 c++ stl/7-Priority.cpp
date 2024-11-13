#include<bits/stdc++.h>
using namespace std;

//greater is in top
void explainPQ()
{
    priority_queue<int> pq;

    pq.push(5);  //{5}
    pq.push(2);  //{5,2}
    pq.push(8);  //{8,5,2,}
    pq.emplace(10);  //{10,8,5,2}

    cout<<pq.top()<<endl;  //print 10
    pq.pop(); //{8,5,2}
    // cout<<pq[1]; not allowed
    cout<<pq.top()<<endl;  //print 8
    cout<<pq.size()<<endl; // 5
    cout<<pq.empty()<<endl; //0 means false 

    //size,swap wmpty function same as other
    // smaller is in top
    //minimum heap
    priority_queue<int,vector<int>,greater<int>> pq1;
    pq1.push(5);  //{5}
    pq1.push(2);  //{2,5}
    pq1.push(8);  //{2,5,8}
    pq1.emplace(10);  //{2,5,8,10}

    cout<<pq1.top()<<endl;  //print 2
}



int main()
{
    explainPQ();
}