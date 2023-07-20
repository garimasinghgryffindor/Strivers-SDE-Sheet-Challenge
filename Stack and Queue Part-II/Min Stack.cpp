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



#include <bits/stdc++.h> 
// Implement class for minStack.
// using MATHEMATICS AND STACK
// SC-> O(1)
class minStack
{
	public:
		stack<long>stk;
		long minm;
		minStack() { }
		
		void push(int num)
		{
			if(stk.empty()) {
				stk.push(num);
				minm = num;
			} else {
				if(num <= minm) {
					// change the minm
					int prevMin = minm;
					minm = num;
					stk.push(2ll*minm - prevMin);
				} else {
					// simply push
					stk.push(num);
				}
			}
		}
		
		int pop()
		{
			if(stk.empty()) return -1;
			
			if(stk.top() <= minm) {
				// current element is the minimum
				// actual current element is
				int tp = minm;
				minm = 2*minm - stk.top();
				stk.pop();
				return tp;
			} else {
				int tp = stk.top();
				stk.pop();
				return tp;
			}
		}
		
		int top()
		{
			if(stk.empty()) return -1;
			
			if(stk.top() <= minm) {
				// current element is the minimum
				// actual current element is
				return minm;
			} else {
				return stk.top();
			}
		}
		
		int getMin()
		{
			if(stk.empty()) return -1;
			return minm;
		}
};
