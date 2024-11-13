/*
Pattern - 21: Hollow Rectangle Pattern


Problem Statement: Given an integer N, print the following pattern : 


Here, N = 5.

Examples:

Input Format: N = 3
Result: 
***
* *
***

Input Format: N = 6
Result:   
******
*    *
*    *
*    *
*    *
******

*/

#include<bits/stdc++.h>
using namespace std;

void pattern(int n)
{
    for(int i=0;i<n;i++)
    {
        
        for(int j=0;j<n;j++)
        {    
            if(i==0||j==0||j==n-1||i==n-1)
                cout<<"*";
            else 
                cout<<" ";
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
