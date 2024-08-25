
class Solution {
    
    int cnt = 0;
    
    void helper(int col, int n, vector<bool> &down, vector<bool> &up, vector<bool> &left){
        if(col == n){
            cnt++;
            return;
        }
        
        for(int row=0; row<n; row++){
            if(!down[row+col] && !up[n-1-row+col] && !left[row]){
                
                left[row] = true;
                down[row+col] = true;
                up[n-1-row+col] = true;

                helper(col+1, n, down, up, left);
                
                left[row] = false;
                down[row+col] = false;
                up[n-1-row+col] = false;                
            }
        }
    }
    
public:
    int totalNQueens(int n) {

        int x = 2*n - 1;
        vector<bool> up(x, false);
        vector<bool> down(x, false);
        vector<bool> left(n, false);
        
        helper(0, n, down, up, left);
        
        return cnt;
    }
};