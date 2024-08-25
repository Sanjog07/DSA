
int dp[602][102][102];

class Solution {
    
    int helper(int n,vector<string>& nums, int z, int o){
        if(n == 0 && z >= 0 && o >= 0){
            // vaise yha pe, z and o will always be +ve
            // bcz humne jyada z and o wale ele liye hi nhi
            return 0;
        } 
        if(dp[n][z][o] != -1){
            return dp[n][z][o];
        }
        
        string str = nums[n-1];
        int cntz = z;
        int cnto = o;
        
        for(int i=0; i<str.size(); i++){
            if(str[i] == '0'){
                cntz--;
            }else{
                cnto--;
            }
        }
        
        int ans1 = 0, ans2 = 0;
        if(cntz >= 0 && cnto >= 0){
            ans1 = 1 + helper(n-1, nums, cntz, cnto);
        }
        
        ans2 = helper(n-1, nums, z, o);
        
        return dp[n][z][o] = max(ans1, ans2);
    }
    
public:
    int findMaxForm(vector<string>& nums, int z, int o) {
        int n = nums.size();
        
        dp[n+1][z+1][o+1];
        memset(dp, -1, sizeof(dp));
        
        return helper(n, nums, z, o);
    }
};






