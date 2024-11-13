/*
Pattern - 11: Binary Number Triangle Pattern


Problem Statement: Given an integer N, print the following pattern : 


Here, N = 5.

Examples:

Input Format: N = 3
Result: 
1
01
101

Input Format: N = 6
Result:   
1
01
101
0101
10101
010101

*/

#include<bits/stdc++.h>
using namespace std;

void pattern(int n)
{
    /*
    int a=1;
    int b=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<a;
            a=1-a;
        }
        b=1-b;
        a=b;
        cout<<'\n';
    }
    */
   int start=1;
   for(int i=1;i<=n;i++)
    {
        if(i%2==0)
            start=0;
        else 
            start=1;
        for(int j=1;j<=i;j++)
        {
            cout<<start;
            start=1-start;
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