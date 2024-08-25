class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        // YE PEPCODING WALA SOLU HAI ISSE TLE AA RHI HAI
        
//         int n = nums.size();
        
//         // we'll take help of next greater element to the right (NGR)
        
//         vector<int> ngr; // will store ngr (uska idx) of all the elements in it
//         stack<int> s;
        
//         s.push(n-1); // hum value nhi idx push kr rhe hai
//         ngr.push_back(n); // -1 nhi nums ki length push krenge
        
//         for(int i=n-2; i>=0; i--){
//             while(!s.empty() && nums[i] >= nums[s.top()]){
//                 s.pop();
//             }
            
//             if(s.empty()){
//                 ngr.push_back(n);
//             }else{
//                 ngr.push_back(s.top());
//             }
            
//             s.push(i);
//         }
        
//         vector<int> ans;
//         int j = 0;
//         for(int i=0; i<n-k; i++){
//             if(j < i){
//                 j = i;
//             }
            
//             while(ngr[j] < i+k){
                
//                 j = ngr[j];
                
//                 // i+k means vo current window ke andar hi hai
//                 // and isse liye humne ngr -1 na leke uski length li
//             }
            
//             ans.push_back(nums[j]);
//         }
        
//         return ans;
        
        
        // YE STRIVER WALA SOLU HAI
        // using deque
        
        // i.e hum apni deque mei decreasing order maintain krenge
        // and iterate krte time -> iss element se chhote jitne bhi elements hai deque mei (peeche se) unhe delete krdo deque se
        
        vector<int> ans;
        deque<int> q;
        
        int n = nums.size();
        
        for(int i=0; i<k; i++){
            while(!q.empty() && nums[q.back()] < nums[i]){
                q.pop_back();
            }
            q.push_back(i);
        }
        ans.push_back(nums[q.front()]);
        
        for(int i=k; i<n; i++){
            // out of bound elements wali condition
            if(q.front() < (i-k+1)){
                q.pop_front();
            }
            
            // starting mei chhote elements wali condi.
            while(!q.empty() && nums[q.back()] < nums[i]){
                q.pop_back();
            }
            q.push_back(i);
            
            ans.push_back(nums[q.front()]);
        }
        
        return ans;
    }
    
};