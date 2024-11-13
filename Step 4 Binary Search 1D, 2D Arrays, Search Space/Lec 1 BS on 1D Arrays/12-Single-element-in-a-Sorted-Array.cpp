/*
Search Single Element in a sorted array


40

2
Problem Statement: Given an array of N integers. Every number in the array except one appears twice. Find the single number in the array.

Pre-requisite: Binary Search Algorithm

Examples
Example 1:
Input Format:
 arr[] = {1,1,2,2,3,3,4,5,5,6,6}
Result:
 4
Explanation:
 Only the number 4 appears once in the array.

Example 2:
Input Format:
 arr[] = {1,1,3,5,5}
Result:
 3
Explanation:
 Only the number 3 appears once in the array.

*/

#include <bits/stdc++.h>
using namespace std;

int BruteForce(vector<int> &arr)
{
    // use xor
    int n = arr.size(); // size of the array.
    int ans = 0;
    // XOR all the elements:
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ arr[i];
    }
    return ans;

    // TC O(N)
    // SC O(1)
}

int Optimal(vector<int> arr, int n)
{
    int low = 0;
    int high = n - 1;
    int mid;

    if(n==1)
        return arr[0];
    
    if(arr[0]!=arr[1])
        return arr[0];
        
    if(arr[n-1]!=arr[n-2])
        return arr[n-1];

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
            return arr[mid];

        // if mid is odd index then mid-1 and mid index are same
        // aur if mid is even then mid and mid+1 index value is same
        // if not both of them that means the single element is in left side
        /*
                {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6}
                (0,1) (2,3) (4,5)
                means single se pehle 
                even then odd
                single elment ke bad 
                odd then even
        */

        if ((mid % 2 == 0 && arr[mid] == arr[mid + 1]) || (mid % 2 == 1 && arr[mid] == arr[mid - 1]))
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;

    // TC O(logN)
    // SC O(1)
}
int main()
{
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    int ans = BruteForce(arr);
    cout << "The single element is: " << ans << "\n";

    int n = arr.size();
    ans = Optimal(arr, n);
    cout << "The single element is: " << ans << "\n";
    return 0;
}
