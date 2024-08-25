class Solution{
  public:
    vector <int> countDistinct (int nums[], int n, int k){
        vector <int> ans;
        vector <int> freq(100001,0);
        
        int cnt =0;
        for(int i=0;i<k; i++){
            if(freq[nums[i]] == 0){
                cnt++;
            }
            freq[nums[i]]++;
        }
        ans.push_back(cnt);
        
        for(int i=k; i<n; i++){
            int val = nums[i-k];
            if(freq[val] == 1){
                cnt--;
            }
            freq[val]--;
            
            if(freq[nums[i]] == 0){
                cnt++;
            }
            freq[nums[i]]++;    
            
            ans.push_back(cnt);
        }
        
        return ans;
    }
};