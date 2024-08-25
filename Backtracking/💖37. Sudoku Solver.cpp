class Solution {
    
    bool isValid(vector<vector<char>>& nums, int row,int col, char ch, int n){
        for(int i=0; i<n; i++){
            // colu wise
            if(nums[row][i] == ch){
                return false;
            }
            
            // row wise
            if(nums[i][col] == ch){
                return false;
            }
            
            // sub-boxes wise
            int nr = 3*(row/3) + i/3;
            int nc = 3*(col/3) + i%3;
            
            if(nums[nr][nc] == ch){
                return false;
            }
        } 
        
        return true;
    }
    
    bool solve(vector<vector<char>>& nums,int n){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(nums[i][j] == '.'){
                  for(char ch='1'; ch<='9'; ch++){
                      if(isValid(nums, i, j, ch, n)){
                          nums[i][j] = ch;
                          if(solve(nums, n)){
                              // yha se hi true return isliye kr rhe hai
                              // bcz hume ek hi solu chahiye 
                              // to jaise hi ek solu mil jayega vaise 
                              // hi return kr denge
                              // saare possible solu's nhi nikalne
                              return true;
                          }else{
                              nums[i][j] = '.';
                          }
                        }
                    }
                    
                    return false;
                }
            }
        }   
        
        // i.e when all the cells are filled
        return true;
    }
    
public:
    void solveSudoku(vector<vector<char>>& nums) {
        int n = 9;
        
        solve(nums, n);
    }
};