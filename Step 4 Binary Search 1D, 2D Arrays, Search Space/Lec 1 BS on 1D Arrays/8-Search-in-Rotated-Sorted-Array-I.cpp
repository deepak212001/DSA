/*

Search Element in a Rotated Sorted Array


70

1
Problem Statement: Given an integer array arr of size N, sorted in ascending order (with distinct values) and a target value k. Now the array is rotated at some pivot point unknown to you. Find the index at which k is present and if k is not present return -1.

Examples
Example 1:
Input Format: arr = [4,5,6,7,0,1,2,3], k = 0
Result: 4
Explanation: Here, the target is 0. We can see that 0 is present in the given rotated sorted array, nums. Thus, we get output as 4, which is the index at which 0 is present in the array.

Example 2:
Input Format: arr = [4,5,6,7,0,1,2], k = 3
Result: -1
Explanation: Here, the target is 3. Since 3 is not present in the given rotated sorted array. Thus, we get the output as -1.

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
    int ans = search(arr, n, k);
    if (ans == -1)
        cout << "Target is not present.\n";
    else
        cout << "The index is: " << ans << "\n";
    return 0;
}


