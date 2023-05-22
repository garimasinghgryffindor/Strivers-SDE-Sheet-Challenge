Aggressive Cows : Detailed Solution

Problem Statement: 

There is a new barn with N stalls and C cows. The stalls are located on a straight line at positions x1,….,xN (0 <= xi <= 1,000,000,000). We want to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?



Solution 1: Brute Force

Intuition: 

It’s required that we put all the C cows into our stalls. So for a start, let’s say we set the minimum distance = 1 and put them consecutively. These cows fit perfectly.
This is too close, so let’s increase our minimum distance a bit. Let’s increase the distance further to 2. We can again check that the cows can be accommodated. 
But we want to reduce the possibility of collision/fighting as much as possible, so we keep on increasing the minimum distance. Here is an illustration:












Approach:
After sorting the array, we set a minimum distance, then we keep on increasing until accommodation of all cows is not possible. We stop just before that to get our answer, which in this example is 3. 
For checking if the cows can fit or not, we are simply iterating over our n stalls, and for every stall with the said minimum distance, we place our cow. After we are done, if all cows have been accommodated, we return true, otherwise false. Let’s observe the time complexity of our brute force algorithm here, we are increasing distance in each step (which in the worst case of two cows gets as high as m = array[n-1]-array[0]), and in that step, we are checking if our cows can “fit”, so we are iterating again for each step to check.

int chessTournament(vector<int> positions , int n ,  int c){
    sort(positions.begin() , positions.end());

    int minDist = 1;
    int maxDist = positions[n-1] - positions[0];
    
    int res=0;
    for(int i=minDist ; i<=maxDist ; i++) {
        // if "i" is the minimum distance -> let us see how many chess players can be easily accomodated
        int prev = positions[0];
        int count = 1;
        for(int j=1 ; j<n ; j++) {
            if(positions[j] - prev >= i) {
                // A ok
                count++;
                prev = positions[j];
                if(count == c) {
                    res = max(res, i);
                    break;
                }
            }
        }
    }

    return res;
}


Solution 2: Binary Search
Intuition:
Observing what we did in the previous case, this time complexity can be improved. 
There is a certain maximum “limit” as to what we can increase our minimum distance because we don’t want any cow to be left behind. 












In this example, all values including and after 4 are invalid. There is certain “monotonicity” here, speaking in layman’s terms, we are trying to find d for which the minimum distance is maximized, and there is a certain value, here 4 including and after which the solution to this problem is not possible. In these situations, we use the binary search algorithm.



int chessTournament(vector<int> positions , int n ,  int c){
    sort(positions.begin() , positions.end());

    int minDist = 1;
    int maxDist = positions[n-1] - positions[0];
    
    int res=0;
    int low = minDist;
    int high = maxDist;

    while(low <= high){
        int mid = low + (high - low)/2;
        // if "i" is the minimum distance -> let us see how many chess players can be easily accomodated
        int prev = positions[0];
        int count = 1;
        for(int j=1 ; j<n ; j++) {
            if(positions[j] - prev >= mid) {
                // A ok
                count++;
                prev = positions[j];
                if(count == c) {
                    res = max(res, mid);
                    break;
                }
            }
        }

        if(count == c) {
            low = mid+1;
        }
        else if(count < c) {
            high = mid-1;
        } else {
            low = mid+1;
        }
    }

    return res;
}
