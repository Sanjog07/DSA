

// https://www.youtube.com/watch?v=NQGduRE1Crk&t=608s

typedef pair<int,int> pii;

class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int n = nums.size();
        
        stack<pii> s;
        s.push({nums[n-1], 0});
        
        int ans = 0;
        for(int i=n-2; i>=0; i--){
            int cnt = 0;
            while(!s.empty() && nums[i] > s.top().first){
                cnt = max(cnt+1, s.top().second);
                s.pop();
            }
            
            ans = max(ans, cnt);
            s.push({nums[i], cnt});
        }
        
        return ans;
    }
};