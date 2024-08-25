#include <bits/stdc++.h>
using namespace std;

#define ll long long

// OPTIMIZED HAI YA NHI -> NHI PTA

vector<int> solution(vector<int> base2){
    
    ll no = 0; // base 10

    int n = base2.size();
    for(int i=0; i<n; i++){
        if(base2[i]){
            no += pow(2,i);
        }
    }

    vector<int> ans;
    while(no >= 6){
        ans.push_back(no%6);
        no /= 6;
    }
    ans.push_back(no);


    return ans;
}


int main() {
    
    vector<int> v{0,0,1,1,1,0,0,0,1,1,1,1,1,1};

    vector<int> solu = solution(v);
    for(auto x: solu){
        cout<<x<<" ";
    }

    return 0;
}
