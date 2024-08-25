
// https://leetcode.com/problems/find-players-with-zero-or-one-losses/discuss/1932738/Simple-code-in-c%2B%2B-with-explanation


// i.e hum map ki jagha array or vector ka use kaiose kr skte hai
// to get better T.C


class Solution {
    
public:
    vector<vector<int>> findWinners(vector<vector<int>>& nums) {
        int n = nums.size();
        
        vector<int> m(100001, 0);
        
        for(auto p: nums){
            m[p[0]]++;
        }
        for(auto p: nums){
            if(m[p[1]] > 0){
                m[p[1]]= 0;
            }
            m[p[1]]--;
        }
        
        vector<int> a, b;
        for(int i=1; i<=1e5; i++){
            if(m[i] > 0){
                a.push_back(i);
            }else if(m[i] == -1){
                b.push_back(i);
            }
        }
        
        return {a, b};
    }
};



// class Solution {
// public:
//     vector<vector<int>> findWinners(vector<vector<int>>& mat) {
//         vector<vector<int>> ans;
//         map<int,int> m1,m2;
        
//         for(auto p: mat){
//             m1[p[0]]++;
//             m2[p[1]]++;
//         }
        
//         vector<int> v1, v2;
//         for(auto p: m1){
//             if(m2.find(p.first) == m2.end()){
//                 v1.push_back(p.first);
//             }
//             // else if(m2.find(p.first) != m2.end() && m2[p.first] == 1){
//             //     v2.push_back(p.first);
//             // }
//         }
//         for(auto p: m2){
//             if(p.second == 1){
//                  v2.push_back(p.first);
//             }
//         }
        
//         ans.push_back(v1);
//         ans.push_back(v2);
        
//         return ans;
//     }
// };