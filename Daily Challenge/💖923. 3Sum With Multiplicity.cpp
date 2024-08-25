
int mod = 1e9 + 7;

// Very similar approch to 3-Sum

// https://leetcode.com/problems/3sum-with-multiplicity/discuss/1918476/C%2B%2B-oror-2-Pointer-oror-Simple-implementation-oror-Approach-similar-to-3-Sum-problem

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int tar) {
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        int ans = 0;
        // n-2 tk hi chalayo bcz triplets chahiye
        for(int i=0; i<n-2; i++){
            int l = i+1;
            int r = n-1;
            
            while(l < r){
                int sum = arr[i] + arr[l] + arr[r];
                if(sum == tar){
                    int cntl = 1, cntr = 1;
                    while(l < r && arr[l] == arr[l+1]){
                        cntl++;
                        l++;
                    }
                    while(l < r && arr[r] == arr[r-1]){
                        cntr++;
                        r--;
                    }    
                    
                    if(l != r){
                        ans = (ans%mod + (cntl%mod * cntr%mod)%mod)%mod;
                    }
                    
                    // Ye wala case thodi dhyaan se dekh lena
                    // ye iteration ke last last mei aayega
                    if(l == r){
                        // i.e nCr -> see this case [1,1,2,2,2,2]
                        ans = (ans%mod + (cntl%mod * (cntl-1)/2%mod)%mod)%mod;
                    }   
                    
                    l++;
                    r--;
                }else if(sum < tar){
                    l++;
                }else{
                    r--;
                }
            }
        }
        
        return ans;
    }
};