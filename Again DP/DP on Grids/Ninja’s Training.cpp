#include<bits/stdc++.h>
using namespace std;


// Question
//https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

int dp[100002][4];

int helper(int row, int last, vector<vector<int>> &nums, int n){
    if(row >= n){
        return 0;
    }
    if(last != -1 && dp[row][last] != -1){
        return dp[row][last];
    }

    int res = INT_MIN;
    for(int j=0; j<3; j++){
        if(j != last){
            int ans = nums[row][j] + helper(row+1, j, nums, n);
            res = max(res, ans);
        }
    }
    return dp[row][last] = res;
}

int ninjaTraining(int n, vector<vector<int>> &nums){

    dp[n+1][4];
    memset(dp, -1, sizeof(dp));

    int solu = helper(0, -1, nums, n);

    return solu;
}