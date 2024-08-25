class Solution {
public:
    bool isPowerOfTwo(double n) {
        // base case
        //cout<<n<<"->";
        if(n == 0){
            return false;
        }
        if(n == 1){
            return true;
        }
        
        // check if n/2 is a power of 2 or not
        double x = (double)n/2.0;
        //cout<<x<<" ";
        bool half = isPowerOfTwo(x);
        if(half){
            return true;
        }
        
        return false;
    }
};