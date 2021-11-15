#include <bits/stdc++.h>
using namespace std;

void regSystem(vector<string> &v,int n){
  unordered_map<string,int> freq;

  for(int i=0; i<n; i++){
    freq[v[i]]++;
    if(freq[v[i]] == 1){
      cout<<"OK"<<endl;
    }else{
      string x = v[i] + to_string(freq[v[i]] - 1);
      cout<<x<<endl;
    }
  }
}

int main(){
	int n;
  cin>>n;

  vector<string> v;
  for(int i=0; i<n; i++){
    string s;
    cin>>s;
    v.push_back(s);
  }

  regSystem(v, n);

	return 0;
}