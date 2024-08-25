

// exactly same as NGR problem

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        
        vector<int> ans;
        stack<int> s;
        s.push(n-1);
        ans.push_back(0);
        
        for(int i=n-2; i>=0; i--){
            if(temp[s.top()] > temp[i]){
                ans.push_back(s.top() - i);
            }else{
                while(!s.empty() && temp[s.top()] <= temp[i]){
                    s.pop();
                }
                if(!s.empty()){
                    ans.push_back(s.top() - i);
                }else{
                    ans.push_back(0);
                }
            }
            
            s.push(i);
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};