
typedef pair<int,int> pii;

// notebook

// https://leetcode.com/problems/as-far-from-land-as-possible/discuss/1936891/c%2B%2B-solution-explained-with-images-and-notes -> without dist array

class Solution {
    
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};    
    
public:
    int maxDistance(vector<vector<int>>& nums) {
        int n = nums.size();
        
        
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        
        queue<pii> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(nums[i][j] == 1){
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        
        int ans = 0;
        while(!q.empty()){
            auto f = q.front();
            q.pop();
            
            int x = f.first;
            int y = f.second;
            
           for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx >= 0 && ny >= 0 && nx < n && ny < n && dist[nx][ny] == INT_MAX){
                    q.push({nx, ny});
                    dist[nx][ny] = dist[x][y] + 1;
                    ans = max(ans, dist[nx][ny]);
                }
            }            
        }
        
        return (ans == 0) ? -1 : ans;
    }
};