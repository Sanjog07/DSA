class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        
        // cnt-- krte hue hum elements ko counter-balance kr rhe hai
        // but as majority ele, n/2 times se jyada baar present hai
        // to usko at last koi counter-balance nhi kr payega
        // and it'll the ans
        
        int cnt = 0, res;
        for(int i=0; i<n; i++){
            if(cnt == 0){
                res = nums[i];
            }
            if(nums[i] == res){
                cnt++;
            }else{
                cnt--;
            }
        }
        
        return res;
    }
};




