#include<bits/stdc++.h>
using namespace std;

void explainVector()
{
    
    vector<int> v;    // v is the vecftor name , also use char , double long string etc

    v.push_back(1);    // add 1 at last  {1}
    v.emplace_back(2);   // similary push back  {1,2}
    
    vector<pair<int,int>> vec;
    vec.push_back({1,2});   // {{1,2}}
    vec.emplace_back(3,4);  // {{1,2},{3,4}}

    vector<int> vec1(5,100);   //that means 5 is size and contain 100 ; {100,100,100,100,100}

    vector<int> vec2(5); // that means 5 is size   {0,0,0,0,0} valuse nhi di to 0 dal diya
    
    vector <int> v1(5,20); // {20,20,20,20,20}
    vector<int> v2(v1);  // v1 copy ho jayega v2 me   {20,20,20,20,20}

    v1.push_back(1);  
    // {20,20,20,20,20,1}   vector ka size bada sakte hai kabhi bhi kahi bhi
    // vector is dynamic nature hai uska size fill nhi hota hai change kar
    //skte hai but arr[5] likh diya to 5 se jayada nhi kar skte hai that reason we use
    //vector
   



    //-------Access of element in vector---------
    vector<int> v3={20,10,15,5,7};
    //v3-> {20,10,15,5,7}  with index 0,1,2,3,4
    cout<<v3[3]<<endl;  //5 print
    //also use v.at(3) is similary to v[3]
    //vector<int> :: iterator it= v3.begin();  // just like pointer  , it's point to memory address
    //aur 
    auto it=v1.begin();
    // address de rha hai 0 index ki
    cout<<*(it)<<endl;   //20    *(it) means print the value of this address

    //v3.begin()-> give you starting address of index 0
    //*(v3.begin()) -> *( ) that means print the value of this address

    it=it+2; //  it is memory address of 0 index now after add 2 then the address of index of 2
    //cout<<*it<<endl;//15
    
    vector<int> :: iterator it1= v3.end();
     // now it is store the address of end of last address but doesn't access and element bcz the store address is the 
     // end address of last index and we wnat to starting address of any index to print the element
    //cout<<*it1<<endl; // 946222384 random balue bcz its point end of vector 
    
    it1--; //now we have start address of last element
    //cout<<*(it1)<<endl; //7  print last element of vector
      
    //vector<int> :: iterator it2= v3.rend(); //rend that means point that last after reverse in easy words point the starting point of 20 ;
    auto it2=v3.rend();
    it2=it2-1; // now point starting address of 20;
    cout<<*(it2)<<endl;
 
    //vector<int> :: iterator it3= v3.rbegin();  //rbegin that means point that first after reverse in easy words point the starting point of 7 ;
    auto it3=v3.rbegin();
    //now point stating address of 7 
    cout<<*(it3)<<endl; //7



    cout<<v3.back();  //print last element of vector , 7
 
    //------Print the element of vector---------

    vector<int> v4={10,20,30,40} ;
    for(vector<int> :: iterator it= v4.begin(); it!=v4.end();it++)
        cout<<*(it)<<" ";
    cout<<endl;
     //aur 
     for(auto it= v4.begin();it!=v4.end(); it++)
        cout<<*(it)<<" ";

    cout<<endl;
    for(auto it : v4)
    {
        cout<<" v4 "<<it<<endl;
    }
    cout<<endl;


     //{10,20,30,40}       
    v4.erase(v4.begin()+1);  // remove 1 index element  {10,30,40}
    v4.push_back(50); 
    v4.push_back(60);
    cout<<endl;
    for(auto it= v4.begin();it!=v4.end(); it++)
        cout<<*(it)<<" "; 
    //{10,30,40,50,60}
    
    v4.erase(v4.begin()+1,v4.begin()+4); //remove  from 1 index to 4th index  {10,60}
    cout<<endl;
    for(auto it= v4.begin();it!=v4.end(); it++)
        cout<<*(it)<<" ";
   
    //-----Insert function ------
    vector<int> v5(2,100);  // {100,100}
    v5.insert(v5.begin(),300); //{300,100,100}
    cout<<endl;
    for(auto it= v5.begin();it!=v5.end(); it++)
        cout<<*(it)<<" ";

    v5.insert(v5.begin()+1,2,200); //{300,200,200,100,100}   (v.begin()+1,2,200)  means v.begin()+1 is 1st index pe , 2 time 200 add karo 
    cout<<endl;
    for(auto it= v5.begin();it!=v5.end(); it++)
        cout<<*(it)<<" ";


    vector<int> copy(2,50);  // {50,50}
    v5.insert(v5.begin(),copy.begin(),copy.end());
    // v5 ke starting point pe copy vector  copy ho jayege 
    //{50,50,300,200,200,100,100}
    cout<<endl;
    for(auto it= v5.begin();it!=v5.end(); it++)
        cout<<*(it)<<" ";

    cout<<v5.size(); //7

    vector<int> v6={10,20};
     // v6-> {10,20}
    v6.pop_back();  //{10}
    cout<<endl;
    for(auto it= v6.begin();it!=v6.end(); it++)
        cout<<*(it)<<" ";

    //v1->{10,20}  v2->{30,40}
    //v1.swap(v2); //v1->{30,40}  v2-> {10,,20}


    v6.clear(); // erases the entire vector
    cout<<endl;
    for(auto it= v6.begin();it!=v6.end(); it++)
        cout<<*(it)<<" ";


    cout<<v6.empty(); // print 1 (true) or 0(false)
    

}

// sort(a,a+n, greater<int>); // sort in descending order

int main()
{
    explainVector();
}