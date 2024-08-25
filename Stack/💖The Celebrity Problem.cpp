// https://www.youtube.com/watch?v=CiiXBvrX-5A
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat, int n){
        stack<int> s;
        for(int i=0; i<n; i++){
            s.push(i);
        }
        
        // 1 se jyada celebrity ho hi nhi skte
        // but aisa ho skta hai ki koi bhi celebrity na ho
        
        while(s.size() >= 2){
            int x = s.top();
            s.pop();
            int y = s.top();
            s.pop();
            
            if(mat[x][y] == 0){
                // x doesn't know y
                // i.e y can't be a celebrity
                
                s.push(x);
            }else{
                // x know y
                // i.e x can't be a celebrity
                
                s.push(y);
            }
        }
        
        int pot = s.top(); // this can be a potential ans
        for(int i=0; i<n; i++){
            if(i != pot){
                if(mat[i][pot] != 1 || mat[pot][i] != 0){
                    return -1;
                }
            }
        }
        
        return pot;
    }
};