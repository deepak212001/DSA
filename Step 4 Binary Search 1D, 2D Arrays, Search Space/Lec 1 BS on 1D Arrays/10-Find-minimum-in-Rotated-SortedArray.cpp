/*

Minimum in Rotated Sorted Array


36

0
Problem Statement: Given an integer array arr of size N, sorted in ascending order (with distinct values). Now the array is rotated between 1 to N times which is unknown. Find the minimum element in the array. 

Pre-requisites: Search in Rotated Sorted Array I,  Search in Rotated Sorted Array II & Binary Search algorithm

Examples
Example 1:
Input Format:
 arr = [4,5,6,7,0,1,2,3]
Result:
 0
Explanation:
 Here, the element 0 is the minimum element in the array.

Example 2:
Input Format:
 arr = [3,4,5,1,2]
Result:
 1
Explanation:
 Here, the element 1 is the minimum element in the array.

*/





#include <bits/stdc++.h>
using namespace std;

int search(vector<int> arr, int n)
{
    int low=0;
    int high=n-1;
    int mid;
    int ans=INT_MAX;

    while(low<=high)
    {
        mid=(low+high)/2;
        // for duplicate element 
        if (arr[low] == arr[mid] && arr[mid] == arr[high]) 
        {
            low = low + 1;
            high = high - 1;
            continue;
        }

        if (arr[low] <= arr[high]) 
        {
            ans = min(ans, arr[low]);
            break;
        }

        if(arr[low]<=arr[mid])
        {
            ans=min(ans,arr[low]);
            low=mid+1;
        }
        else
        {
            ans=min(ans,arr[mid]);
            high=mid-1;
        }
    }
    return ans;

    // TC O(logN)
    // SC O(1   )
}

int main()
{
    vector<int> arr = {7, 8, 9, 0,1, 2, 3, 4, 5, 6};
    int n = 9;
    cout<<"Minimum element in rotated sorted array is "<<search(arr,n)<<endl;
    return 0;
}


