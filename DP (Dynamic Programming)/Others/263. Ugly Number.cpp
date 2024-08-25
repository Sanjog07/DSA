class Solution {
    
    bool solve(int n){
        if(n <= 0){
            return false;
        }
        if(n == 1){
            return true;
        }
         
        bool ans1 = false, ans2 = false, ans3 = false;
        if(n%2 == 0){
            ans1 = solve(n/2);
            if(ans1){
                return true;
            }
        }
        if(n%3 == 0){
            ans2 = solve(n/3);
            if(ans2){
                return true;
            }
        } 
        if(n%5 == 0){
            ans3 = solve(n/5);
            if(ans3){
                return true;
            }
        }  
        
        return false;
    }
    
public:
    bool isUgly(int n){
        return solve(n);
    }
};