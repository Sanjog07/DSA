
// https://www.youtube.com/watch?v=LDFZm4iB7tA

class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        
        deque<int> minq;  // increasing order
        deque<int> maxq;  // decreasing order
        // deque mei idx store kr rhe hai
        
        int ans = 0;
        
        int i=0, j=0;
        while(j < n){
            // = isliye liya bcz iss loop ke baad usko push kr hi rhe hai
            while(!minq.empty() && nums[minq.back()] >= nums[j]){
                minq.pop_back();
            }
            minq.push_back(j);
            
            while(!maxq.empty() && nums[maxq.back()] <= nums[j]){
                maxq.pop_back();
            }
            maxq.push_back(j);    
            
            int mie = nums[minq.front()];
            int mae = nums[maxq.front()];
            
            if((mae-mie) > k){
                i++;
                if(i > minq.front()){
                    minq.pop_front();
                }
                if(i > maxq.front()){
                    maxq.pop_front();
                }                
            }else{
                ans = max(ans, (j-i+1));
                j++;
            }
        }
        
        return ans;
    }
};