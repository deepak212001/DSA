/*
 Previous Smaller Element
he only argument given is integer array A.
Output Format

Return the integar array G such that G[i] contains nearest smaller number than A[i].If no such element occurs G[i] should be -1.
For Example

Input 1:
    A = [4, 5, 2, 10, 8]
Output 1:
    G = [-1, 4, -1, 2, 2]
Explaination 1:
    index 1: No element less than 4 in left of 4, G[1] = -1
    index 2: A[1] is only element less than A[2], G[2] = A[1]
    index 3: No element less than 2 in left of 2, G[3] = -1
    index 4: A[3] is nearest element which is less than A[4], G[4] = A[3]
    index 4: A[3] is nearest element which is less than A[5], G[5] = A[3]

Input 2:
    A = [3, 2, 1]
Output 2:
    [-1, -1, -1]
Explaination 2:
    index 1: No element less than 3 in left of 3, G[1] = -1
    index 2: No element less than 2 in left of 2, G[2] = -1
    index 3: No element less than 1 in left of 1, G[3] = -1


*/

#include <bits/stdc++.h>
using namespace std;

vector<int> bruteForce(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans(n, -1);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] < arr[i])
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
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top() >= arr[i])
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
    // vector<int> ves{5, 7, 1, 2, 6, 0};
    vector<int> ves{4, 5, 2, 10, 8};
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