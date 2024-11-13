/*
Longest Consecutive Sequence in an Array


Problem Statement: You are given an array of ‘N’ integers. You need to find the length of the longest sequence which contains the consecutive elements.

Examples
Example 1:
Input:
 [100, 200, 1, 3, 2, 4]

Output:
 4

Explanation:
 The longest consecutive subsequence is 1, 2, 3, and 4.

Input:
 [3, 8, 5, 7, 6]

Output:
 4

Explanation:
 The longest consecutive subsequence is 5, 6, 7, and 8.


*/





#include <bits/stdc++.h>
using namespace std;

bool Search(vector<int>&a, int num) 
{
    int n=a.size();
    for(int i=0;i<n;i++)
    {
        if(a[i]==num)
            return true;
    }
    return false;
}
int BroteForce(vector<int>&a) 
{
    int n=a.size();
    int longest=1;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        int x=a[i];
        int cnt=1;
        while(Search(a,x+1))
        {
            x++;
            cnt++;
        }
        longest=max(longest,cnt);
    }
    return longest;

    // TC O(N^2)
    // SC O(1)
}

int Better(vector<int> a)
{
    int n=a.size();
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    
    sort(a.begin(),a.end());
    int longest=1;
    int cnt=0;
    int lastSmaller=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(a[i]-1==lastSmaller)
        {
            cnt++;
            lastSmaller=a[i];
        }    
        else if(a[i]!=lastSmaller)
        {
            cnt=1;
            lastSmaller=a[i];
        }

        longest=max(longest,cnt);
    }
    return longest;

    // TC O(NlogN)
    // SC O(1)
} 

int Optimal(vector<int> &a)
{
    int n=a.size();
    if(n<2)
        return n;

    set<int>st;
    int longest=1;
    for(int i=0;i<n;i++)
    {
        st.insert(a[i]);
    }
    for(auto it: st)
    {
        if(st.find(it-1)==st.end())
        {
            int cnt=1;
            int x=it;
            while(st.find(x+1)!=st.end())
            {
                x++;
                cnt++;
            }
            longest=max(longest,cnt);
        }
    }
    return longest;

    // TC O(N)
    // SC O(N)

}

int main()
{
    vector<int> a = {100, 200, 1, 2, 3, 4};
    int ans = BroteForce(a);
    cout << "The longest consecutive sequence is " << ans << "\n";

    ans = Better(a);
    cout << "The longest consecutive sequence is " << ans << "\n";
    
    ans = Optimal(a);
    cout << "The longest consecutive sequence is " << ans << "\n";
    return 0;
}

