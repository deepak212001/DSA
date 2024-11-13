/*
Floor and Ceil in Sorted Array


42

0
Problem Statement: You're given an sorted array arr of n integers and an integer x. Find the floor and ceiling of x in arr[0..n-1].
The floor of x is the largest element in the array which is smaller than or equal to x.
The ceiling of x is the smallest element in the array greater than or equal to x.

Pre-requisite: Lower Bound & Binary Search

Example 1:
Input Format: n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x= 5
Result: 4 7
Explanation: The floor of 5 in the array is 4, and the ceiling of 5 in the array is 7.

Example 2:
Input Format: n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x= 8
Result: 8 8
Explanation: The floor of 8 in the array is 8, and the ceiling of 8 in the array is also 8.

*/

#include<bits/stdc++.h>
using namespace std;

int findFloor(vector<int> arr, int n, int x) 
{
    int low=0;
    int high=n-1;
    int mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(arr[mid]>x)
            high=mid-1;
        else 
            low=mid+1;
    }
    return high;
    
}

int findCeil(vector<int> arr, int n, int x) 
{
    int low=0;
    int high=n-1;
    int mid;
    int ans=n;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(arr[mid]>=x)
        {
            ans=mid;
            high=mid-1;
        }
        else 
            low=mid+1;
    }
    return ans;


}

pair<int, int> getFloorAndCeil(vector<int> arr, int n, int x) {
	int f = findFloor(arr, n, x);
	int c = findCeil(arr, n, x);
	return make_pair(f, c);
}

int main() {
	vector<int> arr = {3, 4, 4, 7, 8, 10};
	int n = 6, x = 5;
	pair<int, int> ans = getFloorAndCeil(arr, n, x);
	cout << "The floor and ceil are: " << arr[ans.first]
	     << " " << arr[ans.second] << endl;
	return 0;

    // TC O(logN)
    // SC O(1)
}


/*

int floor(int arr[], int n, int x)
{
    int low=0;
    int high=n-1;
    int mid;
    
    while(low<=high)
    {
        mid=(low+high)/2;
        if(arr[mid]==x)
            return arr[mid];
        if(arr[mid]>x)
            high=mid-1;
        else 
            low=mid+1;
    }
    return high>=0 ? arr[high] : -1;
}

int ceil(int arr[], int n, int x)
{
    int low=0;
    int high=n-1;
    int mid;
    
    while(low<=high)
    {
        mid=(low+high)/2;
        if(arr[mid]==x)
            return arr[mid];
        if(arr[mid]>x)
            high=mid-1;
        else 
            low=mid+1;
    }
    return low<n ? arr[low] : -1;;
}

pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
    sort(arr,arr+n);
    
    int f=floor(arr,n,x);
    int c=ceil(arr,n,x);
    
    return {f,c};

}

*/