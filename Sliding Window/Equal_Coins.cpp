#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl '\n'

void equalCoins(ll x, ll y){
    string ans = "";
		// un dono ko equal amount deni hai, coins koi bhi de skte hai i.e ek ko 2,2 and dusre ko 1,1,2 de skte hai(i.e amount same honi chahiye i.e 4 here)
    if(x%2 == 0 && x != 0){
        ans += "yes";
    }else if(x == 0 && y%2 == 0){
        ans += "yes";
    }else if(y == 0 && x%2 == 0){
        ans += "yes";
    }else{
        ans += "no";
    }
    
    cout<<ans;
    
    return;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll t;
	cin>>t;
	while(t--){
	    ll x,y;
	    cin>>x>>y;
	    
	    equalCoins(x,y);
	    cout<<endl;
	}

	return 0;
}
