/*
Find the Largest element in an array


Problem Statement: Given an array, we have to find the largest element in the array.

Examples
Example 1:
Input:
 arr[] = {2,5,1,3,0};
Output:
 5
Explanation:
 5 is the largest element in the array.

Example2:
Input:
 arr[] = {8,10,5,7,9};
Output:
 10
Explanation:
 10 is the largest element in the array.

*/
#include <bits/stdc++.h>
using namespace std;

int findMaxBruteForce(vector<int> &num)
{
    // Solution1: Sorting
    sort(num.begin(), num.end());
    return num[num.size() - 1];
    // TC O(NlogN)
    // SC O(N)
}

int findMaxIterative(vector<int> &num)
{
    int ans = num[0];
    for (int i = 1; i < num.size(); i++)
    {
        ans = ans < num[i] ? num[i] : ans; // aur
        // ans = max(ans, num[i]);
    }
    return ans;
    // TC O(N)
    // SC O(1)
}

int main()
{
    vector<int> arr1 = {2, 5, 1, 3, 0};
    vector<int> arr2 = {8, 10, 5, 7, 9};

    cout << "The Largest element in the array is: " << findMaxBruteForce(arr1) << endl;
    cout << "The Largest element in the array is: " << findMaxBruteForce(arr2) << endl;
    cout << "-----------------" << endl;
    cout << "The Largest element in the array is: " << findMaxIterative(arr1) << endl;
    cout << "The Largest element in the array is: " << findMaxIterative(arr2) << endl;

    return 0;
}