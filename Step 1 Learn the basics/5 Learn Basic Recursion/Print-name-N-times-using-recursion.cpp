
// TC =O(n)
// SC= o(n)

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