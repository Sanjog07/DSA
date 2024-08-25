#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl '\n'


// https://www.youtube.com/watch?v=Q1fLW_zQr3M&list=TLGGtvAcdwLvPyoxNzA1MjAyMg


////////////////////////////////////////////

// ye ques aise pick -- non-pick technique se solve nhi hoga bcz hum ye guess nhi kr skte ki vo jo min diff hoga vo kitna hoga

///////////////////////////////////////////

// vector<vector<int>> solu;
// vector<int> ans;


// void helper(int i,vector<int> &arr,int n,int tar){
//     if(tar == 0){
//         if((n%2 == 0 && ans.size() == n/2) || (n%2 != 0 && ans.size() == (n+1)/2)){
            
//             solu.push_back(ans);
//             //ans.pop_back();
//         }
        
//         return;
//     }
//     if(i == n){
//         return;
//     }
//     if(tar < 0){
//         return;
//     }
    
//     // we'll apply pick -- non-pick technique
//     if(tar >= arr[i]){
//         ans.push_back(arr[i]);
//         helper(i+1, arr, n, tar-arr[i]);
//         ans.pop_back();
//     }
    
//     helper(i+1, arr, n, tar);
    
//     return;
// }


// void tugOfWar(vector<int> &arr, int n){
// 	int sum = 0;
// 	sum = accumulate(arr.begin(), arr.end(), sum);
	
// 	int tar = sum - sum/2;
	
// 	helper(0, arr, tar);
	
// 	return;
// }

//////////////////////////////////////////////////


// i.e hr ele ke pass 2 opt hai ya to, go to subset 1 or go to subset 2

vector<int> ans1, ans2;
int val = INT_MAX;

void solve(int i, vector<int> &arr, int n, vector<int> &a, vector<int> &b, int sa, int sb){
    
    if(i == n){
        int diff = abs(sa-sb);
        if(diff < val){
            val = diff;
            ans1 = a;
            ans2 = b;

        }
        
        return;
    }
    
    
    if(a.size() < (n+1)/2){ // (n+1)/2 se odd and even wale dono check ho jayege
        a.push_back(arr[i]);
        solve(i+1, arr, n, a, b, sa+arr[i], sb);
        a.pop_back();
    }
    
    if(b.size() < (n+1)/2){
        b.push_back(arr[i]);
        solve(i+1, arr, n, a, b, sa, sb+arr[i]);
        b.pop_back();
    }    
}


int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	vector<int> arr;
	int n;
	cin>>n;
	
	for(int i=0; i<n; i++){
	    int x;
	    cin>>x;
	    arr.push_back(x);
	}
	
	vector<int> a, b;
	solve(0, arr, n, a, b, 0, 0);
	
    for(int i=0; i<ans1.size(); i++){
        cout<<ans1[i]<<" ";
    }
    cout<<endl;
    for(int i=0; i<ans2.size(); i++){
        cout<<ans2[i]<<" ";
    }  
    
    
	return 0;
}