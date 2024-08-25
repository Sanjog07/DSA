

// https://www.youtube.com/watch?v=OnVtJ_7T-6s

class Solution {
public:
    vector<int> avoidFlood(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n,1);
        
        unordered_map<int,int> m;
        set<int> s;
        
        for(int i=0; i<n; i++){
            int val = arr[i];
            if(val == 0){
                s.insert(i);
            }else{
                if(m.find(val) != m.end()){
                    auto it = s.upper_bound(m[val]);
                    if(it != s.end()){
                        ans[*it] = val;
                        s.erase(it);
                    }else{
                        return {};
                    }
                }
                m[val] = i;
                ans[i] = -1;
            }
        }
        
        return ans;
    }
};