// Print Fibonacci Series up to Nth term
/*
Example 1:
Input: N = 5
Output: 0 1 1 2 3 5
Explanation: 0 1 1 2 3 5 is the fibonacci series up to 5th term.(0 based indexing)

//ye nth term tak print kara rha hai

#include<bits/stdc++.h>
using namespace std;

void Print(int arr[], int n )
{
    for(int i=0;i<=n;i++)
        cout<<arr[i]<<" ";
}
void fibonacci(int arr[],int n)
{
    for(int i=2;i<=n;i++)
        arr[i]=arr[i-1]+arr[i-2];
    Print(arr,n);
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    arr[0]=0;
    arr[1]=1;
    fibonacci(arr,n);
    return 0;
}

// using rec
// 1 1 2 3 5 8 13 
 ye nth possion pe bta rha hai
#include<bits/stdc++.h>
using namespace std;

int fibonacci(int n)
{
    if(n<=1) return n;
    int last=fibonacci(n-1);
    int slast=fibonacci(n-2);
    return last+slast;
}
int main()
{
    int n;
    cin>>n;
    cout<<fibonacci(n);
    return 0;
}
*/

