

// so jo STL wala pow(x,y) fnc hai vo -> double value return krta hai
// and x and y ki bhi value as double accept krta hai

// CURRENT SOLU IS FOR FAST POWER (notes mei hai fast power)
// not vo wala recursive fun(a,b) = fun(a,b-1);
// typical power nikalne wala

class Solution {
    
    double helper(double x, int n){
        if(n == 0){
            return 1;
        }
        
        double small = helper(x,n/2);
        
        small *= small;
        
        if(n%2 == 0){
            return small;
        }
        
        return x*small;
    }
    
public:
    double myPow(double x, int n) {
        if(n == 0){
            return 1;
        }
        double ans = helper(x,n);
        
        if(n < 0){
            ans = (1/ans);
        }
        
        return ans;
    }
};