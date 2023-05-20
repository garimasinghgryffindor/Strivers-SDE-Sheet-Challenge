Matrix Median

Problem Statement
You have been given a matrix of ‘N’ rows and ‘M’ columns filled up with integers where every row is sorted in non-decreasing order. Your task is to find the overall median of the matrix i.e if all elements of the matrix are written in a single line, then you need to return the median of that linear array.
The median of a finite list of numbers is the "middle" number when those numbers are listed in order from smallest to greatest. If there is an odd number of observations, the middle one is picked. For example, consider the list of numbers [1, 3, 3, 6, 7, 8, 9]. This list contains seven numbers. The median is the fourth of them, which is 6.


Solution: Naive Approach


int getMedian(vector<vector<int>> &matrix)
{
    // brute force
    // naive approach
    vector<int>res;
    int r = matrix.size();
    int c = matrix[0].size();

    for(int i=0 ; i<r ; i++) {
        for(int j=0 ; j<c ; j++) {
            res.push_back(matrix[i][j]);
        }
    }

    sort(res.begin(), res.end());

    int mid = res.size()/2;

    return res[mid];

}




Solution: Binary Search


int countLessThanMid(vector<int>num , int mid) {
    int l = 0 ,h = num.size()-1;
    while(l<=h) {
        int md = l + (h-l)/2;
        if(num[md] <= mid) {
            l = md + 1;
        } else {
            h = md - 1;
        }
    }

    return l;
}

int getMedian(vector<vector<int>> &matrix)
{
    // Binary Search
    int low = 1;
    int high = 1e9;
    int r = matrix.size();
    int c = matrix[0].size();

    while(low <= high) {
        int mid = low + (high - low)/2;
        int cnt = 0;
        for(int i=0 ; i<r ; i++) {
            cnt += countLessThanMid(matrix[i],mid);
        }
        
        if(cnt <= r*c/2) {
            low = mid+1;
        } else {
            high = mid - 1;
        }
    }

    return low;

}
