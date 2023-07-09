N meetings in one room

Problem Statement: There is one meeting room in a firm. You are given two arrays, start and end each of size N.For an index ‘i’, start[i] denotes the starting time of the ith meeting while end[i]  will denote the ending time of the ith meeting. Find the maximum number of meetings that can be accommodated if only one meeting can happen in the room at a  particular time. Print the order in which these meetings will be performed.

Initial Thought Process:- Say if you have two meetings, one which gets over early and another which gets over late. Which one should we choose?  If our meeting lasts longer the room stays occupied and we lose our time. On the other hand, if we choose a meeting that finishes early we can accommodate more meetings. Hence we should choose meetings that end early and utilize the remaining time for more meetings.

static bool compare(pair<int,int>&a,pair<int,int>&b) {
    if(a.second < b.second) 
        return true;
    if(a.second > b.second)
        return false;
    if(a.first < b.first)
        return true;
    return false;
}

int maximumActivities(vector<int> &start, vector<int> &finish) {
    vector<pair<int,int>> activity;
    int n = start.size();
    for(int i=0 ; i<n ; i++) {
        activity.push_back({start[i], finish[i]});
    }

    sort(activity.begin(), activity.end(), compare);

    int currentEnd = -1;
    int count = 0;

    for(int i=0 ; i<n ; i++) {
        if(activity[i].first >= currentEnd) {
            count++;
            currentEnd = activity[i].second;
        }
    }

    return count;
}
