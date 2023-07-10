Fractional Knapsack Problem : Greedy Approach


Problem Statement: The weight of N items and their corresponding values are given. We have to put these items in a knapsack of weight W such that the total value obtained is maximized.

Note: We can either take the item as a whole or break it into smaller units.

Approach: 
The greedy method to maximize our answer will be to pick up the items with higher values. Since it is possible to break the items as well we should focus on picking up items having higher value /weight first. To achieve this, items should be sorted in decreasing order with respect to their value /weight. Once the items are sorted we can iterate. Pick up items with weight lesser than or equal to the current capacity of the knapsack. In the end, if the weight of an item becomes more than what we can carry, break the item into smaller units. Calculate its value according to our current capacity and add this new value to our answer.




double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // ITEMS contains {weight, value} pairs.
    vector<pair<double,pair<int,int>>> items2;
    for(auto x: items) {
        items2.push_back({(double)x.second/(double)x.first, {x.first, x.second}});
    }

    sort(items2.rbegin(),items2.rend());

    double res = 0;
    int capacityLeft = w;

    for(auto x: items2) {
        if(x.second.first <= capacityLeft) {
            // take the item as whole
            capacityLeft -= x.second.first;
            res += x.second.second;
            if(capacityLeft == 0)
                break;
        } else {
            // take whatsover fraction of the item is possible
            res += capacityLeft*x.first;
            capacityLeft = 0;
            break;
        }
    }

    return res;
}


Space Optimization

static bool compare(pair<int,int>&a,pair<int,int>&b) {
    double r1 = (double)a.second/a.first;
    double r2 = (double)b.second/b.first;

    return r1 > r2;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // ITEMS contains {weight, value} pairs.
    
    sort(items.begin(),items.end(), compare);

    double res = 0;
    int capacityLeft = w;

    for(auto x: items) {
        if(x.first <= capacityLeft) {
            // take the item as whole
            capacityLeft -= x.first;
            res += x.second;
            if(capacityLeft == 0)
                break;
        } else {
            // take whatsover fraction of the item is possible
            res += capacityLeft*((double)x.second/x.first);
            capacityLeft = 0;
            break;
        }
    }

    return res;
}
