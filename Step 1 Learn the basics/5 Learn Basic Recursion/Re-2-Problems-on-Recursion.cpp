/*
Basic Recursion Problems

1. Print Nmae 5 time

TC =O(n)
SC= o(n)

#include<bits/stdc++.h>
using namespace std;
void printName(int times)
{   
    if(times<1) return;
    cout<<"Deepak"<<endl;
    times--;
    printName(times);
    
}

int main() {
    int printTime=0;
    cin>>printTime;
    printName(printTime);
    return 0;
}


2. Print Linearly from 1 to n

TC=O(n)
SC=O(n)

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

4. Print in terms of n to 1


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

5. Print Linearly from 1 to n (but by beerk track)  means not use i+1


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

6. Print Linearly from n to 1 (but by beerk track)  means not use i+1


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


*/