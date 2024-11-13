/*
Remove Duplicates in-place from Sorted Array


Problem Statement: Given an integer array sorted in non-decreasing order, remove the duplicates in place such that each unique element appears only once. The relative order of the elements should be kept the same.

If there are k elements after removing the duplicates, then the first k elements of the array should hold the final result. It does not matter what you leave beyond the first k elements.

Note: Return k after placing the final result in the first k slots of the array.

Examples
Example 1:
Input:
 arr[1,1,2,2,2,3,3]

Output:
 arr[1,2,3,_,_,_,_]

Explanation:
 Total number of unique elements are 3, i.e[1,2,3] and Therefore return 3 after assigning [1,2,3] in the beginning of the array.

Example 2:
Input:
 arr[1,1,1,2,2,3,3,3,3,4,4]

Output:
 arr[1,2,3,4,_,_,_,_,_,_,_]

Explanation:
 Total number of unique elements are 4, i.e[1,2,3,4] and Therefore return 4 after assigning [1,2,3,4] in the beginning of the array.

*/

#include <bits/stdc++.h>

using namespace std;
int BruteForce(vector<int> &arr)
{
    set<int> s;
    for (int i = 0; i < arr.size(); i++)
    {
        s.insert(arr[i]);
    }
    int j = 0;
    for (int n : s)
    {
        arr[j++] = n;
    }
    return j;
    // TC O(NlogN)
    // SC O(N)
}

int Optimal(vector<int> &arr)
{
    int j=0;
    for(int i=1;i<arr.size();i++)
    {
        if(arr[i]!=arr[i-1])
            arr[++j]=arr[i];
    }
    return j+1;
    // TC O(N)
    // SC O(1)
}



int main()
{
    vector<int> arr = {1, 1, 2, 2, 2, 3, 3,4};
    // vector<int> arr = {1, 1, 2, 2, 2, 3, 3};
    int k = BruteForce(arr);
    cout << "The array after removing duplicate elements is " << endl;
    for (int i = 0; i < k; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;

    vector<int> arr1 = {1, 1, 2, 2, 2, 3, 3,4};
    k = Optimal(arr1);
    cout << "The array after removing duplicate elements using Optimal approach is " << endl;
    for (int i = 0; i < k; i++)
    {
        cout << arr1[i] << " ";
    }
}