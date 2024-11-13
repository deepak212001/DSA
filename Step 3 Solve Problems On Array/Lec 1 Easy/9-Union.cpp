/*

Union of Two Sorted Arrays


Problem Statement: Given two sorted arrays, arr1, and arr2 of size n and m. Find the union of two sorted arrays.

The union of two arrays can be defined as the common and distinct elements in the two arrays.NOTE: Elements in the union should be in ascending order.

Examples
Example 1:
Input:

n = 5,m = 5.
arr1[] = {1,2,3,4,5}
arr2[] = {2,3,4,4,5}
Output:

 {1,2,3,4,5}

Explanation:

Common Elements in arr1 and arr2  are:  2,3,4,5
Distnict Elements in arr1 are : 1
Distnict Elemennts in arr2 are : No distinct elements.
Union of arr1 and arr2 is {1,2,3,4,5}

Example 2:
Input:

n = 10,m = 7.
arr1[] = {1,2,3,4,5,6,7,8,9,10}
arr2[] = {2,3,4,4,5,11,12}
Output:
 {1,2,3,4,5,6,7,8,9,10,11,12}
Explanation:

Common Elements in arr1 and arr2  are:  2,3,4,5
Distnict Elements in arr1 are : 1,6,7,8,9,10
Distnict Elemennts in arr2 are : 11,12
Union of arr1 and arr2 is {1,2,3,4,5,6,7,8,9,10,11,12}

*/

#include <bits/stdc++.h>
using namespace std;

vector<int> UseMap(vector<int> &arr1, vector<int> &arr2)
{
    int n = arr1.size();
    int m = arr2.size();

    map<int, int> freq;
    for (int i = 0; i < n; i++)
        freq[arr1[i]]++;

    for (int i = 0; i < m; i++)
        freq[arr2[i]]++;

    vector<int> ans;

    for (auto &it : freq)
        ans.push_back(it.first);

    return ans;


    // TC O((N+M)log(N+M))
    // SC O(N+M)
}


vector<int> UseSet(vector<int> &arr1, vector<int> &arr2)
{
    int n = arr1.size();
    int m = arr2.size();

    set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(arr1[i]);
    }

    for (int i = 0; i < m; i++)
    {
        st.insert(arr2[i]);
    }

    vector<int> ans;

    for (auto it : st)
        ans.push_back(it);

    return ans;

    // TC O((N+M)log(N+M))
    // SC O(N+M)
}


vector<int> UsePointer(vector<int> &arr1, vector<int> &arr2)
{
    // both array are sorted
    int n = arr1.size();
    int m = arr2.size();

    vector<int> ans;

    int i=0;
    int j=0;
    while(i<n && j<m)
    {
        if(arr1[i]<=arr2[j])
        {
            if(ans.size()==0 || ans.back()!=arr1[i])
                ans.push_back(arr1[i]);
            i++;
        }
        else
        {
            if(ans.size()==0 || ans.back()!=arr2[j])
                ans.push_back(arr2[j]);
            j++;
        }
    }

    while(i<n)
    {
        if(ans.back()!=arr1[i])
            ans.push_back(arr1[i]);
        i++;
    }
    while(j<m)
    {
        if(ans.back()!=arr2[j])
            ans.push_back(arr2[j]);
        j++;
    }

    return ans;
    // TC O(N+M)
    // SC O(N+M)
}

int main()

{
    vector<int> arr1 = {1, 2, 3, 4, 5, 6 ,6, 7, 8, 9, 10};
    vector<int> arr2 = {2, 3, 4, 4, 5, 11, 12};
    vector<int> Union = UseMap(arr1, arr2);
    cout << "Union of arr1 and arr2 by using map is  " << endl;
    for (auto &val : Union)
        cout << val << " ";
    cout<<endl;
    Union = UseSet(arr1, arr2);
    cout << "Union of arr1 and arr2 by using Set is  " << endl;
    for (auto &val : Union)
        cout << val << " ";
    cout<<endl;
    
    Union = UsePointer(arr1, arr2);
    cout << "Union of arr1 and arr2 by using Two Pointer is  " << endl;
    for (auto &val : Union)
        cout << val << " ";
    cout<<endl;


    return 0;
}