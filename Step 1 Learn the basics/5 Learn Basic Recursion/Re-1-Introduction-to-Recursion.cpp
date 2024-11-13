/*

RECURSION -> heb a function call itself until a specified condition is met

function ()
{
    code..
    ..
    ..\
    function()
}
main()
{
    function();
}


count=0
fun()
{
    if(count==4) break
    print(count)
    count++
    fun()
}
main()
{
    fun()
}

output
0
1
2
3
*/
#include<iostream>
using namespace std;

int count=0;
void print()
{
    if(count==4) return;
    cout<<count<<endl;
    count++;
    print();
}

int main()
{
    print();
    return 0 ;
}

/*
0
1
2
3
*/