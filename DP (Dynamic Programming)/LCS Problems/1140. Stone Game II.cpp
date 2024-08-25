
// https://www.youtube.com/watch?v=6hu5G-abkdg
// isse pehle stone game iii wala dekh lena

class Solution {
    
    int dp[101][202]; // ye 202 kaise li hai nhi pta
    int solve(vector<int>& arr,int n,int i,int m){
        if(i >= n){
            return 0;
        }
        if(dp[i][m] != -1){
            return dp[i][m];
        }
        
        int solu = INT_MIN;
        int val = 0;
        for(int j=i; j<(i+2*m); j++){
            if(j < n){
                val += arr[j];
                int ans = val - solve(arr,n,j+1,max(m, (j-i+1)));
                solu = max(solu, ans);
            }
        }
        
        return dp[i][m] = solu;
    }
    
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        
        memset(dp, -1, sizeof dp);
        
        int val = solve(piles,n,0,1);
        int total = 0;
        total = accumulate(piles.begin(), piles.end(),total);
        
        int alice = (val+total)/2;
        
        return alice;
    }
};