/*

Count Occurrences in Sorted Array


Problem Statement: You are given a sorted array containing N integers and a number X, you have to find the occurrences of X in the given array.

Examples
Example 1:
Input:
 N = 7,  X = 3 , array[] = {2, 2 , 3 , 3 , 3 , 3 , 4}
Output
: 4
Explanation:
 3 is occurring 4 times in 
the given array so it is our answer.

Example 2:
Input:
 N = 8,  X = 2 , array[] = {1, 1, 2, 2, 2, 2, 2, 3}
Output
: 5
Explanation:
 2 is occurring 5 times in the given array so it is our answer.

*/


#include<bits/stdc++.h>
using namespace std;

int BruetForce(vector<int>& arr, int n, int x) 
{
    int cnt = 0;
    for (int i = 0; i < n; i++) {

        // counting the occurrences:
        if (arr[i] == x) cnt++;
    }
    return cnt;

    // TC O(N)
    // SC O(1)
}


int firstSearch(int n, int key, vector < int > & v)
{
    int low=0;
    int high=n-1;
    int mid;
    int first=-1;

    while(low<=high)
    {
        mid=(low+high)/2;
        if(v[mid]==key)
        {
            first=mid;
            high=mid-1;
        }
        else if(v[mid]>key)
            high=mid-1;
        else 
            low=mid+1;
    }
    return first;
}
int lastSearch(int n, int key, vector < int > & v)
{
    int low=0;
    int high=n-1;
    int mid;
    int last=-1;

    while(low<=high)
    {
        mid=(low+high)/2;
        if(v[mid]==key)
        {
            last=mid;
            low=mid+1;
        }
        else if(v[mid]>key)
            high=mid-1;
        else 
            low=mid+1;
    }
    return last;
}


int Optimal(vector < int > & v, int n, int key) 
{
    int first=firstSearch(n,key,v);
    if(first==-1)
        return 0;
    int last=lastSearch(n,key,v);
    return last-first+1;

    // TC 2*O(logN)
    // SC O(1)
}

int main()
{
    vector<int> arr =  {2, 4, 6, 8, 8, 8, 11, 13};
    int n = 8, x = 8;
    int ans = BruetForce(arr, n, x);
    cout << "The number of occurrences is: "<< ans << "\n";
    ans = Optimal(arr, n, x);
    cout << "The number of occurrences is: "<< ans << "\n";
    return 0;
}

