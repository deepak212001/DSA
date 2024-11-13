/*
Rotate array by K elements


Rotate array by K elements

Problem Statement: Given an array of integers, rotating array of elements by k elements either left or right.

Examples:

Example 1:
Input: N = 7, array[] = {1,2,3,4,5,6,7} , k=2 , right
Output: 6 7 1 2 3 4 5
Explanation: array is rotated to right by 2 position .

Example 2:
Input: N = 6, array[] = {3,7,8,9,10,11} , k=3 , left 
Output: 9 10 11 3 7 8
Explanation: Array is rotated to right by 3 position.

*/



#include<bits/stdc++.h>
using namespace std;

void BruteForce(vector<int> &arr, int k) {
    vector<int> temp;
    k%=arr.size();  // if k is more than size of array 
    int c=arr.size()-k;
    for(int i=c;i<arr.size();i++)
    {
        temp.push_back(arr[i]);
    }

    for(int i=0;i<c;i++)
    {
        temp.push_back(arr[i]);
    }
    

    // print 
    for(int i=0;i<arr.size();i++)
    {
        cout<<temp[i]<<" ";
    }

    cout<<endl;
    // TC O(N)
    // SC O(N)
}


void Optimal(vector<int> &arr, int k) {
    k%=arr.size();
    int c=arr.size()-k-1;
    reverse(arr.begin(),arr.end());
    reverse(arr.begin(),arr.begin()+c);
    reverse(arr.begin()+c,arr.end());

    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }

    // TC O(N)
    // SC O(1)
}


int main() {
    vector<int> arr= {1,2,3,4,5,6,7};
    int k=10    ;
    BruteForce(arr,k);
    Optimal(arr,k);
}
