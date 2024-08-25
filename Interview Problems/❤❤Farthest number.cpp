class Solution{   
  public:
    vector<int> farNumber(int n,vector<int> nums){
        vector<int> ans(n);
        
        vector<int> arr(n);
        
        int mi = INT_MAX;
        for(int i=n-1; i>=0; i--){
            mi = min(mi, nums[i]);
            arr[i] = mi;
        }
        
        // make min suffix array i.e arr and apply BS on it
        for(int i=0; i<n; i++){
            int idx = lower_bound(arr.begin(), arr.end(), nums[i]) - arr.begin();
            
            // see  8 9 9 -> upper_bound kyu nhi
            if(idx <= i){//ye < wali condi acche se dekhna see 3 1 5 2 4 for ele == 2
                ans[i] = -1;
            }else{
                ans[i] = idx-1;
            }
        }
        
        return ans;
    }
};