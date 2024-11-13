/*
Pattern-5: Inverted Right Pyramid


Problem Statement: Given an integer N, print the following pattern : 


Here, N = 5.

Examples:

Input Format: N = 3
Result: 
* * *
* * 
*

Input Format: N = 6
Result:
* * * * * *
* * * * * 
* * * * 
* * * 
* * 
*

*/

#include<bits/stdc++.h>
using namespace std;

void pattern(int n)
{
    for(int i=n;i>0;i--)
    {
        for(int j=1;j<=i;j++)
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