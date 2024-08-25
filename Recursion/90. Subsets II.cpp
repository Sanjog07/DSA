
// ISS WALE CODE MEI 2 METHODS GIVEN HAI


class Solution {
    
//     set<vector<int>> helper(vector<int>& nums,int i,int n){
//         set<vector<int>> s;    
//         if(i == n-1){
//             vector<int> v;
//             s.insert(vector<int>()); // curr ele nhi lenge
//             v.push_back(nums[i]);
//             s.insert(v); // curr ele ko lenge
            
//             return s;
//         }
        
//         set<vector<int>> ans = helper(nums,i+1,n);
        
//         // if current ele ko consider nhi krna
//         for(auto vec: ans){
//             s.insert(vec);
//         }
//         // if current ele ko consider krna hai
//         for(auto vec: ans){
//             vec.push_back(nums[i]);
//             //reverse(vec.begin(), vec.end());
//             s.insert(vec);
//         }
        
//         return s;
//     }
    
    
    void helperAnother(int idx,int n,vector<int> &ans,vector<vector<int>> &res, vector<int>& nums){
        
        res.push_back(ans);
        
        for(int i=idx; i<n; i++){
            if(i == idx || nums[i] != nums[i-1]){
                ans.push_back(nums[i]);
                helperAnother(i+1,n,ans,res,nums);
                ans.pop_back();
            }
        }
        
        return;
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
//         // so set mei ans store krte chalenge so that jo repeat ho rhe
//         // hai vo na aaye
//         int n = nums.size();
        
//         // sort nhi krenge to kuch cases fass skte hai
//         //e.g: [4,4,4,1,4]
//         sort(nums.begin(), nums.end());
        
//         set<vector<int>> acc = helper(nums,0,n);
        
//         vector<vector<int>> solu;
//         for(auto vec: acc){
//             solu.push_back(vec);
//         }
        
//         return solu;
        
        
        /////// ANOTHER METHOD //////////
        
        jo set wala method hai usmei, set mei insertion will 
        take logN time -> so optimize krna pdega
        
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> ans;
        
        sort(nums.begin(), nums.end());
        helperAnother(0,n,ans,res,nums);
        
        return res;
    }
};