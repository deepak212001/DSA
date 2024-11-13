/*

Find the Smallest Divisor Given a Threshold


42

0
Problem Statement: You are given an array of integers 'arr' and an integer i.e. a threshold value 'limit'. Your task is to find the smallest positive integer divisor, such that upon dividing all the elements of the given array by it, the sum of the division's result is less than or equal to the given threshold value.

Examples
Example 1:
Input Format:
 N = 5, arr[] = {1,2,3,4,5}, limit = 8
Result:
 3
Explanation:
 We can get a sum of 15(1 + 2 + 3 + 4 + 5) if we choose 1 as a divisor.
The sum is 9(1 + 1 + 2 + 2 + 3)  if we choose 2 as a divisor. Upon dividing all the elements of the array by 3, we get 1,1,1,2,2 respectively. Now, their sum is equal to 7 <= 8 i.e. the threshold value. So, 3 is the minimum possible answer.

Example 2:
Input Format:
 N = 4, arr[] = {8,4,2,3}, limit = 10
Result:
 2
Explanation:
 If we choose 1, we get 17 as the sum. If we choose 2, we get 9(4+2+1+2) <= 10 as the answer. So, 2 is the answer.



Point to remember:

While dividing the array elements with a chosen number, we will always take the ceiling value. And then we will consider their summation. For example, 3 / 2 = 2.
Observation:

Minimum possible divisor: We can easily consider 1 as the minimum divisor as it is the smallest positive integer.
Maximum possible divisor: If we observe, we can conclude the maximum element in the array i.e. max(arr[]) is the maximum possible divisor. Any number > max(arr[]), will give the exact same result as max(arr[]) does. This divisor will generate the minimum possible result i.e. n(1 for each element), where n = size of the array.
With these observations, we can surely say that our answer will lie in the range
[1, max(arr[])].
*/

/*

Input Format:
 N = 5, arr[] = {1,2,3,4,5}, limit = 8
Result:
 3

 if divide by 1
    1/1 +2/1+ 3/1 + 4/1+ 5/1 = 1+2++3+4+5=15  > limit so no

if divide by 2   take ceil value
    1/2 + 2/2 + 3/2 + 4/2 + 5/2 = 1+ 1 +2 + 2 +3= 9 >limit

 if divide  by 3

  1/3 + 2/3 + 3/3+ 4/3 + 5/3 = 1+1+1+2+2= 7 so retur 3

  Ceil value taken so max diviable vaule is max element of array

*/

#include <bits/stdc++.h>
using namespace std;

bool SumByD(vector<int> arr, int d, int n, int limit)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += ceil((double)arr[i] / (double)d);
    }
    return sum <= limit;
}

int Linaer(vector<int> &arr, int limit)
{
    int n = arr.size();
    int maxi = *max_element(arr.begin(), arr.end());
    for (int i = 1; i <= maxi; i++)
    {
        if (SumByD(arr, i, n, limit))
            return i;
    }
    return -1;

    // TC O(N*M) M is max element of array
    // SC O(1)
}

int Binary(vector<int> &arr, int limit)
{
    int n = arr.size();
    int low=1;
    int high = *max_element(arr.begin(), arr.end());
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (SumByD(arr, mid, n, limit))
            high = mid - 1; // ye true means limit ke equal ya less to small chahiye to left side lena hai
        else
            low = mid + 1;
    }
    return low;

    // TC O(N* logM) M is max element of array
    // SC O(1)
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int limit = 8;
    int ans = Linaer(arr, limit);
    cout << "The minimum divisor is: " << ans << "\n";
    cout << "The minimum divisor is: " << Binary(arr, limit) << "\n";
    return 0;
}
