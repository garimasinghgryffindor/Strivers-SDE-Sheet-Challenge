4 Sum | Find Quads that add up to a target value

Solution 1: Using 3 pointers and Binary Search
Intuition:
Approach:

The main idea is to sort the array, and then we can think of searching in the array using the binary search technique. Since we need the 4 numbers which sum up to target. So we will fix three numbers as nums[i], nums[j] and nums[k], and search for the remaining (target – (nums[i] + nums[j] + nums[k])) in the array. Since we sorted the array during the start, we can apply binary search to search for this value, and if it occurs we can store them. In order to get the unique quads, we use a set data structure to store them.


vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        sort(nums.begin(),nums.end());
      
       set<vector<int>> sv;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
    
                for(int k=j+1;k<n;k++)
                { 
                  
                   int x = (long long)target - 
                           (long long)nums[i]-
                           (long long)nums[j]-(long long)nums[k];
                   
                        if(binary_search(nums.begin()+k+1,nums.end(),x)){
                            vector<int> v;
                            v.push_back(nums[i]);
                            v.push_back(nums[j]);
                            v.push_back(nums[k]);
                            v.push_back(x);
                            sort(v.begin(),v.end());
                            sv.insert(v);
                        }
                }
            }
        }
        vector<vector<int>> res(sv.begin(),sv.end());
        return res;
    }



Solution 2: Optimized Approach
Intuition: In the previous approach we fixed three-pointers and did a binary search to find the fourth. Over here we will fix two-pointers and then find the remaining two elements using two pointer technique as the array will be sorted at first.
Approach: Sort the array, and then fix two pointers, so the remaining sum will be (target – (nums[i] + nums[j])). Now we can fix two-pointers, one front, and another back, and easily use a two-pointer to find the remaining two numbers of the quad. In order to avoid duplications, we jump the duplicates, because taking duplicates will result in repeating quads. We can easily jump duplicates, by skipping the same elements by running a loop.



    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        set<vector<int>> st;
        vector<int> innerVector;
        vector <vector<int> >::iterator it;
        sort(nums.begin(),nums.end());
        
        int len = nums.size();
        
        for(int i=0 ; i<len-3 ; i++)
        {
            for(int l=i+1 ; l<len-2 ; l++)
            {
                int j = l+1;
                int k = len-1;
            
                while(j<k)
                {
                    int sum=nums[i];
                    
                    if((sum>0 && nums[l] > INT_MAX - sum) || (sum<0 && nums[l] < INT_MIN - sum))
                        break;
                    sum+=nums[l];
                    
                    if((sum>0 && nums[j] > INT_MAX - sum) || (sum<0 && nums[j] < INT_MIN - sum))
                        break;
                    sum+=nums[j];
                    
                    if((sum>0 && nums[k] > INT_MAX - sum) || (sum<0 && nums[k] < INT_MIN - sum))
                        break;
                    sum+=nums[k];
                    
                    if(sum==target)
                    {
                        innerVector.push_back(nums[i]);
                        innerVector.push_back(nums[l]);
                        innerVector.push_back(nums[j]);
                        innerVector.push_back(nums[k]);
                    
                        st.insert(innerVector);
                        innerVector.clear();
                        
                        j++;
                        k--;
                    }
                
                    else if(sum<target)
                    {
                        j++;
                    }
                
                    else
                    {
                        k--;
                    }
                }
            }
            
        }
        
        vector <vector<int> > res(st.begin(), st.end());
        
        return res;
    }
