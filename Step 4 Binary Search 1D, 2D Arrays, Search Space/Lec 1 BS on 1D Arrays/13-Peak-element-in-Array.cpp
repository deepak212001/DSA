/*

Peak element in Array


56

3
Problem Statement: Given an array of length N. Peak element is defined as the element greater than both of its neighbors. Formally, if 'arr[i]' is the peak element, 'arr[i - 1]' < 'arr[i]' and 'arr[i + 1]' < 'arr[i]'. Find the index(0-based) of a peak element in the array. If there are multiple peak numbers, return the index of any peak number.

Note: For the first element, the previous element should be considered as negative infinity as well as for the last element, the next element should be considered as negative infinity.

Pre-requisite: Binary Search Algorithm

Examples
Example 1:
Input Format: arr[] = {1,2,3,4,5,6,7,8,5,1}
Result: 7
Explanation: In this example, there is only 1 peak that is at index 7.

Example 2:
Input Format: arr[] = {1,2,1,3,5,6,4}
Result: 1
Explanation: In this example, there are 2 peak numbers that are at indices 1 and 5. We can consider any of them.

Example 3:
Input Format: arr[] = {1, 2, 3, 4, 5}
Result: 4
Explanation: In this example, there is only 1 peak that is at the index 4.

Example 4:
Input Format: arr[] = {5, 4, 3, 2, 1}
Result: 0
Explanation: In this example, there is only 1 peak that is at the index 0.

*/




#include <bits/stdc++.h>
using namespace std;

int Linear(vector<int> &arr) 
{
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        if((i==0 || arr[i-1]<arr[i]) && (i==n-1|| arr[i]>arr[i+1]))
            return i;
    }
    return -1;

    // TC O(N)
    // SC O(1)
}

int Binary(vector<int> arr)
{
    int n=arr.size();
    
    if(n==1)
        return 0;
    // if first element is peak
    if(arr[0]>arr[1])
        return 0;
    // if last element is peak
    if(arr[n-1]>arr[n-2])
        return n-1;

    int low=0;
    int high=n-1;
    int mid;

    while(low<=high)
    {
        mid=(low+high)/2;

        if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1])
            return mid;
        if(arr[mid-1]<arr[mid])
            low=mid+1;
        else    
            high=mid-1;
    }
    return -1;

    // TC O(logN)
    // SC O(1)
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    int ans = Linear(arr);
    cout << "The peak is at index: " << ans << "\n";

    cout << "The peak is at index: " << Binary(arr) << "\n";
    return 0;
}

