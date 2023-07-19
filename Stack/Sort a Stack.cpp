
// BRUTE FORCE
// using two stacks here
// TC-> O(N^2)
// SC-> O(2*N)
#include <bits/stdc++.h> 
#include <stack>
void sortStack(stack<int> &stk)
{
	stack <int> st;
    stack <int> st1;

    while(!stk.empty()) {
        int tp = stk.top();
        stk.pop();
        if(st.empty()) {
            st.push(tp);
        } else {
            while(!st.empty() && st.top() > tp) {
                int x = st.top();
                st1.push(x);
                st.pop();
            }
            st.push(tp);
            while(!st1.empty()) {
                int x = st1.top();
                st.push(x);
                st1.pop();
            }
        }
    }

    swap(stk, st);
}



// OPTIMAL
// USING RECURSION
#include <bits/stdc++.h>
void merge(stack<int>&stk, int num) {
    if(stk.empty() || num >= stk.top()) {
        stk.push(num);
        return;
    }

    int tp = stk.top();
    stk.pop();
    merge(stk, num);
    merge(stk, tp);
}

void sortStack(stack<int> &stk)
{
	if(stk.empty()) {
        return;
    }
    int num = stk.top();
    stk.pop();
    sortStack(stk);
    
    merge(stk, num);
}
