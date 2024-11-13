/*
Linear Search in C


Problem Statement: Given an array, and an element num the task is to find if num is present in the given array or not. If present print the index of the element or print -1.

Examples:

Example 1:
Input: arr[]= 1 2 3 4 5, num = 3
Output: 2
Explanation: 3 is present in the 2nd index

Example 2:
Input: arr[]= 5 4 3 2 1, num = 5
Output: 0
Explanation: 5 is present in the 0th index

*/




#include<bits/stdc++.h>
using namespace std;

int Linear(vector<int> &arr, int target) {

    for (int i = 0; i < arr.size(); i++)
    {
        if(arr[i]==target)
            return i;
    }
    return -1;

    // TC O(N)
    // SC O(1)
}


int main() {
    vector<int> arr= {1,2,3,4,5,6,7};
    vector<int> arr1= {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
    cout<<Linear(arr,8)<<endl;
    cout<<Linear(arr,7)<<endl;
    cout<<Linear(arr,0)<<endl;
    cout<<Linear(arr1,5)<<endl;
}
