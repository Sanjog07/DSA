
// https://www.youtube.com/watch?v=RG5rWV6in38&list=TLGGGO0ecV5KdhkxOTA1MjAyMg

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl '\n'

unordered_map<char,int> m;

ll getVal(string str){
    ll n = str.length();
    
    ll num = m[str[0]];
    for(ll i=1; i<n; i++){
        num = ((num*10) + m[str[i]]);
    }
    return num;
    // string num = "";
    // for(ll i=0; i<n; i++){
    //     num += (m[str[i]] - '0');
    // }
    
    // return stoll(num);
}

void solve(int i, string &uni, vector<bool> &vis, string a, string b, string c){
    
    if(i == uni.length()){
        ll x = getVal(a);
        ll y = getVal(b);
        ll z = getVal(c);

        //cout<<x<<" "<<y<<" "<<z<<endl;
        
        if((x+y) == z){
            for(char ch='a'; ch<='z'; ch++){
                if(m.find(ch) != m.end()){
                    cout<<ch<<"-"<<m[ch]<<" ";
                }
            }
            cout<<endl;
        }
        
        return;
    }
    
    char ch = uni[i];
    
    for(int j=0; j<=9; j++){
        if(vis[j] == false){
            vis[j] = true;
            m[ch] = j;
            solve(i+1, uni, vis, a, b, c);
            vis[j] = false;
            m[ch] = -1;        
        }
    }
    
    return;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	m.clear();
	
	string a, b, c;
	cin>>a;
	cin>>b;
	cin>>c;
	
    string uni = ""; // the unique string
	//unordered_set<char> s;
	for(int i=0; i<a.length(); i++){
	    // s.insert(a[i]);
        char ch = a[i];
	    if(m.find(ch) == m.end()){
            uni += ch;
	        m[ch] = -1;
	    }        
	}
	for(int i=0; i<b.length(); i++){
	    // s.insert(b[i]);

        char ch = b[i];
	    if(m.find(ch) == m.end()){
            uni += ch;
	        m[ch] = -1;
	    }         
	}
	for(int i=0; i<c.length(); i++){
	    // s.insert(c[i]);

        char ch = c[i];
	    if(m.find(ch) == m.end()){
            uni += ch;
	        m[ch] = -1;
	    }         
	}
	
	// for(auto ele: s){
	//     uni += ele;
	// }

	// for(int i=0; i<uni.length(); i++){
	//     char ch = uni[i];
	//     if(m.find(ch) == m.end()){
	//         m[ch] = -1;
	//     }
	// }    

    //cout<<uni<<endl;
	
	vector<bool> vis(10, false);
	
	solve(0, uni, vis, a, b, c);

	return 0;
}