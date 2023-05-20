Nth Root of a Number using Binary Search

Problem Statement: Given two numbers N and M, find the Nth root of M.


Solution:

Nth root of a number M is defined as a number X when raised to the power N equals to M.
Approach: In order to find the Nth root of any given integer we are gonna use Binary Search.

Step 1: Take low and high. Low will be equal to 1 and high will be M. We will take the mid of low and high such that the searching space is reduced using low + high / 2.

Step 2: Make a separate function to multiply mid N times.

Step 3: Run the while loop till (high – low > eps). Take eps as 1e-6, since we have to find answers to 6 decimal places.

Step 4:  If the mid is less than M, then we will reduce search space to low and mid. Else, if it is greater than M then search space will be reduced to mid and high.

Step 5: After the loop breaks we will have our answer as low or high.

We have to find the answer to 6 decimals. So, we will have a double 1e-6. We will run the while loop till (high – low > eps). When we will come out of the loop we will have the answer which will be equal to low as well as high.


int NthRoot(int n, int m) {
  int l = 0, r = m, mid;
  bool flag = true;
  while(l<=r) {
    mid = l + (r-l)/2;
    int res = 1;
    flag = true;

    if(sqrt(INT_MAX) < mid) {
      r = mid-1;
      continue;
    }

    for(int i=0 ; i<n ; i++) {
      res*=mid;
      
      if(res > m) {
        flag = false;
        break;
      }
    }

    if(res == m) {
      return mid;
    } else if(res > m) {
      r = mid-1;
    } else {
      l = mid+1;
    }
  }

  return -1;
}
