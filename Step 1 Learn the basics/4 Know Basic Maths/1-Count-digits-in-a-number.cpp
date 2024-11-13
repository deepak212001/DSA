/*

Count digits in a number


Problem Statement: Given an integer N, return the number of digits in N.

Examples
Example 1:
Input:N = 12345
Output:5
Explanation:  The number 12345 has 5 digits.
Example 2:
Input:N = 7789
Output: 4
Explanation: The number 7789 has 4 digits.
*/

#include<bits/stdc++.h>
using namespace std;

int BruteForce(int n)
{
    int count=0;
    while(n)
    {
        count++;
        n/=10;
    }
    return count;
    //TC 0(logN +1)
    /* n ki jitni digit utni timw while loop chalega*/
}

int Optimal(int n)
{
    int count=(int)log10(n); 
    // auto casted log value  float me to int me change kar dega
    return count+1;

    /*
    int count=to_string(n).size();
    return count;
    */
    // TC O(1)
    // SC O(1)
}

int main()
{
    int n;
    cout<<"Enter n ";
    cin>>n;
    cout<<"\n "<<BruteForce(n);
    cout<<"\n "<<Optimal(n);

}