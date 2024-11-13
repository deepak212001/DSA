/*

Reverse a given Array

Problem Statement: You are given an array. The task is to reverse the array and print it. 

Examples:

Example 1:
Input: N = 5, arr[] = {5,4,3,2,1}
Output: {1,2,3,4,5}
Explanation: Since the order of elements gets reversed the first element will occupy the fifth position, the second element occupies the fourth position and so on.

Example 2:
Input: N=6 arr[] = {10,20,30,40}
Output: {40,30,20,10}
Explanation: Since the order of elements gets reversed the first element will occupy the fifth position, the second element occupies the fourth position and so on.

*/

// Solution 1: Using an extra array.


/*
#include<bits/stdc++.h>
using namespace std;

void Print(int arr[], int n )
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
void reverseArr(int arr[],int n)
{
    int ans[n];
    for(int i=0;i<n;i++)
        ans[n-i-1]=arr[i];
    Print(ans,n);
}
int main()
{
    int n=5;
    int arr[]={5,4,3,2,1};
    reverseArr(arr,n);
    return 0;
}
*/
// TC O(N)
// SC O(N)

// Solution 2: Space-optimized iterative method

/*
#include<bits/stdc++.h>
using namespace std;

void Print(int arr[], int n )
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
void reverseArr(int arr[],int n)
{
    int p1=0,p2=n-1;
    while(p1<p2)
    {
        swap(arr[p1],arr[p2]);
        p1++;
        p2--;
    }
    Print(arr,n);
}

void rev(int arr[],int n,int i)
{
    if(i>=n/2)
        return ;
    swap(arr[i],arr[n-i-1]);
    rev(arr,n,i+1);
}
int main()
{
    int n=5;
    int arr[]={5,4,3,2,1};
    // reverseArr(arr,n);
    rev(arr,n,0);
    Print(arr,n);
    return 0;
}
*/

// TC O(N)
// SC O(1)



// Solution 3: Recursive method

/*
#include<bits/stdc++.h>
using namespace std;

void Print(int arr[], int n )
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
void reverseArr(int arr[], int start, int end) {
   if (start < end) {
      swap(arr[start], arr[end]);
      reverseArr(arr, start + 1, end - 1);
   }
}
int main()
{
    int n=5;
    int arr[]={5,4,3,2,1};
    reverseArr(arr,0,n-1);
    Print(arr,n);
    return 0;
}
*/

// TC O(N)
// SC O(1)

/*
#include<bits/stdc++.h>
using namespace std;

void Print(int arr[], int n )
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}

void reverseArr(int arr[], int start, int end) {
    if (start >= end) 
        return;
    swap(arr[start], arr[end]);
    reverseArr(arr, start + 1, end - 1);
}
int main()
{
    int n=5;
    int arr[]={5,4,3,2,1};
    reverseArr(arr,0,n-1);
    Print(arr,n);
    return 0;
}
*/

// Solution 4: Using library function (New Approach)


#include<bits/stdc++.h>
using namespace std;

void Print(int arr[], int n )
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
void reverseArr(int arr[], int n) 
{
   reverse(arr,arr+n);
}
int main()
{
    int n=5;
    int arr[]={5,4,3,2,1};
    reverseArr(arr,n);
    Print(arr,n);
    return 0;
}
