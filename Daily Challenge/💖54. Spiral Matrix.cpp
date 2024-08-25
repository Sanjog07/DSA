
// https://www.youtube.com/watch?v=1ZGJzvkcLsA

// Blocks wale ye dikkat btana chah rha tha, ki hum chaaro(4)
// first row, last col, last row and first col ek saath print kr rhe hai
// and vo jo while wali condi hai vo in chaaro ko print krne ke baad check
// ho rhi hai -> isliye last wale cases mei dobara print ho ja rha hai
// so upar wale solu mei ye hr single print ke baad check krega

// https://www.youtube.com/watch?v=SVFXEqn3Ceo&t=87s
// ya fir ye pepcoding wale ka tareeka bhi shi hai

// https://www.youtube.com/watch?v=6Yqbxo8KS6E
// iske sirf code dekhna -> basic wala code hai iska

// Overflow wali condi. bhot acche se smajh nhi aayi
// koi video acchhi si mile to dekh lena

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        int sr = 0, er = m-1, sc = 0, ec = n-1;
        
        vector<int> ans;
        
        int dir = 0;
        while(sr <= er && sc <= ec){
            if(dir == 0){ // first row
                for(int i=sc; i<=ec; i++){
                    ans.push_back(mat[sr][i]);
                }
                sr++;                
            }else if(dir == 1){ // last column
                for(int i=sr; i<=er; i++){
                    ans.push_back(mat[i][ec]);
                }
                ec--;
            }else if(dir == 2){ // last row
                for(int i=ec; i>=sc; i--){
                    ans.push_back(mat[er][i]);
                }
                er--;                
            }else if(dir == 3){ // first column
                for(int i=er; i>=sr; i--){
                    ans.push_back(mat[i][sc]);
                }
                sc++;
            }
            
            dir = (dir+1)%4;
            
        }
        
        return ans;
    }
};