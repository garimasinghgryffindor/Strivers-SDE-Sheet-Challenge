#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack
{
	public:
		stack<pair<int,int>>stk;
		minStack() 
		{ 
			
		}
		
		void push(int num)
		{
			if(stk.empty()) {
				stk.push({num, num});
			} else {
				if(stk.top().second < num) {
					stk.push({num, stk.top().second});
				} else {
					stk.push({num, num});
				}
			}
		}
		
		int pop()
		{
			if(stk.empty()) {
				return -1;
			}
			int tp = stk.top().first;
			stk.pop();
			return tp;
		}
		
		int top()
		{
			if(stk.empty()) {
				return -1;
			}
			return stk.top().first;
		}
		
		int getMin()
		{
			if(stk.empty()) {
				return -1;
			}
			return stk.top().second;
		}
};
