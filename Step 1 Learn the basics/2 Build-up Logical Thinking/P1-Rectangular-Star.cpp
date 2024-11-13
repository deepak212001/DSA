/*
Pattern-1: Rectangular Star Pattern


Problem Statement: Given an integer N, print the following pattern.


Examples:

Example 1:
Input: N = 3
Output: 
* * *
* * *
* * *


Example 2:
Input: N = 6
Output:
* * * * * *
* * * * * *
* * * * * *
* * * * * *
* * * * * *
* * * * * *
*/

#include<bits/stdc++.h>
using namespace std;

void pattern(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<"* ";
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