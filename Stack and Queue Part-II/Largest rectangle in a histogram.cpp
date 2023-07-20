 
//  // brute force
//  int largestRectangle(vector < int > & heights) {
//    // finding all possible areas of rectangles 
//    int n = heights.size();
//    int res = 0;
//    for(int i=0 ; i<n ; i++) {
//      int area = 0;
//      int minL;
//      for(int j=i ; j<n ; j++) {
//        if(i==j) {
//          minL = heights[j];
//        }
//        else {
//          minL = min(minL, heights[j]);
//        }
//        area = minL*(j-i+1);
//        res = max(res, area);
//      }
//    }
//    return res;
//  }



 
//  // brute force 2.0
//  // we will try all the heights
//  // and try to maximize the width
//  int largestRectangle(vector < int > & heights) {
//    int n = heights.size();
//    int res = 0;
//    for(int i=0 ; i<n ; i++) {
//      int h = heights[i];
//      int rightSmaller = i;
//      int leftSmaller = i;
//      int f = 0;
//      for(int j=i+1 ; j<n ; j++) {
//        if(heights[j] < heights[i]) {
//          rightSmaller = j-1;
//          f = 1;
//          break;
//        }
//      }
//       if(!f) {
//         rightSmaller = n-1;
//       }

//       f = 0;
//      for(int j=i-1 ; j>=0 ; j--) {
//        if(heights[j] < heights[i]) {
//          leftSmaller = j+1;
//          f = 1;
//          break;
//        }
//      }
//      if(!f) {
//        leftSmaller = 0;
//      }

//     int area = heights[i]*(rightSmaller-leftSmaller+1);
//     res = max(res, area);    
//    }
//    return res;
//  }


#include <bits/stdc++.h>
// optimal approach
// using NEXT SMALLER ELEMENT
int largestRectangle(vector < int > & heights) {
int n = heights.size();
      stack < int > st;
      int leftsmall[n], rightsmall[n];
      for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
          st.pop();
        }
        if (st.empty())
          leftsmall[i] = 0;
        else
          leftsmall[i] = st.top() + 1;
        st.push(i);
      }
      // clear the stack to be re-used
      while (!st.empty())
        st.pop();

      for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i])
          st.pop();

        if (st.empty())
          rightsmall[i] = n - 1;
        else
          rightsmall[i] = st.top() - 1;

        st.push(i);
      }
      int maxA = 0;
      for (int i = 0; i < n; i++) {
        maxA = max(maxA, heights[i] * (rightsmall[i] - leftsmall[i] + 1));
      }
      return maxA;
    }
