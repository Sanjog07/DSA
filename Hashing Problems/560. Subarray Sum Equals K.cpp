class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int,int> m;
        int pre = 0, cnt = 0;
        
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