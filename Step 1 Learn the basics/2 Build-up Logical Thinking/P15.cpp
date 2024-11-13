/*
Pattern-15: Reverse Letter Triangle Pattern



Problem Statement: Given an integer N, print the following pattern : 


Here, N = 5.

Examples:

Input Format: N = 3
Result: 
A B C
A B
A

Input Format: N = 6
Result:   
A B C D E F
A B C D E 
A B C D
A B C
A B
A

*/

#include<bits/stdc++.h>
using namespace std;

void pattern(int n)
{
    for(int i=1;i<=n;i++)
    {
        char ch='A';
        for(int j=i;j<=n;j++)
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