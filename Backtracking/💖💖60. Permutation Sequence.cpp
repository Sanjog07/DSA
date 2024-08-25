
// https://www.youtube.com/watch?v=wT7gcXLYoao&list=PLgUwDviBIf0rQ6cnlaHRMuOp4H_D-7hwP&index=7

class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        
        vector<int> nums;
        for(int i=1; i<n; i++){
            fact *= i;
            nums.push_back(i);
        }
        
        nums.push_back(n);
        k--;
        
        string ans = "";
        while(true){
            int x = k/fact;
            ans += to_string(nums[x]);
            
            nums.erase(nums.begin() + x);
            if(nums.size() == 0){
                break;
            }

            k %= fact;
            fact /= nums.size();
            
        }
        
        return ans;
    }
};