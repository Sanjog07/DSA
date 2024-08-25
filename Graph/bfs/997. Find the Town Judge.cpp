
//https://leetcode.com/problems/find-the-town-judge/discuss/1987326/EASY-C%2B%2B-SOLUTION-or-OUT-DEGREE-or-IN-DEGREE


class Solution {
public:
    int findJudge(int n, vector<vector<int>>& nums) {
        // it seems like Celebrity problem
        // but isko uss tarah se implement nhi kr skte
        // as ismei 2d array nhi given hai
        
        // int freq[n+1] = {0};
        vector<int> freq(n+1, 0);
        for(auto p: nums){
            freq[p[1]]++;
        }
        
        int pot = -1;
        for(int i=1; i<=n; i++){
            int val = freq[i];
            if(val == n-1){
                pot = i;
                break;
            }
        }
        
        for(auto p: nums){
            if(p[0] == pot){
                return -1;
            }
        }
        
        return pot;
    }
};