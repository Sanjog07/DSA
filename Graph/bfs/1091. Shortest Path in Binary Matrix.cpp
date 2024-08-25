

// Recursion or bACKTRAcking ->TLE
// so use -> BFS

// iss ques mei chhoti se optimization ye ho skti hai ki 
// ismei visited array bnane ki zaruarat hi nhi hai
// hum jis cell ko visit kr lete hai uski jagha -1 put krte jayo
// as hum sirf vo cells consider kr rhe hai where nums[i][j] = 0


class custom{
    public:
    
    int x;
    int y;
    int d;
};


class Solution {
    
    int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};    
    
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& nums) {
        int n = nums.size();
        
        if(nums[0][0] == 1 || nums[n-1][n-1] == 1){
            return -1;
        } 
        if(n == 1){
            return 1;
        }
        
        // All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner)  --> it means ki ek cell, 8 cells se connected hai
        // i.e uske 8 nbrs hai
        
        //vector<vector<int>> vis(n, vector<int>(n, 0));
        
        queue<custom> q;  
        q.push({0,0,1});
        nums[0][0] = -1;
        
        while(!q.empty()){
            auto f = q.front();
            q.pop();
            
            int dist = f.d;
            
            for(int i=0; i<8; i++){
                int nx = f.x + dx[i];
                int ny = f.y + dy[i];
                
                if(nx == n-1 && ny == n-1){
                    return dist + 1;
                }
                
                if(nx >= 0 && ny >= 0 && nx < n && ny < n && nums[nx][ny] == 0){  //  && vis[nx][ny] == 0 
                    
                    q.push({nx, ny, dist + 1});
                    nums[nx][ny] = -1; // it is showing that this cell is visited     
                    
                    //vis[nx][ny] = 1;
                }                
            }
        }
        
        return -1;
    }
};







// it is giving TLE 
class Solution {
    
    int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1}; 
    
    int helper(int i,int j, vector<vector<int>>& nums,int n){
        if(i == n-1 && j == n-1){
            return 1;
        }
        
        nums[i][j] = 2; // means visited
        
        int ans = INT_MAX-1;
        for(int k=0; k<8; k++){
            int nx = i + dx[k];
            int ny = j + dy[k];
            
            if(nx >= 0 && ny >= 0 && nx < n && ny < n && nums[nx][ny] == 0){
                
                int val = 1 + helper(nx, ny, nums, n);
                ans = min(ans, val);
            }
        }
        
        nums[i][j] = 0;
        return ans;
    }
    
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& nums) {
        int n = nums.size();
        
        if(nums[0][0] == 1 || nums[n-1][n-1] == 1){
            return -1;
        } 
        if(n == 1){
            return 1;
        }    
        
        int solu = helper(0, 0, nums, n);
        
        return (solu == INT_MAX-1) ? -1 : solu;
    }
};









// // https://www.youtube.com/watch?v=eBB97X_kbHE

// class Point{
// public:
//     int x;
//     int y;
//     int count;
// };
 
// class Solution {
// public:
//     int dx[8]={1,1,1,-1,-1,-1,0,0};
//     int dy[8]={1,0,-1,1,-1,0,1,-1};
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
//         if(grid[0][0]==1) return -1;
        
//         int row= (int) grid.size();
//         int column= (int) grid[0].size();
        
//         queue<Point> q;
//         q.push({0,0,1});
//         grid[0][0]=-1;
        
//         while(!q.empty())
//         {
//             Point p= q.front();
//             q.pop();
            
//             if(p.x==row-1 && p.y==column-1)
//                 return p.count;
            
//             for(int i=0;i<8;i++)
//             {
//                 int x=p.x+dx[i];
//                 int y=p.y+dy[i];
                
//                 if(x>=0 && y>=0 && x<row && y<column && grid[x][y]==0)
//                 {
//                     q.push({x,y,p.count+1});
//                     grid[x][y]=-1;
//                 }
//             }
//         }
        
//         return -1;
//     }
// };