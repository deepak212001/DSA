/*
Count Maximum Consecutive One's in the array


Problem Statement: Given an array that contains only 1 and 0 return the count of maximum consecutive ones in the array.

Examples:

Example 1:

Input: prices = {1, 1, 0, 1, 1, 1}

Output: 3

Explanation: There are two consecutive 1’s and three consecutive 1’s in the array out of which maximum is 3.

Input: prices = {1, 0, 1, 1, 0, 1} 

Output: 2

Explanation: There are two consecutive 1's in the array. 

*/

#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &arr)
{
    int count=0;
    int maxi=0;
    for(int i=0;i<arr.size();i++)
    {
        if (arr[i]==1)
            count++;
        else 
            count=0;
        maxi=max(maxi,count);
    }
    return maxi;
    // TC O(N)
    // SC O(1)
}


int main() {
  vector < int > nums = { 1, 1, 0, 1, 1, 1 };
  int ans = findMaxConsecutiveOnes(nums);
  cout << "The maximum  consecutive 1's are " << ans;
  return 0;
}