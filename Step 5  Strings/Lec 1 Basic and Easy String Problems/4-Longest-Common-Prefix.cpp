/*


*/

// C++ program to find longest common prefix 
// of given array of words.


#include<bits/stdc++.h>
using namespace std;

// Function to find the longest common prefix
string longestCommonPrefix(vector<string>& strs) 
{
    string ans="";
    sort(strs.begin(),strs.end());
    int n=strs.size();
    string beg=strs[0],end=strs[n-1];
    for(int i=0;i<min(beg.size(),end.size());i++)
    {
        if(beg[i]!=end[i]) 
            return ans;
        ans+=beg[i];
    }
    return ans;

    // TC O(NlogN)
    // SC O(1)
}

// Driver Code
int main()
{
    vector<string> arr = {"geeksforgeeks", "geeks", "geek", "geezer"};
    cout << "The longest common prefix is: " << longestCommonPrefix(arr);
    return 0;
}

