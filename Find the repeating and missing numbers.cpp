Find the repeating and missing numbers

Problem Statement: You are given a read-only array of N integers with values also in the range [1, N] both inclusive. Each integer appears exactly once except A which appears twice and B which is missing. The task is to find the repeating and missing numbers A and B where A repeats twice and B is missing.

Solution 1: Using Count Sort

vector<int> find_missing_repeating(vector<int> array)
{
    int n = array.size() + 1;

    vector<int> substitute(n, 0); // initializing the substitute array with 0 of size n+1.

    vector<int> ans;              // initializing the answer  array .

    for (int i = 0; i < array.size(); i++)
    {
        substitute[array[i]]++;
    }

    for (int i = 1; i <= array.size(); i++)
    {
        if (substitute[i] == 0 || substitute[i] > 1)
        {
            ans.push_back(i);
        }
    }

    return ans;
}



Solution 2: Using Maths 
Intuition + Approach: 

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long int len = A.size();

    long long int S = (len * (len+1) ) /2;
    long long int P = (len * (len +1) *(2*len +1) )/6;
    long long int missingNumber=0, repeating=0;
     
    for(int i=0;i<A.size(); i++){
       S -= (long long int)A[i];
       P -= (long long int)A[i]*(long long int)A[i];
    }
     
    missingNumber = (S + P/S)/2;

    repeating = missingNumber - S;

    vector <int> ans;

    ans.push_back(repeating);
    ans.push_back(missingNumber);

    return ans;
}


Solution 3: XOR
Intuition + Approach: 
