
#include <bits/stdc++.h>
using namespace std;


vector<int> UsePointer(vector<int> &arr1, vector<int> &arr2)
{
    // both array are sorted
    int n = arr1.size();
    int m = arr2.size();

    vector<int> ans;

    int i=0;
    int j=0;
    while(i<n && j<m)
    {
        if(arr1[i]<arr2[j])
            i++;
        else if(arr1[i]==arr2[j])
        {
            if(ans.size()==0 || ans.back()!=arr2[j])
                ans.push_back(arr2[j]);
            j++;
            i++;
        }
        else 
            j++;
    }


    return ans;
    // TC O(N+M)
    // SC O(N+M)
}

int main()

{
    vector<int> arr1 = {1, 2, 3, 4, 5, 6 ,6, 7, 8, 9, 10};
    vector<int> arr2 = {2, 3, 4, 4, 5, 11, 12};
    // vector<int> Union = UseMap(arr1, arr2);
    // cout << "Union of arr1 and arr2 by using map is  " << endl;
    // for (auto &val : Union)
    //     cout << val << " ";
    // cout<<endl;
    // Union = UseSet(arr1, arr2);
    // cout << "Union of arr1 and arr2 by using Set is  " << endl;
    // for (auto &val : Union)
    //     cout << val << " ";
    // cout<<endl;
    
    vector<int> Union = UsePointer(arr1, arr2);
    cout << "Union of arr1 and arr2 by using Two Pointer is  " << endl;
    for (auto &val : Union)
        cout << val << " ";
    cout<<endl;


    return 0;
}