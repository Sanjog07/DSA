class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& arr, int k) {
        int n = arr.size();
        
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > pq;
        
        for(int i=0; i<n; i++){
            vector<int> vec = arr[i];
            
            int x = vec[0];
            int y = vec[1];
            int val = x*x + y*y;
            pq.push({val, i});
        }
        
        vector<vector<int>> solu;
        while(!pq.empty() && k--){
            pair<int,int> p = pq.top();
            pq.pop();
            
            solu.push_back(arr[p.second]);
        }
        
        return solu;
    }
};