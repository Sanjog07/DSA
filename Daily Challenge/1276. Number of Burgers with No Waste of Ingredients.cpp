class Solution {
public:
    vector<int> numOfBurgers(int t, int c) {
        if(t > 4*c || t < 2*c || t%2 != 0){
            return {};
        }
        
        // SEE HINT
        int a = t/2 - c;
        int b = 2*c - t/2;
        
        return {a,b};
    }
};