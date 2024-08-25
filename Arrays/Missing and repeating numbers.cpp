#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &nums, int n){

        int mis,rep;
        for(int i=0; i<n; i++){
            if(nums[abs(nums[i])-1] > 0){
                nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
            }else{
                rep = abs(nums[i]);
            }
        }

        for(int i=0; i<n; i++){
            if(nums[i] > 0){
                mis = i+1;
            }
        }

        return {mis, rep};
}
