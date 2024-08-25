class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& nums) {
        int n = nums.size();
        
        vector<vector<string>> ans(n);
        
        // yha pe hume pta nhi tha ki ans vector ka size kya hoga
        // as hum ans ke indexes ko access kr rhe thhe 
        // na ki ans.push_back() krke -> jismei ans vector ka size 
        // initially na dena pde
        // so isliye humne n size de diya
        // but here ans ka size <= n (i.e max, n ho skta hai)
        // so last mei jitne bhi extra humne create kiye thhe
        // unhe pop_back() kr denge
        
        int cnt = -1;
        
        unordered_map<string,int> m;
        for(int i=0; i<n; i++){
            string str = nums[i];
            string ss = str;
            sort(ss.begin(), ss.end());
            
            if(m.find(ss) != m.end()){
                ans[m[ss]].push_back(str);
            }else{
                cnt++;
                m[ss] = cnt;
                ans[m[ss]].push_back(str);
            }
        }
        
        // ye extra wale delete kr diye
        int diff = n - (cnt+1);
        for(int i=0; i<diff; i++){
            ans.pop_back();
        }
        
        return ans;
    }
};