/*
Pattern - 13: Increasing Number Triangle Pattern


Problem Statement: Given an integer N, print the following pattern : 


Here, N = 5.

Examples:

Input Format: N = 3
Result: 
1
2 3
4 5 6

Input Format: N = 6
Result:   
1
2  3
4  5  6
7  8  9  10
11  12  13  14  15
16  17  18  19  20  21

*/

#include<bits/stdc++.h>
using namespace std;

void pattern(int n)
{
    int no=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<no<<" ";
            no++;
        }   
        cout<<'\n';
    }
}

int main()
{
    int n;
    cout<<"Enter the value of n ";
    cin>>n;
    pattern(n);
    return 0;
}