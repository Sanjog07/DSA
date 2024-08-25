
// https://www.youtube.com/watch?v=iEZbDcO55C4

// see notebook

#define ll long long

class Solution {
public:
    int minimumLines(vector<vector<int>>& nums) {
        int n = nums.size();
        if(n == 1){
            // 2 pts se 1 line bnti hai
            return 0;
        }
        
        // sort on the basis of days
        sort(nums.begin(), nums.end()); 
        
        ll oldx = nums[0][0];
        ll oldy = nums[0][1];
        
        ll curx = nums[1][0];
        ll cury = nums[1][1]; 
        
        
        
        ll oldn = cury - oldy;  // slope ka numerator
        ll oldd = curx - oldx; // slope ka denominator
        
        ll cnt = 1;
        for(int i=2; i<n; i++){
            curx = nums[i][0];
            cury = nums[i][1];
            
            ll curn = cury - oldy;
            ll curd = curx - oldx;
            
            if(oldn*curd == oldd*curn){
                // i.e there slopes are equal
                continue;
            }else{
                cnt++;
                oldx = nums[i-1][0];
                oldy = nums[i-1][1];
                
                oldn = cury - oldy;
                oldd = curx - oldx;
            }
        }
        
        return cnt;
    }
};





