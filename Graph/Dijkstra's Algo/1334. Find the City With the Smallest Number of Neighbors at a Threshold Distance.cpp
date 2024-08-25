typedef pair<int,int> pii;
class Solution {
    
    int solve(int src,vector<vector<pii>> &adj,int thres,int n){
        
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, src});
        vector<int> distance(n, INT_MAX);
        
        while(!pq.empty()){
            auto f = pq.top();
            pq.pop();
            int node = f.second;
            int dist = f.first;
            
            for(auto p: adj[node]){
                int nbr = p.first;
                int wt = p.second;
                
                
                // agr aise krenge to ans bhot jyada aayega
                // i.e wrong aayega
                // bcz jb ek nbr apne parent pe jayega tb bhi vo
                // cnt ko increase kr skta ahi
                
                // if((dist + wt) <= thres){
                //     cnt++;
                //     pq.push({(dist + wt), nbr});
                // }
                
                if((dist + wt) < distance[nbr]){
                    distance[nbr] = (dist + wt);
                    pq.push({distance[nbr], nbr});
                }
            }
        }
            
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(i != src && distance[i] <= thres){
                cnt++;
            }
        }
        
        return cnt;
    }
    
public:
    int findTheCity(int n, vector<vector<int>>& nums, int thres) {
        vector<vector<pii>> adj(n);

        for(auto v: nums){
            adj[v[0]].push_back({v[1], v[2]});
            adj[v[1]].push_back({v[0], v[2]});
        }
        
        int res = INT_MAX;
        int solu = -1;
        for(int i=0; i<n; i++){
            int ans = solve(i, adj, thres, n);
            
            // i.e agr equal aa rha hai to bdi value will be ans
            // and loop smaller to bigger hi chal rha hai
            if(ans <= res){
                res = ans;
                solu = i;
            }
        }
        
        return solu;
    }

};