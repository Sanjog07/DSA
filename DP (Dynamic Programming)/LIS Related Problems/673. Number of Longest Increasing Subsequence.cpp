class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> len(n, 1); // length of LIS till now
        vector<int> cnt(n, 1); // no of LIS till now
        
        for(int i=1; i<n; i++){
            for(int j=i-1; j>=0; j--){
                if(nums[i] > nums[j]){
                    int x = len[j] + 1;
                    if(len[i] < x){
                        len[i] = x;
                        cnt[i] = cnt[j];
                    }else{
                        // it means ki ye j wala element i se chhota
                        // to hai but len array mei isse ans update 
                        // nhi ho rha it means pehle koi element
                        // usko update kr chuka hai
                        // so current wala element ek aur nyi
                        // increasing sequence bnayega
                        
                        if(len[i] == len[j] + 1){ 
                            cnt[i] += cnt[j];
                        }
                    }
                }
            }
        }
        
        int me = INT_MIN;
        for(auto a: len){
            me = max(me, a);
        }
        
        int solu = 0;
        for(int i=0; i<n; i++){
            if(len[i] == me){
                solu += cnt[i];
            }
        }
        
        return solu;
    }
};