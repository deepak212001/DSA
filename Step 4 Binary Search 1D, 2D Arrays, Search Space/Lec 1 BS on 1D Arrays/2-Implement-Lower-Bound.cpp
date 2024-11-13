/*
Implement Lower Bound


Problem Statement: Given a sorted array of N integers and an integer x, write a program to find the lower bound of x.

Pre-requisite: Binary Search algorithm

Examples
Example 1:
Input Format:
 N = 4, arr[] = {1,2,2,3}, x = 2
Result:
 1
Explanation:
 Index 1 is the smallest index such that arr[1] >= x.

Example 2:
Input Format:
 N = 5, arr[] = {3,5,8,15,19}, x = 9
Result:
 3
Explanation:
 Index 3 is the smallest index such that arr[3] >= x.


 The lower bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than or equal to a given key i.e. x.

The lower bound is the smallest index, ind, where arr[ind] >= x. But if any such index is not found, the lower bound algorithm returns n i.e. size of the given array.

*/



#include <bits/stdc++.h>
using namespace std;

int BruteForce(vector<int> arr, int n, int target)
{
    // using linear search
    for(int i=0;i<n;i++){
        if(arr[i]>=target)
            return i;
    }
    return -1;

    // TC O(N)
    // SC O(1)
}

int Optimal(vector<int> arr, int n, int target)
{
    // Using binary search
    int low=0;
    int high=n-1;
    int ans =n;
    int mid;
    
    while (low<=high)
    {
        mid=(low+high)/2;
        
        if(arr[mid]>=target)
        {
            ans=mid;
            high=mid-1;
        }
        else 
            low=mid+1;
    }
    return ans;

    // TC O(logN)
    // SC O(1)
    
}
int inbuiltfun(vector<int> arr, int n, int target)
{
    int l=lower_bound(arr.begin(),arr.end(),target)-arr.begin();
    return l;
}

int main()
{
    vector<int> arr = {3, 5, 8, 15, 19};
    int n = 5, x = 9;
    int ind = BruteForce(arr, n, x);
    cout << "The lower bound is the index: " << ind << "\n";
    ind = Optimal(arr, n, x);
    cout << "The lower bound is the index: " << ind << "\n";

    ind = inbuiltfun(arr, n, 6);
    cout << "The lower bound is the index: " << ind << "\n";
    return 0;
}


