/*

-----------PAIR----------
void explainpair()
{
    pair<int ,int> p={1,3};
    cout<<p.first<<" "<<p.second;
    //p.first=1 and p.second=3
    prir<int , pair<int ,int>> p={1,{3,4}};
    cout<<p.first<<" "<<p.second.first<<" "<<p.second.second;
    // p.first=1 ,p.second.first=3,p.second.second=4

    pair<int, int> arr[]={ {1,2},{2,5},{5,1}};
    //index 0 ={1,2} index 1={2,5} index 2={5,1}
    cout<<arr[1].second;
    // arr[1].second =5   , arr[1]={2,5}
}


------------VECTOR------------

    void explainVector()
    {
        vector<int> v;    // v is the vecftor name , also use char , double long string etc

        v.push_back(1);    // add 1 at last  {1}
        v.emplace_back(2);   // similary push back  {1,2}
        vector<pari<int,int>> vec;
        vec.push_back({1,2});   // {{1,2}}
        vec.emplace_back(3,4);  // {{1,2},{3,4}}

        vector<int> v(5,100);   //that means 5 is size and contain 100 ; {100,100,100,100,100}

        vector<int v(5); // that means 5 is size   {0,0,0,0,0} valuse nhi di to 0 dal diya


        vector <int> v1(5,20); // {20,20,20,20,20}
        vector<int> v2(v1);  // v1 copy ho jayega v2 me   {20,20,20,20,20}

        v1.push_back(1);  
        // {20,20,20,20,20,1}   vector ka size bada sakte hai kabhi bhi kahi bhi
        // vector is dynamic nature hai uska size fill nhi hota hai change kar
        //skte hai but arr[5] likh diya to 5 se jayada nhi kar skte hai that reason we use
        //vector

        -------Access of element in vector---------

        v-> {20,10,15,5,7}  with index 0,1,2,3,4
        cout<<v[3]   //5 print
        //also use v.at(3) is similary to v[3]

        vector<int> :: iterator it= v.begin();  // just like pointer  , it's point to memory address
        // address de rha hai 0 index ki
        cout<<*(it);   // *(it) means print the value of this address

        //v.begin()-> give you starting address of index 0
        //*(v.begin()) -> *( ) that means print the value of this address

        it=it+2; //  it is memory address of 0 index now after add 2 then the address of index of 2

        //{10,20,30,40}
         vector<int> :: iterator it= v.end();
         // now it is store the address of end of last address but doesn't access and element bcz the store address is the 
         // end address of last index and we wnat to starting address of any index to print the element

        it--; //now we have start address of last element
        cout<<*(it); //40 print last element of vector
        
        vector<int> :: iterator it= v.rend(); //rend that means point that last after reverse in easy words point the starting point of 10 ;
        it--; // now point starting address of 20;
        vector<int> :: iterator it= v.rbegin();  //rbegin that means point that first after reverse in easy words point the starting point of 40 ;
        it++; //now point stating address of 30 


        cout<<v.back();  //print last element of vector , 40

        ------Print the element of vector---------
        for(vector<int> :: iterator it= v.begin(); it!=v.end();it++)
            cout<<*(it)<<" ";
         //aur 
         for(auto it= v.begin();it!=v.end(); it++)
            cout<<*(it)<<" ";

         //{10,20,30,40}       
        v.erase(v.begin()+1);  // remove 1 index element  {10,30,40} 
        //{10,20,30,40,50,60}
        v.erase(v.begin()+2,v.begin()+4); //remove  from 1 index to 4th index  {10,60}
    
        -----Insert function ------
        vector<int> v(2,100);  // {100,100}
        v.insert(v.begin(),300) //{300,100,100}
        v.insert(v.begin()+1,2,200) //{300,200,200,100,100}   (v.begin()+1,2,200)  means v.begin()+1 is 1st index pe , 2 time 200 add karo 
        
        vector<int> copy(2,50);  // {50,50}
        v.insert(v.begin(),copy.begin(),copy.end());
        // v ke starting point pe copy vector  copy ho jayege 
        //{50,50,300,200,200,100,100}
`       // v-> {10,20}
        cout<<v.size(); //2
        v.pop_back();  //{10}

        //v1->{10,20}  v2->{30,40}
        v1.swap(v2); //v1->{30,40}  v2-> {10,,20}
        v.clear(); // erases the entire vector

        cout<<v.empty(); // print true or false

    
    }

    sort(a,a+n, greater<int>); // sort in descending order
*/

/*
    --------LIST----------------
    it is also dynamic nature
    it is similary to vector , it also add front function also , vector me nhi the !
    it is doubly link list and vector is single link list

    void explainList()
    {
        list<int> ls;

        ls.push_back(2);   //{2}
        ls.emplace_back(4);  //{2,4}

        ls.puch_front(5);  //{5,2,4}  push_front best as compare to vector insert bcz increse time complexity

        ls.emplace_front(6);  //{6,5,2,4}

        //rest function same as vector
        //begin , end , rbegin. rend, clear, insert, size, swap

    }

*/

