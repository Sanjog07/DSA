class Solution {
    
    int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    
    int count(vector<vector<int>> &arr,int i,int j,int m,int n){
        int cnt = 0;
        for(int k=0; k<8; k++){
            int ni = i + dx[k];
            int nj = j + dy[k];
            
            if(ni >= 0 && nj >= 0 && ni < m && nj < n){
                if(arr[ni][nj] == 1 || arr[ni][nj] == -1){
                    cnt++;
                }                
            }
        }
        
        return cnt;
    }
    
public:
    void gameOfLife(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int cnt = count(arr, i, j, m, n);
                if(arr[i][j] == 0 && cnt == 3){
                    arr[i][j] = -2; // kuch bhi likh skte hai yha
                }
                if(arr[i][j] == 1 && (cnt < 2 || cnt > 3)){
                    arr[i][j] = -1; // ye bss differentiate krne ke liye -1 and -2 likhe hai
                }
            }
        }
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(arr[i][j] == -1){
                    arr[i][j] = 0;
                }
                if(arr[i][j] == -2){
                    arr[i][j] = 1;
                }
            }
        }
        
        
    }
};



// // https://leetcode.com/problems/game-of-life/discuss/1938375/Simple-C%2B%2B-solution-with-explanation-oror-O(1)-space-oror-O(N*M)-time-oror-faster-than-100


// class Solution {
//     int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//     int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
// public:
//     void gameOfLife(vector<vector<int>>& nums) {
//         int m = nums.size();
//         int n = nums[0].size();
        
//         vector<vector<int>> mat(m, vector<int> (n, 0));
//         for(int i=0; i<m; i++){
//             for(int j=0; j<n; j++){
//                 if(nums[i][j] == 1){
//                     for(int k=0; k<8; k++){
//                         int ni = i + dx[k];
//                         int nj = j + dy[k];
                        
//                         if(ni >=0 && nj >= 0 && ni < m && nj < n){
//                             mat[ni][nj] += 1;
//                         }
//                     }
//                 }
//             }
//         }
        
//         for(int i=0; i<m; i++){
//             for(int j=0; j<n; j++){
//                 if(nums[i][j] == 0 && mat[i][j] == 3){
//                     nums[i][j] = 1;
//                 }else if(nums[i][j] == 1){
//                     if(mat[i][j] < 2 || mat[i][j] > 3){
//                         nums[i][j] = 0;
//                     }
//                 }
//             }
//         } 
        
//         return;
        
//     }
// };