
// https://www.youtube.com/watch?v=vtNoP43hGJA

typedef pair<int,int> pii;

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& arr) {
        int n = arr.size();
        int x = n/2;
        
        int ans = 0;
        
        priority_queue<pii> pq;
        for(int i=0; i<n; i++){
            int diff = arr[i][1] - arr[i][0];
            pq.push({diff, i});
        }
        
        while(x--){
            int idx = pq.top().second;
            pq.pop();
            
            ans += arr[idx][0];
        }
        
        while(!pq.empty()){
            int idx = pq.top().second;
            pq.pop();
            
            ans += arr[idx][1];            
        }
        
        return ans;
    }
};