x /*

 Trapping Rainwater


 Problem Statement: Given an array of non-negative integers representation elevation of ground. Your task is to find the water that can be trapped after rain.


 Example 1:

     Input: height= [0,1,0,2,1,0,1,3,2,1,2,1]

     Output: 6

     Explanation: As seen from the diagram 1+1+2+1+1=6 unit of water can be trapped



 Example 2:

     Input:  [4,2,0,3,2,5]

     Output:9

 */

#include <bits/stdc++.h>
    using namespace std;

int BruteForce(vector<int> &arr)
{
    int n = arr.size();
    int waterTrapped = 0;
    for (int i = 0; i < n; i++)
    {
        int j = i;
        int leftMax = 0, rightMax = 0;
        while (j >= 0)
        {
            leftMax = max(leftMax, arr[j]);
            j--;
        }
        j = i;
        while (j < n)
        {
            rightMax = max(rightMax, arr[j]);
            j++;
        }
        waterTrapped += min(leftMax, rightMax) - arr[i];
    }
    return waterTrapped;
    // TC O(N^2)
    // SC O(1)
}

int Better(vector<int> &arr)
{
    int n = arr.size();
    int waterTrapped = 0;
    vector<int> prefix(n, 0);
    vector<int> sufferfix(n, 0);

    prefix[0] = arr[0];
    for (int i = 1; i < n; i++)
        prefix[i] = max(prefix[i - 1], arr[i]);

    sufferfix[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        sufferfix[i] = max(sufferfix[i + 1], arr[i]);

    for (int i = 0; i < n; i++)
    {

        int leftMax = prefix[i], rightMax = sufferfix[i];
        waterTrapped += min(leftMax, rightMax) - arr[i];
    }
    return waterTrapped;

    // TC O(3N)
    // SC O(N)+O(N)
}

int Optimal(vector<int> &arr)
{
    int n = arr.size();
    int left = 0, right = n - 1;
    int maxLeft = 0, maxRight = 0;
    int waterTrapped = 0;
    while (left <= right)
    {
        if (arr[left] <= arr[right])
        {
            if (arr[left] >= maxLeft)
                maxLeft = arr[left];
            else
                waterTrapped += maxLeft - arr[left];
            left++;
        }
        else
        {
            if (arr[right] >= maxRight)
                maxRight = arr[right];
            else
                waterTrapped += maxRight - arr[right];
            right--;
        }
    }
    return waterTrapped;

    // TC O(N)
    // SC O(1)
}

int main()
{
    vector<int> arr;
    arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "The water that can be trapped is " << BruteForce(arr) << endl;
    cout << "The water that can be trapped is " << Better(arr) << endl;
    cout << "The water that can be trapped is " << Optimal(arr) << endl;
}