
typedef pair<int,int> pii;

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& nums) {
        int m = nums.size();
        int n = nums[0].size(); 
        
        queue<pii> q;
        int rot = 0, fre =0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(nums[i][j] == 2){
                    rot++;
                    q.push({i, j});
                }else if(nums[i][j] == 1){
                    fre++;
                }
            }
        }   
        
        // pehle fre check kro and then rot check kro
        if(fre == 0){
            return 0;
        }        
        if(rot == 0){
            return -1;
        }

        
        int time = 0;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                auto f = q.front();
                q.pop();
                
                for(int i=0; i<4; i++){
                    int nx = f.first + dx[i];
                    int ny = f.second + dy[i];
                    
                    if(nx >= 0 && ny >= 0 && nx < m && ny < n && nums[nx][ny] == 1){
                        fre--;
                        q.push({nx, ny});
                        nums[nx][ny] = 2;
                    }
                }
            }
            
            if(!q.empty()){
                time++;
            }
        }
        
        return (fre > 0) ? -1 : time;
    }
};






// class custom{
//     public:
    
//     int x;
//     int y;
//     int t;
// };

//     int dx[4] = {-1, 0, 1, 0};
//     int dy[4] = {0, 1, 0, -1};

// class Solution {
// public:
//     int orangesRotting(vector<vector<int>>& nums) {
//         int m = nums.size();
//         int n = nums[0].size();
        
//         queue<custom> q;
//         int rot = 0, fre =0;
//         for(int i=0; i<m; i++){
//             for(int j=0; j<n; j++){
//                 if(nums[i][j] == 2){
//                     rot++;
//                     q.push({i, j, 0});
//                 }else if(nums[i][j] == 1){
//                     fre++;
//                 }
//             }
//         }
        
//         if(fre == 0){
//             return 0;
//         }        
//         if(rot == 0){
//             return -1;
//         }        
        
//         int ans = -1;
//         while(!q.empty()){
//             auto f = q.front();
//             q.pop();

//             int time = f.t;
            
//             for(int i=0; i<4; i++){
//                 int nx = f.x + dx[i];
//                 int ny = f.y + dy[i]; 
                
//                 if(nx >= 0 && ny >= 0 && nx < m && ny < n && nums[nx][ny] == 1){
                    
//                     fre--;
//                     nums[nx][ny] == 2; // make it rotten
//                     // empty wale cell ko to chedenge hi nhi
//                     q.push({nx, ny, time+1});
//                     ans = max(ans, time+1);
//                 }
//             }
//         }
        
//         return (fre > 0) ? -1 : ans;
//     }
// };







// class custom{
//     public:
    
//     int x;
//     int y;
//     int t;
// };

//     int dx[4] = {-1, 0, 1, 0};
//     int dy[4] = {0, 1, 0, -1};

// class Solution {
// public:
//     int orangesRotting(vector<vector<int>>& nums) {
//         int m = nums.size();
//         int n = nums[0].size();
        
//         queue<custom> q;
//         for(int i=0; i<m; i++){
//             for(int j=0; j<n; j++){
//                 if(nums[i][j] == 2){
//                     q.push({i, j, 0});
//                 }
//             }
//         }
        
//         int ans = -1;
//         while(!q.empty()){
//             auto f = q.front();
//             q.pop();

//             int time = f.t;
            
//             for(int i=0; i<4; i++){
//                 int nx = f.x + dx[i];
//                 int ny = f.y + dy[i]; 
                
//                 if(nx >= 0 && ny >= 0 && nx < m && ny < n && nums[nx][ny] == 1){
                    
//                     nums[nx][ny] == 2; // make it rotten
//                     // empty wale cell ko to chedenge hi nhi
//                     q.push({nx, ny, time+1});
//                     ans = max(ans, time+1);
//                 }
//             }
//         }
        
//         for(int i=0; i<m; i++){
//             for(int j=0; j<n; j++){
//                 if(nums[i][j] == 1){
//                     return -1;
//                 }
//             }
//         } 
        
//         return ans;
//     }
// };