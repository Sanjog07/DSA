
typedef pair<int,int> p;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& arr, int k) {
        int m = arr.size();
        int n = arr[0].size();
        
        vector<int> ans;
        
        // priority_queue<p, vector<p>, greater<p>> pq;
        priority_queue<p> pq;
        
        for(int i=0; i<m; i++){
            int cnt = 0;
            for(int j=0; j<n; j++){
                if(arr[i][j] == 1){
                    cnt++;
                }
            }
            pq.push({cnt, i});
            if(pq.size() > k){
                pq.pop();
            }
        }
        
        while(!pq.empty()){
            p x = pq.top();
            pq.pop();
            
            ans.push_back(x.second);
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};