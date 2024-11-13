/*
Nth Root of a Number using Binary Search


47

4
Problem Statement: Given two numbers N and M, find the Nth root of M. The nth root of a number M is defined as a number X when raised to the power N equals M. If the 'nth root is not an integer, return -1.

Examples
Example 1:
Input Format:
 N = 3, M = 27
Result:
 3
Explanation:
 The cube root of 27 is equal to 3.

Example 2:
Input Format:
 N = 4, M = 69
Result:
 -1
Explanation:
 The 4th root of 69 does not exist. So, the answer is -1.

*/





#include <bits/stdc++.h>
using namespace std;

long long func(int mid,int n, int m);
int Linear(int n, int m) 
{
    //Use linear search on the answer space:
    for (int i = 1; i <= m; i++) {
        long long val = func(i, n,m);
        if (val == m ) 
            return i;
        else if (val > m) 
            break;
    }
    return -1;

    // TC O(M)
    // SC O(1)
}
long long func(int mid,int n, int m)
{
    long long ans=1;
    for(int i=0;i<n;i++)
    {
        ans*=mid;
        if(ans>m)
            break;
    }
    return ans;
}
int Binary(int n, int m) 
{
    int low=1;
    int high=m;
    int mid;

    while(low<=high)
    {
        mid=(low+high)/2;
        long long val=func(mid,n,m);

        if(val==m)
            return mid;
        if(val<m)
            low=mid+1;
        else
            high=mid-1;
    }
    return -1;
}

int main()
{
    int n = 3, m = 27;
    int ans = Linear(n, m);
    cout << "The answer is: " << ans << "\n";
    
    cout << "The answer is: " << Binary(6,4096) << "\n";
    cout << "The answer is: " << Binary(3,126) << "\n";
    cout << "The answer is: " << Binary(9,1953125) << "\n";
    return 0;
}

