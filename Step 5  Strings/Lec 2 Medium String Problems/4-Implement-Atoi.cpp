/*

8. String to Integer (atoi)


Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

The algorithm for myAtoi(string s) is as follows:

Whitespace: Ignore any leading whitespace (" ").
Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity is neither present.
Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
Return the integer as the final result.

 

Example 1:

Input: s = "42"

Output: 42

Explanation:

The underlined characters are what is read in and the caret is the current reader position.
Step 1: "42" (no characters read because there is no leading whitespace)
         ^
Step 2: "42" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "42" ("42" is read in)
           ^
Example 2:

Input: s = " -042"

Output: -42

Explanation:

Step 1: "   -042" (leading whitespace is read and ignored)
            ^
Step 2: "   -042" ('-' is read, so the result should be negative)
             ^
Step 3: "   -042" ("042" is read in, leading zeros ignored in the result)
               ^
Example 3:

Input: s = "1337c0d3"

Output: 1337

Explanation:

Step 1: "1337c0d3" (no characters read because there is no leading whitespace)
         ^
Step 2: "1337c0d3" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "1337c0d3" ("1337" is read in; reading stops because the next character is a non-digit)
             ^
Example 4:

Input: s = "0-1"

Output: 0

Explanation:

Step 1: "0-1" (no characters read because there is no leading whitespace)
         ^
Step 2: "0-1" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "0-1" ("0" is read in; reading stops because the next character is a non-digit)
          ^
Example 5:

Input: s = "words and 987"

Output: 0

Explanation:

Reading stops at the first non-digit character 'w'.
*/

#include <bits/stdc++.h>
using namespace std;

int inbuilt(string s)
{
	int val = atoi(s.c_str());  // Convert string to C-style string
	return val;
	// TC O(N)
	// SC O(1)
}

int myAtoi(string str)
{
    int res = 0;
	int sign = 1;
	if (str[0] == '-') {
        sign = -1;
    }
    for (int i=1; str[i] != '\0'; ++i)
        res = res * 10 + str[i] - '0';
 
    return sign*res;

	// TC O(N)
	// SC O(1)
}

int myAtoi1(string s) {
    int n=s.size();
    if(s.empty()) return 0;
    long i=0, sign =1,sum=0,ans=0;
    while(i<n && s[i]==' ') 
        ++i;
    if(s[i]=='-' || s[i]=='+') 
        s[i++]=='-'? sign=-1: sign=1;


    while(i<n)
    {
        if(s[i]>=48 && s[i]<=57) 
            ans=ans*10+ (s[i++]-'0');
        else 
            return ans*sign;
        if(ans>INT_MAX) 
            return sign ==-1 ? INT_MIN:INT_MAX;
    } 
    return ans*sign;
}

int main()
{
	int val;
	string strn1 = "as -12546";

	cout<<inbuilt(strn1)<<endl;
	cout<<myAtoi(strn1)<<endl;
	cout<<myAtoi1(strn1)<<endl;


	return (0);
}


