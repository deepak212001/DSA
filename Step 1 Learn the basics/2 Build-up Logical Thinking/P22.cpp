/*

Pattern - 22: The Number Pattern


Problem Statement: Given an integer N, print the following pattern : 


Here, N = 4.

Examples:

Input Format: N = 3
Result: 
3 3 3 3 3 
3 2 2 2 3 
3 2 1 2 3 
3 2 2 2 3 
3 3 3 3 3

Input Format: N = 6
Result:   
6 6 6 6 6 6 6 6 6 6 6 
6 5 5 5 5 5 5 5 5 5 6 
6 5 4 4 4 4 4 4 4 5 6 
6 5 4 3 3 3 3 3 4 5 6 
6 5 4 3 2 2 2 3 4 5 6 
6 5 4 3 2 1 2 3 4 5 6 
6 5 4 3 2 2 2 3 4 5 6 
6 5 4 3 3 3 3 3 4 5 6 
6 5 4 4 4 4 4 4 4 5 6 
6 5 5 5 5 5 5 5 5 5 6 
6 6 6 6 6 6 6 6 6 6 6

*/

#include<bits/stdc++.h>
using namespace std;

void pattern(int n)
{
    for(int i=0;i<=2*n-1;i++)
    {
        for(int j=0;j<=2*n-1;j++)
        {
            int top=i;
            int bottom=j;
            int right=(2*n-2)-j;
            int left=(2*n-2)-i;

            cout<<(n-min(min(top,bottom),min(left,right)));

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