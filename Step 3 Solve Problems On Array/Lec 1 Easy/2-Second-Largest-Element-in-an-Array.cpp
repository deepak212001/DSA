/*
Find Second Smallest and Second Largest Element in an array


Problem Statement: Given an array, find the second smallest and second largest element in the array. Print ‘-1’ in the event that either of them doesn’t exist.

Examples
Example 1:
Input:
 [1,2,4,7,7,5]
Output:
 Second Smallest : 2
    Second Largest : 5
Explanation:
 The elements are as follows 1,2,3,5,7,7 and hence second largest of these is 5 and second smallest is 2

Example 2:
Input:
 [1]
Output:
 Second Smallest : -1
    Second Largest : -1
Explanation:
 Since there is only one element in the array, it is the largest and smallest element present in the array. There is no second largest or second smallest element present.

*/

#include <bits/stdc++.h>
using namespace std;

// Solution 1: (Brute Force) [this approach only works if there are no duplicates]
int BruteForce(vector<int> &num)
{
    if (num.size() > 1)
    {
        sort(num.begin(), num.end());
        cout << "The Second Smallest and Second Largest element in the array is: " << num[1] << " and " << num[num.size() - 2] << endl; // if [1,2,3,7,7] so wrong
        for (int i = num.size() - 2; i > 0; i++)
        {
            if (num[i] != num[num.size() - 1])
            {
                cout << "Second largest element in array " << num[i] << endl;
                break;
            }
        }
    }
    // TC O(NlogN)
    // SC O(1)
}
    
// Solution 2(Better Solution)
int Better(vector<int> &num)
{
    if (num.size() > 1)
    {
        int smallest = INT_MAX, second_smallest = INT_MAX;
        int largest = INT_MIN, second_largest = INT_MIN;
        for (int i = 0; i < num.size(); i++)
        {
            largest = max(largest, num[i]);
            smallest = min(smallest, num[i]);
        }
        for (int i = 0; i < num.size(); i++)
        {
            if (num[i] != smallest && num[i] < second_smallest)
                second_smallest = num[i];

            if (num[i] != largest && num[i] > second_largest)
                second_largest = num[i];
        }
        cout << "The Second Smallest and Second Largest element in the array is: " << second_smallest << " and " << second_largest << endl;
    }
    // TC O(N)
    // SC O(1)
}

int Optimal(vector<int> &num)
{
    if (num.size() > 1)
    {
        int smallest = num[0], second_smallest = INT_MAX;
        int largest = num[0], second_largest = INT_MIN;
        for (int i = 0; i < num.size(); i++)
        {
            if (num[i] < smallest)
            {
                // second_smallest=smallest;
                smallest = num[i];
            }
            else if (num[i] < second_smallest && num[i] != smallest)
            {
                second_smallest = num[i];
            }

            if (num[i] > largest)
            {
                second_largest = largest;
                largest = num[i];
            }
            else if (num[i] > second_largest && num[i] != largest)
            {
                second_largest = num[i];
            }
        }
        cout << "The Second Smallest and Second Largest element in the array is: " << second_smallest << " and " << second_largest << endl;
    }
    // TC O(N)
    // SC O(1)
}

int Mine(vector<int> &num)
{
    if (num.size() > 1)
    {
        int large_index = 0, small_index = 0;
        int large = num[0], small = num[0];
        int sec_large = INT_MIN;
        int sec_small = INT_MAX;
        for (int i = 0; i < num.size(); i++)
        {
            large_index = large < num[i] ? i : large_index;
            small_index = small > num[i] ? i : small_index;
        }
        for (int i = 0; i < num.size(); i++)
        {
            if (large_index != i)
                sec_large = sec_large < num[i] ? num[i] : sec_large;

            if (small_index != i)
                sec_small = sec_small > num[i] ? num[i] : sec_small;
        }
        cout << "The Second Smallest and Second Largest element in the array is: " << sec_small << " and " << sec_large << endl;
    }

    // TC O(N)
}

int main()
{
    vector<int> arr1 = {2, 5, 1, 3, 0};
    vector<int> arr2 = {8, 10, 5, 7, 9};

    cout << "Brute Force" << endl;
    BruteForce(arr1);
    BruteForce(arr2);

    cout << "Better" << endl;
    Better(arr1);
    Better(arr2);

    cout << "Optimal" << endl;
    Optimal(arr1);
    Optimal(arr2);

    cout << "Mine" << endl;
    Mine(arr1);
    Mine(arr2);
    return 0;
}