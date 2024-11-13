/*
Median of Two Sorted Arrays of different sizes


Problem Statement: Given two sorted arrays arr1 and arr2 of size m and n respectively, return the median of the two sorted arrays. The median is defined as the middle value of a sorted list of numbers. In case the length of the list is even, the median is the average of the two middle elements.

Examples
Example 1:
Input Format:
 n1 = 3, arr1[] = {2,4,6}, n2 = 3, arr2[] = {1,3,5}
Result:
 3.5
Explanation:
 The array after merging 'a' and 'b' will be { 1, 2, 3, 4, 5, 6 }. As the length of the merged list is even, the median is the average of the two middle elements. Here two medians are 3 and 4. So the median will be the average of 3 and 4, which is 3.5.

Example 2:
Input Format:
 n1 = 3, arr1[] = {2,4,6}, n2 = 2, arr2[] = {1,3}
Result:
 3
Explanation:
 The array after merging 'a' and 'b' will be { 1, 2, 3, 4, 6 }. The median is simply 3.

*/


/*
    arr1-> 1, 4, 7, 10, 12      size=5
    arr2-> 2, 3, 6, 15          size=4

    arr3-> 1, 2, 3, 4, 6, 7, 10, 12, 15    size 9  
    size is odd so 5 index  4 left side 4 right side and 5 is lie between them
    9/2 = 4.5

    let size is even 
    arr3-> 10, 20, 30, 40, 50, 60   size 6 

    no one is in middle so 6/2=3
    then 3 and 4 index midle one 
    (arr3[3]+arr3[4]) /2 

*/

#include <bits/stdc++.h>
using namespace std;

double BruteForce(vector<int> &a, vector<int> &b)
{
    int n1 = a.size(), n2 = b.size();
    // double median;
    int n=n1+n2;
    vector<int> newVec(n);
    merge(a.begin(), a.end(), b.begin(), b.end(), newVec.begin());
    // merge a and b also sort
    // merge(v1 starting add, v1 end adress, v2 starting add, v2 end adress, jis vector me dalna hai us ka starting address)
    
    
    return n%2==1 ? (double)(newVec[n/2]) : (double)((newVec[n/2]+newVec[(n/2)-1])/2.0);

    // TC (N1+N2)
    // SC O(N1+N2)

}
double Better(vector<int> &a, vector<int> &b)
{
    int n1 = a.size(), n2 = b.size();
    int n=n1+n2;
    int ind2=n/2;
    int ind1=ind2-1;
    int cnt=0;

    int ind1el=-1;
    int ind2el=-1;
    int i=0,j=0;
    while(i<n1 && j<n2)
    {
        if(a[i]<b[j])
        {
            if(cnt==ind1)
                ind1el=a[i];
            if(cnt==ind2)
                ind2el=a[i];
            
            i++;
        }
        else
        {
            if(cnt==ind1)
                ind1el=b[j];
            if(cnt==ind2)
                ind2el=b[j];
            
            j++;
        }
        cnt++;

    }
    
    while(i<n1)
    {
        if(cnt==ind1)
            ind1el=a[i];
        if(cnt==ind2)
            ind2el=a[i];
        cnt++;
        i++;
    }
    while(j<n2)
    {
        if(cnt==ind1)
            ind1el=b[j];
        if(cnt==ind2)
            ind2el=b[j];
        cnt++;
        j++;
    }
    return n%2==1 ? (double)(ind2el) : (double)((ind1el+ind2el)/2.0);

    // TC O(N1+N2)
    // SC O(1)

}

double Optimal (vector<int> a, vector<int> b)
{
    int n1=a.size();
    int n2=b.size();

    if(n1>n2)
        return Optimal(b,a);

    int n=n1+n2;
    int need=(n+1)/2;

    int low=0;
    int high=n1;
    while(low<=high)
    {
        int mid1=(low+high)/2;     // mid1 for arr1 (a)
        int mid2=need-mid1;       // mid2 for arr2 (b)

        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;

        if(mid1<n1)
            r1=a[mid1];
        if(mid2<n2)
            r2=b[mid2];
        
        if (mid1 - 1 >= 0) 
            l1 = a[mid1 - 1];
        if (mid2 - 1 >= 0) 
            l2 = b[mid2 - 1];

        if(l1<=r2 && l2<=r1)
        {
            if(n%2==1)
                return max(l1,l2);
            else 
                return ((double)(max(l1,l2)+min(r1,r2)))/2.0;
        }
        else if(l1>r2)
            high=mid1-1;
        else 
            low=mid1+1;
    }
    return 0;

    // TC O(log(min(N1,N2)))
    // SC O(1)

}

int main()
{
    vector<int> a = {1, 4, 7, 10, 12};
    vector<int> b = {2, 3, 6, 15};
    cout << "The median of two sorted array is " << fixed << setprecision(1) << BruteForce(a,b) << '\n';
    cout << "The median of two sorted array is " << fixed << setprecision(1) << Better(a,b) << '\n';
    cout << "The median of two sorted array is " << fixed << setprecision(1) << Optimal(a,b) << '\n';
}
