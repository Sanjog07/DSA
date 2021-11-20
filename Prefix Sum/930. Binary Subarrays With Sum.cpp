class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        
        // i.e no of subarrays with k
        
        unordered_map<int,int> m;
        int pre = 0;
        for(int i=0; i<n; i++){
            pre += nums[i];
            
            if(pre == k){
                cnt++;
            }
            if(m.find(pre-k) != m.end()){
                cnt += m[pre-k];
            }
            
            m[pre]++;
        }
        
        return cnt;
    }
};