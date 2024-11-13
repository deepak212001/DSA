/*
Pattern - 9: Diamond Star Pattern



Problem Statement: Given an integer N, print the following pattern : 


Here, N = 5.

Examples:

Input Format: N = 3
Result: 
  *  
 ***
***** 
*****  
 ***
  *   
Input Format: N = 6
Result:   
     *
    ***
   ***** 
  *******
 *********
***********  
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

int unthinkable() {
    int n;
    cout << "Enter the number of rows for the diamond (odd number): ";
    cin >> n;

    if (n % 2 == 0) {
        cout << "Please enter an odd number for a symmetric diamond." << endl;
        return 1;
    }

    int mid = n / 2;

    // Upper part of the diamond
    for (int i = 0; i <= mid; i++) {
        for (int j = 0; j < n; j++) {
            if (j >= mid - i && j <= mid + i) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }

    // Lower part of the diamond
    for (int i = mid - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            if (j >= mid - i && j <= mid + i) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
int main()
{
    int n;
    cout<<"Enter the value of n ";
    cin>>n;
    // pattern(n);
    unthinkable();
    return 0;
}