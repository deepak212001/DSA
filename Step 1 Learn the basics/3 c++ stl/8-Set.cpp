#include<bits/stdc++.h>
using namespace std;

// everything is sorted and unique

void explainSet()
{
    set<int> st;
    st.insert(1);  //{1}
    st.emplace(2);  //{1,2}
    st.insert(2);    //{1,2}
    st.insert(4);   //{1,2,4}
    st.insert(3);   //{1,2,3,4}

    //function of insert in vector can be used also,that only increses efficiency

    //begin(),end() , rbegin(), rend(), size(),
    //empty() and swap() are same as those of abvoe

    
    cout<<st.size()<<endl;

    //{1,2,3,4,5}
    auto it =st.find(3);

    //{1,4,5}
    st.erase(5); //erase 5 and take logarithmic time

    int cnt =st.count(1);  // if 1 exits then return 1 if doesnot exits then 0
    cout<<cnt<<endl;

    auto it3=st.find(3);
    st.erase(it3); // it take contant time

    cout<<endl;
    cout << "Elements present in the set: ";
    for (auto it = st.begin(); it != st.end(); it++) {
        cout << * it << " ";
    }
    cout<<endl;
    //{1,2,3,4,5}
    auto it1=st.find(2);    
    auto it2=st.find(4);
    st.erase(it1,it2); // after erase{1,4}
    // in vector erase(i,j)  similary from 2 to 4 so 2 and 3 will be erase


    cout<<endl;
    cout << "Elements present in the set: ";
    for (auto it = st.begin(); it != st.end(); it++) {
        cout << * it << " ";
    }
    cout<<endl;


    auto it4=st.begin();
    cout<<*it4<<endl;

    //lower_bound() and upper_bound()  function works in the same way as in vector it does
    st.insert(2);
    st.insert(3);
    //this is the syntax
    auto its= st.lower_bound(2);
    auto its1= st.upper_bound(3);  
     
    cout<<*(its)<<endl;     //2
    cout<<*(its1)<<endl;    //4

    st.clear(); // dlt all the element in the set
    cout<<st.empty();  //1 means true;

}


int main()
{
    explainSet();
}

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