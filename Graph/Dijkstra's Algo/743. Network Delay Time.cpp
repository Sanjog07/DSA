
// as this is a ques in dijkstra's algo and yha pe zaruri nhi hai
// ki hume priority_queue hi use krni hai hum yha queue bhi use kr skte hai -> see code below 

typedef pair<int,int> pii;

class Solution {
    
//     class cmp{
//     public:

//         bool operator()(pair<int,int> p1, pair<int,int> p2){
//             return p1.first > p2.first;
//         }
//     };    
    
    
    int solve(vector<vector<pii>>& adj, int n, int k){
        priority_queue<pii,vector<pii>, greater<pii> > pq;
        
        pq.push({0, k});
        vector<int> distance(n+1, INT_MAX);
        distance[k] = 0;
        
        while(!pq.empty()){
            auto f = pq.top();
            pq.pop();
            
            int dist = f.first;
            int node = f.second;
            
            for(auto p: adj[node]){
                int nbr = p.first;
                int d = p.second;
                
                if((d + dist) < distance[nbr]){
                    distance[nbr] = (d + dist);
                    pq.push({distance[nbr], nbr});
                }
            }
        }
        
        int ans = INT_MIN;
        for(int i=1; i<=n; i++){
            ans = max(ans, distance[i]);
        }
        
        return (ans == INT_MAX) ? -1 : ans;
    }
    
public:
    int networkDelayTime(vector<vector<int>>& nums, int n, int k) {
        // yha pe nums, adj list nhi hai
        
        vector<vector<pii>> adj(n+1, vector<pii>());
        for(auto v: nums){
            int src = v[0];
            int dest = v[1];
            int wt = v[2];
            
            adj[src].push_back({dest, wt});
        }
        
        return solve(adj, n, k);
    }
};



// // using QUEUES


// typedef pair<int,int> pii;

// class Solution {
    
// //     class cmp{
// //     public:

// //         bool operator()(pair<int,int> p1, pair<int,int> p2){
// //             return p1.first > p2.first;
// //         }
// //     };    
    
    
//     int solve(vector<vector<pii>>& adj, int n, int k){
//         queue<pii> pq;
        
//         pq.push({0, k});
//         vector<int> distance(n+1, INT_MAX);
//         distance[k] = 0;
        
//         while(!pq.empty()){
//             auto f = pq.front();
//             pq.pop();
            
//             int dist = f.first;
//             int node = f.second;
            
//             for(auto p: adj[node]){
//                 int nbr = p.first;
//                 int d = p.second;
                
//                 if((d + dist) < distance[nbr]){
//                     distance[nbr] = (d + dist);
//                     pq.push({distance[nbr], nbr});
//                 }
//             }
//         }
        
//         int ans = INT_MIN;
//         for(int i=1; i<=n; i++){
//             ans = max(ans, distance[i]);
//         }
        
//         return (ans == INT_MAX) ? -1 : ans;
//     }
    
// public:
//     int networkDelayTime(vector<vector<int>>& nums, int n, int k) {
//         // yha pe nums, adj list nhi hai
        
//         vector<vector<pii>> adj(n+1, vector<pii>());
//         for(auto v: nums){
//             int src = v[0];
//             int dest = v[1];
//             int wt = v[2];
            
//             adj[src].push_back({dest, wt});
//         }
        
//         return solve(adj, n, k);
//     }
// };