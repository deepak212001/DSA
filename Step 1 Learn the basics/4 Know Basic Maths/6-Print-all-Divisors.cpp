/*

Print all Divisors of a given Number

Problem Statement: Given an integer N, return all divisors of N.

A divisor of an integer N is a positive integer that divides N without leaving a remainder. In other words, if N is divisible by another integer without any remainder, then that integer is considered a divisor of N.

Examples
Example 1:
Input:N = 36
Output:[1, 2, 3, 4, 6, 9, 12, 18, 36]
Explanation: The divisors of 36 are 1, 2, 3, 4, 6, 9, 12, 18, 36.
Example 2:
Input:N =12
Output: [1, 2, 3, 4, 6, 12]
Explanation: The divisors of 12 are 1, 2, 3, 4, 6, 12.

*/




#include<bits/stdc++.h>
using namespace std;

vector<int> BruteForce(int n)
{
    vector<int> div;
    int count=0;
    for(int i=1;i<=n;i++)
    {
        if(n%i==0)
            div.push_back(i);
    }
    return div;
    //TC O(N)
    // SC O(N)
}

vector<int> Optimal(int n)
{
    vector<int> div;
    int count=0;
    for(int i=1;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            div.push_back(i);
            if(i!=n/i)
            div.push_back(n/i);
        }   
    }
    sort(div.begin(),div.end());
    return div;
    // TC O(sqr(n))
    // SC O(2*sqr(n))
}

int main()
{
    int n;
    cout<<"Enter n ";
    cin>>n;
    vector<int> d=BruteForce(n);
    for(auto it: d)
    {
        cout<<it<<" ";
    }

    cout<<endl;
    vector<int> v=Optimal(n);
    for(auto it: v)
    {
        cout<<it<<" ";
    }
    

}
