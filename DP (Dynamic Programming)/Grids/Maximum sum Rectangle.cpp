


// ques -> https://practice.geeksforgeeks.org/problems/maximum-sum-rectangle2948/1#
// https://www.youtube.com/watch?v=kKEX4P53MyY&t=331s

class Solution {
    
    int kadane(vector<int> v){
        int n = v.size();
        
        int cs = 0;
        int ms = INT_MIN;
        
        for(int i=0; i<n; i++){
            cs += v[i];
            
            ms = max(ms, cs);
            if(cs < 0){
                cs = 0;
            }
        }
        
        return ms;
    }
    
  public:
    int maximumSumRectangle(int r, int c, vector<vector<int>> mat) {
        // hum kya krenge ki jitne bhi possible rectangles ho skte 
        // hai un sb pe iterate krenge -> and unmei se ans nikalenge
        
        
        // so in this ques jo length of final rectangle -> vo to ye loops
        // decide kr rhe hai 
        // and the width of final rectangle -> will be decided by kadane()
        
        int ans = INT_MIN;
        for(int start=0; start<r; start++){
            
            vector<int> v(c, 0);
            for(int i=start; i<r; i++){
                for(int j=0; j<c; j++){
                    v[j] += mat[i][j];
                }
                
                ans = max(ans, kadane(v));
            }
        }
        
        
        return ans;
    }
};