/*

Median of Row Wise Sorted Matrix


32

3
Problem Statement: Given a row-wise sorted matrix of size MXN, where M is no. of
rows and N is no. of columns, find the median in the given matrix.

Note: MXN is odd.

Examples
Example 1:
Input Format:M = 3, N = 3, matrix[][] =

                    1 4 9
                    2 5 6
                    3 8 7

Result: 5
Explanation:  If we find the linear sorted array, the array becomes 1 2 3 4 5 6
7 8 9. So, median = 5 Example 2: Input Format:M = 3, N = 3, matrix[][] =

                    1 3 8
                    2 3 4
                    1 2 5

Result: 3
Explanation:  If we find the linear sorted array, the array becomes 1 1 2 2 3 3
4 5 7 8. So, median = 3
*/

#include <bits/stdc++.h>
using namespace std;

int BruteForce(vector<vector<int>> &matrix, int m, int n) {
    vector<int> lst;

    // traverse the matrix and
    // copy the elements to list:
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            lst.push_back(matrix[i][j]);
        }
    }

    // sort the list:
    sort(lst.begin(), lst.end());
    return lst[(m * n) / 2];

    // TC O(N*M)
    // SC O(N*M)
}

int upperBound(vector<int> &arr, int x, int n) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] > x) {
            ans = mid;
            // look for smaller index on the left
            high = mid - 1;
        } else {
            low = mid + 1;  // look on the right
        }
    }
    return ans;
}
int countSmallEqual(vector<vector<int>> &matrix, int m, int n, int x) {
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        cnt += upperBound(matrix[i], x, n);
    }
    return cnt;
}

int Binary(vector<vector<int>> &matrix, int m, int n) {
    int low = INT_MAX, high = INT_MIN;

    // point low and high to right elements:
    for (int i = 0; i < m; i++) {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][n - 1]);
    }

    int req = (n * m) / 2;
    while (low <= high) {
        int mid = (low + high) / 2;
        int smallEqual = countSmallEqual(matrix, m, n, mid);
        if (smallEqual <= req)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;

    // TC O(log(MAX(MARTRIX[0]) - MIN(MARTRIX[0]) * N * logN))
    // SC o(1)
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4, 5}, {8, 9, 11, 12, 13}, {21, 23, 25, 27, 29}};
    int m = matrix.size(), n = matrix[0].size();
    int ans = BruteForce(matrix, m, n);
    cout << "The median element is: " << ans << endl;
    cout << "The median element is: " << Binary(matrix, m, n) << endl;
    return 0;
}
