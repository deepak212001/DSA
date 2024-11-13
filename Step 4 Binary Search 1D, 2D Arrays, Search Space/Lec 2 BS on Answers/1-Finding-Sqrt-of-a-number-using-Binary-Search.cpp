/*
Finding Sqrt of a number using Binary Search


Problem Statement: You are given a positive integer n. Your task is to find and return its square root. If ‘n’ is not a perfect square, then return the floor value of 'sqrt(n)'.

Note: The question explicitly states that if the given number, n, is not a perfect square, our objective is to find the maximum number, x, such that x squared is less than or equal to n (x*x <= n). In other words, we need to determine the floor value of the square root of n.

Examples
Example 1:
Input Format:
 n = 36
Result:
 6
Explanation:
 6 is the square root of 36.

Example 2:
Input Format:
 n = 28
Result:
 5
Explanation:
 Square root of 28 is approximately 5.292. So, the floor value will be 5.


*/





#include <bits/stdc++.h>
using namespace std;

int Linear(int n) 
{
    int ans=0;
    for(int i=0;i<=n;i++)
    {
        if(i*i<=n)
            ans=i;
        else 
            break;
    }
    return ans;
    // TC O(N)
    // SC O(1)
}

int Binary(int n) 
{
    int low=1;
    int high=n;
    int mid;
    int ans;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(mid*mid<=n)
        {
            // ans=mid;
            low=mid+1;
        }
        else 
            high=mid-1;
    }
    // return ans;
    return high;
}

int main()
{
    int n = 28;
    int ans = Linear(n);
    cout << "The floor of square root of " << n << " is: " << ans << "\n";
    cout << "The floor of square root of " << n << " is: " << Binary(n) << "\n";
    n=39;
    cout << "The floor of square root of " << n << " is: " <<  Binary(n) << "\n";
    return 0;
}

