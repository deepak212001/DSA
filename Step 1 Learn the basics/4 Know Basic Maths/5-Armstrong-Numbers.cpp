/*

Check if a number is Armstrong Number or not


Problem Statement: Given an integer N, return true it is an Armstrong number otherwise return false.

An Amrstrong number is a number that is equal to the sum of its own digits each raised to the power of the number of digits.

Examples
Example 1:
Input:N = 153
Output:True
Explanation: 1^3+5^3+3^3 = 1 + 125 + 27 = 153
Example 2:
Input:N = 371
Output: True
Explanation: 3^3+5^3+1^3 = 27 + 343 + 1 = 371

*/



#include <bits/stdc++.h>
using namespace std;

int Optimal(int n)
{
    int s=(int)log10(n)+1;
    int dul=n;
    int sum = 0;
    while (n>0)
    {
        int ld=n%10;
        sum+= pow(ld,s);
        n /= 10;
    }
    return sum==dul;
    // TC 0(logN+1)
    // SC O(1)
}


int main()
{
    int n;
    cout << "Enter n ";
    cin >> n;
    Optimal(n) ?cout<<"Armstrong" : cout<<"Not Armstrong";
}