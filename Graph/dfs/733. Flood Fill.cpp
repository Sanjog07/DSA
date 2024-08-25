
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

class Solution {
    
    void helper(int m,int n,vector<vector<int>>& nums, int x, int y, int nc,int cc){
        
        nums[x][y] = nc;
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >= 0 && ny >= 0 && nx < m && ny < n && nums[nx][ny] == cc){
                
                helper(m, n, nums, nx, ny, nc, cc);
            }
                
        }                
    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& nums, int sr, int sc, int nc) {
        
        int m = nums.size();
        int n = nums[0].size();
        
        int cc = nums[sr][sc]; // current color
        
        
        // iss condi ko lgaye bina ye stack overflow de rha hai
        // bcz hum already coloured position ko same color 
        // se fill kiye ja rhe hai
        if(nc == cc){
            return nums;
        }
        
        helper(m, n, nums, sr, sc, nc, cc);
        
        return nums;
    }
};