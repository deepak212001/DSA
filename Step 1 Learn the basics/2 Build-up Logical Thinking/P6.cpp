/*
Pattern - 6: Inverted Numbered Right Pyramid


Problem Statement: Given an integer N, print the following pattern : 


Here, N = 5.

Examples:

Input Format: N = 3
Result: 
1 2 3
1 2
1

Input Format: N = 6
Result:
1 2 3 4 5 6
1 2 3 4 5
1 2 3 4
1 2 3
1 2 
1

*/

#include<bits/stdc++.h>
using namespace std;

void pattern(int n)
{
    for(int i=n;i>0;i--)
    {
        for(int j=1;j<=i;j++)
            cout<<j<<" ";
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