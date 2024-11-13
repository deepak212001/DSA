/*
Search Element in Rotated Sorted Array II


43

0
Problem Statement: Given an integer array arr of size N, sorted in ascending order (may contain duplicate values) and a target value k. Now the array is rotated at some pivot point unknown to you. Return True if k is present and otherwise, return False. 

Pre-requisite: Search Element in Rotated Sorted Array I & Binary Search algorithm

Examples
Example 1:
Input Format:
 arr = [7, 8, 1, 2, 3, 3, 3, 4, 5, 6], k = 3
Result:
 True
Explanation:
 The element 3 is present in the array. So, the answer is True.

Example 2:
Input Format:
 arr = [7, 8, 1, 2, 3, 3, 3, 4, 5, 6], k = 10
Result:
 False
Explanation:
 The element 10 is not present in the array. So, the answer is False.


*/




#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& arr, int n, int k) 
{
    int low=0;
    int high=n-1;
    int mid;

    while(low<=high)
    {
        mid=(low+high)/2;
        if(arr[mid]==k)
            return mid;


        //Edge case:  duplicate element 
        if (arr[low] == arr[mid] && arr[mid] == arr[high]) 
        {
            low = low + 1;
            high = high - 1;
            continue;

            // useful in [1,0,1,1,1] arr
        }

        // check left side is sorted
        if(arr[low]<=arr[mid])
        {
            if(arr[low]<=k && k<=arr[mid])
                high=mid-1;
            else // that means the target is not present in this side
                low=mid+1;
        }
        else // that means right side is sorted 
        {
            if(arr[mid]<=k && k<=arr[high])
                low=mid+1;
            else // that means the target is not present in this side   
                high=mid-1;
        }

    }
    return -1;

    // TC O(logN)
    // SC O(1)
}


int main()
{
    vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int n = 9, k = 1;
    bool ans = search(arr, n, k);
    if (!ans)
        cout << "Target is not present.\n";
    else
        cout << "Target is present in the array.\n";
    return 0;
}


