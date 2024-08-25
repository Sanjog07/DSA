class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int> (n, 0));
        
        int sr = 0, er = n-1, sc = 0, ec = n-1;
        
        int dir = 0;
        int cnt = 1;
        while(sr <= er && sc <= ec){
            if(dir == 0){ // first row
                for(int i=sc; i<=ec; i++){
                    mat[sr][i] = cnt;
                    cnt++;
                }
                sr++;                
            }else if(dir == 1){ // last column
                for(int i=sr; i<=er; i++){
                    mat[i][ec] = cnt;
                    cnt++;
                }
                ec--;
            }else if(dir == 2){ // last row
                for(int i=ec; i>=sc; i--){
                    mat[er][i] = cnt;
                    cnt++;
                }
                er--;                
            }else if(dir == 3){ // first column
                for(int i=er; i>=sr; i--){
                    mat[i][sc] = cnt;
                    cnt++;
                }
                sc++;
            }
            
            dir = (dir+1)%4;
            
        }
            
        return mat; 
    }
};