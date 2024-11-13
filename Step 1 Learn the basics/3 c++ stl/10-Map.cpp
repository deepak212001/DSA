// ------------MAP------------
//     map<key,value>
//     key is unique
//     map stores unique key in sorted order something similer to set 


#include<bits/stdc++.h>
using namespace std;




    void explainMap()
    {
        map<int, int> mp;

        mp[1]=2; //map[key]=value;   {{1,2}}
        mp.emplace({3,1});   //{{1,2},{3,1}}
        mp.insert({2,4});   //{{1,2},{2,4}{3,1}}
        
        map<int,pair<int,int>> mp1;

        map<pair<int,int>,int> mp2;
        mp2[{2,3}]=10;    //{{{2,3},10}}

        //{{1,2},{2,4}{3,1}}
        for(auto it : mp)
        {
            count<<it.first<<" "<<it.second<<endl;  //1 2
            //first ->key and second-> value
        }

        cout<<mp[1]; // 1 is key  so value is 2  , print 2
        cout<<mp[5];  // not found 5 as key 

        auto it =mp.find(3);  // stored address of starting of {3,1}
        cout<<*(it).second;

        auto it = mp.find(5);// 5 is not find then store address end of map menas after the map where end the map

        //this is the syntax
        auto it =mp.lower_bound(2);            
        auto it =mp.upper_bound(3);

        //erase swap size empty are same

    }


/*
----------MULTIMAP----------
//everything same as map only it can store multiple keys
//only mp[key] cannot be used here
// duplicate key and stored


-----------UNORDERMAP--------------
//same as set and unorder_set difference
// duplicate key and not stored
*/


int main()
{
    explainMap();
}

