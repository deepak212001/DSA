/*
1. Sum of first N numbers



#include<bits/stdc++.h>
using namespace std;
int sum=0;
void printCounting(int i,int num)
{   
    if(i>num) 
    {
        cout<<sum;
        return;
    }
    sum+=i;
    printCounting(i+1,num);
}

int main() 
{
    int printTime=0;
    cin>>printTime;
    printCounting(1,printTime);
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
int sum1(int num)
{   
    if(num==0) return 0 ;
    else return num+sum(num-1);
}
int sum(int n)
{
    if(n==0)
        return 
    sum(n-1);
    return 
}
int main() 
{
    int printTime=0;
    cin>>printTime;
    cout<<sum(printTime);
    return 0;
}

2. Factorial of n


*/



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