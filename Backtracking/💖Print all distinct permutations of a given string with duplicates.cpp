
// iss wale duplicates bhi handle ho jayege
class Solution{
	vector<string> ans;
	string s = "";
	void solve(string &str,int n, vector<int> &vis){
	    if(s.length() == str.length()){
	        ans.push_back(s);
	        return;
	    }
	    
	    for(int i=0; i<n; i++){
	        
	        if((vis[i] == 1) || (i != 0 && str[i] == str[i-1] && vis[i-1] == 0)){
                
                // ye vis[i-1] == 0 -> ye cheez hi identify krna sbse
                // imp hai
	            continue;
	        }	        
	        //if(!vis[i]){
              char ch = str[i];
    	        s += ch;
    	        vis[i] = 1;
    	        
    	        solve(str, n, vis);
    	        
    	        vis[i] = 0;
    	        s.pop_back();	            
	        //}
	    }
	}
	
	public:
		vector<string>find_permutation(string str){
		    int n = str.size();
		    
		    vector<int> vis(n, 0);
		    
		    sort(str.begin(), str.end());
		    solve(str, n, vis);
		    
		    return ans;
		}
};

