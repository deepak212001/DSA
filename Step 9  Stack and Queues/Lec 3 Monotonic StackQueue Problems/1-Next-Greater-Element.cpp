/*

Next Greater Element Using Stack


Problem Statement: Given a circular integer array A, return the next greater element for every element in A. The next greater element for an element x is the first element greater than x that we come across while traversing the array in a clockwise manner. If it doesn't exist, return -1 for this element.

Examples:

Example 1:

Input: N = 11, A[] = {3,10,4,2,1,2,6,1,7,2,9}

Output: 10,-1,6,6,2,6,7,7,9,9,10

Explanation: For the first element in A ,i.e, 3, the greater element which comes next to it while traversing and is closest to it is 10. Hence,10 is present on index 0 in the resultant array. Now for the second element,i.e, 10, there is no greater number and hence -1 is it’s next greater element (NGE). Similarly, we got the NGEs for all other elements present in A.


Example 2:

Input:  N = 6, A[] = {5,7,1,7,6,0}

Output: 7,-1,7,-1,7,5

*/

#include <bits/stdc++.h>
using namespace std;

vector<int> bruteForce(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                ans[i] = arr[j];
                break;
            }
        }
    }
    return ans;
    // TC 0(N*N)
    // SC 0(N)
}

vector<int> Optimal(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= arr[i])
            st.pop();
        if (!st.empty())
        {
            ans[i] = st.top();
        }
        st.push(arr[i]);
    }
    return ans;
    // TC 0(2N)
    // SC 0(N)
}

int main()
{
    vector<int> ves{5, 7, 1, 2, 6, 0};
    vector<int> res = bruteForce(ves);
    cout << "The next greater elements are" << endl;
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << "\n-----\n";
    vector<int> result = Optimal(ves);
    cout << "The next greater elements are" << endl;
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
}