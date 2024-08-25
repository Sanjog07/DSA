
#include<bits/stdc++.h>

bool cmp(vector<int> v1, vector<int> v2){
    return v1[1] > v2[1];
}

int jobScheduling(vector<vector<int>> &nums){
    int n = nums.size();

    int mx = INT_MIN;
    for(int i=0; i<n; i++){
        mx = max(mx, nums[i][0]);
    }

    vector<bool> arr(mx+1, true);

    sort(nums.begin(), nums.end(), cmp);

    int ans = 0;
    for(int i=0; i<n; i++){
        int val = nums[i][1];
        int dead = nums[i][0];

        for(int j=dead; j>=1; j--){
            if(arr[j] == true){
                arr[j] = false;
                ans += val;
                break;
            }
        }        
    }

    return ans;
}
