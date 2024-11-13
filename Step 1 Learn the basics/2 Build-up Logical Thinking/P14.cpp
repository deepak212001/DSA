/*
Pattern-14: Increasing Letter Triangle Pattern


Problem Statement: Given an integer N, print the following pattern : 


Here, N = 5.

Examples:

Input Format: N = 3
Result: 
A
A B
A B C

Input Format: N = 6
Result:   
A
A B
A B C
A B C D
A B C D E
A B C D E F

*/

#include<bits/stdc++.h>
using namespace std;

void pattern(int n)
{
    for(int i=1;i<=n;i++)
    {
        char ch='A';
        for(int j=1;j<=i;j++)
        {    
            cout<<ch;
            ch++;
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