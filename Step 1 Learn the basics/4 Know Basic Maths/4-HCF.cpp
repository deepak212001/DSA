/*

Find GCD of two numbers


Problem Statement: Given two integers N1 and N2, find their greatest common divisor.

The Greatest Common Divisor of any two integers is the largest number that divides both integers.

Examples
Example 1:
Input:N1 = 9, N2 = 12
                
Output:3
Explanation:Factors of 9: 1, 3 and 9
Factors of 12: 1, 2, 3, 4, 6, 12
Common Factors: 1, 3 out of which 3 is the greatest hence it is the GCD.
Example 2:
Input:N1 = 20, N2 = 15
                
Output: 5
Explanation:Factors of 20: 1, 2, 4, 5
Factors of 15: 1, 3, 5
Common Factors: 1, 5 out of which 5 is the greatest hence it is the GCD.

*/


#include<bits/stdc++.h>
using namespace std;

int BruteForce(int n1,int n2)
{
    int hcf=0;
    int i=1;
    while(i<=min(n1,n2) )
    {
        if(n1%i==0 && n2%i==0)
            hcf=i;
        i++;
    }
    return hcf;
    //TC 0(min(n1,n2))
    //SC O(1)
}


int Better(int n1,int n2)
{
    int hcf=0;
    int i=min(n1,n2);
    while(i>0 )
    {
        if(n1%i==0 && n2%i==0)
            return i;
        i--;
    }
    return 1;
    //TC 0(min(n1,n2))
    //SC O(1)

}

int Optimal(int n1,int n2)
{
    while(n1>0 && n2>0)
    {
        if(n1>n2)
            n1%=n2;
            // n1-=n2;
        else
            n2%=n1;
            // n2-=n1;
    }
    if(n1==0)
        return n2;
    return n1;

    //TC O(min(n1,n2))
   //SC O(1)

   /*
   EQUILATERAL ALGO
   Eg, n1 = 20, n2 = 15:

    gcd(20, 15) = gcd(20-15, 15) = gcd(5, 15)

    gcd(5, 15) = gcd(15-5, 5) = gcd(10, 5)

    gcd(10, 5) = gcd(10-5, 5) = gcd(5, 5)

    gcd(5, 5) = gcd(5-5, 5) = gcd(0, 5)

    Hence, return 5 as the gcd.
   */
}

int main()
{
    int num1,num2;
    cout<<"Enter 2 num ";
    cin>>num1>>num2;
    cout<<"\n "<<BruteForce(num1,num2);
    cout<<"\n "<<Better(num1,num2);
    cout<<"\n "<<Optimal(num1,num2);

}