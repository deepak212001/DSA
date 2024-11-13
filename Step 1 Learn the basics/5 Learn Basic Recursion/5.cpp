// Factorial of a Number : Iterative and Recursive

// Solution 1: Iterative

/*
#include <iostream>
using namespace std;
int factorial(int X) {
   int ans = 1;
   for (int i = 1; i <= X; i++) {
      ans = ans * i;
   }
   return ans;
}
int main() {
   int X = 5;
   int result = factorial(X);
   cout << "The factorial of " << X << " is " << result;
}

// TC O(N)
// SC O(1)

*/

// Solution 2: Recursive

#include<bits/stdc++.h>
using namespace std;
int fact(int num)
{   
    if(num==1) return 1;
    else return num*fact(num-1);
}

int main() 
{
    int printTime=0;
    cin>>printTime;
    cout<<fact(printTime);
    return 0;
}

// TC O(N)
// SC O(N)