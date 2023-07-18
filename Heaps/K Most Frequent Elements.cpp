// NAIVE APPROACH
// USING MAPS
static bool compare(pair<int,int>&a,pair<int,int>&b) {
    return a.second > b.second;
}

vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    vector<int>res;
    unordered_map<int,int> mp;
    for(auto x: arr) {
        mp[x]++;
    }

    vector<pair<int,int> > vec(mp.begin(), mp.end());
    sort(vec.begin(), vec.end(), compare);
    
    for(int i=0 ; i<k ; i++) {
        res.push_back(vec[i].first);
    }

    return res;
}



// USING MAX HEAPS
struct compare {
    bool operator()(pair<int, int> p1, pair<int, int> p2)
    {
        // If frequencies of two elements are same
        // then the larger number should come first
        if (p1.second == p2.second)
            return p1.first < p2.first;
 
        // Insert elements in the priority queue on the
        // basis of decreasing order of frequencies
        return p1.second < p2.second;
    }
};
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // similar
    // almost similar time complexity
    // instead of using sort we will be using priority_queue
    vector<int>res;
    unordered_map<int,int>mp;
    for(auto x: arr) {
        mp[x]++;
    }
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq(mp.begin(), mp.end());
    
    int count = k;
    while(count--) {
        res.push_back(pq.top().first);
        pq.pop();
    }
    
    return res;
}



// using QUICK SELECT
// nth_element() is an STL algorithm which rearranges the list in such a way such that
// the element at the nth position is the one which should be at that position if we sort 
// the list.
// 
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    vector<int>res;
    unordered_map<int,int>mp;
    for(auto x: arr) {
        --mp[x];
    }
    
    vector<pair<int,int>> vec;

    for(auto x: mp) {
        vec.push_back({x.second, x.first});
    }
    
    nth_element(vec.begin(), vec.begin()+k, vec.end());
    
    for(int i=0 ; i<k ; i++) {
        res.push_back(vec[i].second);
    }
    
    return res;
}


