class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int tar) {
        int n = nums.size();
        
        vector<int> ans;
        
        if(!binary_search(nums.begin(), nums.end(), tar)){
            ans.push_back(-1);
            ans.push_back(-1);
            
            return ans;
        }
        
        int r = upper_bound(nums.begin(), nums.end(), tar) - nums.begin();
        int l = lower_bound(nums.begin(), nums.end(), tar) - nums.begin(); 
        
        ans.push_back(l);
        ans.push_back(r-1);        
        
        return ans;
    }
};

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int tar) {
        int n = nums.size();
        
        vector<int> ans;
        
        int r = upper_bound(nums.begin(), nums.end(), tar) - nums.begin();
        int l = lower_bound(nums.begin(), nums.end(), tar) - nums.begin(); 
        
        if(r == l){
            ans.push_back(-1);
            ans.push_back(-1);            
        }else{
            ans.push_back(l);
            ans.push_back(r-1);                    
        }
        
        return ans;
    }
};
