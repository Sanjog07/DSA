class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        
        // 2^n tk chalega bahar wala loop
        for(int i=0; i<(1<<n); i++){
            
            vector<int> ans;
            for(int j=0; j<n; j++){
                int mask = (1<<j);
                if((i&mask) != 0){
                    ans.push_back(nums[j]);
                }
            }
            
            res.push_back(ans);
        }
        
        //and andar wala loop n tk chalega
        //so T.C =  O (2^n * n);
        
        return res;
        
        
    }
};