/*
1. Reverse an array using Recursion
Example 1:
Input: N = 5, arr[] = {5,4,3,2,1}
Output: {1,2,3,4,5}
Explanation: Since the order of elements gets reversed the first element will
occupy the fifth position, the second element occupies the fourth position and
so on.



#include<bits/stdc++.h>
using namespace std;

void Print(int arr[], int n )
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
void reverseArr(int arr[],int n)
{
    int ans[n];
    for(int i=0;i<n;i++)
        ans[n-i-1]=arr[i];
    Print(ans,n);
}
int main()
{
    int n=5;
    int arr[]={5,4,3,2,1};
    reverseArr(arr,n);
    return 0;
}



2. Check if the given String is Palindrome or not
Example 1:
Input: Str =  “ABCDCBA”
Output: Palindrome
Explanation: String when reversed is the same as string.


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
*/
