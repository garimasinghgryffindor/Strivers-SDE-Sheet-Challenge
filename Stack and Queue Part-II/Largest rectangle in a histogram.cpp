 
 // brute force
 int largestRectangle(vector < int > & heights) {
   // finding all possible areas of rectangles 
   int n = heights.size();
   int res = 0;
   for(int i=0 ; i<n ; i++) {
     int area = 0;
     int minL;
     for(int j=i ; j<n ; j++) {
       if(i==j) {
         minL = heights[j];
       }
       else {
         minL = min(minL, heights[j]);
       }
       area = minL*(j-i+1);
       res = max(res, area);
     }
   }
   return res;
 }
