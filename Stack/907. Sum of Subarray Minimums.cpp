
// https://leetcode.com/problems/sum-of-subarray-minimums/discuss/1860714/C%2B%2B-oror-MONOTONIC-STACK-oror-NEXT-SMALLER-%2B-PREVIOUS-SMALLER-ELEMENT

//ISS QUES MEI MOD KAISE LGA KUCH ACCHE SE CLARITY NHI AAYI


int mod = 1e9 + 7;

// https://www.youtube.com/watch?v=9-TXIVEXX2w
// ismei thoda sa yaad krne ki cheez hai ->> jyada shi se smajh nhi aayi vo

 vector<int> nsr(vector<int> &arr){
     int n = arr.size();
     stack<int> s;
     s.push(n-1);
     vector<int> ans;
     
     ans.push_back(n);
     
     for(int i=n-2; i>=0; i--){
       while(!s.empty() && arr[s.top()] >= arr[i]){
         s.pop();
       }
       if(s.empty()){
         ans.push_back(n);
       }else{
         ans.push_back(s.top());
       }
       s.push(i);
     }
     reverse(ans.begin(), ans.end());
     return ans;
}

 vector<int> nsl(vector<int> &arr){
     int n = arr.size();
     stack<int> s;
     s.push(0);
     vector<int> ans;
     
     ans.push_back(-1);
     
     for(int i=1; i<n; i++){
       while(!s.empty() && arr[s.top()] > arr[i]){
         s.pop();
       }
       if(s.empty()){
         ans.push_back(-1);
       }else{
         ans.push_back(s.top());
       }
       s.push(i);
     }
     
     return ans;
}

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> a = nsr(arr);
        vector<int> b = nsl(arr);
        
        // for(int i=0; i<n; i++){
        //     cout<<b[i]<<" "<<a[i]<<endl;
        // }
        
        // jha pe elements repeat ho rhe hai vha thoda dhyaan dena 
        // hoga ki nsr and nsl kaise lene hai
        // so iske liye nsr ya nsl mei pop krte hue kisi bhi ek mei
        // equality lgayo and dusre mei na lgayo
        // here humne nsr mei equality lgayi hui hai and nsl mei nhi
        // iska ulta bhi kr skte thhe
        
        long long sum = 0;

        for(int i=0; i<n; i++){
            long long x = b[i];
            long long y = a[i];
            
            long long freq = ((i-x)%mod*(y-i)%mod)%mod;
            
            long long val = ((freq%mod) * (arr[i]%mod)) % mod;
            
            sum = (sum%mod + val%mod)%mod;
            
        }
        
        return sum;
    }
};