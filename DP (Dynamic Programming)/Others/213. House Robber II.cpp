class Solution {
    
    int dp[102];
    int solve(vector<int>& nums,int n,int i){
        if(i > n){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        
        int a = nums[i] + solve(nums,n,i+2);
        int b = solve(nums,n,i+1);
        
        return dp[i] = max(a,b);
    }
    
public:
    int rob(vector<int>& nums){
        
        // iss circular aur normal wale mei ek hi diff aayega
        // ki jb hum i == 0 ko consider krenge uss case 
        // mei hum i == n-1 wala element nhi le skte 
        // bcz vo dono adjacent honge
        // aur bilkul same hoga -> without circular wale ki tarah
        // but ye theorotically tha 
        // implement krte hue thodi diff approach hai
        
        // implement krte hue hum 2 parts mei ques ko solve krenge
        // 1st part mei 0 to n-2 wale elements and 2nd part mei 
        // 1 to n-1 wale elements
        // as jb hum i==0 se start to n-1 element humne chahiye 
        // hi nhi thha -> to usse remove hi kr diya -> in 1st part
        
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        
        dp[n];
        memset(dp, -1, sizeof dp);
        
        int a = solve(nums,n-2,0);
        
        // so yha pe 2 dp array bnani pdegi -> ya fir purani wali 
        // ko hi firse initilize kr do
        
        // and zaruri nhi hai hr jagha 2 dp bnani pde aisi aisi situation mei -> as yha pe to starting pt ke saath saath ending pt bhi change ho gye thhe isliye dusri dp ki zarurat thi
        
        memset(dp, -1, sizeof dp);
        int b = solve(nums,n-1,1);
        
        return max(a,b);
    }
};