class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& arr) {
        int n = arr.size();
        vector<string> ans(n);
        
        priority_queue<pair<int,int>> pq;
        for(int i=0; i<n; i++){
            pq.push({arr[i], i});
        }
        
        int cnt = 1;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            if(cnt == 1){
                ans[it.second] = "Gold Medal";
            }else if(cnt == 2){
                ans[it.second] = "Silver Medal";
            }else if(cnt == 3){
                ans[it.second] = "Bronze Medal";
            }else{
                ans[it.second] = to_string(cnt);
            }
            
            cnt++;
        }
        
        return ans;
    }
};