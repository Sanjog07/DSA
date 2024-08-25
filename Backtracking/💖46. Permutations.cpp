
// https://www.youtube.com/watch?v=f2ic2Rsc9pU&t=2s
// thodi si aur optimization mei hume v wala vector bnane ki zarurat hi nhi hai
// nums hi puch back krdo


class Solution {
    
    vector<vector<int>> ans;
    vector<int> v;
    
    void solve(int i,vector<int>& nums,int n){
        if(i == n-1){
            v.push_back(nums[i]);
            ans.push_back(v);
            v.pop_back();
            
            return;
        }
        if(i >= n){
            return;
        }
        
        for(int j=i; j<n; j++){
            swap(nums[j], nums[i]);
            v.push_back(nums[i]);
            
            solve(i+1, nums, n);
            
            v.pop_back();
            swap(nums[j], nums[i]);
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        
        solve(0, nums, n);
        
        return ans;
    }
};