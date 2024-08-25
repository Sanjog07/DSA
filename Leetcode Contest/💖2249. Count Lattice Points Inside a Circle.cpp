
// https://leetcode.com/problems/count-lattice-points-inside-a-circle/discuss/1976815/Easy-C%2B%2B-code


class Solution {
public:
    int countLatticePoints(vector<vector<int>>& nums) {
        int n = nums.size();
        
        set<pair<int,int> > s;
        for(int i=0; i<n; i++){
            auto trip = nums[i];
            int x = trip[0];
            int y = trip[1];
            int r = trip[2];
            
            for(int i=-r; i<=r; i++){
                for(int j=-r; j<=r; j++){
                    if((i*i) + (j*j) <= r*r){
                        s.insert({x+i, y+j});
                    }
                } 
            }
        }
        
        return s.size();
    }
};