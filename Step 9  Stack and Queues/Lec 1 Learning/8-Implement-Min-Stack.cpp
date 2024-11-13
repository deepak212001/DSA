/*
Implement Min Stack : O(2N) and O(N) Space Complexity


Problem Statement: Implement Min Stack | O(2N) and O(N) Space Complexity. Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Examples:

Input Format:["MinStack", "push", "push", "push", "getMin", "pop", "top", "getMin"]
[
[ ], [-2], [0], [-3], [ ], [ ], [ ], [ ]
]

Result: [null, null, null, null, -3, null, 0, -2]
Explanation:
stack < long long > st
st.push(-2); Push element in stack
st.push(0); Push element in stack
st.push(-3); Push element in stack
st.getMin(); Get minimum element fromstack
st.pop(); Pop the topmost element
st.top(); Top element is 0
st.getMin(); Minimum element is -2

*/

#include <bits/stdc++.h>
using namespace std;

// brute force

/*
class MinStack
{
    stack<pair<int, int>> st;

public:
    void push(int val)
    {
        int minV;
        if (st.empty())
        {
            minV = val;
        }
        else
            minV = min(st.top().second, val);
        st.push({val, minV});
    }
    void pop()
    {
        st.pop();
    }
    int top()
    {
        return st.top().first;
    }
    int getMin()
    {
        return st.top().second;
    }

    // TC O(1)
    // SC 0(2N)
};
*/

class MinStack
{
    stack<long long> st;
    long long mini;

public:
    /** initialize your data structure here. */
    MinStack()
    {
        while (st.empty() == false)
            st.pop();
        mini = INT_MAX;
    }

    void push(int value)
    {
        long long val = long(value);
        if (st.empty())
        {
            mini = val;
            st.push(val);
        }
        else
        {
            if (val < mini)
            {
                st.push(2 * val * 1LL - mini);
                mini = val;
            }
            else
            {
                st.push(val);
            }
        }
    }

    void pop()
    {
        if (st.empty())
            return;
        long long el = st.top();
        st.pop();

        if (el < mini)
        {
            mini = 2 * mini - el;
        }
    }

    int top()
    {
        if (st.empty())
            return -1;

        long long el = st.top();
        if (el < mini)
            return mini;
        return el;
    }

    int getMin()
    {
        return mini;
    }

    // TC O(1)
    // SC 0(N)
};

int main()
{
    MinStack s;
    s.push(3);
    s.push(5);
    cout << s.getMin() << endl;
    s.push(2);
    s.push(1);
    cout << s.getMin() << endl;
    s.pop();
    cout << s.getMin() << endl;
    s.pop();
    cout << s.top() << endl;
}