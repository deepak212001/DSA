/*
Minimise Maximum Distance between Gas Stations


48

2
Problem Statement: You are given a sorted array ‘arr’ of length ‘n’, which contains positive integer positions of ‘n’ gas stations on the X-axis. You are also given an integer ‘k’. You have to place 'k' new gas stations on the X-axis. You can place them anywhere on the non-negative side of the X-axis, even on non-integer positions. Let 'dist' be the maximum value of the distance between adjacent gas stations after adding k new gas stations.
Find the minimum value of ‘dist’.

Note: Answers within 10^-6 of the actual answer will be accepted. For example, if the actual answer is 0.65421678124, it is okay to return 0.654216. Our answer will be accepted if that is the same as the actual answer up to the 6th decimal place.

Examples
Example 1:
Input Format:
 N = 5, arr[] = {1,2,3,4,5}, k = 4
Result:
 0.5
Explanation:
 One of the possible ways to place 4 gas stations is {1,1.5,2,2.5,3,3.5,4,4.5,5}. Thus the maximum difference between adjacent gas stations is 0.5. Hence, the value of ‘dist’ is 0.5. It can be shown that there is no possible way to add 4 gas stations in such a way that the value of ‘dist’ is lower than this.
Example 2:
Input Format:
 N = 10, arr[] = {1,2,3,4,5,6,7,8,9,10}, k = 1
Result:
 1
Explanation:
 One of the possible ways to place 1 gas station is {1,1.5,2,3,4,5,6,7,8,9,10}. Thus the maximum difference between adjacent gas stations is still 1. Hence, the value of ‘dist’ is 1. It can be shown that there is no possible way to add 1 gas station in such a way that the value of ‘dist’ is lower than this.

Let’s understand how to place the new gas stations so that the maximum distance between two consecutive gas stations is reduced.

Let’s consider a small example like this: given gas stations = {1, 7} and k = 2.

Observation: A possible arrangement for placing 2 gas stations is as follows: {1, 7, 8, 9}. In this arrangement, the new gas stations are positioned after the last existing one. Prior to adding the new stations, the maximum distance between stations was 6 (i.e. the distance between 1 and 7). Even after placing the 2 new stations, the maximum distance remains unchanged at 6.

Conclusions:

From the above observation, we can conclude that placing new gas stations before the first existing station or after the last existing station will make no difference to the maximum distance between two consecutive stations.
So, in order to minimize the maximum distance we have to place the new gas stations in between the existing stations.
How to place the gas stations in between so that the maximum distance is minimized:

Until now we have figured out that we have to place the gas stations in between the existing ones. But we have to place them in such a way that the maximum distance between two consecutive stations is the minimum possible.
Let’s understand this considering the previous example. Given gas stations = {1, 7} and k = 2.
If we place the gas stations as follows: {1, 2, 6, 7}, the maximum distance will be 4(i.e. 6-2 = 4). But if we place them like this: {1, 3, 5, 7}, the maximum distance boils down to 2. It can be proved that we cannot make the maximum distance lesser than 2.
To minimize the maximum distance between gas stations, we need to insert new stations with equal spacing. If we have to add 'k' gas stations within a section of length 'section_length', each station should be placed at a distance of
(section_length / (k + 1)) from one another.
This way, we maintain a uniform spacing between consecutive gas stations.

For example, the gas stations are = {1, 7} and k = 2. Here, the ‘dist’ is = (7-1) = 6. So, the space between two gas stations will be dis / (k+1) = 6 / (2+1) = 2. The placements will be as follows: {1, 3, 5, 7}.


*/

#include <bits/stdc++.h>
using namespace std;

long double LinearBrute(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> howMany(n - 1, 0);

    for (int gasStation = 0; gasStation <= k; gasStation++)
    {
        long double maxSection = -1;
        int maxInd = -1;
        for (int i = 0; i < n - 1; i++)
        {
            long double diff = arr[i + 1] - arr[i];
            long double sectionLength = diff / (long double)(howMany[i] + 1);
            if (sectionLength > maxSection)
            {
                maxSection = sectionLength;
                maxInd = i;
            }
        }
        howMany[maxInd]++;
    }

    long double maxAns = -1;
    for (int i = 0; i < n - 1; i++)
    {
        long double diff = arr[i + 1] - arr[i];
        long double sectionLength = diff / (long double)(howMany[i] + 1);
        maxAns = max(maxAns, sectionLength);
    }
    return maxAns;

    // TC O(N*K)  K=NO OF GAS STATION
    // SC O(N-1)
}

long double HeapBetter(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> howMany(n - 1, 0);

    priority_queue<pair<long double, int>> pq;

    for(int i=0;i<n-1;i++)
    {
        pq.push({arr[i+1]-arr[i],i});
    }

    for(int gasStation=1;gasStation<=k;gasStation++)
    {
        auto it=pq.top();
        pq.pop();
        int ind=it.second;
        howMany[ind]++;
        long double diff = arr[ind + 1] - arr[ind];
        long double sectionLength = diff / (long double)(howMany[ind] + 1);
        pq.push({sectionLength,ind});
    }
    return pq.top().first;

    // TC O(N*logN + k*logN)
    // SC O(N-1)

}

bool NoOfGasStation(vector<int> arr, long double dist, int k)
{
    int n=arr.size();   
    int cnt=0;

    for(int i=1;i<n;i++)
    {
        int NoInBetween=(arr[i]-arr[i-1])/dist;
        if((arr[i]-arr[i-1])==dist*NoInBetween)
            NoInBetween--;
        
        cnt+=NoInBetween;
    }
    return cnt>k;
}

long double BinaryOptimal(vector<int> &arr, int k)
{
    long double low=0;
    long double high=0;
    int n=arr.size();
    for(int i=0;i<n-1;i++)
    {
        high=max(high,(long double)(arr[i+1]-arr[i]));
    }

    long double diff=1e-6;
    while(high-low>diff)
    {
        long double mid=(low+high)/2.0;
        if(NoOfGasStation(arr,mid,k))
            low=mid;
        else 
            high=mid;
    }
    return high;

    // TC O(N*log(LEN)) N = size of the given array, Len = length of the answer space.
    // SC O(1)
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    long double ans = LinearBrute(arr, k);
    cout << "The answer is: " << ans << "\n";
    cout << "The answer is: " << HeapBetter(arr,k) << "\n";
    cout << "The answer is: " << BinaryOptimal(arr,k) << "\n";
    return 0;
}
