/*
Pattern - 12: Number Crown Pattern



Problem Statement: Given an integer N, print the following pattern : 


Here, N = 5.

Examples:

Input Format: N = 3
Result: 
1    1
12  21
123321

Input Format: N = 6
Result:   
1          1
12        21
12       321
1234    4321
12345  54321
123456654321

*/

#include<bits/stdc++.h>
using namespace std;


void pattern12(int N)
{
    
      int spaces = 2*(N-1);
      
      for(int i=1;i<=N;i++)
      {
          for(int j=1;j<=i;j++){
              cout<<j;
          }
          for(int j = 1;j<=spaces;j++){
              cout<<" ";
          }
          for(int j=i;j>=1;j--){
              cout<<j;
          }
          
          cout<<endl;
          spaces-=2;
      }
}

void pattern(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j<=i)
                cout<<j;
            else
                cout<<" ";
        }
        for(int j=n;j>0;j--)
        {
            if(j<=i)
                cout<<j;
            else
                cout<<" ";
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