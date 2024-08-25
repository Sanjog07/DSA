class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > pq;
        
        int n = nums.size();
        for(int i=0; i<n; i++){
            pq.push({nums[i], i});
            if(pq.size() > k){
                pq.pop();
            }
        }
        
        vector<int> ans;
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > q;
        
        while(!pq.empty()){
            q.push({pq.top().second, pq.top().first});
            pq.pop();
        }
        
        while(!q.empty()){
            ans.push_back(q.top().second);
            q.pop();
        }
        
        return ans;
    }
};