/*

K-th Element of two sorted arrays


25

2
Pre-requisite: Median of 2 sorted arrays

Problem Statement: Given two sorted arrays of size m and n respectively, you are tasked with finding the element that would be at the kth position of the final sorted array.

*/

#include <bits/stdc++.h>
using namespace std;

int BruteForce(vector<int> &a, vector<int> &b, int m, int n, int k)
{
    vector<int> arr3;
    // merge the array
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (a[i] < b[j])
            arr3.push_back(a[i++]);
        else
            arr3.push_back(b[j++]);
    }

    while (i < m)
        arr3.push_back(a[i++]);
    while (j < n)
        arr3.push_back(b[j++]);

    return arr3[k - 1];

    // TC O(N+M)
    // SC O(N+M)
}

int Better(vector<int> &a, vector<int> &b, int m, int n, int k)
{
    int ele = -1;
    int cnt = 0; // counter
    // apply the merge step:
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (a[i] < b[j])
        {
            if (cnt == k - 1)
                ele = a[i];
            cnt++;
            i++;
        }
        else
        {
            if (cnt == k - 1)
                ele = b[j];
            cnt++;
            j++;
        }
    }

    // copy the left-out elements:
    while (i < m)
    {
        if (cnt == k - 1)
            ele = a[i];
        cnt++;
        i++;
    }
    while (j < n)
    {
        if (cnt == k - 1)
            ele = b[j];
        cnt++;
        j++;
    }
    return ele;

    // TC O(N+M)
    // SC O(1)
}

int Optimal(vector<int> &a, vector<int> &b, int m, int n, int k)
{
    // Using binary search

    if (m > n)
        return kthElement(b, a, n, m, k);

    int left = k; // length of left half

    // apply binary search:
    int low = max(0, k - n), high = min(k, m);
    while (low <= high)
    {
        int mid1 = (low + high) >> 1;
        int mid2 = left - mid1;
        // calculate l1, l2, r1 and r2;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if (mid1 < m)
            r1 = a[mid1];
        if (mid2 < n)
            r2 = b[mid2];
        if (mid1 - 1 >= 0)
            l1 = a[mid1 - 1];
        if (mid2 - 1 >= 0)
            l2 = b[mid2 - 1];

        if (l1 <= r2 && l2 <= r1)
        {
            return max(l1, l2);
        }

        // eliminate the halves:
        else if (l1 > r2)
            high = mid1 - 1;
        else
            low = mid1 + 1;
    }
    return 0; // dummy statement

    // TC O(log(min(N,M)))
    //  SC O(1)
}

int main()
{
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    cout << "The k-ht element of two sorted array is: " << BruteForce(a, b, a.size(), b.size(), 5) << '\n';
    cout << "The k-ht element of two sorted array is: " << Better(a, b, a.size(), b.size(), 5) << '\n';
    cout << "The k-ht element of two sorted array is: " << Optimal(a, b, a.size(), b.size(), 5) << '\n';
}
