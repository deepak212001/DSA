/*

 --------LIST----------------
    it is also dynamic nature
    it is similary to vector , it also add front function also , vector me nhi the !
    it is doubly link list and vector is single link list

*/

#include<bits/stdc++.h>
using namespace std;

void explainList()
{
    list<int> ls;

    ls.push_back(2);   //{2}
    ls.emplace_back(4);  //{2,4}

    ls.push_front(5);  //{5,2,4}  push_front best as compare to vector insert bcz increse time complexity

    ls.emplace_front(6);  //{6,5,2,4}

    for(auto it: ls)
    {
        cout<<it<<endl;
    }
    /*
    6
    5
    2
    4
    */

    //rest function same as vector
    //begin , end , rbegin. rend, clear, insert, size, swap

}

int main()
{
    explainList();
}