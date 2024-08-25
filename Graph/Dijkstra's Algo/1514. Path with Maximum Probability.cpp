

// see notebook

typedef pair<int,double> pid;
typedef pair<double,int> pdi;

class Solution {
    
    double solve(vector<vector<pid>> &adj,int s,int e,int n){
        
        priority_queue<pdi> pq;
        pq.push({1.0, s});
        
        vector<double> prob(n, 0.0);
        
        prob[s] = 1.0;
        
        while(!pq.empty()){
            auto f = pq.top();
            pq.pop();
            
            double pnode = f.first; 
            int node = f.second;
            
            for(auto p: adj[node]){
                int nbr = p.first;
                double pro = p.second;
                
                if(prob[nbr] < (pnode * pro)){
                    prob[nbr] = (pnode * pro);
                    pq.push({prob[nbr], nbr});
                }
            }
        }
        
        return prob[e];
    }
    
public:
    double maxProbability(int n, vector<vector<int>>& nums, vector<double>& suc, int s, int e) {
        
        vector<vector<pid>> adj(n);
        
        int m = nums.size();
        for(int i=0; i<m; i++){
            double wt = suc[i];
            int x = nums[i][0];
            int y = nums[i][1];
            
            adj[x].push_back({y, wt});
            adj[y].push_back({x, wt});
        }
        
        
        double ans = solve(adj, s, e, n);
        
        return ans;
    }
};