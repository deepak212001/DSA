/*
Kth Missing Positive Number


37

0
Problem Statement: You are given a strictly increasing array ‘vec’ and a positive integer 'k'. Find the 'kth' positive integer missing from 'vec'.

Examples
Example 1:
Input Format:
 vec[]={4,7,9,10}, k = 1
Result:
 1
Explanation:
 The missing numbers are 1, 2, 3, 5, 6, 8, 11, 12, ……, and so on. Since 'k' is 1, the first missing element is 1.
Example 2:
Input Format:
 vec[]={4,7,9,10}, k = 4
Result:
 5
Explanation:
 The missing numbers are 1, 2, 3, 5, 6, 8, 11, 12, ……, and so on. Since 'k' is 4, the fourth missing element is 5.

*/




#include <bits/stdc++.h>
using namespace std;

int Linear(vector < int > vec, int n, int k) 
{
    for(int i=0;i<n;i++)
    {
        if(vec[i]<=k)
            k++;
        else 
            break;
    }
    return k;

    // TC O(N)
    // SC O(1)

}
 


int Binary(vector < int > vec, int n, int k) 
{

    // NO OF MISSING NUMBERS IS  V[i]-i-1
    /*
        {4, 7, 9, 10};
         0  1  2  3  index 
         3 index tak kitne miss hai 
            v[3]-(3+1 ) = 10-4=6
            means 6 no miss  -> 1,2,3,5,6,8 miss    
            if k=5
            index    miss
            0         3
            1         5
            2         6
            3         6
                     
    */
    
    int low=0;
    int high=n-1;
    int mid;

    while(low<=high)
    {
        mid=(low+high)/2;

        int miss = vec[mid]-(mid+1);
        if(miss<k)
            low=mid+1;
        else 
            high=mid-1;
    }
    return k+high+1;
    return k+low //both are correct ;
    

    // TC O(logN)
    // SC O(1)
}
int findKthPositive(vector<int>& arr, int k) {
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]<=k)   
                k++;
            else 
                break;
        }
        return k;
    }

int main()
{
    vector<int> vec = {4, 7, 9, 10};
    int n = 4, k = 4;
    int ans = Linear(vec, n, k);
    cout << "The missing number is: " << ans << "\n";
    cout << "The missing number is: " << Binary(vec,n,k) << "\n";
    return 0;
}

