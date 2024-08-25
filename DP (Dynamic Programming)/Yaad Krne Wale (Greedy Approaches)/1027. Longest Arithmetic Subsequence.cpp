
//https://www.youtube.com/watch?v=Lm38EAoDc7c

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 2){
            return 2;
        }
        
        vector<unordered_map<int,int> > dp(n);
        
        // code ke saath saath ye explaination dekh lena
        
        // here dp[i] will store ki -> iss particular element
        // pe pichle elements se kitne kitne diff aa skte hai
        // aur un sabhi different differences ko map mei store kiya hai
        // eg [9,4,7,2,10]
        // ismei jb 4(i) se 7(j) pe jayege -> then 7 ke map mei                 //  3 (i.e 7 - 4) store kr denge
        // and when 7 ka loop chalayege i.e 7 is i, and jb usse 10 pe phuchenge i.e 10 is j -> tb firse diff = 3 aayega (i.e 10 - 7)
        // and this is showing that there is a sequence
        // i.e 4->7->10
        // so if condi mei hum yhi check kr rhe hai ki agr jo diff
        // ab aaya hai vo pehle se hi mere wale map mei store hai
        // to length ko increase kro
        
        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int diff = nums[i] - nums[j];
                if(dp[i].find(diff) != dp[i].end()){
                    dp[j][diff] = dp[i][diff] + 1;
                }else{
                    dp[j][diff] = 2;
                }
                
                ans = max(ans, dp[j][diff]);
            }
        }

        
        return ans;
    }
};