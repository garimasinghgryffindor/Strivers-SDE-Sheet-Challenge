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



bool isPossible(vector<int>num,int n,long long mid) {
    int res = 1;
    long long sum=0;
    for(int i=0 ; i<num.size() ; i++) {
        if(sum + num[i] <= mid) {
            sum += num[i];
        } else if (num[i] > mid) {
            return false;
        } else {
            res++;
            sum = num[i];
        }
        // res++;
        if(res > n) {
            return false;
        }
    }

    return true;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{   
    if(n > m) return -1;

    long long low = time[0], high = 0;

    for(int i=0 ; i<m ; i++) {
        if(time[i] < low) {
            low = time[i];
        }
        high += time[i];
    }

    // binary search

    while(low<=high) {
        // keep searching
        long long mid = low + (high-low)/2;

        if(isPossible(time,n,mid)) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return low;
}
