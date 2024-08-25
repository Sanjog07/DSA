class Solution {
public:
    int numRescueBoats(vector<int>& arr, int lim) {
        int n = arr.size();
        
        // we're going to use 2-pointer approach
        
        sort(arr.begin(), arr.end());
        
        int s = 0;
        int e = n-1;
        
        int ans = 0;
        while(s <= e){
            int val = arr[s] + arr[e];
            if(val <= lim){
                s++;
                e--;
            }else{
                e--;
            }
            
            ans++;
        }
        
        return ans;
    }
};