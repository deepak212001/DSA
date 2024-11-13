/*

{1,5,3,2,8}

sort(it,it+3);
sort(starting point, end point )

pair<int,int> a={{1,2},{2,1},{4,1}}

// sort it according to second element 
// if second element is same , then sort
// it according to first element but in descending

sort(a,a+n,comp);

bool comp(pair<int,int> p1, pair<int,int> p2)
{
    if(p1.second<p2.second) return true;
    if(p1.second>p2.second) return false;

    //if they are same
    if(p1.first>p2.first ) return true;
    return false;
}



--------NEXT PERMUTATION---

string s="123"
do{
    cout<<s<<endl;
}while(next_permutation(s.begin(),s.end()));


a={5,6,8,5,2}
int ele=*max_element(a,a+n);
*/