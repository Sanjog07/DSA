class Solution {
public:
    int countStudents(vector<int>& stu, vector<int>& sand) {
        int n = stu.size();
        int m = sand.size();
        
        stack<int> s;
        queue<pair<int,int> > q;
        
        for(int i=m-1; i>=0; i--){
            s.push(sand[i]);
        }
        for(int i=0; i<n; i++){
            q.push({stu[i], i});
        }
        
        int pt = -1;
        while(!s.empty() && !q.empty()){
            auto it = q.front();
            int val = it.first;
            int idx = it.second;
            
            q.pop();
            if(s.top() == val){
                s.pop();
                pt = -1;
            }else{
                
                q.push({val, idx});
                
                if(idx == pt){
                    return q.size();
                }
                
                if(pt == -1){
                    pt = idx;
                }                
                                
            }
        }
        
        return 0;
    }
};