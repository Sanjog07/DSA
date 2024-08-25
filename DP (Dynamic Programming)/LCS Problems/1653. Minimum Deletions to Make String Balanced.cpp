class Solution {
public:
    int minimumDeletions(string str) {
        int n = str.length();
        
        stack<int> s;
        
        int min_deletions = 0;
        for(int i=0; i<n; i++){
            if(s.empty()){
                s.push(str[i]);
            }else if(s.top() == 'b' && str[i] == 'a'){
                min_deletions++;
                s.pop();
            }else{
                s.push(str[i]);
            }
        }
        
        return min_deletions;
    }
};