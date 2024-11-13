#include<bits/stdc++.h>
using namespace std;

void explainPair()
{
    pair<int,int> p={1,3};

    cout<<p.first<<" "<<p.second;  //1 3

    pair<int,pair<int,int>> p1={1,{3,4}};
    cout<<p1.first<<" "<<p1.second.second<<" "<<p1.second.first; //1 4 3
    // count<<p1.second; wrong give error; 

    pair<int,int> arr[]={{1,2},{2,5},{5,1}};
    // cout<<arr[1]; wrong give error;
    // cout<<arr[1].first<<" "<<arr[1].second; //2 5
}
int main()
{
    explainPair();
}