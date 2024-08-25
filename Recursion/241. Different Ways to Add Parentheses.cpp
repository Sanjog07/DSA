class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        int n = expression.size();
        
        vector<int> ans;
        for(int i=0; i<n; i++){
            char ch = expression[i];
            if(ch == '+' || ch == '-' || ch == '*'){
                string left = expression.substr(0,i);
                string right = expression.substr(i+1);
                
                vector<int> l = diffWaysToCompute(left);
                vector<int> r = diffWaysToCompute(right);
                
                for(auto x: l){
                    for(auto y: r){
                        if(ch == '+'){
                            ans.push_back(x+y);
                        }
                        if(ch == '*'){
                            ans.push_back(x*y);
                        }
                        if(ch == '-'){
                            ans.push_back(x-y);
                        }
                    }
                }
                //upar, left wala loop hi pehle chalega right wala 
                // nhi bcz hum value left to right calculate krte hai
            }
        }
        
        if(ans.empty()){
            ans.push_back(stoi(expression));
        }
        
        return ans;
    }
};