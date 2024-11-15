/* Problem statement
Sort the given unsorted array 'arr' of size 'N' in non-decreasing order using
the selection sort algorithm.



 Note:
Change in the input array/list itself.


Example:
Input:
N = 5
arr = {8, 6, 2, 5, 1}

Output:
1 2 5 6 8
Explanation:

Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
6
2 13 4 1 3 6
Sample Output 1:
1 2 3 4 6 13
Explanation Of Sample Input 1:
 Select 1 and swap with element at index 0. arr= {1,13,4,2,3,6}

 Select 2 and swap with element at index 1. arr= {1,2,4,13,3,6}

 Select 3 and swap with element at index 2. arr= {1,2,3,13,4,6}

 Select 4 and swap with element at index 3. arr= {1,2,3,4,13,6}

 Select 6 and swap with element at index 4. arr= {1,2,3,4,6,13}
Sample Input 2:
5
9 3 6 2 0
Sample Output 2:
0 2 3 6 9
Constraints :
1 <= N <= 10^3
0 <= arr[i] <= 10^5
Time Limit: 1 sec 


TC O(N^2)
SC O(1)

*/

#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[],int n) {
    for (int i = 0; i < n-1; i++) {
        int min_index = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
}
void printArr(int arr[],int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
int main() {
    int arr[] = {9, 3, 6, 2, 0};
    int n=(sizeof(arr))/sizeof(arr[0]);
    printArr(arr,n);
    selectionSort(arr,n);
    printArr(arr,n);
    return 0;
}