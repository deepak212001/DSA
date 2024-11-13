/*
Count Subarray sum Equals K


Problem Statement: Given an array of integers and an integer k, return the total number of subarrays whose sum equals k.

A subarray is a contiguous non-empty sequence of elements within an array.

Examples
Example 1:
Input Format:
 N = 4, array[] = {3, 1, 2, 4}, k = 6
Result:
 2
Explanation:
 The subarrays that sum up to 6 are [3, 1, 2] and [2, 4].

Example 2:
Input Format:
 N = 3, array[] = {1,2,3}, k = 3
Result:
 2
Explanation:
 The subarrays that sum up to 3 are [1, 2], and [3].

*/

#include <bits/stdc++.h>
using namespace std;

int BruteForce(vector<int> &arr, int target)
{
    int n = arr.size();
    int cnt = 0;
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
                cnt++;
        }
    }
    return cnt;

    // TC O(N^3)
    // SC O(1)
}

int Better(vector<int> &arr, int target)
{
    int cnt = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == target)
                cnt++;
        }
    }
    return cnt;

    // TC O(N^2)
    // SC O(1)
}

int BetterHashing(vector<int> &arr, int target)
{
    int n = arr.size();
    int cnt = 0;
    long long sum = 0;
    map<long long, int> prevSum;

    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == target)
            cnt++;

        long long rem =sum-target;

        if(prevSum.find(rem)!=prevSum.end())
        {
            // int len =i-prevSum[rem];
            cnt++;
        }
        else 
            prevSum[sum]=i;

    }
    return cnt;

    // TC O(NlogN)
    // SC O(N)
}

int Optimal(vector<int> &arr, int target)
{
    int n=arr.size();
    int left=0, right=0;
    int cnt=0;
    long long sum=arr[0];
    while(right<n)
    {
        while(left<=right && sum>target)
        {
            sum-=arr[left];
            left++;
        }

        if(sum==target)
            cnt++;
        
        right++;
        if(right<n) 
            sum+=arr[right];
    }
    return cnt;

    // TC O(N)
    // SC O(1)
}

int Optimal2(vector < int > & arr, int k)
{
    int n = arr.size(); // size of the given array.
    map<int,int> mpp;
    int preSum = 0, cnt = 0;

    mpp[0] = 1; // Setting 0 in the map.
    for (int i = 0; i < n; i++) {
        // add current element to prefix Sum:
        preSum += arr[i];

        // Calculate x-k:
        int remove = preSum - k;

        // Add the number of subarrays to be removed:
        cnt += mpp[remove];

        // Update the count of prefix sum
        // in the map.
        mpp[preSum] += 1;
    }
    return cnt;
}

int main()
{
    vector<int> a = {3, 1, 2, 4};
    long long k = 6;
    int len = BruteForce(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    len = Better(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    len = BetterHashing(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    len = Optimal(a, k);
    // optimal only  use when all elements are +ves
    cout << "The length of the longest subarray is: " << len << "\n";
    len = Optimal2(a, k);
    // optimal only  use when all elements are +ves
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}