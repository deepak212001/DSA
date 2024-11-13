/*
Move all Zeros to the end of the array


In this article we will learn how to solve the most asked coding interview problem: "Move all Zeros to the end of the array"

Problem Statement: You are given an array of integers, your task is to move all the zeros in the array to the end of the array and move non-negative integers to the front by maintaining their order.

Examples
Example 1:
Input:
 1 ,0 ,2 ,3 ,0 ,4 ,0 ,1
Output:
 1 ,2 ,3 ,4 ,1 ,0 ,0 ,0
Explanation:
 All the zeros are moved to the end and non-negative integers are moved to front by maintaining order

Example 2:
Input:
 1,2,0,1,0,4,0
Output:
 1,2,1,4,0,0,0
Explanation:
 All the zeros are moved to the end and non-negative integers are moved to front by maintaining order

*/



#include<bits/stdc++.h>
using namespace std;

void BruteForce(vector<int> &arr) {
    vector<int> temp;
    int count=0;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]!=0)
            temp.push_back(arr[i]);
        else 
            count++;
    }
    for(int i=0;i<count;i++)
        temp.push_back(0);
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i]=temp[i];
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


void Optimal(vector<int> &arr) 
{
    int j=0;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]!=0)
        {
            swap(arr[i],arr[j]);
            j++;
        }
    }

       // print 
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<endl;
    // TC O(N)
    // SC O(1)
}


void Optimal1(vector<int> &arr) {
    int j=-1;

    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]==0)
        {
            j=i;
            break;
        }
    }

    if(j==-1)
        return ;

    for(int i=j+1;i<arr.size();i++)
    {
        if(arr[i]!=0)
        {
            swap(arr[i],arr[j]);
            j++;
        }
    }

       // print 
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<endl;
    // TC O(N)
    // SC O(1)
}


int main() {
    vector<int> arr= {1,2,3,4,5,6,7};
    vector<int> arr1= {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
    // BruteForce(arr);
    // BruteForce(arr1);
    // Optimal(arr);
    // Optimal(arr1);

    Optimal1(arr);
    Optimal1(arr1);
}
