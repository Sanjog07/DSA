class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int tar) {
        vector<int> ans;
        int n = nums.size();
        
        unordered_map<int,int> m;
        for(int i=0; i<n; i++){
            int x = nums[i];
            if(m.find(tar-x) != m.end()){
                ans.push_back(m[tar-x]);
                ans.push_back(i);
                break;
            }
            
            m[nums[i]] = i;
        }
        
        return ans;
    }
};