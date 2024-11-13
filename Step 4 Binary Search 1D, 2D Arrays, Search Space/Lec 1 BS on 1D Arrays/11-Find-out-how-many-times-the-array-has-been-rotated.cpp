/*
Find out how many times the array has been rotated


42

5
Problem Statement: Given an integer array arr of size N, sorted in ascending order (with distinct values). Now the array is rotated between 1 to N times which is unknown. Find how many times the array has been rotated.

Pre-requisites: Find minimum in Rotated Sorted Array,  Search in Rotated Sorted Array II & Binary Search algorithm

Examples
Example 1:
Input Format:
 arr = [4,5,6,7,0,1,2,3]
Result:
 4
Explanation:
 The original array should be [0,1,2,3,4,5,6,7]. So, we can notice that the array has been rotated 4 times.

Example 2:
Input Format:
 arr = [3,4,5,1,2]
Result:
 3
Explanation:
 The original array should be [1,2,3,4,5]. So, we can notice that the array has been rotated 3 times.



*/

#include <bits/stdc++.h>
using namespace std;

int Linear(vector<int> &arr)
{
    int n = arr.size(); // size of array.
    int ans = INT_MAX, index = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < ans)
        {
            ans = arr[i];
            index = i;
        }
    }
    return index;

    // TC O(N)
    // SC O(1)
}
int Binary(vector<int> arr)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int mid;
    int ans = INT_MAX;
    int index = -1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[low] <= arr[high])
        {
            if (arr[low] < ans)
            {
                ans = arr[low];
                index = low;
            }
            break;
        }

        if (arr[low] <= arr[mid])
        {
            if (arr[low] < ans)
            {
                ans = arr[low];
                index = low;
            }
            low = mid + 1;
        }
        else
        {
            if (arr[mid] < ans)
            {
                ans = arr[mid];
                index = mid;
            }
            high = mid - 1;
        }
    }
    return index;

    // TC O(logN)
    // SC O(1   )
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int ans = Linear(arr);
    cout << "The array is rotated " << ans << " times.\n";
    cout << "The array is rotated " << Binary(arr) << " times.\n";
    return 0;
}
