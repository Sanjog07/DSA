
// see in notebook

// https://www.youtube.com/watch?v=L1u-R_s2Mok

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        bool hasOne = false;
        for(int i=0; i<n; i++){
            if(nums[i] == 1){
                hasOne = true;
                break;
            }
        }
        
        if(!hasOne){
            return 1;
        }
        
        if(n == 1){
            return 2;
        }
        
        for(int i=0; i<n; i++){
            if(nums[i] <= 0 || nums[i] > n){
                nums[i] = 1;
            }
        }   
        
        for(int i=0; i<n; i++){
            int x = abs(nums[i]);
            if(nums[x-1] > 0){
                nums[x-1] *= -1;
            }
        }  
        
        for(int i=1; i<n; i++){
            if(nums[i] > 0){
                return i+1;
            }
        }
        
        return n+1;
    }
};




class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int,bool> m;
        for(int i=0; i<n; i++){
            m[nums[i]] = true;
        }
        
        //int tar = *max_element(nums.begin(), nums.end());
        
        // for(int i=1; i<=INT_MAX; i++){
        //     if(m.find(i) == m.end()){
        //         return i;
        //     }
        // }
        
        //chhoti si optimization
        
        for(int i=1; i<=n+1; i++){
            if(m.find(i) == m.end()){
                return i;
            }
        }        
        
        return -1;
    }
};



// TLE

// class Solution {
// public:
//     int firstMissingPositive(vector<int>& nums) {
//         int n = nums.size();
        
//         vector<bool> present(INT_MAX, false); 
//         //unordered_map<int,bool> m;
//         for(int i=0; i<n; i++){
//             if(nums[i] > 0 && nums[i] != INT_MAX){
//                 present[nums[i]] = true;
//             }
//         }
        
//         //int tar = *max_element(nums.begin(), nums.end());
        
//         for(int i=1; i<INT_MAX; i++){
//             // if(m.find(i) == m.end()){
//             //     return i;
//             // }
//             if(present[i] == false){
//                 return i;
//             }
//         }
        
//         return INT_MAX;
//     }
// };