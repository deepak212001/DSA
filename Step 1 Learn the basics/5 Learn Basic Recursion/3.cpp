// Print N to 1 using Recursion


/*
#include<bits/stdc++.h>
using namespace std;

void printCounting(int num)
{   
    if(num<=0) return;
    cout<<num<<endl;
    printCounting(num-1);
}

int main() 
{
    int printTime=0;
    cin>>printTime;
    printCounting(printTime);
    return 0;
}
*/

// Print Linearly from n to 1 (but by beerk track)  means not use i+1


#include<bits/stdc++.h>
using namespace std;

void printCounting(int i,int num)
{   
    if(i>num) return;
    printCounting(i+1,num);
    cout<<i<<endl;
}

int main() 
{
    int printTime=0;
    cin>>printTime;
    printCounting(1,printTime);
    return 0;
}