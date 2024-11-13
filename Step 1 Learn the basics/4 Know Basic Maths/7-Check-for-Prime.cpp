/*
Check if a number is prime or not


Problem Statement: Given an integer N, check whether it is prime or not. A prime number is a number that is only divisible by 1 and itself and the total number of divisors is 2.

Examples
Example 1:
Input:N = 2
Output:True
Explanation: 2 is a prime number because it has two divisors: 1 and 2 (the number itself).
Example 2:
Input:N =10
Output: False
Explanation: 10 is not prime, it is a composite number because it has 4 divisors: 1, 2, 5 and 10.


*/



#include<bits/stdc++.h>
using namespace std;

bool BruteForce(int n)
{
    for(int i=2;i<n;i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
    //TC 0(N)
    //SC O(1)
}

int Optimal(int n)
{
    for(int i=2;i*i<n;i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
    // TC O(sqr(n))
    // SC O(1)
}

int main()
{
    int n;
    cout << "Enter n ";
    cin >> n;
    BruteForce(n) ? cout<<"Prime" : cout<<"Not Prime";
    Optimal(n) ? cout<<"Prime" : cout<<"Not Prime";
}