Allocate Minimum Number of Pages

Problem Statement: 

Given an array of integers A of size N and an integer B.
The College library has N bags, the ith book has A[i] number of pages.
You have to allocate books to B number of students so that the maximum number of pages allocated to a student is minimum.



Solution: Using Binary Search
Intuition : 
Let’s analyze a case. 
We are given A = [12, 34, 67, 90] and B = 1. So, for one student we can allocate all books to this student. Why so? Because we have to maximize the number of pages allocated to a student and then find the minimum out of it. So, this fact gives us an idea that a single student will be allocated the sum of all pages available.
Let’s analyze another case.
We are required to find the minimum number of pages among all possible maximum number of pages of allocations. So, in the worst case, the minimum possible will be minimum pages among all given books.
Now, we know the lowest possible answer and the maximum possible answer and for general cases, the answer will lie in between these edge cases. Thus, we have a search space. This search space will be sorted. Guess what? We reached our approach to use a binary solution.



#include <bits/stdc++.h>
bool ispossible(long long & hpd, int& limit, vector<int> &times){
	long long count = 1, sum = 0;
	for(int &time: times){
		if(time>hpd) return false;
		if(sum+time<=hpd) sum+=time;
		else {
			count++;
			sum = time;
			}
        }
	return count<=limit;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	long long l = 1, r = LLONG_MAX, mid;
	while(l<r){
		mid = l+(r-l)/2;
		if(ispossible(mid, n, time)) r = mid;
		else l = mid+1;
	}
	return l;
}




