
// https://leetcode.com/problems/max-consecutive-ones-iii/discuss/2032911/C%2B%2B-or-Sliding-Window-or-Easy-Solution


class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        
        int i=0, j=0;
        
        int ans = 0;
        int temp = k;
        while(j < n){
            if(nums[j] == 1){
                j++;
            }else if(nums[j] == 0 && temp > 0){
                temp--;
                j++;
            }else{
                ans = max(ans, (j-i));
                while(temp <= 0){
                    if(nums[i] == 0){
                        temp++;
                    }
                    i++;
                }
            }
        }
        
        // see [0,0,0,1] & 4
        ans = max(ans, (j-i));
        
        return ans;
    }
};