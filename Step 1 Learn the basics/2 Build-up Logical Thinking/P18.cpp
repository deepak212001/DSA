/*
Pattern-18: Alpha-Triangle Pattern


Problem Statement: Given an integer N, print the following pattern : 


Here, N = 5.

Examples:

Input Format: N = 3
Result: 
C
B C
A B C

Input Format: N = 6
Result:   
F
E F
D E F
C D E F
B C D E F
A B C D E F


*/

#include<bits/stdc++.h>
using namespace std;

void pattern(int n)
{
    for(int i=0;i<n;i++)
    {
        char ch='A'+n-i-1;
        for(int j=0;j<=i;j++)
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