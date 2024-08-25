

// ques -> https://www.geeksforgeeks.org/largest-rectangular-sub-matrix-whose-sum-0/

#include<bits/stdc++.h>
using namespace std;

// in type ke ques mei sirf ye wala fnc change hota hai
int maxLen(vector<int> a){
    unordered_map<int,int> m;
    int n = a.size();
    int pre = 0;
    int len = 0;
    
    for(int i=0; i<n; i++){
        pre += a[i];
        if(pre == 0){
            len = max(len , i+1);
        }else if(m.find(pre) != m.end()){
            len = max(len , i - m[pre]);
        }else{
            m[pre] = i;
        }
    }
    return len;
}

// we've to return the size of the matrix
int largestSubmatrixWithSumZero(vector<vector<int>> &mat, int r, int c){
    int ans = 0;
    for(int start=0; start<r; start++){
        
        vector<int> v(c, 0);
        for(int i=start; i<r; i++){
            for(int j=0; j<c; j++){
                v[j] += mat[i][j];
            }
            
            int row = (i - start + 1);
            int col = maxLen(v); 
            ans = max(ans, row*col);
        }
    }
    return ans;
}    
