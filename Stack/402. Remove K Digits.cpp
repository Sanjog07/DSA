class Solution {
public:
    string removeKdigits(string str, int k) {
        int n = str.length();
        if(n == k){
            return "0";
        }
        
        string ans = "";
        stack<int> s;
        s.push(str[0] - '0');
        
        int cnt = 0; 
        int pvt = -1;
        for(int i=1; i<n; i++){
            if(pvt != -1){
                break;
            }
            char ch = str[i];
            int val = ch - '0';
            
            while(!s.empty() && s.top() > val){
                s.pop();
                cnt++;
                if(cnt == k){
                    pvt = i;
                    break;
                }
            }
            
            s.push(val);
            
        }
        
        // if even after this the cnt < k,it means we've to remove
        // characters from the back
        int rem = (k - cnt);
        while(rem--){
            s.pop();
        }
        
        while(!s.empty()){
            ans += to_string(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        
        // jo baaki bache hue characters hai string mei vo as it is 
        // daal do
        if(pvt != -1){
            for(int i=pvt+1; i<n; i++){
                char ch = str[i];
                ans += ch;
            }
        }
        
        // remove the leading zeroes
        int zer = 0;
        for(int i=0; i<ans.length(); i++){
            char ch = ans[i];
            if(ch != '0'){
                break;
            }else{
                zer++;
            }
        }
        
        if(zer == ans.length()){
            return "0";
        }
        
        string solu = "";
        for(int i=zer; i<ans.length(); i++){
            solu += ans[i];
        }
        return solu;
    }
};