/*
First and Last occurrence in a sorted array


51

7
Given a sorted array of N integers, write a program to find the index of the last occurrence of the target key. If the target is not found then return -1.

Note: Consider 0 based indexing

Examples:

Example 1:
Input: N = 7, target=13, array[] = {3,4,13,13,13,20,40}
Output: 2 4
Explanation: As the target value is 13 , it appears for the first time at index number 2.

Example 2:
Input: N = 7, target=60, array[] = {3,4,13,13,13,20,40}
Output: -1
Explanation: Target value 60 is not present in the array

*/

#include <bits/stdc++.h>

using namespace std;

vector<int> Linear(int n, int key, vector<int> &v)
{
    int first = -1;
    int last = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (v[i] == key)
        {
            last = i;
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (v[i] == key)
        {
            first = i;
            break;
        }
    }

    return {first, last};

    // TC O(N)
    // SC O(1)
}

int lower(int n, int key, vector<int> &v)
{
    int low = 0;
    int high = n - 1;
    int mid = 0;
    int ans = n;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (v[mid] >= key)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

int upper(int n, int key, vector<int> &v)
{
    int low = 0;
    int high = n - 1;
    int mid = 0;
    int ans = n;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (v[mid] > key)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

vector<int> LowerUpper(int n, int key, vector<int> &v)
{
    int first = lower(n, key, v);
    if (first == n || v[first] != key)
        return {-1, -1};

    return {first, upper(n, key, v) - 1};

    // TC O(logN)
    // SC O(1)
}

int firstSearch(int n, int key, vector<int> &v)
{
    int low = 0;
    int high = n - 1;
    int mid;
    int first = -1;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (v[mid] == key)
        {
            first = mid;
            high = mid - 1;
        }
        else if (v[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return first;
}
int lastSearch(int n, int key, vector<int> &v)
{
    int low = 0;
    int high = n - 1;
    int mid;
    int last = -1;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (v[mid] == key)
        {
            last = mid;
            low = mid + 1;
        }
        else if (v[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return last;
}

vector<int> Optimal(int n, int key, vector<int> &v)
{
    int first = firstSearch(n, key, v);
    if (first == -1)
        return {-1, -1};
    int last = lastSearch(n, key, v);
    return {first, last};

    // TC 2*O(logN)
    // SC O(1)
}

int main()
{
    int n = 7;
    int key = 13;
    vector<int> v = {3, 4, 13, 13, 13, 20, 40};

    // returning the last occurrence index if the element is present otherwise -1
    vector<int> ans = Linear(n, key, v);
    cout << ans[0] << " " << ans[1] << endl;
    ans = LowerUpper(n, key, v);
    cout << ans[0] << " " << ans[1] << endl;

    ans = Optimal(n, key, v);
    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}