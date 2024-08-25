
// https://www.youtube.com/watch?v=gatxvipc5b8

typedef tuple<int,int,int> tii;

class Solution {
    
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};    
    
public:
    int minimumEffortPath(vector<vector<int>>& nums) {
        int m = nums.size();
        int n = nums[0].size();
        
        priority_queue<tii, vector<tii>, greater<tii>> pq;
        pq.push({0,0,0});
        
        vector<vector<int>> effort(m, vector<int> (n, INT_MAX));
        effort[0][0] = 0;
        
        while(!pq.empty()){
            auto [eff, x, y] = pq.top();
            pq.pop();
            
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && ny >= 0 && nx < m && ny < n){

                    int iskaEff = abs(nums[nx][ny] - nums[x][y]); // i.e diff in the heights
                    
                    int newEff = max(eff, iskaEff);
                    if(newEff  < effort[nx][ny]){
                        effort[nx][ny] = newEff;
                        pq.push({newEff, nx, ny});
                    }
                }                
            } 
        }
        
        return effort[m-1][n-1];
    }
};