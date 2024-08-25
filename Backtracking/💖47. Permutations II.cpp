class Solution {
    
    vector<vector<int>> ans;
    vector<int> v;
    
    void solve(vector<int>& nums,int n, vector<int> &vis){
        if(v.size() == nums.size()){
            ans.push_back(v);
            return;
        }

        for(int i=0; i<n; i++){
	        if((vis[i] == 1) || (i != 0 && nums[i] == nums[i-1] && vis[i-1] == 0)){
                
                // ye vis[i-1] == 0 -> ye cheez hi identify krna sbse
                // imp hai
	            continue;
	        }
            
            vis[i] = 1;
            v.push_back(nums[i]);
            solve(nums, n, vis);
            v.pop_back();
            vis[i] = 0;
        }
        
        return;
    }    
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> vis(n, 0);
        sort(nums.begin(), nums.end());
        solve(nums, n, vis);
        
        return ans;        
    }
};



// [1,2,2,1] -> this method won't work for this case

// class Solution {
    
//     vector<vector<int>> ans;
//     vector<int> v;
    
//     void solve(int i,vector<int>& nums,int n){
//         if(i == n-1){
//             v.push_back(nums[i]);
//             ans.push_back(v);
//             v.pop_back();
            
//             return;
//         }
//         if(i >= n){
//             return;
//         }
        
//         for(int j=i; j<n; j++){
//             if(j != i && nums[j] == nums[i]){
//                 continue;
//             }
//             swap(nums[j], nums[i]);
//             v.push_back(nums[i]);
            
//             solve(i+1, nums, n);
            
//             v.pop_back();
//             swap(nums[j], nums[i]);
//         }
//     }
    
// public:
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         int n = nums.size();
        
//         sort(nums.begin(), nums.end());
//         solve(0, nums, n);
        
//         return ans;
//     }
// };