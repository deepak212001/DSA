/*

Search Insert Position  (lower bound)


31

0
Problem Statement: You are given a sorted array arr of distinct values and a target value x. You need to search for the index of the target value in the array.

If the value is present in the array, then return its index. Otherwise, determine the index where it would be inserted in the array while maintaining the sorted order.

Pre-requisite: Lower Bound & Binary Search

Example 1:
Input Format: arr[] = {1,2,4,7}, x = 6
Result: 3
Explanation: 6 is not present in the array. So, if we will insert 6 in the 3rd index(0-based indexing), the array will still be sorted. {1,2,4,6,7}.

Example 2:
Input Format: arr[] = {1,2,4,7}, x = 2
Result: 1
Explanation: 2 is present in the array and so we will return its index i.e. 1.  

    */

#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int>& arr, int x) 
{
    /*
    int n=arr.size();
    int low=0;
    int high =n-1;
    int ans=n;
    
    while (low<=high)
    {
        int mid=(low+high)/2;

        if(arr[mid]>=x)
        {
            ans=mid;
            high=mid-1;
        }
        else
            low=mid+1;
    }
    return ans;
    */


    int n=arr.size();
    int low=0;
    int high=n-1;
    int mid;
    if(arr[high]<x)
        return n;
    while (low<=high)
    {
        mid=(low+high)/2;
        
        if(arr[mid]==x)
            return mid;
        if(arr[mid] >x)
            high=mid-1;
        else 
            low=mid+1;
    }
    return low;
    
}


int main()
{
    vector<int> arr = {1, 2, 4, 7};
    int x = 6;
    int ind = searchInsert(arr, x);
    cout << "The index is: " << ind << "\n";
    ind = searchInsert(arr, 2);
    cout << "The index is: " << ind << "\n";
    return 0;
}