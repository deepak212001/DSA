/*
Check if the given String is Palindrome or not
Example 1:
Input: Str =  “ABCDCBA”
Output: Palindrome
Explanation: String when reversed is the same as string.
*/

/*
#include<bits/stdc++.h>
using namespace std;
bool isPalindrone(string s)
{
    int n=s.size();
    for(int i=0;i<n/2;i++)
        if(s[i]!=s[n-i-1])
            return false;
    return true;
}

int main()
{
    string str= "ABCDCBA";
    if(isPalindrone(str))
        cout<<"Palindore";
    else
        cout<<"Not Palindore";
    return 0;
}

// TC O(N)
// SC O(1)
*/

// Recursive Approach:

#include<bits/stdc++.h>
using namespace std;
bool isPalindrone(string s,int i)
{
    if(i>=s.size()/2)
        return true;
    if(s[i]!=s[s.size()-i-1])
        return false;
    return isPalindrone(s,i+1);
}

int main()
{
    string str= "ABCDCBA";
    if(isPalindrone(str,0))
        cout<<"Palindore";
    else
        cout<<"Not Palindore";
    return 0;
}

// TC O(N)
// SC O(1)