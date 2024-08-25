

// RECURSIVE SOLU
// neeche iterative wala hai

// SOLUTION LINK: https://www.youtube.com/watch?v=dzYq5VEMZIg

// notes bhi bnaye hue hai

class Solution {
    
    int helper(int n, int k){
        if(n == 1){
            return 0;
        }
        
        int x = helper(n-1, k); // chhoti problem se pucho ki safe position konsi hai.
        
        int y = (x+k)%n; // and then uss pos ko apni terms mei convert kr lo
        
        return y;
    }
    
public:
    int findTheWinner(int n, int k) {
        
        // SO THIS IS STANDARD JOSEPHUS PROBLEM
        
        // hum yha pe 0 ki terms mei helper fun likh rhe hai
        //as the conversion formula y = (x+k)%n works for starting with 0 not with 1
        
        // and last mei jo bhi ans aayega usmei +1 krke return kr denge
        // not in helper fnc but iss wale mei
        
        int ans = helper(n,k);
        
        return ans+1;

    }
};


// ITERATIVE SOLU

class Solution {
public:
    int findTheWinner(int n, int k) {
        //vector<int> ans(n+1);
        
        //ans[0] = 0;
        int ans = 0;
        for(int i=2; i<=n; i++){
            // int x = ans[i-1];
            // int y = (x+k)%n;
            
            ans = (ans+k)%i;
            //ans[i] = y;
        }
        
        //return ans[n-1]+1;
        return ans+1;
    }
};