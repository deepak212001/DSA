/*
Pattern - 16: Alpha-Ramp Pattern


Problem Statement: Given an integer N, print the following pattern : 


Here, N = 5.

Examples:

Input Format: N = 3
Result: 
A
B B
C C C

Input Format: N = 6
Result:   
A 
B B
C C C
D D D D
E E E E E
F F F F F F

*/

#include<bits/stdc++.h>
using namespace std;

void pattern(int n)
{
    char ch='A';
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {    
            cout<<ch;
        }
        ch++;
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