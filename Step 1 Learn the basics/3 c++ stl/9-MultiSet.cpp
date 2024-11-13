// -------MULTISET----------
// only sorted
// everything is same as set
// only store duplicate elemnts also 

#include<bits/stdc++.h>
using namespace std;

void explainMultiSet()
{
    multiset<int> ms;
    ms.insert(1);  //{1}
    ms.insert(1);  //{1,1}
    ms.insert(1);  //{1,1,1}

    cout<<endl;
    cout << "Elements present in the set: ";
    for (auto it = ms.begin(); it != ms.end(); it++) {
        cout << * it << " ";
    }
    cout<<endl;


    ms.erase(1);   // all 1's erased

    cout<<ms.empty()<<endl; // 1

    ms.insert(2);  //{2}
    ms.insert(3);  //{2,3}
    ms.insert(1);  //{1,2,3}
    ms.insert(1);  //{1,1,2,3}
    int cnt= ms.count(1);   // cnt=2
    cout<<cnt<<endl;    //2
    //only a single one erase
    ms.erase(ms.find(1));   //erase the first 1's
    cout<<ms.size()<<endl; // 3   {1,2,3}
    

    ms.insert(1);  //{1,1,2,3}
    ms.insert(1);  //{1,1,1,2,3}
    ms.insert(4);  //{1,1,1,2,3,4}
    ms.insert(5);  //{1,1,1,2,3,4,5}
    ms.insert(6);  //{1,1,1,2,3,4,5,6}
    


    //{1,1,1,2,3,4,5,6}
    ms.erase(ms.find(2),next(ms.find(3),));  //{1,1,1,5,6} 

    cout<<endl;
    cout << "Elements present in the set: ";
    for (auto it = ms.begin(); it != ms.end(); it++) {
        cout << * it << " ";
    }
    cout<<endl;
    //rest all function same as set  */

}

int main()
{
    explainMultiSet();
}