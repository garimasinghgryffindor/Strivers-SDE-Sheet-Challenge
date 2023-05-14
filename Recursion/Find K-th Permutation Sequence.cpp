Find K-th Permutation Sequence

Problem Statement: Given N and K, where N is the sequence of numbers from 1 to N([1,2,3….. N]) find the Kth permutation sequence.

For N = 3  the 3!  Permutation sequences in order would look like this:-


Solution 1: Brute Force Solution

Approach:  Recursion
The extreme naive solution is to generate all the possible permutations of the given sequence.  This is achieved using recursion and every permutation generated is stored in some other data structure (here we have used a vector). Finally, we sort the data structure in which we have stored all the sequences and return the Kth sequence from it.


class Solution {
public:
    void permutation(string s,int idx, vector<string>&res) {
        if(idx == s.length()) {
            res.push_back(s);
            return;
        }
        
        for(int i=idx ; i<s.length() ; i++) {
            swap(s[i],s[idx]);
            permutation(s,idx+1,res);
            swap(s[i],s[idx]);
        }
    }
    
    string getPermutation(int n, int k) {
        string s="";
        for(int i=1 ; i<=n ; i++) {
            s.push_back(i+'0');
        }
        
        vector<string>res;
        
        permutation(s,0,res);
        
        sort(res.begin(), res.end());
        
        auto it = res.begin()+(k-1);
        
        return *it;
        
    }
};



Solution 2:(Optimal Approach)
Say we have N = 4  and K = 17. Hence the number sequence is {1,2,3,4}. 

Intuition:
Since this is a permutation we can assume that there are four positions that need to be filled using the four numbers of the sequence. First, we need to decide which number is to be placed at the first index. Once the number at the first index is decided we have three more positions and three more numbers.  Now the problem is shorter. We can repeat the technique that was used previously until all the positions are filled. The technique is explained below.

class Solution {
public:
    string getPermutation(int n, int k) {
        int fact=1;
        vector<int>num;
        for(int i=1 ; i<n ; i++) {
            fact *= i;
            num.push_back(i);
        }
        num.push_back(n);
        
        string ans = "";
        
        int k1 = k-1;
        while(true){
            int idx = k1/fact;
            ans+=to_string(num[idx]);
            num.erase(num.begin()+idx);
            if(num.size() == 0)
                break;
            k1 = k1%fact;
            fact = fact/num.size();
        }
        
        return ans;
        
    }
};
