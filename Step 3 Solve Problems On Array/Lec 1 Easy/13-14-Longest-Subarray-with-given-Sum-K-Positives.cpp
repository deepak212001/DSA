/*
Longest Subarray with given Sum K(Positives)


192

0
Problem Statement: Given an array and a sum k, we need to print the length of the longest subarray that sums to k.

Examples
Example 1:
Input Format: N = 3, k = 5, array[] = {2,3,5}
Result: 2
Explanation: The longest subarray with sum 5 is {2, 3}. And its length is 2.

Example 2:
Input Format: N = 5, k = 10, array[] = {2,3,5,1,9}
Result: 3
Explanation: The longest subarray with sum 10 is {2, 3, 5}. And its length is 3.

*/

#include <bits/stdc++.h>
using namespace std;

int BruteForce(vector<int> &arr, int target)
{
    int n = arr.size();
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }
            if (sum == target)
                len = max(len, j - i + 1);
        }
    }
    return len;

    // TC O(N^3)
    // SC O(1)
}

int Better(vector<int> &arr, int target)
{
    int len = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == target)
                len = max(len, j - i + 1);
        }
    }
    return len;

    // TC O(N^2)
    // SC O(1)
}

int BetterHashing(vector<int> &arr, int target)
{
    int n = arr.size();
    int maxLen = 0;
    long long sum = 0;
    map<long long, int> prevSum;

    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == target)
            maxLen=max(maxLen,i+1);

        long long rem =sum-target;

        if(prevSum.find(rem)!=prevSum.end())
        {
            int len =i-prevSum[rem];
            maxLen=max(maxLen,len);

        }
        if(prevSum.find(sum)==prevSum.end())
            prevSum[sum]=i;

    }
    return maxLen;

    // TC O(NlogN)
    // SC O(N)
}

int Optimal(vector<int> &arr, int target)
{
    int n=arr.size();
    int left=0, right=0;
    int maxLen=0;
    long long sum=arr[0];
    while(right<n)
    {
        while(left<=right && sum>target)
        {
            sum-=arr[left];
            left++;
        }

        if(sum==target)
            maxLen=max(maxLen,right-left+1);
        
        right++;
        if(right<n) 
            sum+=arr[right];
    }
    return maxLen;

    // TC O(N)
    // SC O(1)
}

int main()
{
    vector<int> a = {2, 3, 5, 1, 9};
    long long k = 10;
    int len = BruteForce(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    len = Better(a, 9);
    cout << "The length of the longest subarray is: " << len << "\n";
    len = BetterHashing(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    len = Optimal(a, 2);
    // optimal only  use when all elements are +ves
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}
