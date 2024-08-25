

// freq array Memory limit exceeded dega as nums[i] ki limit is 10^9

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int,int> m;
        
        for(int i=0; i<n; i++){
            m[nums[i]]++;
        }
        
        int cnt = 0;
        for(auto p: m){
            int ele = p.first;
            int freq = p.second;
            int tar = k - ele;
            
            if(ele == tar){
                int x = m[ele];
                cnt += x/2;
                m[ele] -= (2*x);
            }else{
                if(m.find(tar) != m.end()){
                    int x = min(m[ele], m[tar]);
                    cnt += x;

                    m[ele] -= x;
                    m[tar] -= x;                    
                }
            }
        }
        
        return cnt;
    }
};






// class Solution {
// public:
//     int maxOperations(vector<int>& nums, int k) {
        
//         int n = nums.size();
//         unordered_map<int, int> freqMap;
//         int ans = 0;
        
//         for(int i = 0 ; i < n ; i++){
            
//             if(freqMap[k - nums[i]] > 0){
//                 ans++;
//                 freqMap[k-nums[i]]--;
//             }else{
//                 freqMap[nums[i]]++;
//             }
            
//         }
        
//         return ans;
        
        
//     }
// };