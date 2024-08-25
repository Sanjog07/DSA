




// https://www.youtube.com/watch?v=g6OxU-hRGtY

// see notebook


class Solution{
    
    int solve(int n){
        if(n == 1 || n == 0){
            return n;
        }
        
        int x = log2(n);
        int a = 1 << (x-1); // 2^(x-1)
        int b = 1 << x; // 2^x
        
        int ans = a*x + (n-b+1);
        ans += solve(n - b);
        
        return ans;
    }
    
public:
    int countBits(int n){
        return solve(n);
    }
};
