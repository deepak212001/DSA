/*
Pattern - 8: Inverted Star Pyramid



Problem Statement: Given an integer N, print the following pattern : 


Here, N = 5.

Examples:

Input Format: N = 3
Result: 
*****  
 ***
  *   
Input Format: N = 6
Result:     
***********
 *********
  *******
   ***** 
    ***    
     *

*/


#include<bits/stdc++.h>
using namespace std;

void pattern(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j>=i)
                cout<<"* ";
            else 
                cout<<"  ";
        }

        for(int j=0;j<n-i;j++)
        {   
            cout<<"* ";
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
