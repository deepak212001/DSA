/*
Find the number that appears once, and the other numbers twice


Problem Statement: Given a non-empty array of integers arr, every element appears twice except for one. Find that single one.

Examples
Example 1:
Input Format:
 arr[] = {2,2,1}
Result:
 1
Explanation:
 In this array, only the element 1 appear once and so it is the answer.

Example 2:
Input Format:
 arr[] = {4,1,2,1,2}
Result:
 4
Explanation:
 In this array, only element 4 appear once and the other elements appear twice. So, 4 is the answer.

*/



#include <bits/stdc++.h>
using namespace std;

int BruteForce(vector<int> &arr) 
{
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        int num=arr[i];
        int count =0;
        for(int j=0;j<n;j++)
        {
            if(arr[j]==num)
                count++;
        }
        if(count<2)
            return num;
    }
    return -1;

    // TC O(N^2)
    // SC O(1)
}

int BetterHash(vector<int> &arr)
{
    int n=arr.size();
    int maxi = arr[0];
    for (int i = 0; i < n; i++) 
    {
        maxi = max(maxi, arr[i]);
    }
    vector<int> hash(maxi+1,0);
    for(int i=0;i<n;i++)
    {
        hash[arr[i]]++;
    }
    for(int i=0;i<n; i++){
        if(hash[arr[i]]==1)
            return arr[i]; 
    }
    return -1;

    // TC O(N)
    // SC O(maxi+1)
}


int Better(vector<int> &arr)
{
    // Hashing using the map data structure: 

    int n=arr.size();
    map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        mp[arr[i]]++;
    }
    for(auto it : mp)
    {
        if(it.second==1)
            return it.first;
    }
    return -1;

    // TC O(NlogM)  M=(N/2)+1
    // SC O(M)
}


int Optimal(vector<int> &arr)
{
    int xor1=0;
    for(int i=0;i<arr.size();i++)
    {
        xor1^=arr[i];
    }
    
    return xor1;

    // TC O(N)
    // SC O(1)
}



int main()
{
    vector<int> arr = {4, 1, 2, 1, 2};
    int ans = BruteForce(arr);
    cout << "The single element by Brute Force is: " << ans << endl;
    ans = BetterHash(arr);
    cout << "The single element is: " << ans << endl;
    ans = Better(arr);
    cout << "The single element is: " << ans << endl;
    ans = Optimal(arr);
    cout << "The single element is: " << ans << endl;
    return 0;
}