/*
Two Sum : Check if a pair with given sum exists in Array


Problem Statement: Given an array of integers arr[] and an integer target.

1st variant: Return YES if there exist two numbers such that their sum is equal to the target. Otherwise, return NO.

2nd variant: Return indices of the two numbers such that their sum is equal to the target. Otherwise, we will return {-1, -1}.

Note: You are not allowed to use the same element twice. Example: If the target is equal to 6 and num[1] = 3, then nums[1] + nums[1] = target is not a solution.

Examples:

Example 1:
Input Format: N = 5, arr[] = {2,6,5,8,11}, target = 14
Result: YES (for 1st variant)
       [1, 3] (for 2nd variant)
Explanation: arr[1] + arr[3] = 14. So, the answer is “YES” for the first variant and [1, 3] for 2nd variant.

Example 2:
Input Format: N = 5, arr[] = {2,6,5,8,11}, target = 15
Result: NO (for 1st variant)
	[-1, -1] (for 2nd variant)
Explanation: There exist no such two numbers whose sum is equal to the target.

*/

#include <bits/stdc++.h>
using namespace std;

vector<int> BruteForce(int n, vector<int> &arr, int target) 
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(i!=j)
            {
                if(arr[i]+arr[j]==target)
                    return {i,j};
            }
        }
    }
    return {-1,-1};

    // TC O(N^2);
    // SC O(1)

}


vector<int> Better(int n, vector<int> &arr, int target) 
{
    map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        int num=arr[i];
        int more=target-num;
        if(mp.find(more)!=mp.end())
        {
            return {i, mp[more]};
        }
        mp[num]=i;
    }
    return {-1,-1};
    
    // TC O(N)
    // SC O(N)
}

string Optimal(int n, vector<int> &arr, int target) 
{
    sort(arr.begin(),arr.end());
    int right=n-1;
    int left=0;
    while(left<right)
    {
        if(arr[left]+arr[right]==target)
            return "Yes";
        if(arr[left]+arr[right]>target)
            right--;
        if(arr[left]+arr[right]<target)
            left++;
    }
    return "No";
    
    // TC O(N)
    // SC O(N)
}




int main()
{
    int n = 5;
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    int target2 = 15;
    vector<int> ans = BruteForce(n, arr, target);
    cout << "This is the answer for variant 1: " << ans[0]<<" ans "<<ans[1] << endl;
    ans = BruteForce(n, arr, target2);
    cout << "This is the answer for variant 2: " << ans[0]<<" ans "<<ans[1]  << endl;
    
    ans = Better(n, arr, target);
    cout << "This is the answer for variant 1: " << ans[0]<<" ans "<<ans[1] << endl;
    ans = Better(n, arr, target2);
    cout << "This is the answer for variant 2: " << ans[0]<<" ans "<<ans[1]  << endl;
    
    string an = Optimal(n, arr, target);
    cout << "This is the answer for variant 1: " << an << endl;
    an = Optimal(n, arr, target2);
    cout << "This is the answer for variant 2: " << an<< endl;
    return 0;

}