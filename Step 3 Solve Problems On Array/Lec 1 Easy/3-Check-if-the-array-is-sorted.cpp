/*

Check if an Array is Sorted

Problem Statement: Given an array of size n, write a program to check if the given array is sorted in (ascending / Increasing / Non-decreasing) order or not. If the array is sorted then return True, Else return False.

Note: Two consecutive equal values are considered to be sorted.

Examples
Example 1:
Input:
 N = 5, array[] = {1,2,3,4,5}
Output
: True.
Explanation:
 The given array is sorted i.e Every element in the array is smaller than or equals to its next values, So the answer is True.


Example 2:
Input:
 N = 5, array[] = {5,4,6,7,8}
Output
: False.
Explanation:
 The given array is Not sorted i.e Every element in the array is not smaller than or equal to its next values, So the answer is False.

Here element 5 is not smaller than or equal to its future elements.



*/

#include <bits/stdc++.h>

using namespace std;

bool BruteForce(vector<int> &num)
{
    int n=num.size();
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(num[i]>num[j])
                return false;
        }
    }
    return true;
    // TC O(N^2)    
    // SC O(1)
}

bool Optimal(vector<int> &num)
{
    int n=num.size();
    for(int i=1;i<n;i++)
    {
        if(num[i-1]>num[i])
            return false;
    }
    return true;
    // TC O(N)
    // SC O(1)
}
bool Optimal(vector<int> &num)
{
    int n=num.size();
    int left=0;
    int right=n-1;

    while(left<=right)
    {
        if(num[left]>num[right])
            return false;
        left++;
        right--;
    }
    return true;
    // TC O(N)
    // SC O(1)
}

int main()
{
    vector<int> arr1 = {2, 5, 1, 3, 0};
    vector<int> arr2 = {1, 2, 3, 4, 5};
    cout << BruteForce(arr1) << endl;
    cout << BruteForce(arr2) << endl;
    cout << Optimal(arr1) << endl;
    cout << Optimal(arr2) << endl;
    return 0;
}