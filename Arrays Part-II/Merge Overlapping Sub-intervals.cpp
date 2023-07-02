Merge Overlapping Sub-intervals

Problem Statement: Given an array of intervals, merge all the overlapping intervals and return an array of non-overlapping intervals.

Solution 1: Brute force
Approach: First check whether the array is sorted or not.If not sort the array. Now linearly iterate over the array and then check for all of its next intervals whether they are overlapping with the interval at the current index. Take a new data structure and insert the overlapped interval. If while iterating if the interval lies in the interval present in the data structure simply continue and move to the next interval.

vector < pair < int, int >> merge(vector < pair < int, int >> & arr) {

    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector < pair < int, int >> ans;

    for (int i = 0; i < n; i++) {
        int start = arr[i].first, end = arr[i].second;

        //since the intervals already lies 
        //in the data structure present we continue
        if (!ans.empty()) {
            if (end <= ans.back().second) {
                continue;
            }
        }

        for (int j = i + 1; j < n; j++) {
            if (arr[j].first <= end) {
                end = max(end, arr[j].second);
            }
        }
    
        end = max(end, arr[i].second);

        ans.push_back({start, end});
    }

    return ans;
}




Solution 2: Optimal approach
Approach: Linearly iterate over the array if the data structure is empty insert the interval in the data structure. If the last element in the data structure overlaps with the current interval we merge the intervals by updating the last element in the data structure, and if the current interval does not overlap with the last element in the data structure simply insert it into the data structure.

Intuition: Since we have sorted the intervals, the intervals which will be merging are bound to be adjacent. We kept on merging simultaneously as we were traversing through the array and when the element was non-overlapping we simply inserted the element in our data structure.

class Solution {
public:   
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin() , intervals.end() );
        vector<vector<int> > res;
        
        res.push_back(intervals[0]);
        
        for(int i=1 ; i<intervals.size() ; i++)
        {
            if(intervals[i][0]>res.back()[1])
            {
                res.push_back(intervals[i]);
            } else
            {
                res.back()[1] = max(res.back()[1] , intervals[i][1]);
            }
        }
        
        return res;
    }
};
