

// thoda observation wala ques hai

// https://leetcode.com/problems/russian-doll-envelopes/discuss/1674324/C%2B%2B-O(NlogN)-and-O(N2)-Approach

        // O(n^2) approch to bilkul LIS jaisi hai
        // bss starting mei nums ko sort kr lena
        // as here koi subseq vgerh nhi leni
        // and we can pich the elements in any order -> khi se bhi
        // that's why we can sort it
        
        //so we'll do O(NlogN) approch



// iss tarah se hum 2 vector ke basis pe sort kr skte hai
bool cmp(vector<int> &a, vector<int> &b){
    // width ke basis pe sort krenge
    if(a[0] == b[0]){
        // agr width equal hai to jiski height jyada hai
        //usko pehle rkhenge
        return a[1] > b[1];
    }
    
    return a[0] < b[0];
}

class Solution {
    
public:
    int maxEnvelopes(vector<vector<int>>& nums) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end(), cmp);
        
        vector<int> dp;
        int len = 1;
        
        // iss ques mei ye ek imp pt hai ki jb widths equal hai
        // tb jiski height jyada hai vo pehle aayega
        // naa ki jiski height small hai
        // [[5,4],[6,4],[6,7],[2,3],[6,5],[7,6]]
        // dry run above eg -> smajh aa jayega
        
        dp.push_back(nums[0][1]);
        for(int i=1; i<n; i++){
            
            int val = nums[i][1]; // i.e height at ith idx
            auto it = lower_bound(dp.begin(), dp.end(), val);
            int idx = it - dp.begin();
            
            if(it == dp.end()){
                len++;
                dp.push_back(val);
            }else{
                dp[idx] = val;
            }
        }
        
        return len;
        //return dp.size();
    }
};