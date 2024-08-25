

	int maxSumIS(int arr[], int n){
	    // same as LIS
	    
	    if(n == 1){
	        return arr[0];
	    }
	    
	    //dp array ko given array wale elements se hi initialize kr do
	    vector<int> dp{arr, arr+n};
	    
	    int ans = dp[0];
	    for(int i=1; i<n; i++){
	        for(int j=i-1; j>=0; j--){
	            if(arr[i] > arr[j]){
	                dp[i] = max(dp[i], dp[j] + arr[i]);
	            }
	        }
	        
	        ans = max(ans,dp[i]);
	    }
	    
	    return ans;
	}