Job Sequencing Problem

Problem Statement: You are given a set of N jobs where each job comes with a deadline and profit. The profit can only be earned upon completing the job within its deadline. Find the number of jobs done and the maximum profit that can be obtained. Each job takes a single unit of time and only one job can be performed at a time.


Approach:  The strategy to maximize profit should be to pick up jobs that offer higher profits. Hence we should sort the jobs in descending order of profit. Now say if a job has a deadline of 4 we can perform it anytime between day 1-4, but it is preferable to perform the job on its last day. This leaves enough empty slots on the previous days to perform other jobs.
Basic Outline of the approach:-
Sort the jobs in descending order of profit. 
If the maximum deadline is x, make an array of size x .Each array index is set to -1 initially as no jobs have been performed yet.
For every job check if it can be performed on its last day.
If possible mark that index with the job id and add the profit to our answer. 
If not possible, loop through the previous indexes until an empty slot is found.





bool static compare(vector<int>&a,vector<int>&b) {
    return (a[1] > b[1]);
}

int jobScheduling(vector<vector<int>> &jobs)
{
    sort(jobs.begin(), jobs.end(), compare);

    int maxDeadline = -1;
    int n = jobs.size();
    for(int i=0 ; i<n ; i++) {
        maxDeadline = max(maxDeadline, jobs[i][0]);
    }

    vector<bool>slots(maxDeadline+1,false);

    int countJobs = 0, maxProfit = 0;

    for(int i=0 ; i<n ; i++) {
        for(int j=jobs[i][0] ; j>0 ;j--) {
            if(!slots[j]) {
                slots[j] = true;
                countJobs++;
                maxProfit+=jobs[i][1];
                break;
            }
        }
    }

    return maxProfit;

}
