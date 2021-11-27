class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        // 3 sum wali approach lgayege 
        // ki 2 elements ko fixed rkhenge and baaki 2 elements
        // ko 2 pointer se nikalenge
        
        vector<vector<int>> solu;
        
        int n = nums.size();
        if(n < 4){
            return {};
        }
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n-3; i++){
            
            if(i != 0 && nums[i] == nums[i-1]){
                continue;
            }
            
            for(int j=i+1; j<n-2; j++){
                
                if(j != i+1 && nums[j] == nums[j-1]){
                    continue;
                }
                
                int l = j+1;
                int r = n-1;
                
                int a = nums[i] + nums[j];
                int tar = target - a;
                
                while(l < r){
                    int x = nums[l] + nums[r];
                    if(x == tar){
                        vector<int> ans;
                        ans.push_back(nums[i]);
                        ans.push_back(nums[j]);
                        ans.push_back(nums[l]);
                        ans.push_back(nums[r]);
                        
                        solu.push_back(ans);
                        
                        while(l < r && nums[l] == nums[l+1]){
                            l++;
                        }
                        while(l < r && nums[r] == nums[r-1]){
                            r--;
                        }
                        
                        l++;
                        r--;
                    }else if(x < tar){
                        l++;
                    }else{
                        r--;
                    }
                }
            }
        }
        
        return solu;
    }
};