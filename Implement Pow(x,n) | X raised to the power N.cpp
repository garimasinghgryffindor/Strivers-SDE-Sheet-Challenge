Implement Pow(x,n) | X raised to the power N


Solution 1: Brute force approach 
Approach:  Looping from 1 to n and keeping a ans(double) variable. Now every time your loop runs, multiply x with ans. At last, we will return the ans.
Now if n is negative we must check if n is negative, if it is negative divide 1 by the and.



double myPow(double x, int n){
    if (n == INT_MAX) return x;
    else if (n == INT_MIN) return (x == 1 || x == -1) ? 1 : 0;
    if(n<0)
    {
        x=1/x;
        n*=-1;
    }
    /*if(n==0)
        return 1;
    else
        return x*myPow(x,n-1);*/
    double ans = 1;
    for(int i=0;i<n;i++)
        ans = ans*x;
    return ans;
}
};



Solution 2: Using Binary Exponentiation

class Solution {
public:
    double myPow(double x, int n) {
        long nn = n;
        double res = 1.0;
        
        if(nn < 0) nn = -1*nn;
        
        while(nn > 0) {
            if(nn%2 == 1) {
                // odd
                res = res*x;
                nn--;
            } else {
                // even
                x = x*x;
                nn/=2;
            }
        }
        
        if(n < 0) 
            res = 1.0 / res;
        
        return res;
    }
};
