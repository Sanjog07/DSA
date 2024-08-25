
#define ll long long

    bool cmp(pair<ll,ll> &a, pair<ll,ll> &b){
        if(a.first == b.first){
            return a.second > b.second;
        }
        
        return a.first < b.first;
    }

class Solution {

public:
    ll maximumImportance(int n, vector<vector<int>>& nums) {
        //int n = nums.size();
        
        vector<int> freq(n, 0);
        for(auto p: nums){
            int x = p[0];
            int y = p[1];
            
            freq[x]++;
            freq[y]++;
        }
        
        vector<pair<ll,ll>> vec;
        for(int i=0; i<n; i++){
            vec.push_back({freq[i], i});
        }
        
        sort(vec.begin(), vec.end(), cmp);
        
        vector<ll> ans(n);
        
        int cnt = 1;
        for(auto p: vec){
            ans[p.second] = cnt;
            cnt++;
        }
        
        ll res = 0;
        for(auto v: nums){
            int x = v[0];
            int y = v[1];
            
            res += (ans[x] + ans[y]);
        }
        
        return res;
    }
};