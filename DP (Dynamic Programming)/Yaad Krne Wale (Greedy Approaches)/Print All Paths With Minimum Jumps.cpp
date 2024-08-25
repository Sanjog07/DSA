#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=phgjL7SbsWs&list=PL-Jc9J83PIiEZvXCn-c5UIBvfT8dA-8EG&index=5

void solve(vector<int> nums){
    int n = nums.size();
    vector<int> dp(n, INT_MAX-1);

    dp[n-1] = 0;
    for(int i=n-2; i>=0; i--){
        int jumps = nums[i];
        for(int j=1; j<=jumps; j++){
            if((i+j) < n){
                dp[i] = min(dp[i], dp[i+j] + 1);
            }
        }
    }

    cout<<dp[0]<<endl;
    queue<pair<int,string> > q;
    string s = "0 ";
    q.push({0, s});   

    while(!q.empty()){
        auto it = q.front();
        int i = it.first;
        if(i == n-1){
            cout<<it.second<<"."<<endl;
        }
        q.pop();

        int jumps = nums[i];

        for(int j=1; j<=jumps; j++){
            if((i+j) < n && dp[i+j] == dp[i]-1){
                q.push({(i+j), it.second + "-> " + to_string(i+j) + " "});
            }
        }
    } 

}


int main() {
    
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    solve(v);

    return 0;
}
