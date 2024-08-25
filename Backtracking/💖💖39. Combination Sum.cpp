class Solution {
    
    vector<vector<int>> ans;
    vector<int> v;
    
    void helper(int i,vector<int>& nums, int tar,int n){
        if(tar == 0){
            ans.push_back(v);
            return;
        }
        if(i >= n){
            return;
        }
        
        if(nums[i] <= tar){
            v.push_back(nums[i]);
            helper(i, nums, tar - nums[i], n);
            v.pop_back();
        }
        
        helper(i+1, nums, tar, n);
        
        return;
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int tar) {
        int n = nums.size();
        
        helper(0, nums, tar, n);
        
        return ans;
    }
};