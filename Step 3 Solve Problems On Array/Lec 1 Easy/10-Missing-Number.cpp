/*

Find the missing number in an array


82

0
Problem Statement: Given an integer N and an array of size N-1 containing N-1 numbers between 1 to N. Find the number(between 1 to N), that is not present in the given array.

Examples
Example 1:
Input Format:
 N = 5, array[] = {1,2,4,5}
Result:
 3
Explanation: 
In the given array, number 3 is missing. So, 3 is the answer.

Example 2:
Input Format:
 N = 3, array[] = {1,3}
Result:
 2
Explanation: 
In the given array, number 2 is missing. So, 2 is the answer.

*/

#include <bits/stdc++.h>
using namespace std;

int BruteForce(vector<int> &arr)
{
    // for(int i=0;i<arr.size();i++)
    // {
    //     if(arr[i]!=i+1)
    //         return i+1;
    // }
    // return -1;
    // //if arr is stored;

    for(int i=1;i<=arr.size();i++)
    {
        bool flag=true;
        for(int j=0;j<arr.size();j++)
        {
            if(arr[j]==i)
            {
                flag=false;
                break;
            }
        }
        if(flag)
            return i;
    }
    return -1;

    // TC O(N^2)
    // SC O(1)
}


int Better(vector<int> &arr)
{
    // using hashing
    int hash[arr.size()+1]={0};
    for(int i=0;i<arr.size();i++)
    {
        hash[arr[i]]++;
    }

    for(int i=1;i<=arr.size();i++)
    {
        if(hash[i]==0)
            return i;
    }
    return -1;

    // TC O(N)
    // SC O(N)
}

int OptimalM(vector<int> &arr)
{
    // Summation Approach  1 to n sum = (n*(n+1)/2)

    int n=arr.size();
    int total=(n*(n+1)/2);
    for(int i=0;i<n-1;i++)
    {
        total-=arr[i];
    }
    return total;

    // TC O(N)
    // SC O(1)
}


int OptimalG(vector<int> &arr)
{
    // using XOR gate
    // 2^2 =0 
    /*
    Input : A = 7 , B = 9

    Output: 14

    Explanation : A = 7 ( 0111 )2 , B = 9 ( 1001 )2

    1st bit of A = 1 and B = 1 so XOR value will be 0
    2nd bit of A = 1 and B = 0 so XOR Value will be 1
    3rd bit of A = 1 and B = 0 so XOR Value will be 1
    4th bit of A = 0 and B = 1 so XOR Value will be 1
    XOR value has binary representation : (1110)2

    Decimal value of XOR = 14
    */

    int xor1=0, xor2=0;
    for(int i=0;i<arr.size();i++)
    {
        xor1^=arr[i];
        xor2^=(i+1);
    }
    xor2^=arr.size()+1;
    return xor1^xor2;

    /*
    xor1=1^2^3^5
    xor2=1^2^3^4^5
    xor1^xor2=(1^1)^(2^2)^(3^3)^(4)^(5^5)=0^0^0^4^0=4
    */

    // TC O(N)
    // SC O(1)
}


int main()
{
    vector<int> a = {1, 2, 3,5};
    int ans = BruteForce(a);
    cout << "The missing number is: " << ans << endl;
    ans = Better(a);
    cout << "The missing number is: " << ans << endl;
    ans = OptimalM(a);
    cout << "The missing number is: " << ans << endl;
    ans = OptimalG(a);
    cout << "The missing number is: " << ans << endl;
    return 0;
}