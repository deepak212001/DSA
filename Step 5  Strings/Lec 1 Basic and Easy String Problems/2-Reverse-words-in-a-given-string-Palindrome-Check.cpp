/*
Reverse Words in a String


Problem Statement: Given a string s, reverse the words of the string.

Examples:

Example 1:
Input: s=”this is an amazing program”
Output: “program amazing an is this”

Example 2:
Input: s=”This is decent”
Output: “decent is This”

*/


#include<bits/stdc++.h>
using namespace std;

string BruteForce(string s)
{
    stack<string> st;
    int i;
    string str="";
    for(i=0;i<s.length();i++)
    {
        if(s[i]==' ')
        {
            st.push(str);
            str="";
        }
        else 
            str+=s[i];
    }
    st.push(str);
    string ans="";
    while(!st.empty())
    {
        ans+=st.top()+" ";
        st.pop();
    }
   
    return ans;

    // TC O(N)
    // SC O(N)

        //aur

    string text = "i like this program very much";
    vector<string> str;
    istringstream iss(text);
    for (string s; iss >> s;) {
        str.push_back(s);
    }
    reverse(str.begin(), str.end());
    cout << str[0];
    for (int i = 1; i < str.size(); i++) {
        cout << " " << str[i];
    }
    //TC O(N)
    // SC O(N)
}


string optimal(string s)
{
    int left = 0;
    int right = s.length()-1;
    
    string temp="";
    string ans="";
    
    while (left <= right) {
        char ch= s[left];
        if (ch != ' ') {
            temp += ch;
        } else if (ch == ' ') {
            if (ans!="") ans = temp + " " + ans;
            else ans = temp;
            temp = "";
        }
        left++;
    }
    
    if (temp!="") {
        if (ans!="") ans = temp + " " + ans;
        else ans = temp;
    }
    
    return ans;    
        
    // TC O(N)
    // SC O(1)
}
int main()
{
    string st="TUF is great for interview preparation";
    cout<<optimal(st)<<endl;
    cout<<BruteForce(st)<<endl;



}