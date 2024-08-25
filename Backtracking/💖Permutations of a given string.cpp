
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





class Solution{
	vector<string> ans;
	string s = "";
	void solve(string &str,int n, vector<int> &vis){
	    if(s.length() == str.length()){
	        ans.push_back(s);
	        return;
	    }
	    
	    for(int i=0; i<n; i++){
            if(!vis[i]){
                char ch = str[i];
    	        s += ch;
    	        vis[i] = 1;
    	        
    	        solve(str, n, vis);
    	        
    	        vis[i] = 0;
    	        s.pop_back();	            
	        }
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



// class Solution{
//     vector<string> ans;
    
//     void solve(int i,string &str,int n){
//         if(i == n){
//             ans.push_back(str);

//             return;
//         }
        
//         for(int j=i; j<n; j++){
//             swap(str[j], str[i]);
            
//             solve(i+1, str, n);

//             swap(str[j], str[i]);
//         }
//     }    
// 	public:
// 		vector<string>find_permutation(string str){
//             int n = str.size();
            
            
//             // as hum ans ko sort kr rhe hai -> ans can be of n! length
//             // so approach would be sort the i/p string and ye swap wali
//             // approach na lagyo simple vo visited or substr wali lgado
            
//             sort(str.begin(), str.end());
//             solve(0, str, n);
            
//             sort(ans.begin(), ans.end());
//             return ans;		    
// 		}
// };