/*
-------------Deque------------

void explainDeque()
{
    deque<int>dq;
    dp.push_back(1);   //{1}
    dq.emplace_back(2);   //{1,2}
    dq.push_front(4);   //{4,1,2}
    dq.emplace_front(3);   //{3,4,1,2}

    dp.pop_back();   //{3,4,1}
    dp.pop_front();   //{4,1}

    dp.back();
    dp.front();

    /rest function same as vector
        //begin , end , rbegin. rend, clear, insert, size, swap

}

*/

/*
----------STACK------------
LIFO  last in frist out
void explainStack()
{
    stack<int> st;

    st.push(1);   // {1}
    st.push(2);   // {2,1}
    st.push(3);   // {3,3,2,1}
    st.push(3);   // {3,3,2,1}
    st.emplace(5);   // {5,3,3,2,1}

    cout<<st.top(); // 5     front element is top 

    st.pop();   // {3,3,2,1}

    cout<<st.top();  //3
    cout<<st.size();  //4
    cout<<st.empty();  //false

    stack<int>st1,st2;
    s1.swap(st2);
}

*/

/*

-----------QUEUE------------
FIFO   fist in first out 
void explainqueue()
{
    queue<int> q;

    q.push(1);   // {1}
    q.push(2);   // {1,2}
    q.emplace(4);   // {1,2,4}
    q.back()+=5;
    cout<<q.back(); // 9
    //q->{1,2,9}
    cout<<q.front(); // 1   

    q.pop();   // {2,9}
    cout<<q.front(); // 2  
    //size swap empty same as stack
}

*/

/*
-----------PRIORITY------------
//greater is in top
void explainPQ()
{
    priority_queue<int> pq;

    pq.push(5);  //{5}
    pq.push(2);  //{5,2}
    pq.push(8);  //{8,5,2,}
    pq.emplace(10);  //{10,8,5,2}

    cout<<pq.top();  //print 10
    pq.pop(); //{8,5,2}
    cout<<pq.top();  //print 8

    //size,swap wmpty function same as other
    // smaller is in top
    //minimum heap
    priority_queue<int,vector<int>,greater<int>> pq;
    pq.push(5);  //{5}
    pq.push(2);  //{2,5}
    pq.push(8);  //{2,5,8}
    pq.emplace(10);  //{2,5,8,10}

    cout<<pq.top();  //print 2
}

*/

/*
-----------SET--------
everything is sorted and unique

void explainSet()
{
    set<int> st;
    st.insert(1);  //{1}
    st.emplace(2);  /{1,2}
    st.insert(2);    //{1,2}
    st.insert(4);   //{1,2,4}
    st.insert(3);   //{1,2,3,4}

    //function of insert in vector can be used also,that only increses efficiency

    //begin(),end() , rbegin(), rend(), size(),
    //empty() and swap() are same as those of abvoe

    //{1,2,3,4,5}
    auto it =st.find(3);

    //{1,4,5}
    st.erase(5); //erase 5 and take logarithmic time

    int cnt =st.count(1);   if 1 exits then return 1 if doesnot exits then 0

    auto it=st.find(3);
    st.erase(it); // it take contant time

    //{1,2,3,4,5}
    auto it1=st.find(2);    
    auto it2=st.find(4);
    st.erase(it1,it2); // after erase{1,4,5}
    // in vector erase(i,j)  similary from 2 to 4 so 2 and 3 will be erase



    //lower_bound() and upper_bound()  function works in the same way as in vector it does

    //this is the syntax
    auto it= st.lower_bounf(2);
    auto it= st.upper_bounf(3);   

}

*/

/*
-------MULTISET----------
//only sorted
//everything is same as set
//only store duplicate elemnts also 

void explainMultiSet()
{
    multiset<int> ms;
    ms.insert(1);  //{1}
    ms.insert(1);  //{1,1}
    ms.insert(1);  //{1,1,1}

    ms.erase(1);   // all 1's erased

    int cnt= ms.count(1);   // cnt=3
    //only a single one erase
    ms.erase(ms.find(1));   //erase the first 1's
    //{1,1,1,2,3,4,5,6}
    ms.erase(ms.find(2),ms.find(2)+2);  //{1,1,1,5,6}
    //rest all function same as set

}
*/

/*
-----------UNORDERED SET----------


only unique


void explainset()
{
    unordered_set<int> st;

    //lower_bound and upper_bound functiomn
    // does not works, rest all function are same as above ,
    // it does not store in any particular order it has a better complexity 
    // than set in most cases, except some when collision happens

}

*/


/*

------------MAP------------
    map<key,value>
    map stores unique key in sorted order something similer to set 


    void explainMap()
    {
        map<int, int> mp;
        map<int,pair<int,int>> mp;

        mp[1]=2; //map[key]=value;   {{1,2}}
        mp.emplace({3,1});   //{{1,2},{3,1}}
        mp.insert({2,4});   //{{1,2},{2,4}{3,1}}
        
        map<pair<int,int>,int> mp;
        mp[{2,3}]=10;    //{{{2,3},10}}

        /{{1,2},{2,4}{3,1}}
        for(auto it : mp)
        {
            count<<it.first<<" "<<it.econd<<endl;  //1 2
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
*/


/*
----------MULTIMAP----------
//everything same as map only it can store multiple keys
//only mp[key] cannot be used here
// duplicate key and stored


-----------UNORDERMAP--------------
//same as set and unorder_set difference
// duplicate key and not stored
*/