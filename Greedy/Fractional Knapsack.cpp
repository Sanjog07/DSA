#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<double, int> p1, pair<double, int> p2){
    return p1.first > p2.first;
}

double maximumValue (vector<pair<int, int>>& nums, int n, int w){
    vector<pair<double, int>> arr;

    for(int i=0; i<n; i++){
        auto p = nums[i];
        double val = (double)p.second/(double)p.first;
        arr.push_back({val, i});
    }

    sort(arr.begin(), arr.end(), cmp);
//     for(auto p: arr){
//         cout<<p.first<<" "<<p.second<<endl;
//     }
        
    double ans = 0;
    for(int i=0; i<n; i++){
        if(w == 0){
            return ans;
        }   
        auto p = arr[i];
        double val = p.first;
        int idx = p.second;

        if(w >= nums[idx].first){
            ans += (double)nums[idx].second;
            w -= nums[idx].first;
        }else{
            ans += (w * val);
            w = 0;
        }
    }

    return ans;
}