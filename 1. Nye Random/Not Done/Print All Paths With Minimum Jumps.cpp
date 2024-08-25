#include <bits/stdc++.h>
using namespace std;

#define ll long long

typedef pair<int,string> pii;

vector<string> helper(int n,vector<int> &nums){       
    vector<int> dp(n,INT_MAX);
    
    dp[n-1] = 0;
    for(int i=n-2; i>=0; i--){
        int jumps = nums[i];
        for(int j=1; j<=jumps; j++){
            if((i+j) < n && dp[i+j] != INT_MAX){
                dp[i] = min(dp[i], dp[i+j] + 1);
            }
        }
    }
    
    int ans = dp[0];   
    
    vector<string> res;
    queue<pii> q;
    q.push({0,to_string(0)});
    
    while(!q.empty()){
        auto f = q.front();
        q.pop();
        
        int idx = f.first;
        string asf = f.second;
        
        if(idx == n-1){
            asf += ' .';
            res.push_back(asf);
            continue;
        }
        
        int req = dp[idx] - 1;
        int jumps = nums[idx];
        
        for(int j=1; j<=jumps; j++){
            if((idx+j) < n && dp[idx+j] == req){
                string temp = " -> " + to_string(idx+j);
                q.push({(idx+j), (asf + temp)});
            }
        }
    }
    
    cout<<ans<<endl;
    return res;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin>>n;
	
	vector<int> nums(n);
	for(int i=0; i<n; i++){
	    int x;
	    cin>>x;
	    nums[i] = x;
	}
	
	vector<string> solu = helper(n,nums);
	for(int i=0; i<solu.size(); i++){              
	    string str = solu[i];
	    cout<<str<<endl;
	}

	return 0;
}