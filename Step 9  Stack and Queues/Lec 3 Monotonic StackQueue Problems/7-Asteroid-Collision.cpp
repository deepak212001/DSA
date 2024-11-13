/*
We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.



Example 1:

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
Example 2:

Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.
Example 3:

Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.

*/

#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int> &arr)
{
    vector<int> ans;
    for (auto cur : arr)
    {
        if (cur > 0)
            ans.push_back(cur);
        else
        {
            while (!ans.empty() && ans.back() > 0 && ans.back() < abs(cur))
                ans.pop_back();

            if (!ans.empty() && ans.back() == abs(cur))
                ans.pop_back();
            else if (ans.empty() || ans.back() < 0)
                ans.push_back(cur);
        }
    }
    return ans;
}
vector<int> Mine(vector<int> &asteroids)
{
    stack<int> st;
    for (auto cur : asteroids)
    {
        bool destory = true;
        while (!st.empty() && st.top() > 0 && cur < 0)
        {
            int pre = st.top();
            if (pre == abs(cur))
            {
                st.pop();
                destory = false;
                break;
            }
            else if (pre < abs(cur))
            {
                st.pop();
            }
            else
            {
                destory = false;
                break;
            }
        }
        if (destory)
            st.push(cur);
    }
    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    vector<int> vec = {4, 7, 1, 1, 2, -3, -7, 17, 15, -16, -18, -19};
    vector<int> ans = Mine(vec);
    for (auto el : ans)
        cout << el << " ";

    return 0;
}