// Print 1 to N using Recursion

// TC=O(n)
// SC=O(n)

/*
#include<bits/stdc++.h>
using namespace std;

void printCounting(int curr,int num)
{   
    if(curr>num) return;
    cout<<curr<<endl;
    printCounting(curr+1,num);
}

int main() 
{
    int printTime=0;
    cin>>printTime;
    printCounting(1,printTime);
    return 0;
}

*/

// Print Linearly from 1 to n (but by beerk track)  means not use i+1


#include<bits/stdc++.h>
using namespace std;

void printCounting(int i,int num)
{   
    if(i<1) return;
    printCounting(i-1,num);
    cout<<i<<endl;
}

int main() 
{
    int printTime=0;
    cin>>printTime;
    printCounting(printTime,printTime);
    return 0;
}