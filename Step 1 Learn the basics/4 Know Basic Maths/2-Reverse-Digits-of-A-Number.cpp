/*
Reverse Digits of A Number


Problem Statement: Given an integer N return the reverse of the given number.

Note: If a number has trailing zeros, then its reverse will not include them. For e.g., reverse of 10400 will be 401 instead of 00401.

Examples
Example 1:
Input:N = 12345
Output:54321
Explanation: The reverse of 12345 is 54321.
Example 2:
Input:N = 7789
Output: 9877
Explanation: The reverse of number 7789 is 9877.


*/

#include <bits/stdc++.h>
using namespace std;

int Optimal(int n)
{
    int rev = 0;
    while (n)
    {
        rev=rev * 10 + n % 10;
        n /= 10;
    }
    return rev;
    // TC 0(logN+1)
}


int main()
{
    int n;
    cout << "Enter n ";
    cin >> n;
    cout<<"\n "<<Optimal(n);
}