/*
Left Rotate the Array by One


Problem Statement: Given an array of N integers, left rotate the array by one place.

Examples
Example 1:
Input:
 N = 5, array[] = {1,2,3,4,5}
Output:
 2,3,4,5,1
Explanation:
 
Since all the elements in array will be shifted 
toward left by one so ‘2’ will now become the 
first index and and ‘1’ which was present at 
first index will be shifted at last.


Example 2:
Input:
 N = 1, array[] = {3}
Output:
 3
Explanation:
 Here only element is present and so 
the element at first index will be shifted to 
last index which is also by the way the first index.


*/


#include<bits/stdc++.h>
using namespace std;

void BruteForce(vector<int> &arr) {
    vector<int> temp;
    for(int i=1;i<arr.size();i++)
    {
        temp.push_back(arr[i]);
    }
    temp.push_back(arr[0]);

    // print 
    for(int i=0;i<arr.size();i++)
    {
        cout<<temp[i]<<" ";
    }

    cout<<endl;
    // TC O(N)
    // SC O(N)
}


void Optimal(vector<int> &arr) {
    int temp =arr[0];
    for(int i=1;i<arr.size();i++)
    {
        arr[i-1]=arr[i];
    }
    arr[arr.size()-1]=temp;

    // print 
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }

    // TC O(N)
    // SC O(1)
}


int main() {
    vector<int> arr= {1,2,3,4,5};
    BruteForce(arr);
    Optimal(arr);
}

