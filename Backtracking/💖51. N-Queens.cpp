
class Solution {
    
    vector<vector<string>> res;
    
    void helper(int col, int n, vector<string> &mark, vector<bool> &down, vector<bool> &up, vector<bool> &left){
        if(col == n){
            res.push_back(mark);
            return;
        }
        
        for(int row=0; row<n; row++){
            if(!down[row+col] && !up[n-1-row+col] && !left[row]){
                
                left[row] = true;
                down[row+col] = true;
                up[n-1-row+col] = true;
                
                mark[row][col] = 'Q';
                helper(col+1, n, mark, down, up, left);
                mark[row][col] = '.';
                
                left[row] = false;
                down[row+col] = false;
                up[n-1-row+col] = false;                
            }
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        
        vector<string> mark(n);
        string str(n, '.');
        
        for(int i=0; i<n; i++){
            mark[i] = str;
        }
        
        int x = 2*n - 1;
        vector<bool> up(x, false);
        vector<bool> down(x, false);
        vector<bool> left(n, false);
        
        helper(0, n, mark, down, up, left);
        
        return res;
    }
};



class Solution {
    
    vector<vector<string>> res;

    bool isSafe(int row,int col, vector<string> &mark, int n){
        
        int i = row;
        int j = col;
        
        j--;
        while(j >= 0){
            if(mark[i][j] != 'Q'){
                j--;
            }else{
                return false;
            }
        }
        
        i = row;
        j = col;
        
        i--;
        j--;
        while(i >= 0 && j >= 0){
            if(mark[i][j] != 'Q'){
                i--;
                j--;
            }else{
                return false;
            }            
        }
        
        i = row;
        j = col;
        
        i++;
        j--;
        while(i < n && j >= 0){
            if(mark[i][j] != 'Q'){
                i++;
                j--;
            }else{
                return false;
            }             
        }
        
        return true;
    }
    
    void helper(int col, int n, vector<string> &mark){
        if(col == n){
            res.push_back(mark);
            return;
        }
        
        for(int row=0; row<n; row++){
            if(isSafe(row, col, mark, n)){
                mark[row][col] = 'Q';
                helper(col+1, n, mark);
                mark[row][col] = '.';
            }
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        
        vector<string> mark(n);
        string str(n, '.');
        for(int i=0; i<n; i++){
            mark[i] = str;
        }
        
        helper(0, n, mark);
        
        return res;
    }
};





