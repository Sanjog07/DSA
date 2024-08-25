    
    
  /////////// O(n) approach //////////////
    
class Solution{
	public:
		int AlternatingaMaxLength(vector<int>&nums){
		   int n = nums.size();
		   
		   int mi = 1;
		   int ma = 1;
		   
		   for(int i=1; i<n; i++){
		       if(nums[i] > nums[i-1]){
		           ma = mi+1;
		       }else if(nums[i] < nums[i-1]){
		           mi = ma + 1;
		       }
		   }
		   
		   return max(ma, mi);
		}
};



/////////  O(n^2) approach ////////////////

int dp[100002][2];
class Solution{
    
    int solve(vector<int>&nums,int n){
        
		for(int i=1; i<n; i++){
		    int val = nums[i];
		    for(int j=i-1; j>=0; j--){
		        if(val > nums[j]){
		            dp[i][0] = max(dp[i][0], dp[j][1] + 1);
		        }
		        if(val < nums[j]){
		            dp[i][1] = max(dp[i][1], dp[j][0] + 1);
		        }
		    }
		}  
		
		return max(dp[n-1][0], dp[n-1][1]);
    }
    
	public:
	
		int AlternatingaMaxLength(vector<int>&nums){
		    int n = nums.size();
		    
		    dp[n][2];
		    for(int i=0; i<n; i++){
		        for(int j=0; j<2; j++){
		            dp[i][j] = 1;
		        }
		    }
		    
		    return solve(nums, n);

		}

};