class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // so hum ek no ko fixed rkhengr and 
        // fir doublet nikalenge using 2 pointer
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> solu;
        for(int i=0; i<n-2; i++){
            int tar = 0 - nums[i];
            
            // hume repeated characters ko skip krna hai
            if(i != 0 && nums[i] == nums[i-1]){
                continue;
            }
            
            int l = i+1;
            int r = n-1;
            while(l < r){//equal to nhi aayega bcz same element nhi lene
                int x = nums[l] + nums[r];
                if(x == tar){
                    vector<int> ans;
                    ans.push_back(nums[i]);
                    ans.push_back(nums[l]);
                    ans.push_back(nums[r]);
                    
                    solu.push_back(ans);
                    
                    
                    // ye repeated chaarcters ko skip krne ke liye
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
        
        return solu;
        
        //-----------------------------------//
        
//         vector<vector<int>> ans;
//         int n = nums.size();
        
//         sort(nums.begin(), nums.end());
        
//         for(int i=0; i<=n-3; i++){
//             int tar = 0 - nums[i];
            
//             //now find doublet with sum == tar
//             if(i != 0 && nums[i] == nums[i-1]){
//                 continue;
//             }
            
//             int prev;
//             unordered_map<int,int> m;
//             for(int k=i+1; k<n; k++){
//                 int x = nums[k];
                
//                 if(k != (i+1) && nums[k] == prev){
//                     continue;
//                 }
                
//                 if(m.find(tar-x) != m.end()){
//                     vector<int> solu;
//                     solu.push_back(nums[i]);
//                     solu.push_back(tar-x);
//                     solu.push_back(x);
                    
//                     ans.push_back(solu);
                    
//                     prev = x;
                    
//                     //m.erase(tar-x);
                    
//                 }else{
//                     m[x] = k;
//                 }
            
//             }
            
//         }
        
//         return ans;
        
        
        ////-------------------//////
        
//       https://leetcode.com/problems/3sum/  set<int> s(nums.begin(), nums.end());
//         for(auto ele: s){
//             int tar = 0 - ele;
            
//             unordered_map<int,int> m;
//             int j = i+1;
//             for(int k=j; k<n; k++){
//                 int x = nums[k];
//                 if(m.find(tar-x) != m.end()){
//                     vector<int> solu;
//                 }
//             }
//         }
    }
};