class Solution {
public:
    bool isPowerOfThree(int n){
        if(n == 0){
            return false;
        }
        if(n == 1){
            return true;
        }
        if(n%3 != 0){
            return false;
        }
        
        bool check = isPowerOfThree(n/3);
        if(check){
            return true;
        }
        
        return false;
    }
};