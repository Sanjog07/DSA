class Solution {
    
    bool isValid(vector<vector<char>>& nums, int row,int col, char ch, int n){
        for(int i=0; i<n; i++){
            // colu wise
            if(nums[row][i] == ch && i != col){
                return false;
            }
            
            // row wise
            if(nums[i][col] == ch && i != row){
                return false;
            }
            
            //sub-boxes wise
            int nr = 3*(row/3) + i/3;
            int nc = 3*(col/3) + i%3;
            if(nr != row || nc != col){
                if(nums[nr][nc] == ch){
                    return false;
                }
            }

        } 
        
        return true;
    }    
    
public:
    bool isValidSudoku(vector<vector<char>>& nums) {
        int n = 9;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(nums[i][j] != '.'){
                    if(isValid(nums, i, j, nums[i][j], n) == false){
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
};