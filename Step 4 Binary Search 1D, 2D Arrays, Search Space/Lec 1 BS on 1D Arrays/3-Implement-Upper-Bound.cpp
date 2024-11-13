/*
Implement Upper Bound


Problem Statement: Given a sorted array of N integers and an integer x, write a program to find the upper bound of x.

Pre-requisite: Binary Search algorithm

Examples
Example 1:
Input Format:
 N = 4, arr[] = {1,2,2,3}, x = 2
Result:
 3
Explanation:
 Index 3 is the smallest index such that arr[3] > x.

Example 2:
Input Format:
 N = 6, arr[] = {3,5,8,9,15,19}, x = 9
Result:
 4
Explanation:
 Index 4 is the smallest index such that arr[4] > x.


 The upper bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than the given key i.e. x.

The upper bound is the smallest index, ind, where arr[ind] > x.

But if any such index is not found, the upper bound algorithm returns n i.e. size of the given array. The main difference between the lower and upper bound is in the condition. For the lower bound the condition was arr[ind] >= x and here, in the case of the upper bound, it is arr[ind] > x.

*/

#include <bits/stdc++.h>
using namespace std;

int BruteForce(vector<int> arr, int target, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > target)
            return i;
    }
    return n;

    // TC 0(N)
    // SC O(1)
}

int Optimal(vector<int> arr, int n, int target)
{
    // Using binary search
    /*
    int low=0;
    int high=n-1;
    int ans =n;
    int mid;

    while (low<=high)
    {
        mid=(low+high)/2;

        if(arr[mid]>target)
        {
            ans=mid;
            high=mid-1;
        }
        else
            low=mid+1;
    }
    return ans;
    */

    int low = 0;
    int high = n - 1;
    int mid;
    if (arr[high] < target)
        return high;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
    // TC O(logN)
    // SC O(1)
}
int inbuiltfun(vector<int> arr, int n, int target)
{
    int l = upper_bound(arr.begin(), arr.end(), target) - arr.begin();
    return l;
}

int main()
{
    vector<int> arr = {3, 5, 8, 9, 15, 19};
    int n = 6, x = 9;
    int ind = BruteForce(arr, x, n);
    cout << "The upper bound is the index: " << ind << "\n";
    ind = Optimal(arr, n, x);
    cout << "The upper bound is the index: " << ind << "\n";

    ind = inbuiltfun(arr, n, 6);
    cout << "The upper bound is the index: " << ind << "\n";
    return 0;
}
