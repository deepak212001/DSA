/*

Check if a number is Palindrome or Not


49

0
Problem Statement: Given an integer N, return true if it is a palindrome else return false.

A palindrome is a number that reads the same backward as forward. For example, 121, 1331, and 4554 are palindromes because they remain the same when their digits are reversed.

Examples
Example 1:
Input:N = 4554
Output:Palindrome Number
Explanation: The reverse of 4554 is 4554 and therefore it is palindrome number
Example 2:
Input:N = 7789
Output: Not Palindrome
Explanation: The reverse of number 7789 is 9877 and therefore it is not palindrome

*/

#include <bits/stdc++.h>
using namespace std;

int Optimal(int n)
{
    int dul=n;
    int rev = 0;
    while (n)
    {
        rev=rev * 10 + n % 10;
        n /= 10;
    }
    return rev==dul;
    // TC 0(logN+1)
    // SCO(1)
}


int main()
{
    int n;
    cout << "Enter n ";
    cin >> n;
    Optimal(n) ?cout<<"Palindrome" : cout<<"Not Palidrome";
}