/*
Pattern - 20: Symmetric-Butterfly Pattern


4

1
Problem Statement: Given an integer N, print the following pattern : 


Here, N = 5.

Examples:

Input Format: N = 3
Result: 
*    *
**  **
******
**  **
*    *


Input Format: N = 6
Result:   
*          *
**        **
***      ***
****    ****
*****  *****
************
*****  *****
****    ****
***      ***
**        **
*          *


*/


#include<bits/stdc++.h>
using namespace std;

void pattern(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<'*';
        }

        for(int j=2*n-2;j>2*i;j--)
        { 
            cout<<" ";
        }
        for(int j=0;j<=i;j++)
        {
            cout<<'*';
        }
        cout<<'\n';

    }

    for(int i=0;i<n;i++)
    {
        for(int j=1;j<n-i;j++)
        {
            cout<<'*';
        }

        for(int j=0;j<=2*i+1;j++)
        { 
            cout<<" ";
        }
        for(int j=1;j<n-i;j++)
        {
            cout<<'*';
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