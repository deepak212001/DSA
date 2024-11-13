/*
Pattern-19: Symmetric-Void Pattern


6

0
Problem Statement: Given an integer N, print the following pattern : 


Here, N = 5.

Examples:

Input Format: N = 3
Result: 
******
**  **
*    *
*    *
**  **
******

Input Format: N = 6
Result:   
************
*****  *****
****    ****
***      ***
**        **
*          *
*          *
**        **
***      ***
****    ****
*****  *****
************

*/

#include<bits/stdc++.h>
using namespace std;

void pattern19(int N)
{
      // for the upper half of the pattern.
      
      // initial spaces.
      int iniS = 0;
      for(int i=0;i< N;i++){
          
          //for printing the stars in the row.
          for(int j=1;j<=N-i;j++){
              cout<<"*";
          }
          
          //for printing the spaces in the row.
          for(int j=0;j<iniS;j++){
              cout<<" ";
          }
          
          //for printing the stars in the row.
          for(int j=1;j<=N-i;j++){
              cout<<"*";
          }
          
          // The spaces increase by 2 every time we hit a new row.
          iniS+=2;
          
          // As soon as the stars for each iteration are printed, we move to the
          // next row and give a line break otherwise all stars
          // would get printed in 1 line.
          cout<<endl;
      }
      
      // for lower half of the pattern
      
      // initial spaces.
      iniS = 2*N -2;
      for(int i=1;i<=N;i++){
          
          //for printing the stars in the row.
          for(int j=1;j<=i;j++){
              cout<<"*";
          }
          
          //for printing the spaces in the row.
          for(int j=0;j<iniS;j++){
              cout<<" ";
          }
          
          //for printing the stars in the row.
          for(int j=1;j<=i;j++){
              cout<<"*";
          }
          
          // The spaces decrease by 2 every time we hit a new row.
          iniS-=2;
          
          // As soon as the stars for each iteration are printed, we move to the
          // next row and give a line break otherwise all stars
          // would get printed in 1 line.
          cout<<endl;
      }
      
}

void pattern(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=n-i;j++)
        {
            cout<<'*';
        }

        for(int j=0;j<2*i;j++)
        { 
            cout<<" ";
        }
        for(int j=1;j<=n-i;j++)
        {
            cout<<'*';
        }
        cout<<'\n';

    }

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
}

int main()
{
    int n;
    cout<<"Enter the value of n ";
    cin>>n;
    pattern(n);
    return 0;
}