

// https://www.codingninjas.com/codestudio/problems/1115652?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0


// same as count subarrays with sum k

#include <bits/stdc++.h> 
    int subarraysXor(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int,int> m;
        int pre = 0, cnt = 0;
        
        for(int i=0; i<n; i++){
            pre ^= nums[i];
            
            if(pre == k){
                cnt++;
            }
            if(m.find(pre ^ k) != m.end()){
                cnt += m[pre ^ k];
            }
            
            m[pre]++;
        }
        
        return cnt;
    }