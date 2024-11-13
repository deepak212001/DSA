/*
Pattern - 17: Alpha-Hill Pattern


Problem Statement: Given an integer N, print the following pattern : 


Here, N = 4.

Examples:

Input Format: N = 3
Result: 
  A  
 ABA 
ABCBA


Input Format: N = 6
Result:   
     A     
    ABA    
   ABCBA   
  ABCDCBA  
 ABCDEDCBA 
ABCDEFEDCBA

*/

#include<bits/stdc++.h>
using namespace std;

void pattern(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            cout<<" ";
        }
        /*
        char ch='A';
        for(int j=0;j<=i;j++)
        {
            cout<<ch;
            ch++;
        }
        ch--;
        for(int j=0;j<i;j++)
        {
            ch--;
            cout<<ch;
        }
        */
        char ch = 'A';
        int breakpoint = (2*i+1)/2;
        for(int j=1;j<=2*i+1;j++){      
            cout<<ch;
            if(j <=breakpoint) ch++;
            else ch--;
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