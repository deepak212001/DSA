/*
Pattern - 7: Star Pyramid


Problem Statement: Given an integer N, print the following pattern : 


Here, N = 5.

Examples:

Input Format: N = 3
Result: 
  *  
 *** 
*****   
Input Format: N = 6
Result:
     *     
    ***    
   *****   
  *******  
 ********* 
***********


*/


#include<bits/stdc++.h>
using namespace std;

void pattern(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j>=n-i+1)
                cout<<"* ";
            else 
                cout<<"  ";
        }

        for(int j=1;j<i;j++)
        {   
            cout<<"* ";
        }
        cout<<'\n';

    }
        /*
        Aur

        for (int i = 0; i < N; i++)
        {
            for (int j =0; j<N-i-1; j++)
            {
                cout <<" ";
            }
            
            for(int j=0;j< 2*i+1;j++){
                
                cout<<"*";
            }
            
            for (int j =0; j<N-i-1; j++)
            {
                cout <<" ";
            }
            cout << endl;
        }

        */
       

}

int main()
{
    int n;
    cout<<"Enter the value of n ";
    cin>>n;
    pattern(n);
    return 0;
}